#pragma once
#include "auto/tl/tonlib_api.h"
#include "common.hpp"
#include "schemas/v2.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::MasterchainInfo Convert(const tonlib_api::blocks_getMasterchainInfo::ReturnType& value) {
  schemas::v2::MasterchainInfo result;
  result.init = Convert(value->init_);
  result.last = Convert(value->last_);
  result.state_root_hash = types::ton_hash{value->state_root_hash_};
  return result;
}

inline schemas::v2::BlockSignature Convert(const tonlib_api::object_ptr<tonlib_api::blocks_signature>& value) {
  schemas::v2::BlockSignature result;
  result.node_id_short = types::ton_hash{value->node_id_short_.as_slice().str()};
  result.signature = types::bytes{value->signature_};
  return result;
}

inline schemas::v2::MasterchainBlockSignatures Convert(
  const tonlib_api::blocks_getMasterchainBlockSignatures::ReturnType& value
) {
  schemas::v2::MasterchainBlockSignatures result;
  result.id = Convert(value->id_);
  for (auto& sig : value->signatures_) {
    result.signatures.push_back(Convert(sig));
  }
  return result;
}

inline schemas::v2::ShardBlockLink Convert(const tonlib_api::object_ptr<tonlib_api::blocks_shardBlockLink>& value) {
  schemas::v2::ShardBlockLink result;
  result.id = Convert(value->id_);
  result.proof = types::bytes{value->proof_};
  return result;
}

inline schemas::v2::BlockLinkBack Convert(const tonlib_api::object_ptr<tonlib_api::blocks_blockLinkBack>& value) {
  schemas::v2::BlockLinkBack result;
  result.to_key_block = value->to_key_block_;
  result.from = Convert(value->from_);
  result.to = Convert(value->to_);
  result.dest_proof = types::bytes{value->dest_proof_};
  result.proof = types::bytes{value->proof_};
  result.state_proof = types::bytes{value->state_proof_};
  return result;
}

inline schemas::v2::ShardBlockProof Convert(const tonlib_api::blocks_getShardBlockProof::ReturnType& value) {
  schemas::v2::ShardBlockProof result;
  result.from = Convert(value->from_);
  result.mc_id = Convert(value->mc_id_);
  for (auto& link : value->links_) {
    result.links.emplace_back(Convert(link));
  }
  for (auto& link : value->mc_proof_) {
    result.mc_proof.emplace_back(Convert(link));
  }
  return result;
}

inline schemas::v2::ConsensusBlock Convert(const core::ConsensusBlockResult& value) {
  schemas::v2::ConsensusBlock result;
  result.consensus_block = value.seqno;
  result.timestamp = value.timestamp;
  return result;
}

inline schemas::v2::Shards Convert(const tonlib_api::blocks_getShards::ReturnType& value) {
  schemas::v2::Shards result;
  for (const auto& item : value->shards_) {
    result.shards.emplace_back(Convert(item));
  }
  return result;
}

inline schemas::v2::BlockHeader Convert(const tonlib_api::blocks_getBlockHeader::ReturnType& value) {
  schemas::v2::BlockHeader result;
  result.id = Convert(value->id_);
  result.global_id = value->global_id_;
  result.version = value->version_;
  result.after_merge = value->after_merge_;
  result.after_split = value->after_split_;
  result.before_split = value->before_split_;
  result.want_merge = value->want_merge_;
  result.want_split = value->want_split_;
  result.validator_list_hash_short = value->validator_list_hash_short_;
  result.catchain_seqno = value->catchain_seqno_;
  result.min_ref_mc_seqno = value->min_ref_mc_seqno_;
  result.is_key_block = value->is_key_block_;
  result.prev_key_block_seqno = value->prev_key_block_seqno_;
  result.start_lt = value->start_lt_;
  result.end_lt = value->end_lt_;
  result.gen_utime = value->gen_utime_;
  for (const auto& item : value->prev_blocks_) {
    result.prev_blocks.emplace_back(Convert(item));
  }
  return result;
}

inline schemas::v2::OutMsgQueueSize Convert(const tonlib_api::object_ptr<tonlib_api::blocks_outMsgQueueSize>& value) {
  schemas::v2::OutMsgQueueSize result;
  result.id = Convert(value->id_);
  result.size = value->size_;
  return result;
}

inline schemas::v2::OutMsgQueueSizes Convert(const tonlib_api::blocks_getOutMsgQueueSizes::ReturnType& value) {
  schemas::v2::OutMsgQueueSizes result;
  for (const auto& item : value->shards_) {
    result.shards.emplace_back(Convert(item));
  }
  result.ext_msg_queue_size_limit = value->ext_msg_queue_size_limit_;
  return result;
}
}  // namespace ton_http::converters
