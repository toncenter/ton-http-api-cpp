#include "tonlib_worker.h"
#include "userver/formats/json.hpp"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<std::unique_ptr<tonlib_api::smc_info>> TonlibWorker::loadContract(
  const std::string& address,
  std::optional<std::int32_t> seqno,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  if (session == nullptr && archival.has_value()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "Failed to get session: ");
  }
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::smc_load>{
      .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
      .request_creator =
        [address]() {
          return tonlib_api::make_object<tonlib_api::smc_load>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address)
          );
        },
      .session = session
    };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [address_ = address,
       workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::smc_load>(tonlib_api::make_object<tonlib_api::accountAddress>(address_))
        );
      },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), false));
  return ton::move_tl_object_as<tonlib_api::smc_info>(result);
}
td::Result<std::unique_ptr<tonlib_api::ok>> TonlibWorker::forgetContract(
  std::int64_t id, std::optional<bool> archival, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_forget>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id]() { return tonlib_api::make_object<tonlib_api::smc_forget>(id); },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<RunGetMethodResult> TonlibWorker::runGetMethod_impl(
  std::int64_t smc_id,
  const std::string& method_name,
  const std::vector<std::string>& stack,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [id_ = smc_id, method_name_ = method_name, stack_str = stack] {
        auto method_int = td::string_to_int256(method_name_);
        auto stack = utils::parse_stack(stack_str).move_as_ok();
        if (method_int.is_null()) {
          return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
            id_, tonlib_api::make_object<tonlib_api::smc_methodIdName>(method_name_), std::move(stack)
          );
        }
        return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
          id_, tonlib_api::make_object<tonlib_api::smc_methodIdNumber>(method_int->to_long()), std::move(stack)
        );
      },
    .session = session
  };
  TRY_RESULT(runmethod_result, send_request_function(std::move(request), false));
  auto state_request = multiclient::RequestFunction<tonlib_api::smc_getRawFullAccountState>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] { return tonlib_api::make_object<tonlib_api::smc_getRawFullAccountState>(id_); },
    .session = session
  };
  TRY_RESULT(state_result, send_request_function(std::move(state_request), false));
  return RunGetMethodResult{std::move(runmethod_result), std::move(state_result)};
}
td::Result<RunGetMethodResult> TonlibWorker::runGetMethod(
  const std::string& address,
  const std::string& method_name,
  const std::vector<std::string>& stack,
  std::optional<std::int32_t> seqno,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  TRY_STATUS(utils::parse_stack(stack));
  TRY_RESULT(smc_info, loadContract(address, seqno, archival, session));

  auto&& run_method_result = runGetMethod_impl(smc_info->id_, method_name, stack, archival, session);

  TRY_STATUS(forgetContract(smc_info->id_, archival, session));
  return std::move(run_method_result);
}
}  // namespace ton_http::core
