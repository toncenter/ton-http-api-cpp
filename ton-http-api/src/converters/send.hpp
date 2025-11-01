#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::ExtMessageInfo Convert(const tonlib_api::object_ptr<tonlib_api::raw_extMessageInfo>& value) {
  schemas::v2::ExtMessageInfo result;
  result.hash = types::ton_hash{value->hash_};
  result.hash_norm = types::ton_hash{value->hash_norm_};
  return result;
}
}
