#pragma once
#include "auto/tl/tonlib_api.h"
#include "common.hpp"
#include "schemas/v2.hpp"
#include "utils/suspended.hpp"


namespace ton_http::converters {

using namespace ton;

template <typename To>
inline To Convert(tonlib_api::raw_getAccountState::ReturnType&) {
  throw std::logic_error("Not implemented");
}

template <>
inline schemas::v2::AddressInformation Convert<schemas::v2::AddressInformation>(tonlib_api::raw_getAccountState::ReturnType& value) {
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

inline void DecodeWalletV1Data(schemas::v2::WalletInformation& value, td::Ref<vm::Cell>& data) {
  auto cs = vm::CellSlice{vm::NoVm{}, data};
  value.seqno = cs.fetch_long(32);
  value.wallet = true;
}

inline void DecodeWalletV3Data(schemas::v2::WalletInformation& value, td::Ref<vm::Cell>& data) {
  auto cs = vm::CellSlice{vm::NoVm{}, data};
  value.seqno = cs.fetch_long(32);
  value.wallet_id = cs.fetch_long(32);
  value.wallet = true;
}

inline void DecodeWalletV5Data(schemas::v2::WalletInformation& value, td::Ref<vm::Cell>& data) {
  auto cs = vm::CellSlice{vm::NoVm{}, data};
  value.is_signature_allowed = cs.fetch_long(1);
  value.seqno = cs.fetch_long(32);
  value.wallet_id = cs.fetch_long(32);
  value.wallet = true;
}

template <>
inline schemas::v2::WalletInformation Convert<schemas::v2::WalletInformation>(tonlib_api::raw_getAccountState::ReturnType& value) {
  schemas::v2::WalletInformation result;

  // auto r_code_hash =
  result.balance = types::int256{std::to_string(value->balance_ < 0 ? 0 : value->balance_)};
  if (value->code_.empty()) {
    if (value->frozen_hash_.empty()) {
      result.account_state = schemas::v2::AccountStateEnum::kUninitialized;
    } else {
      result.account_state = schemas::v2::AccountStateEnum::kFrozen;
    }
  } else {
    result.account_state = schemas::v2::AccountStateEnum::kActive;
  }
  result.last_transaction_id = Convert(value->last_transaction_id_);

  if (!value->code_.empty()) {
    if (auto r_cell = vm::std_boc_deserialize(value->code_); r_cell.is_ok()) {
      auto code_hash = r_cell.move_as_ok()->get_hash().as_slice();
      auto code_hash_b64 = td::base64_encode(code_hash);
      if (auto r_data = vm::std_boc_deserialize(value->data_); r_data.is_ok()) {
        auto data = r_data.move_as_ok();
        LOG_ERROR() << "code_hash: " << code_hash_b64;
        if (code_hash_b64 == "oM/CxIruFqJx8s/AtzgtgXVs7LEBfQd/qqs7tgL2how=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV1R1;
          DecodeWalletV1Data(result, data);
        } else if (code_hash_b64 == "1JAvzJ+tdGmPqONTIgpo2g3PcuMryy657gQhfBfTBiw=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV1R2;
          DecodeWalletV1Data(result, data);
        } else if (code_hash_b64 == "WHzHie/xyE9G7DeX5F/ICaFP9a4k8eDHpqmcydyQYf8=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV1R3;
          DecodeWalletV1Data(result, data);
        } else if (code_hash_b64 == "XJpeaMEI4YchoHxC+ZVr+zmtd+xtYktgxXbsiO7mUyk=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV2R1;
          DecodeWalletV1Data(result, data);
        } else if (code_hash_b64 == "/pUw0yQ4Uwg+8u8LTCkIwKv2+hwx6iQ6rKpb+MfXU/E=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV2R2;
          DecodeWalletV1Data(result, data);
        } else if (code_hash_b64 == "thBBpYp5gLlG6PueGY48kE0keZ/6NldOpCUcQaVm9YE=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV3R1;
          DecodeWalletV3Data(result, data);
        } else if (code_hash_b64 == "hNr6RJ+Ypph3ibojI1gHK8D3bcRSQAKl0JGLmnXS1Zk=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV3R2;
          DecodeWalletV3Data(result, data);
        } else if (code_hash_b64 == "ZN1UgFUixb6KnbWc6gEFzPDQh4bKeb64y3nogKjXMi0=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV4R1;
          DecodeWalletV3Data(result, data);
        } else if (code_hash_b64 == "/rX/aCDi/w2Ug+fg1iyBfYRniftK5YDIeIZtlZ2r1cA=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV4R2;
          DecodeWalletV3Data(result, data);
        } else if (code_hash_b64 == "89fKU0k97trCizgZhqhJQDy6w9LFhHea8IEGWvCsS5M=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV5Beta;
          DecodeWalletV5Data(result, data);
        } else if (code_hash_b64 == "IINLe3KxEhR+Gy+0V7hOdNGjDwT3N9T2KmaOlVLSty8=") {
          result.wallet_type = schemas::v2::WalletInformation::Wallet_Type::kWalletV5R1;
          DecodeWalletV5Data(result, data);
        }
      }
    }
  }
  return result;
}


}
