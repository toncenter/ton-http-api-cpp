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
}  // namespace ton_http::converters
