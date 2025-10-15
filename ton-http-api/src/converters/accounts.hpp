#pragma once
#include "auto/tl/tonlib_api.h"
#include "common.hpp"
#include "schemas/v2.hpp"
#include "utils/suspended.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::AddressInformation Convert(tonlib_api::raw_getAccountState::ReturnType& value) {
  schemas::v2::AddressInformation result;
  result.balance = types::int256{std::to_string(value->balance_)};
  result.extra_currencies = Convert(value->extra_currencies_);
  result.last_transaction_id = Convert(value->last_transaction_id_);
  result.block_id = Convert(value->block_id_);
  result.code = types::bytes{value->code_};
  result.data = types::bytes{value->data_};
  result.frozen_hash = types::ton_hash{value->frozen_hash_};
  result.sync_utime = value->sync_utime_;

  if (value->code_.empty()) {
    if (value->frozen_hash_.empty()) {
      result.state = schemas::v2::AccountStateEnum::kUninitialized;
    } else {
      result.state = schemas::v2::AccountStateEnum::kFrozen;
    }
  } else {
    result.state = schemas::v2::AccountStateEnum::kActive;
  }
  return result;
}

inline schemas::v2::ExtendedAddressInformation Convert(tonlib_api::getAccountState::ReturnType& value) {
  schemas::v2::ExtendedAddressInformation result;
  result.address = Convert(value->address_);
  result.balance = types::int256{std::to_string(value->balance_)};
  result.extra_currencies = Convert(value->extra_currencies_);
  result.last_transaction_id = Convert(value->last_transaction_id_);
  result.block_id = Convert(value->block_id_);
  result.sync_utime = value->sync_utime_;
  result.account_state = Convert(value->account_state_);
  result.revision = value->revision_;
  return result;
}

}
