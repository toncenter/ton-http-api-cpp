#include "tonlib_worker.h"
#include "userver/formats/json.hpp"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<std::unique_ptr<tonlib_api::smc_info>> TonlibWorker::loadContract(
    const std::string& address,
    std::optional<std::uint32_t> seqno,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  if (session == nullptr && archival.has_value()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    auto r_session = tonlib_.get_session(options, nullptr);
    if (r_session.is_error()) {
      return td::Status::Error(533, r_session.move_as_error_prefix("Failed to get session: ").message());
    }
    session = r_session.move_as_ok();
  }
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    auto res =
        lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session);
    if (!res.is_ok()) {
      return res.move_as_error();
    }
    with_block = res.move_as_ok();
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
                tonlib_api::make_object<tonlib_api::smc_load>(
                    tonlib_api::make_object<tonlib_api::accountAddress>(address_)
                )
            );
          },
      .session = session
  };
  auto result = send_request_function(std::move(request), false);
  if (result.is_error()) {
    return result.move_as_error();
  }
  return ton::move_tl_object_as<tonlib_api::smc_info>(result.move_as_ok());
}
td::Result<std::unique_ptr<tonlib_api::ok>> TonlibWorker::forgetContract(
    std::int64_t id, std::optional<bool> archival, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_forget>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
        [id]() {
          return tonlib_api::make_object<tonlib_api::smc_forget>(id);
    },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<RunGetMethodResult> TonlibWorker::runGetMethod(
    const std::string& address,
    const std::string& method_name,
    const std::vector<std::string>& stack,
    std::optional<std::uint32_t> seqno,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  auto r_smc_info = loadContract(address, seqno, archival, session);
  if (!r_smc_info.is_ok()) {
    return r_smc_info.move_as_error();
  }
  auto smc_info = r_smc_info.move_as_ok();
  auto r_stack = utils::parse_stack(stack);
  if (r_stack.is_error()) {
    return r_stack.move_as_error();
  }
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
        [id_ = smc_info->id_, method_name_ = method_name, stack_str = stack] {
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
  auto result = send_request_function(std::move(request), false);
  if (result.is_error()) {
    return result.move_as_error();
  }

  auto state_request = multiclient::RequestFunction<tonlib_api::smc_getRawFullAccountState>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
        [id_ = smc_info->id_] { return tonlib_api::make_object<tonlib_api::smc_getRawFullAccountState>(id_); },
    .session = session
};
  auto state_result = send_request_function(std::move(state_request), false);
  if (state_result.is_error()) {
    return state_result.move_as_error();
  }

  auto forget_result = forgetContract(smc_info->id_, archival, session);
  if (forget_result.is_error()) {
    return forget_result.move_as_error();
  }

  return RunGetMethodResult{result.move_as_ok(), state_result.move_as_ok()};
}
}
