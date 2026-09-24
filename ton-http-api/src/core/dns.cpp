#include "dns.h"

#include <set>
#include <utility>

#include "block/block-auto.h"
#include "common/util.h"
#include "smc-envelope/ManualDns.h"
#include "td/utils/misc.h"
#include "td/utils/overloaded.h"
#include "td/utils/utf8.h"
#include "vm/boc.h"
#include "vm/dict.h"

namespace ton_http::core::dns {
namespace {
namespace api = ton::tonlib_api;
constexpr std::size_t kMaxResolverCalls = 64;

td::Status InvalidResponse(const std::string& message) {
  return td::Status::Error(502, "DNS resolution: " + message);
}

td::Result<api::object_ptr<api::dns_EntryData>> ParseRecord(td::Ref<vm::Cell> cell) {
  auto cs = vm::load_cell_slice(cell);
  auto tag = cs.size() >= 16 ? block::gen::t_DNSRecord.check_tag(cs) : -1;
  switch (tag) {
    case block::gen::DNSRecord::dns_text:
    case block::gen::DNSRecord::dns_next_resolver:
    case block::gen::DNSRecord::dns_adnl_address:
    case block::gen::DNSRecord::dns_smc_address:
    case block::gen::DNSRecord::dns_storage_address:
      break;
    default: {
      TRY_RESULT(boc, vm::std_boc_serialize(cell));
      return api::object_ptr<api::dns_EntryData>(api::make_object<api::dns_entryDataUnknown>(boc.as_slice().str()));
    }
  }
  auto parsed = ton::DnsInterface::EntryData::from_cellslice(cs);
  if (parsed.is_error()) {
    return InvalidResponse("malformed DNS record: " + parsed.error().message().str());
  }
  api::object_ptr<api::dns_EntryData> result;
  parsed.ok().data.visit(td::overloaded(
    [&](const ton::DnsInterface::EntryDataText& value) {
      result = api::make_object<api::dns_entryDataText>(value.text);
    },
    [&](const ton::DnsInterface::EntryDataNextResolver& value) {
      result = api::make_object<api::dns_entryDataNextResolver>(
        api::make_object<api::accountAddress>(value.resolver.rserialize(true))
      );
    },
    [&](const ton::DnsInterface::EntryDataSmcAddress& value) {
      result = api::make_object<api::dns_entryDataSmcAddress>(
        api::make_object<api::accountAddress>(value.smc_address.rserialize(true))
      );
    },
    [&](const ton::DnsInterface::EntryDataAdnlAddress& value) {
      result = api::make_object<api::dns_entryDataAdnlAddress>(
        api::make_object<api::adnlAddress>(td::adnl_id_encode(value.adnl_address.as_slice()).move_as_ok())
      );
    },
    [&](const ton::DnsInterface::EntryDataStorageAddress& value) {
      result = api::make_object<api::dns_entryDataStorageAddress>(value.bag_id);
    }
  ));
  return std::move(result);
}

td::Result<api::dns_resolve::ReturnType> ParseRecords(td::Ref<vm::Cell> cell, const std::string& domain) {
  std::vector<api::object_ptr<api::dns_entry>> entries;
  vm::Dictionary dict(std::move(cell), 256);
  td::Status error = td::Status::OK();
  auto valid = dict.check_for_each([&](td::Ref<vm::CellSlice> value, td::ConstBitPtr key, int bits) {
    if (bits != 256 || value.is_null() || value->size_ext() != 0x10000) {
      return false;
    }
    auto record = ParseRecord(value->prefetch_ref());
    if (record.is_error()) {
      error = record.move_as_error();
      return false;
    }
    entries.push_back(api::make_object<api::dns_entry>(domain, td::Bits256(key), record.move_as_ok()));
    return true;
  });
  TRY_STATUS(std::move(error));
  if (!valid) {
    return InvalidResponse("invalid record dictionary");
  }
  return api::make_object<api::dns_resolved>(std::move(entries));
}

td::Result<api::dns_resolve::ReturnType> ResolveImpl(
  const PreparedDomain& domain, std::string resolver, const Query& query
) {
  std::string remaining = domain.encoded;
  std::set<std::pair<std::string, std::string>> visited;
  for (std::size_t hop = 0; hop < kMaxResolverCalls; ++hop) {
    if (!visited.emplace(resolver, remaining).second) {
      return InvalidResponse("resolver cycle detected");
    }
    TRY_RESULT(result, query(resolver, remaining));
    if (!result) {
      return InvalidResponse("missing dnsresolve get-method result");
    }
    if (result->exit_code_ != 0 && result->exit_code_ != 1) {
      return InvalidResponse("dnsresolve get-method failed with exit code " + std::to_string(result->exit_code_));
    }
    const auto& stack = result->stack_;
    if (stack.size() != 2 || !stack[0] || !stack[1] || stack[0]->get_id() != api::tvm_stackEntryNumber::ID) {
      return InvalidResponse("expected a consumed-bit count and a record cell");
    }
    const auto& number = static_cast<const api::tvm_stackEntryNumber&>(*stack[0]).number_;
    if (!number || number->get_id() != api::tvm_numberDecimal::ID) {
      return InvalidResponse("invalid consumed-bit count");
    }
    auto parsed_bits = td::to_integer_safe<int>(static_cast<const api::tvm_numberDecimal&>(*number).number_);
    if (parsed_bits.is_error()) {
      return InvalidResponse("invalid consumed-bit count");
    }
    auto bits = parsed_bits.move_as_ok();
    if (bits < 0 || bits % 8 != 0 || static_cast<std::size_t>(bits) > remaining.size() * 8) {
      return InvalidResponse("consumed-bit count is outside the domain or not byte-aligned");
    }
    auto consumed = static_cast<std::size_t>(bits / 8);
    // TONlib serializes TVM null as an empty Lisp list.
    const auto* list = stack[1]->get_id() == api::tvm_stackEntryList::ID ?
      &static_cast<const api::tvm_stackEntryList&>(*stack[1]).list_ :
      nullptr;
    if (list && *list && (*list)->elements_.empty()) {
      if (consumed != 0 && consumed != remaining.size()) {
        return InvalidResponse("partial resolution without a next resolver");
      }
      return api::make_object<api::dns_resolved>(std::vector<api::object_ptr<api::dns_entry>>{});
    }
    if (consumed == 0 || stack[1]->get_id() != api::tvm_stackEntryCell::ID) {
      return InvalidResponse("invalid record cell");
    }
    const auto& data = static_cast<const api::tvm_stackEntryCell&>(*stack[1]).cell_;
    if (!data) {
      return InvalidResponse("missing record cell");
    }
    auto decoded = vm::std_boc_deserialize(data->bytes_);
    if (decoded.is_error()) {
      return InvalidResponse("invalid record BOC: " + decoded.error().message().str());
    }
    auto cell = decoded.move_as_ok();
    if (consumed == remaining.size()) {
      return ParseRecords(std::move(cell), domain.domain);
    }
    // Contracts may consume a label with or without its terminating zero byte.
    if (remaining[consumed - 1] != '\0' && remaining[consumed] != '\0') {
      return InvalidResponse("delegation splits a domain label");
    }
    TRY_RESULT(record, ParseRecord(std::move(cell)));
    if (record->get_id() != api::dns_entryDataNextResolver::ID) {
      return InvalidResponse("partial resolution did not return a next resolver");
    }
    resolver = static_cast<const api::dns_entryDataNextResolver&>(*record).resolver_->account_address_;
    remaining.erase(0, consumed);
  }
  return InvalidResponse("resolver hop limit exceeded (64 calls)");
}
}  // namespace

td::Result<PreparedDomain> prepare_domain(std::string domain, bool custom_resolver) {
  if (!td::check_utf8(domain)) {
    return td::Status::Error(422, "domain must be valid UTF-8");
  }
  domain = td::utf8_to_lower(domain);
  if (!domain.empty() && domain.back() == '.') {
    domain.pop_back();
  }
  if (domain.empty() || domain.front() == '.' || domain.back() == '.' || domain.find("..") != std::string::npos) {
    return td::Status::Error(422, "domain must contain nonempty labels");
  }
  for (unsigned char c : domain) {
    if (c <= 32 || c == 127) {
      return td::Status::Error(422, "domain must not contain spaces or control characters");
    }
  }
  auto encoded = ton::DnsInterface::encode_name(domain);
  if (custom_resolver) {
    encoded.insert(encoded.begin(), '\0');
  }
  if (encoded.size() > 127) {
    return td::Status::Error(422, "encoded domain must not exceed 127 bytes");
  }
  return PreparedDomain{std::move(domain), std::move(encoded)};
}

td::Result<std::string> root_from_config(const api::configInfo& config) {
  if (!config.config_) {
    return InvalidResponse("config parameter 4 is missing");
  }
  auto decoded = vm::std_boc_deserialize(config.config_->bytes_);
  if (decoded.is_error()) {
    return InvalidResponse("invalid config parameter 4 BOC");
  }
  auto cs = vm::load_cell_slice_quiet(decoded.move_as_ok());
  if (!cs.is_valid() || cs.size() != 256 || cs.size_refs() != 0) {
    return InvalidResponse("config parameter 4 must contain a 256-bit address");
  }
  td::Bits256 address;
  cs.fetch_bits_to(address);
  return "-1:" + address.to_hex();
}

td::Result<api::dns_resolve::ReturnType> resolve(
  const PreparedDomain& domain, std::string resolver, const Query& query
) {
  try {
    return ResolveImpl(domain, std::move(resolver), query);
  } catch (const vm::VmError& error) {
    return InvalidResponse(error.get_msg());
  } catch (const vm::VmVirtError& error) {
    return InvalidResponse(error.get_msg());
  }
}

}  // namespace ton_http::core::dns
