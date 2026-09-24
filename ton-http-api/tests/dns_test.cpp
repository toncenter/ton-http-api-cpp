#include "core/dns.h"

#include <set>

#include "block/block-parse.h"
#include "smc-envelope/ManualDns.h"
#include "td/utils/tests.h"
#include "vm/boc.h"
#include "vm/dict.h"

namespace {
namespace dns = ton_http::core::dns;
namespace api = ton::tonlib_api;
using Record = ton::DnsInterface::EntryData;
using namespace std::string_literals;

block::StdAddress Address(unsigned char value = 1) {
  td::Bits256 hash;
  hash.as_slice().fill(value);
  return block::StdAddress(0, hash);
}

td::Ref<vm::Cell> Dictionary(const std::vector<std::pair<std::string, td::Ref<vm::Cell>>>& records) {
  vm::Dictionary dict(256);
  for (const auto& [category, cell] : records) {
    CHECK(dict.set_ref(td::sha256_bits256(category), cell));
  }
  return dict.get_root_cell();
}

td::Ref<vm::Cell> WalletRecord(const block::StdAddress& address) {
  vm::CellBuilder cb;
  cb.store_long(0x9fd3, 16);
  CHECK(block::tlb::t_MsgAddressInt.store_std_address(cb, address.workchain, address.addr));
  cb.store_long(0, 8);  // No capability flags.
  return cb.finalize();
}

api::object_ptr<api::smc_runResult> Reply(int consumed_bits, td::Ref<vm::Cell> cell = {}) {
  std::vector<api::object_ptr<api::tvm_StackEntry>> stack;
  stack.push_back(
    api::make_object<api::tvm_stackEntryNumber>(api::make_object<api::tvm_numberDecimal>(std::to_string(consumed_bits)))
  );
  if (cell.is_null()) {
    stack.push_back(api::make_object<api::tvm_stackEntryList>(
      api::make_object<api::tvm_list>(std::vector<api::object_ptr<api::tvm_StackEntry>>{})
    ));
  } else {
    auto boc = vm::std_boc_serialize(cell).move_as_ok();
    stack.push_back(api::make_object<api::tvm_stackEntryCell>(api::make_object<api::tvm_cell>(boc.as_slice().str())));
  }
  return api::make_object<api::smc_runResult>(0, std::move(stack), 0);
}

TEST(Dns, DomainEncoding) {
  auto domain = dns::prepare_domain("Sub.Domain.TON.", false).move_as_ok();
  ASSERT_EQ(domain.domain, "sub.domain.ton");
  ASSERT_EQ(domain.encoded, "ton\0domain\0sub\0"s);
  ASSERT_EQ(dns::prepare_domain("User.T.Me", false).move_as_ok().encoded, "me\0t\0user\0"s);
  ASSERT_EQ(dns::prepare_domain("sub", true).move_as_ok().encoded, "\0sub\0"s);
  ASSERT_EQ(dns::prepare_domain("ТЕСТ.ton", false).move_as_ok().domain, "тест.ton");
  ASSERT_TRUE(dns::prepare_domain(std::string(126, 'a'), false).is_ok());
  ASSERT_TRUE(dns::prepare_domain(std::string(127, 'a'), false).is_error());
  ASSERT_TRUE(dns::prepare_domain(std::string(125, 'a'), true).is_ok());
  ASSERT_TRUE(dns::prepare_domain(std::string(126, 'a'), true).is_error());
  for (const auto& invalid :
       {""s, "."s, ".ton"s, "a..ton"s, "a.ton.."s, "a b.ton"s, "a\0b.ton"s, "a\n.ton"s, "\xff.ton"s, "a\x7f.ton"s}) {
    ASSERT_TRUE(dns::prepare_domain(invalid, false).is_error());
  }
}

TEST(Dns, RootConfig) {
  auto addr = Address().addr;
  auto cell = vm::CellBuilder().store_bits(addr.cbits(), 256).finalize();
  auto boc = vm::std_boc_serialize(cell).move_as_ok();
  api::configInfo config(api::make_object<api::tvm_cell>(boc.as_slice().str()));
  ASSERT_EQ(dns::root_from_config(config).move_as_ok(), "-1:" + addr.to_hex());
  config.config_.reset();
  ASSERT_TRUE(dns::root_from_config(config).is_error());
  config.config_ = api::make_object<api::tvm_cell>("invalid BOC");
  ASSERT_TRUE(dns::root_from_config(config).is_error());
  boc = vm::std_boc_serialize(vm::CellBuilder().store_long(0, 8).finalize()).move_as_ok();
  config.config_ = api::make_object<api::tvm_cell>(boc.as_slice().str());
  ASSERT_TRUE(dns::root_from_config(config).is_error());
}

TEST(Dns, DelegationAndAllRecordTypes) {
  const auto address = Address();
  auto next = Record::next_resolver(address).as_cell().move_as_ok();
  auto unknown = vm::CellBuilder().store_long(0x1234, 16).store_long(42, 8).finalize();
  auto records = Dictionary(
    {{"wallet", WalletRecord(address)},
     {"site", Record::adnl_address(address.addr).as_cell().move_as_ok()},
     {"storage", Record::storage_address(address.addr).as_cell().move_as_ok()},
     {"dns_next_resolver", next},
     {"text", Record::text("hello").as_cell().move_as_ok()},
     {"custom", unknown}}
  );
  const auto domain = dns::prepare_domain("sub.domain.ton", false).move_as_ok();
  int calls = 0;
  auto result = dns::resolve(domain, "root", [&](const std::string& resolver, const std::string& encoded) {
                  ++calls;
                  if (calls == 1) {
                    ASSERT_EQ(resolver, "root");
                    ASSERT_EQ(encoded, "ton\0domain\0sub\0"s);
                    return Reply(24, next);  // Root leaves the separator for the next resolver.
                  }
                  ASSERT_EQ(resolver, address.rserialize(true));
                  if (calls == 2) {
                    ASSERT_EQ(encoded, "\0domain\0sub\0"s);
                    return Reply(56, next);
                  }
                  ASSERT_EQ(encoded, "\0sub\0"s);
                  return Reply(static_cast<int>(encoded.size() * 8), records);
                }).move_as_ok();
  ASSERT_EQ(calls, 3);  // Terminal next-resolver record must not be followed.
  ASSERT_EQ(result->entries_.size(), 6u);
  std::set<int> types;
  for (const auto& entry : result->entries_) {
    ASSERT_EQ(entry->name_, domain.domain);
    types.insert(entry->entry_->get_id());
    if (entry->entry_->get_id() == api::dns_entryDataUnknown::ID) {
      ASSERT_EQ(entry->category_, td::sha256_bits256("custom"));
      const auto& bytes = static_cast<const api::dns_entryDataUnknown&>(*entry->entry_).bytes_;
      ASSERT_EQ(vm::std_boc_deserialize(bytes).move_as_ok()->get_hash(), unknown->get_hash());
    }
  }
  ASSERT_EQ(types.size(), 6u);
}

TEST(Dns, TelegramAndCustomResolver) {
  auto next = Record::next_resolver(Address()).as_cell().move_as_ok();
  for (bool custom : {false, true}) {
    auto domain = dns::prepare_domain(custom ? "user" : "user.t.me", custom).move_as_ok();
    int calls = 0;
    auto result = dns::resolve(domain, "start", [&](const std::string&, const std::string& encoded) {
                    ++calls;
                    if (!custom && calls == 1) {
                      ASSERT_EQ(encoded, "me\0t\0user\0"s);
                      return Reply(32, next);
                    }
                    ASSERT_EQ(encoded, "\0user\0"s);
                    return Reply(static_cast<int>(encoded.size() * 8));
                  }).move_as_ok();
    ASSERT_TRUE(result->entries_.empty());
    ASSERT_EQ(calls, custom ? 1 : 2);
  }
}

TEST(Dns, DelegationConsumesSeparator) {
  auto domain = dns::prepare_domain("a.ton", false).move_as_ok();
  auto next = Record::next_resolver(Address()).as_cell().move_as_ok();
  int calls = 0;
  auto result = dns::resolve(domain, "root", [&](const auto&, const std::string& encoded) {
                  if (++calls == 1) {
                    return Reply(32, next);
                  }
                  ASSERT_EQ(encoded, "a\0"s);
                  return Reply(16);
                }).move_as_ok();
  ASSERT_EQ(calls, 2);
  ASSERT_TRUE(result->entries_.empty());
}

TEST(Dns, EmptyUnknownRecord) {
  auto domain = dns::prepare_domain("a.ton", false).move_as_ok();
  auto records = Dictionary({{"custom", vm::CellBuilder().finalize()}});
  auto result = dns::resolve(domain, "root", [&](const auto&, const std::string& encoded) {
                  return Reply(static_cast<int>(encoded.size() * 8), records);
                }).move_as_ok();
  ASSERT_EQ(result->entries_.size(), 1u);
  ASSERT_EQ(result->entries_[0]->entry_->get_id(), api::dns_entryDataUnknown::ID);
}

TEST(Dns, MissingAndMalformedResults) {
  auto domain = dns::prepare_domain("a.ton", false).move_as_ok();
  for (int bits : {0, static_cast<int>(domain.encoded.size() * 8)}) {
    auto result = dns::resolve(domain, "root", [&](const auto&, const auto&) { return Reply(bits); }).move_as_ok();
    ASSERT_TRUE(result->entries_.empty());
  }
  auto next = Record::next_resolver(Address()).as_cell().move_as_ok();
  for (int bits : {-8, 1, 1024, 0, 8}) {
    ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) { return Reply(bits, next); }).is_error());
  }
  ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) { return Reply(24); }).is_error());
  auto wrong_type = Record::text("not a resolver").as_cell().move_as_ok();
  ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) { return Reply(24, wrong_type); }).is_error());
  ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) {
                auto result = Reply(0);
                result->exit_code_ = 42;
                return result;
              }).is_error());
  ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) {
                auto result = Reply(0);
                result->stack_.pop_back();
                return result;
              }).is_error());
  ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto&) {
                auto result = Reply(0);
                result->stack_[1] = api::make_object<api::tvm_stackEntryUnsupported>();
                return result;
              }).is_error());
  auto failure =
    dns::resolve(domain, "root", [](const auto&, const auto&) -> td::Result<api::smc_runGetMethod::ReturnType> {
      return td::Status::Error(504, "query timed out");
    });
  ASSERT_TRUE(failure.is_error());
  ASSERT_EQ(failure.error().code(), 504);
}

