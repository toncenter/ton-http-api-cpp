#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::TonBlockIdExt Convert(tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& value) {
  schemas::v2::TonBlockIdExt result;
  result.workchain = value->workchain_;
  result.shard = value->shard_;
  result.seqno = value->seqno_;
  result.root_hash = types::ton_hash{value->root_hash_};
  result.file_hash = types::ton_hash{value->file_hash_};
  return result;
}

inline schemas::v2::MasterchainInfo Convert(tonlib_api::blocks_getMasterchainInfo::ReturnType& value) {
  schemas::v2::MasterchainInfo result;
  result.init = Convert(value->init_);
  result.last = Convert(value->last_);
  result.state_root_hash = types::ton_hash{value->state_root_hash_};
  return result;
}

inline schemas::v2::DetectAddress Convert(core::DetectAddressResult& value) {
  schemas::v2::DetectAddress result;
  result.raw_form = value.to_raw_form(true);

  block::StdAddress b_addr(value.address);
  b_addr.bounceable = false;
  result.bounceable =  schemas::v2::DetectAddressBase64Variant{b_addr.rserialize(false), b_addr.rserialize(true)};

  b_addr.bounceable = true;
  result.non_bounceable = schemas::v2::DetectAddressBase64Variant{b_addr.rserialize(false), b_addr.rserialize(true)};
  if (value.given_type == "raw_form") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kRawForm;
  } else if (value.given_type == "friendly_bounceable") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kFriendlyBounceable;
  } else if (value.given_type == "friendly_non_bounceable") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kFriendlyNonBounceable;
  } else {
    throw std::runtime_error("Unknown given type, this should not happen");
  }
  result.test_only = value.address.testnet;
  return result;
}

}

