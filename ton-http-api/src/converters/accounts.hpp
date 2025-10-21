#pragma once
#include <ranges>


#include "auto/tl/tonlib_api.h"
#include "common.hpp"
#include "schemas/v2.hpp"
#include "userver/formats/serialize/common_containers.hpp"


namespace ton_http::converters {

using namespace ton;

template <typename To>
inline To Convert(tonlib_api::raw_getAccountState::ReturnType&) {
  throw std::logic_error("Not implemented");
}

template <>
inline schemas::v2::AddressInformation Convert<schemas::v2::AddressInformation>(
    tonlib_api::raw_getAccountState::ReturnType& value
) {
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
inline schemas::v2::WalletInformation Convert<schemas::v2::WalletInformation>(
    tonlib_api::raw_getAccountState::ReturnType& value
) {
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
      auto code_cell = r_cell.move_as_ok();
      auto code_hash_b64 = td::base64_encode(code_cell->get_hash().as_slice());
      if (auto r_data = vm::std_boc_deserialize(value->data_); r_data.is_ok()) {
        auto data = r_data.move_as_ok();
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

inline schemas::v2::DnsRecord Convert(const core::DnsRecord& value) {
  if (std::holds_alternative<core::DnsRecordNextResolver>(value)) {
    auto v = std::get<core::DnsRecordNextResolver>(value);
    schemas::v2::DnsRecordNextResolver rec;
    rec.resolver.workchain_id = v.resolver.workchain;
    rec.resolver.address = types::ton_hash_hex{v.resolver.addr.as_slice().str()};
    return rec;
  }
  if (std::holds_alternative<core::DnsRecordAdnlAddress>(value)) {
    auto v = std::get<core::DnsRecordAdnlAddress>(value);
    schemas::v2::DnsRecordAdnlAddress rec;
    rec.adnl_addr = types::ton_hash_hex{v.adnl_addr};
    return rec;
  }
  if (std::holds_alternative<core::DnsRecordSmcAddress>(value)) {
    auto v = std::get<core::DnsRecordSmcAddress>(value);
    schemas::v2::DnsRecordSmcAddress rec;
    rec.smc_addr.workchain_id = v.smc_addr.workchain;
    rec.smc_addr.address = types::ton_hash_hex{v.smc_addr.addr.as_slice().str()};
    return rec;
  }
  if (std::holds_alternative<core::DnsRecordStorageAddress>(value)) {
    auto v = std::get<core::DnsRecordStorageAddress>(value);
    schemas::v2::DnsRecordStorageAddress rec;
    rec.bag_id = types::ton_hash_hex{v.bag_id};
    return rec;
  }
  UNREACHABLE();
}


inline schemas::v2::TokenData Convert(core::TokenDataResultPtr& value) {
  if (auto* val = dynamic_cast<core::JettonMasterDataResult*>(value.get())) {
    schemas::v2::JettonMasterData result;
    result.address = types::ton_addr{val->address_};
    result.total_supply = types::int256{val->total_supply_};
    result.mintable = val->mintable_;
    result.admin_address = types::ton_addr{val->admin_address_};
    result.jetton_wallet_code = types::bytes{val->jetton_wallet_code_};
    if (val->jetton_content_onchain_) {
      result.jetton_content.type = schemas::v2::TokenContent::Type::kOnchain;
      schemas::v2::TokenContentDict onchain_content{};
      onchain_content.extra = userver::formats::json::ValueBuilder{val->jetton_content_}.ExtractValue();
      result.jetton_content.data = onchain_content;
    } else {
      result.jetton_content.type = schemas::v2::TokenContent::Type::kOffchain;
      if (!val->jetton_content_.contains("uri")) {
        throw utils::TonlibException{"missing uri field in offchain data", 500};
      }
      result.jetton_content.data = val->jetton_content_.at("uri");
    }
    return result;
  }
  if (auto* val = dynamic_cast<core::JettonWalletDataResult*>(value.get())) {
    schemas::v2::JettonWalletData result;
    result.address = types::ton_addr{val->address_};
    result.balance = types::int256{val->balance_};
    result.owner_address = types::ton_addr{val->owner_address_};
    result.jetton_master_address = types::ton_addr{val->jetton_master_address_};
    result.jetton_wallet_code = types::bytes{val->jetton_wallet_code_};
    result.mintless_is_claimed = val->mintless_is_claimed_;
    return result;
  }
  if (auto* val = dynamic_cast<core::NFTCollectionDataResult*>(value.get())) {
    schemas::v2::NftCollectionData result;
    result.address = types::ton_addr{val->address_};
    result.next_item_index = types::int256{val->next_item_index_};
    if (!val->owner_address_.empty()) {
      result.owner_address = types::ton_addr{val->owner_address_};
    }
    if (val->collection_content_onchain_) {
      result.collection_content.type = schemas::v2::TokenContent::Type::kOnchain;
      schemas::v2::TokenContentDict onchain_content{};
      onchain_content.extra = userver::formats::json::ValueBuilder{val->collection_content_}.ExtractValue();
      result.collection_content.data = onchain_content;
    } else {
      result.collection_content.type = schemas::v2::TokenContent::Type::kOffchain;
      if (!val->collection_content_.contains("uri")) {
        throw utils::TonlibException{"missing uri field in offchain data", 500};
      }
      result.collection_content.data = val->collection_content_.at("uri");
    }
    return result;
  }
  if (auto* val = dynamic_cast<core::NFTItemDataResult*>(value.get())) {
    schemas::v2::NftItemData result;
    result.address = types::ton_addr{val->address_};
    result.init = val->init_;
    result.index = types::int256{val->index_};
    result.collection_address = types::ton_addr{val->collection_address_};
    result.owner_address = types::ton_addr{val->owner_address_};
    if (val->is_dns_) {
      LOG_ERROR() << "It's DNS!";
      schemas::v2::DnsRecordSet record_set;
      if (val->dns_content_.contains("dns_resolver_next")) {
        record_set.dns_next_resolver = Convert(val->dns_content_["dns_resolver_next"]);
      }
      if (val->dns_content_.contains("wallet")) {
        record_set.wallet = Convert(val->dns_content_["wallet"]);
      }
      if (val->dns_content_.contains("site")) {
        record_set.site = Convert(val->dns_content_["site"]);
      }
      if (val->dns_content_.contains("storage")) {
        record_set.storage = Convert(val->dns_content_["storage"]);
      }
      userver::formats::json::ValueBuilder builder;
      for (auto& [k, v] : val->dns_content_)
        if (!(k == "dns_resolver_next" || k == "wallet" ||
          k == "site" || k == "storage")) {
        auto dns_record = Convert(v);
        std::visit([&](auto& item) { builder[k] = item; }, dns_record);
      }
      record_set.extra = builder.ExtractValue();

      schemas::v2::DnsContent content;
      content.domain = val->domain_;
      content.data = record_set;
      result.content = content;
    } else {
      LOG_ERROR() << "It's not a DNS!";
      schemas::v2::TokenContent content;
      if (val->content_onchain_) {
        content.type = schemas::v2::TokenContent::Type::kOnchain;
        schemas::v2::TokenContentDict onchain_content{};
        onchain_content.extra = userver::formats::json::ValueBuilder{val->content_}.ExtractValue();
        content.data = onchain_content;
      } else {
        content.type = schemas::v2::TokenContent::Type::kOffchain;
        if (!val->content_.contains("uri")) {
          throw utils::TonlibException{"missing uri field in offchain data", 500};
        }
        content.data = val->content_.at("uri");
      }
      result.content = content;
    }
    return result;
  }
  throw utils::TonlibException{"failed to serialize TokenData", 500};
}
}  // namespace ton_http::converters
