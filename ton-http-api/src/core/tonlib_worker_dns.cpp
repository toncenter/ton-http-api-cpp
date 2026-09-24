#include "tonlib_worker.h"

#include "dns.h"
#include "vm/boc.h"
#include "vm/cells/CellBuilder.h"

namespace ton_http::core {
td::Result<tonlib_api::dns_resolve::ReturnType> TonlibWorker::dnsResolve(
  const std::string& domain,
  std::optional<std::string> resolver_address,
  std::optional<std::int32_t> seqno,
  multiclient::SessionPtr session
) const {
  TRY_RESULT(prepared, dns::prepare_domain(domain, resolver_address.has_value()));
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> block;
  if (seqno) {
    TRY_RESULT_ASSIGN(block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno, {}, {}, session));
  } else {
    TRY_RESULT(info, getMasterchainInfo(session));
    block = std::move(info->last_);
  }
  // Pin the full block identity for config discovery and every contract load.
  auto make_block =
    [w = block->workchain_, s = block->shard_, n = block->seqno_, r = block->root_hash_, f = block->file_hash_] {
      return tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, s, n, r, f);
    };
  if (!resolver_address) {
    auto config_request = multiclient::RequestFunction<tonlib_api::withBlock>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator =
        [make_block] {
          return tonlib_api::make_object<tonlib_api::withBlock>(
            make_block(), tonlib_api::make_object<tonlib_api::getConfigParam>(0, 4)
          );
        },
      .session = session
    };
    TRY_RESULT(raw_config, send_request_function(std::move(config_request), true));
    auto config = ton::move_tl_object_as<tonlib_api::configInfo>(raw_config);
    TRY_RESULT(root, dns::root_from_config(*config));
    resolver_address = std::move(root);
  }
  return dns::resolve(
    prepared,
    *resolver_address,
    [&](
      const std::string& resolver, const std::string& encoded
    ) -> td::Result<tonlib_api::smc_runGetMethod::ReturnType> {
      auto load = multiclient::RequestFunction<tonlib_api::withBlock>{
        .parameters = {.mode = multiclient::RequestMode::Single},
        .request_creator =
          [make_block, resolver] {
            return tonlib_api::make_object<tonlib_api::withBlock>(
              make_block(),
              tonlib_api::make_object<tonlib_api::smc_load>(tonlib_api::make_object<tonlib_api::accountAddress>(resolver
              ))
            );
          },
        .session = session
      };
      TRY_RESULT(boc, vm::std_boc_serialize(vm::CellBuilder().store_bytes(encoded).finalize()));
      TRY_RESULT(loaded, send_request_function(std::move(load), true));
      auto smc = ton::move_tl_object_as<tonlib_api::smc_info>(loaded);
      auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
        .parameters = {.mode = multiclient::RequestMode::Single},
        .request_creator =
          [id = smc->id_, bytes = boc.as_slice().str()] {
            std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
            stack.push_back(tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(
              tonlib_api::make_object<tonlib_api::tvm_slice>(bytes)
            ));
            stack.push_back(tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(
              tonlib_api::make_object<tonlib_api::tvm_numberDecimal>("0")
            ));
            return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
              id, tonlib_api::make_object<tonlib_api::smc_methodIdName>("dnsresolve"), std::move(stack)
            );
          },
        .session = session
      };
      // A loaded contract belongs to one TONlib client. Do not retry the
      // get-method on another client using the same handle.
      auto result = send_request_function(std::move(request), false);
      auto forgotten = forgetContract(smc->id_, {}, session);
      if (result.is_error()) {
        return result.move_as_error();
      }
      if (forgotten.is_error()) {
        return forgotten.move_as_error();
      }
      return result;
    }
  );
}
}  // namespace ton_http::core
