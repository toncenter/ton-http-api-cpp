#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"
#include "common.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::MasterchainInfo Convert(tonlib_api::blocks_getMasterchainInfo::ReturnType& value) {
  schemas::v2::MasterchainInfo result;
  result.init = Convert(value->init_);
  result.last = Convert(value->last_);
  result.state_root_hash = types::ton_hash{value->state_root_hash_};
  return result;
}

}