TEST(Dns, InvalidDictionaryAndMalformedKnownRecord) {
  auto domain = dns::prepare_domain("a.ton", false).move_as_ok();
  td::Ref<vm::Cell> malformed = vm::CellBuilder().store_long(0xba93, 16).finalize();
  auto dict = Dictionary({{"dns_next_resolver", malformed}});
  for (auto cell : {malformed, dict}) {
    ASSERT_TRUE(dns::resolve(domain, "root", [&](const auto&, const auto& encoded) {
                  return Reply(static_cast<int>(encoded.size() * 8), cell);
                }).is_error());
  }
}

TEST(Dns, HopLimit) {
  std::string name = "a";
  for (int i = 0; i < 61; ++i) {
    name += ".a";
  }
  auto domain = dns::prepare_domain(name, false).move_as_ok();
  auto next = Record::next_resolver(Address()).as_cell().move_as_ok();
  int calls = 0;
  auto result = dns::resolve(domain, "root", [&](const auto&, const auto&) {
    ++calls;
    return Reply(8, next);  // Alternate consuming one label and its separator.
  });
  ASSERT_TRUE(result.is_error());
  ASSERT_EQ(calls, 64);
  ASSERT_TRUE(result.error().message().str().find("hop limit") != std::string::npos);
}
}  // namespace

int main() {
  auto& runner = td::TestsRunner::get_default();
  runner.run_all();
  return runner.any_test_failed() ? 1 : 0;
}
