#include "tonlib_worker.h"
#include "userver/formats/json.hpp"
#include "utils/common.hpp"

namespace ton_http::core {
td::Result<ConsensusBlockResult> TonlibWorker::getConsensusBlock(multiclient::SessionPtr) const {
  auto res = tonlib_.get_consensus_block();
  if (res.is_error()) {
    return res.move_as_error();
  }
  return ConsensusBlockResult{res.move_as_ok(), std::time(nullptr)};
}
td::Result<tonlib_api::blocks_getMasterchainInfo::ReturnType> TonlibWorker::getMasterchainInfo(
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getMasterchainInfo>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator = [] { return tonlib_api::make_object<tonlib_api::blocks_getMasterchainInfo>(); },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_getMasterchainBlockSignatures::ReturnType> TonlibWorker::getMasterchainBlockSignatures(
  std::int32_t seqno, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getMasterchainBlockSignatures>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [seqno] { return tonlib_api::make_object<tonlib_api::blocks_getMasterchainBlockSignatures>(seqno); },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_lookupBlock::ReturnType> TonlibWorker::lookupBlock(
  const std::int32_t& workchain,
  const std::int64_t& shard,
  const std::optional<std::int32_t>& seqno,
  const std::optional<std::int64_t>& lt,
  const std::optional<std::int32_t>& unixtime,
  multiclient::SessionPtr session
) const {
  if (!(seqno.has_value() || lt.has_value() || unixtime.has_value())) {
    return td::Status::Error(416, "one of seqno, lt, unixtime should be specified");
  }
  int lookupMode = 0;
  if (seqno.has_value()) {
    lookupMode += 1;
  }
  if (lt.has_value()) {
    lookupMode += 2;
  }
  if (unixtime.has_value()) {
    lookupMode += 4;
  }

  // try non-archival
  auto request = multiclient::RequestFunction<tonlib_api::blocks_lookupBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [lookupMode, workchain, shard, seqno, lt, unixtime] {
        return tonlib_api::make_object<tonlib_api::blocks_lookupBlock>(
          lookupMode,
          tonlib_api::make_object<tonlib_api::ton_blockId>(workchain, shard, seqno.has_value() ? seqno.value() : 0),
          (lt.has_value() ? lt.value() : 0),
          (unixtime.has_value() ? unixtime.value() : 0)
        );
      },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_getShardBlockProof::ReturnType> TonlibWorker::getShardBlockProof(
  const std::int32_t& workchain,
  const std::int64_t& shard,
  const std::int32_t& seqno,
  const std::optional<std::int32_t>& from_seqno,
  multiclient::SessionPtr session
) const {
  std::int32_t mode = 0;
  auto r_blk_id = lookupBlock(workchain, shard, seqno, std::nullopt, std::nullopt, session);
  if (r_blk_id.is_error()) {
    return r_blk_id.move_as_error();
  }
  auto blk_id = r_blk_id.move_as_ok();

  auto request = multiclient::RequestFunction<tonlib_api::blocks_getShardBlockProof>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [mode,
       w = blk_id->workchain_,
       s = blk_id->shard_,
       ss = blk_id->seqno_,
       r = blk_id->root_hash_,
       f = blk_id->file_hash_] {
        return tonlib_api::make_object<tonlib_api::blocks_getShardBlockProof>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, s, ss, r, f), mode, nullptr
        );
      },
    .session = session
  };

  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> from_blk_id = nullptr;
  if (from_seqno.has_value()) {
    mode = 1;
    auto r_from_blk_id =
      lookupBlock(ton::masterchainId, ton::shardIdAll, from_seqno.value(), std::nullopt, std::nullopt, session);
    if (r_from_blk_id.is_error()) {
      return r_from_blk_id.move_as_error_prefix("lookup from block error: ");
    }
    from_blk_id = r_from_blk_id.move_as_ok();
    request.request_creator = [mode,
                               w = blk_id->workchain_,
                               s = blk_id->shard_,
                               ss = blk_id->seqno_,
                               r = blk_id->root_hash_,
                               f = blk_id->file_hash_,
                               fw = from_blk_id->workchain_,
                               fs = from_blk_id->shard_,
                               fss = from_blk_id->seqno_,
                               fr = from_blk_id->root_hash_,
                               ff = from_blk_id->file_hash_] {
      return tonlib_api::make_object<tonlib_api::blocks_getShardBlockProof>(
        tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, s, ss, r, f),
        mode,
        tonlib_api::make_object<tonlib_api::ton_blockIdExt>(fw, fs, fss, fr, ff)
      );
    };
  }
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_getShards::ReturnType> TonlibWorker::getShards(
  std::optional<std::int32_t> mc_seqno,
  std::optional<std::int64_t> lt,
  std::optional<std::int32_t> unixtime,
  multiclient::SessionPtr session
) const {
  auto r_blk_id = lookupBlock(ton::masterchainId, ton::shardIdAll, mc_seqno, lt, unixtime, session);
  if (r_blk_id.is_error()) {
    return r_blk_id.move_as_error();
  }
  auto blk_id = r_blk_id.move_as_ok();
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getShards>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [w = blk_id->workchain_,
       s = blk_id->shard_,
       ss = blk_id->seqno_,
       r = blk_id->root_hash_,
       f = blk_id->file_hash_] {
        return tonlib_api::make_object<tonlib_api::blocks_getShards>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, s, ss, r, f)
        );
      },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_getBlockHeader::ReturnType> TonlibWorker::getBlockHeader(
  const std::int32_t& workchain,
  const std::int64_t& shard,
  const std::int32_t& seqno,
  const std::string& root_hash,
  const std::string& file_hash,
  multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> blk_id = nullptr;
  if (!root_hash.empty() && !file_hash.empty()) {
    blk_id = tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain, shard, seqno, root_hash, file_hash);
  } else {
    auto r_blk_id = lookupBlock(workchain, shard, seqno, std::nullopt, std::nullopt, session);
    if (r_blk_id.is_error()) {
      return r_blk_id.move_as_error();
    }
    blk_id = r_blk_id.move_as_ok();
  }
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getBlockHeader>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [w = blk_id->workchain_,
       s = blk_id->shard_,
       ss = blk_id->seqno_,
       r = blk_id->root_hash_,
       f = blk_id->file_hash_] {
        return tonlib_api::make_object<tonlib_api::blocks_getBlockHeader>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, s, ss, r, f)
        );
      },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
td::Result<tonlib_api::blocks_getOutMsgQueueSizes::ReturnType> TonlibWorker::getOutMsgQueueSizes(
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getOutMsgQueueSizes>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator = [] { return tonlib_api::make_object<tonlib_api::blocks_getOutMsgQueueSizes>(); },
    .session = session
  };
  return send_request_function(std::move(request), true);
}
}  // namespace ton_http::core
