#pragma once
#include "auto/tl/tonlib_api.h"
#include "auto/tl/tonlib_api.hpp"
#include "core/types.hpp"
#include "schemas/v2.hpp"
#include "td/utils/overloaded.h"


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

inline schemas::v2::ExtraCurrencyBalance Convert(const tonlib_api::object_ptr<tonlib_api::extraCurrency>& item) {
  schemas::v2::ExtraCurrencyBalance result;
  result.id = item->id_;
  result.amount = types::int256{std::to_string(item->amount_)};
  return result;
}

inline std::vector<schemas::v2::ExtraCurrencyBalance> Convert(const std::vector<tonlib_api::object_ptr<tonlib_api::extraCurrency>>& value) {
  std::vector<schemas::v2::ExtraCurrencyBalance> result;
  for (auto &item : value) {
    result.emplace_back(Convert(item));
  }
  return result;
}

inline schemas::v2::InternalTransactionId Convert(const tonlib_api::object_ptr<tonlib_api::internal_transactionId>& value) {
  schemas::v2::InternalTransactionId result;
  result.hash = types::ton_hash{value->hash_};
  result.lt = value->lt_;
  return result;
}

inline schemas::v2::AccountAddress Convert(const tonlib_api::object_ptr<tonlib_api::accountAddress>& value) {
  schemas::v2::AccountAddress result;
  result.account_address = types::ton_addr{value->account_address_};
  return result;
}

inline schemas::v2::RWalletLimit Convert(const tonlib_api::object_ptr<tonlib_api::rwallet_limit>& value) {
  schemas::v2::RWalletLimit result;
  result.seconds = value->seconds_;
  result.value = value->value_;
  return result;
}

inline std::vector<schemas::v2::RWalletLimit> Convert(const std::vector<tonlib_api::object_ptr<tonlib_api::rwallet_limit>>& value) {
  std::vector<schemas::v2::RWalletLimit> result;
  for (auto& item : value) {
    result.emplace_back(Convert(item));
  }
  return result;
}

inline schemas::v2::RWalletConfig Convert(const tonlib_api::object_ptr<tonlib_api::rwallet_config>& value) {
  schemas::v2::RWalletConfig result;
  result.start_at = value->start_at_;
  result.limits = Convert(value->limits_);
  return result;
}

inline schemas::v2::PChanConfig Convert(const tonlib_api::object_ptr<tonlib_api::pchan_config>& value) {
  schemas::v2::PChanConfig result;
  result.alice_public_key = value->alice_public_key_;
  result.alice_address = Convert(value->alice_address_);
  result.bob_public_key = value->bob_public_key_;
  result.bob_address = Convert(value->bob_address_);
  result.init_timeout = value->init_timeout_;
  result.close_timeout = value->close_timeout_;
  result.channel_id = value-> channel_id_;
  return result;
}

inline schemas::v2::PChanState Convert(const tonlib_api::object_ptr<tonlib_api::pchan_State>& value) {
  schemas::v2::PChanState result;
  ton::tonlib_api::downcast_call(*value.get(),
    td::overloaded(
    [&](tonlib_api::pchan_stateInit& val) {
      schemas::v2::PChanStateInit res;
      res.signed_A = val.signed_A_;
      res.signed_B = val.signed_B_;
      res.min_A = val.min_A_;
      res.min_B = val.min_B_;
      res.expire_at = val.expire_at_;
      res.A = val.A_;
      res.B = val.B_;
      result = res;
    },
    [&](tonlib_api::pchan_stateClose& val) {
      schemas::v2::PChanStateClose res;
      res.signed_A = val.signed_A_;
      res.signed_B = val.signed_B_;
      res.min_A = val.min_A_;
      res.min_B = val.min_B_;
      res.expire_at = val.expire_at_;
      res.A = val.A_;
      res.B = val.B_;
      result = res;
    },
    [&](tonlib_api::pchan_statePayout& val) {
      schemas::v2::PChanStatePayout res;
      res.A = val.A_;
      res.B = val.B_;
      result = res;
    },
    [&](auto&) {
      LOG_ERROR() << "Unsupported pchan state type: " << value->get_id();
    }
  ));
  return result;
}

inline schemas::v2::AccountState Convert(const tonlib_api::object_ptr<tonlib_api::AccountState>& value) {
  schemas::v2::AccountState result;
  ton::tonlib_api::downcast_call(*value.get(),
    td::overloaded(
      [&](tonlib_api::raw_accountState& val) {
        schemas::v2::AccountStateRaw res;
        res.code = types::bytes{val.code_};
        res.data = types::bytes{val.data_};
        res.frozen_hash = types::ton_hash{val.frozen_hash_};
        result.emplace<schemas::v2::AccountStateRaw>(res);
      },
      [&](tonlib_api::wallet_v3_accountState& val) {
        schemas::v2::AccountStateWalletV3 res;
        res.wallet_id = val.wallet_id_;
        res.seqno = val.seqno_;
        result.emplace<schemas::v2::AccountStateWalletV3>(res);
      },
      [&](tonlib_api::wallet_v4_accountState& val) {
        schemas::v2::AccountStateWalletV4 res;
        res.wallet_id = val.wallet_id_;
        res.seqno = val.seqno_;
        result.emplace<schemas::v2::AccountStateWalletV4>(res);
      },
      [&](tonlib_api::wallet_highload_v1_accountState& val) {
        schemas::v2::AccountStateWalletHighloadV1 res;
        res.wallet_id = val.wallet_id_;
        res.seqno = val.seqno_;
        result.emplace<schemas::v2::AccountStateWalletHighloadV1>(res);
      },
      [&](tonlib_api::wallet_highload_v2_accountState& val) {
        schemas::v2::AccountStateWalletHighloadV2 res;
        res.wallet_id = val.wallet_id_;
        result.emplace<schemas::v2::AccountStateWalletHighloadV2>(res);
      },
      [&](tonlib_api::dns_accountState& val) {
        schemas::v2::AccountStateDns res;
        res.wallet_id = val.wallet_id_;
        result.emplace<schemas::v2::AccountStateDns>(res);
      },
      [&](tonlib_api::rwallet_accountState& val) {
        schemas::v2::AccountStateRWallet res;
        res.wallet_id = val.wallet_id_;
        res.seqno = val.seqno_;
        res.unlocked_balance = val.unlocked_balance_;
        res.config = Convert(val.config_);
        result.emplace<schemas::v2::AccountStateRWallet>(res);
      },
      [&](tonlib_api::pchan_accountState& val) {
        schemas::v2::AccountStatePChan res;
        res.config = Convert(val.config_);
        res.state = Convert(val.state_);
        res.description = val.description_;
        result.emplace<schemas::v2::AccountStatePChan>(res);
      },
      [&](auto&) {
        LOG_ERROR() << "Unsupported account state type: " << value->get_id();
      }
  ));
  LOG_ERROR() << "result: " << result.index();
  return result;
}


}
