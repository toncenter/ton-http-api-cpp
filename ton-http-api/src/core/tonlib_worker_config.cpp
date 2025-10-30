#include "tonlib_worker.h"
#include "utils/common.hpp"

namespace ton_http::core {
td::Result<tonlib_api::getConfigParam::ReturnType> TonlibWorker::getConfigParam(
  const std::int32_t& param, std::optional<std::int32_t> seqno, multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::getConfigParam>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator = [param_ = param] { return tonlib_api::make_object<tonlib_api::getConfigParam>(param_, 0); },
      .session = session
    };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [param_ = param,
       workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::getConfigParam>(param_, 0)
        );
      },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), true));
  return ton::move_tl_object_as<tonlib_api::configInfo>(result);
}
td::Result<tonlib_api::getConfigParam::ReturnType> TonlibWorker::getConfigAll(
  std::optional<std::int32_t> seqno, multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::getConfigAll>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator = [] { return tonlib_api::make_object<tonlib_api::getConfigAll>(0); },
      .session = session
    };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::getConfigAll>(0)
        );
      },
    .session = session
  };
  auto result = send_request_function(std::move(request), true);
  if (result.is_error()) {
    return result.move_as_error();
  }
  return ton::move_tl_object_as<tonlib_api::configInfo>(result.move_as_ok());
}
td::Result<std::unique_ptr<tonlib_api::smc_libraryResult>> TonlibWorker::getLibraries(
  std::vector<std::string> libs, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_getLibraries>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [libs] {
        std::vector<td::Bits256> lib_hashes;
        for (auto& lib : libs) {
          td::Bits256 hash;
          hash.as_slice().copy_from(lib);
          lib_hashes.push_back(hash);
        }
        return tonlib_api::make_object<tonlib_api::smc_getLibraries>(std::move(lib_hashes));
      },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
}  // namespace ton_http::core
