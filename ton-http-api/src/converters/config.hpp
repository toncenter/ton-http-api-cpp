#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"
#include "common.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::ConfigInfo Convert(const tonlib_api::object_ptr<tonlib_api::configInfo>& value) {
  schemas::v2::ConfigInfo result;
  result.config = Convert(value->config_);
  return result;
}

inline schemas::v2::LibraryEntry Convert(const tonlib_api::object_ptr<tonlib_api::smc_libraryEntry>& value) {
  schemas::v2::LibraryEntry result;
  result.hash = types::ton_hash{value->hash_.as_slice().str()};
  result.data = types::bytes{value->data_};
  return result;
}

inline schemas::v2::LibraryResult Convert(const tonlib_api::object_ptr<tonlib_api::smc_libraryResult>& value) {
  schemas::v2::LibraryResult result;
  for (const auto& item : value->result_) {
    result.result.emplace_back(Convert(item));
  }
  return result;
}

}
