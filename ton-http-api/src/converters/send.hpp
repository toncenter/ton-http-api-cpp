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

inline schemas::v2::Fees Convert(const tonlib_api::object_ptr<tonlib_api::fees>& value) {
  schemas::v2::Fees result;
  result.in_fwd_fee = value->in_fwd_fee_;
  result.storage_fee = value->storage_fee_;
  result.gas_fee = value->gas_fee_;
  result.fwd_fee = value->fwd_fee_;
  return result;
}

inline schemas::v2::QueryFees Convert(const tonlib_api::object_ptr<tonlib_api::query_fees>& value) {
  schemas::v2::QueryFees result;
  result.source_fees = Convert(value->source_fees_);
  for (const auto& item : value->destination_fees_) {
    result.destination_fees.emplace_back(Convert(item));
  }
  return result;
}
}
