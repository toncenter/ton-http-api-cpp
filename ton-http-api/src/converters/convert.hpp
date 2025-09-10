#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"

namespace ton_http {
namespace converters {

inline schemas::v2::TonBlockIdExt Convert(tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& value) {
  schemas::v2::TonBlockIdExt result;
  result.workchain = value->workchain_;
  result.shard = types::shard_id{value->shard_};
  result.seqno = value->seqno_;
  result.root_hash = types::ton_hash{value->root_hash_};
  result.file_hash = types::ton_hash{value->file_hash_};
  return result;
}

inline schemas::v2::MasterchainInfoResult Convert(tonlib_api::blocks_getMasterchainInfo::ReturnType& value) {
  schemas::v2::MasterchainInfoResult result;
  result.init = Convert(value->init_);
  result.last = Convert(value->last_);
  result.state_root_hash = types::ton_hash{value->state_root_hash_};
  return result;
}

}
}
