#include "tonlib_worker.h"
#include "utils/common.hpp"

namespace ton_http::core {
td::Result<tonlib_api::raw_getAccountState::ReturnType> TonlibWorker::getAddressInformation(
  const std::string& address, std::optional<std::int32_t> seqno, multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::raw_getAccountState>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator =
        [address_ = address] {
          return tonlib_api::make_object<tonlib_api::raw_getAccountState>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_)
          );
        },
      .session = session
    };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [address_ = address,
       workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::raw_getAccountState>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_)
          )
        );
      },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), true));
  return ton::move_tl_object_as<tonlib_api::raw_fullAccountState>(result);
}
td::Result<tonlib_api::getAccountState::ReturnType> TonlibWorker::getExtendedAddressInformation(
  const std::string& address, std::optional<std::int32_t> seqno, multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::getAccountState>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator =
        [address_ = address] {
          return tonlib_api::make_object<tonlib_api::getAccountState>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_)
          );
        },
      .session = session
    };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [address_ = address,
       workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::getAccountState>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_)
          )
        );
      },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), true));
  return ton::move_tl_object_as<tonlib_api::fullAccountState>(result);
}
}  // namespace ton_http::core
