#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"


namespace ton_http::converters {

using namespace ton;

inline schemas::v2::ShortTxId Convert(
  const tonlib_api::object_ptr<tonlib_api::blocks_shortTxId>& value, std::int32_t workchain
) {
  schemas::v2::ShortTxId result;
  result.mode = value->mode_;
  result.account = types::ton_addr{std::to_string(workchain) + ":" + td::hex_encode(value->account_)};
  result.lt = value->lt_;
  result.hash = types::ton_hash{value->hash_};
  return result;
}

inline schemas::v2::BlockTransactions Convert(const tonlib_api::blocks_getTransactions::ReturnType& value) {
  schemas::v2::BlockTransactions result;
  result.id = Convert(value->id_);
  result.req_count = value->req_count_;
  result.incomplete = value->incomplete_;
  for (const auto& item : value->transactions_) {
    result.transactions.emplace_back(Convert(item, result.id.workchain));
  }
  return result;
}

template <typename To>
To Convert(const tonlib_api::object_ptr<tonlib_api::raw_message>&) {
  throw std::logic_error("Not implemented");
}

inline schemas::v2::MsgData Convert(const tonlib_api::object_ptr<tonlib_api::msg_Data>& value) {
  schemas::v2::MsgData result;
  ton::tonlib_api::downcast_call(
    *value.get(),
    td::overloaded(
      [&](const tonlib_api::msg_dataRaw& val) {
        schemas::v2::MsgDataRaw res;
        res.body = types::bytes{val.body_};
        res.init_state = types::bytes{val.init_state_};
        result = res;
      },
      [&](const tonlib_api::msg_dataText& val) {
        schemas::v2::MsgDataText res;
        res.text = types::bytes{val.text_};
        result = res;
      },
      [&](const tonlib_api::msg_dataDecryptedText& val) {
        schemas::v2::MsgDataDecryptedText res;
        res.text = types::bytes{val.text_};
        result = res;
      },
      [&](const tonlib_api::msg_dataEncryptedText& val) {
        schemas::v2::MsgDataEncryptedText res;
        res.text = types::bytes{val.text_};
        result = res;
      },
      [&](const auto&) { LOG_ERROR() << "Unsupported msg data type: " << value->get_id(); }
    )
  );
  return result;
}


template <>
inline schemas::v2::MessageStd Convert<schemas::v2::MessageStd>(
  const tonlib_api::object_ptr<tonlib_api::raw_message>& value
) {
  schemas::v2::MessageStd result;
  result.hash = types::ton_hash{value->hash_};
  result.source = Convert(value->source_);
  result.destination = Convert(value->destination_);
  result.value = types::int256{std::to_string(value->value_)};
  result.extra_currencies = Convert(value->extra_currencies_);
  result.fwd_fee = types::int256{std::to_string(value->fwd_fee_)};
  result.ihr_fee = types::int256{std::to_string(value->ihr_fee_)};
  result.created_lt = value->created_lt_;
  result.body_hash = types::ton_hash{value->body_hash_};
  if (value->msg_data_) {
    result.msg_data = Convert(value->msg_data_);
  }
  return result;
}

template <>
inline schemas::v2::Message Convert<schemas::v2::Message>(
  const tonlib_api::object_ptr<tonlib_api::raw_message>& value
) {
  schemas::v2::Message result;
  result.hash = types::ton_hash{value->hash_};
  result.source = types::ton_addr{value->source_->account_address_};
  result.destination = types::ton_addr{value->destination_->account_address_};
  result.value = types::int256{std::to_string(value->value_)};
  result.extra_currencies = Convert(value->extra_currencies_);
  result.fwd_fee = types::int256{std::to_string(value->fwd_fee_)};
  result.ihr_fee = types::int256{std::to_string(value->ihr_fee_)};
  result.created_lt = value->created_lt_;
  result.body_hash = types::ton_hash{value->body_hash_};
  if (value->msg_data_) {
    result.msg_data = Convert(value->msg_data_);
  }
  tonlib_api::downcast_call(
    *value->msg_data_,
    td::overloaded(
      [&](const tonlib_api::msg_dataRaw& data) {
        auto r_body_cell = vm::std_boc_deserialize(data.body_);
        if (r_body_cell.is_ok()) {
          auto body_cell = r_body_cell.move_as_ok();
          auto r_loaded_cell = body_cell->load_cell();
          if (r_loaded_cell.is_ok()) {
            auto loaded_cell = r_loaded_cell.move_as_ok();
            const size_t n_bytes = (loaded_cell.data_cell->get_bits() + 7) / 8;
            const size_t n_trailing_bits = 8 - loaded_cell.data_cell->get_bits() % 8;
            std::string buffer(n_bytes, 0);
            std::memcpy(buffer.data(), loaded_cell.data_cell->get_data(), n_bytes);
            // this zeroes last 1 bit which is 1 in C++ and 0 in python implementation
            buffer[buffer.length() - 1] = static_cast<char>(buffer.back() & ~static_cast<char>((1 << n_trailing_bits) - 1));
            result.message = td::base64_encode(buffer) + "\n"; // this is back compatibility
          }
        } else {
          result.message_decode_error = "Failed to load cell or get body slice. But why?";
          LOG_ERROR() << "Failed to load cell or get body slice. But why? msg_hash: " << value->hash_;
        }
      },
      [&](const tonlib_api::msg_dataText& data) { result.message = data.text_; },
      [&](const tonlib_api::msg_dataDecryptedText& data) { result.message = data.text_; },
      [&](const tonlib_api::msg_dataEncryptedText& data) { result.message = data.text_; },
      [&](const auto& x) { LOG_DEBUG() << "failed to decode type " << x.get_id(); }
    )
  );
  return result;
}

template <typename To>
To Convert(const tonlib_api::object_ptr<tonlib_api::raw_transaction>&) {
  throw std::logic_error("Not implemented");
}

template <>
inline schemas::v2::TransactionStd Convert<schemas::v2::TransactionStd>(
  const tonlib_api::object_ptr<tonlib_api::raw_transaction>& value
) {
  schemas::v2::TransactionStd result;
  result.address = Convert(value->address_);
  result.utime = value->utime_;
  result.data = types::bytes{value->data_};
  result.transaction_id = Convert(value->transaction_id_);
  result.fee = types::int256{std::to_string(value->fee_)};
  result.storage_fee = types::int256{std::to_string(value->storage_fee_)};
  result.other_fee = types::int256{std::to_string(value->other_fee_)};
  if (value->in_msg_) {
    result.in_msg = Convert<schemas::v2::MessageStd>(value->in_msg_);
  }
  for (const auto& msg : value->out_msgs_) {
    result.out_msgs.emplace_back(Convert<schemas::v2::MessageStd>(msg));
  }
  return result;
}


template <>
inline schemas::v2::TransactionExt Convert<schemas::v2::TransactionExt>(
  const tonlib_api::object_ptr<tonlib_api::raw_transaction>& value
) {
  schemas::v2::TransactionExt result;
  result.address = Convert(value->address_);
  auto account = block::StdAddress::parse(value->address_->account_address_).move_as_ok();
  result.account = types::ton_addr{std::to_string(account.workchain) + ":" + account.addr.to_hex()};
  result.utime = value->utime_;
  result.data = types::bytes{value->data_};
  result.transaction_id = Convert(value->transaction_id_);
  result.fee = types::int256{std::to_string(value->fee_)};
  result.storage_fee = types::int256{std::to_string(value->storage_fee_)};
  result.other_fee = types::int256{std::to_string(value->other_fee_)};
  if (value->in_msg_) {
    result.in_msg = Convert<schemas::v2::MessageStd>(value->in_msg_);
  }
  for (const auto& msg : value->out_msgs_) {
    result.out_msgs.emplace_back(Convert<schemas::v2::MessageStd>(msg));
  }
  return result;
}

template <>
inline schemas::v2::Transaction Convert<schemas::v2::Transaction>(
  const tonlib_api::object_ptr<tonlib_api::raw_transaction>& value
) {
  schemas::v2::Transaction result;
  result.address = Convert(value->address_);
  const auto account = block::StdAddress::parse(value->address_->account_address_).move_as_ok();
  result.account = types::ton_addr{std::to_string(account.workchain) + ":" + account.addr.to_hex()};
  result.utime = value->utime_;
  result.data = types::bytes{value->data_};
  result.transaction_id = Convert(value->transaction_id_);
  result.fee = types::int256{std::to_string(value->fee_)};
  result.storage_fee = types::int256{std::to_string(value->storage_fee_)};
  result.other_fee = types::int256{std::to_string(value->other_fee_)};
  if (value->in_msg_) {
    result.in_msg = Convert<schemas::v2::Message>(value->in_msg_);
  }
  for (const auto& msg : value->out_msgs_) {
    result.out_msgs.emplace_back(Convert<schemas::v2::Message>(msg));
  }
  return result;
}

inline schemas::v2::BlockTransactionsExt Convert(const tonlib_api::blocks_getTransactionsExt::ReturnType& value) {
  schemas::v2::BlockTransactionsExt result;
  result.id = Convert(value->id_);
  result.req_count = value->req_count_;
  result.incomplete = value->incomplete_;
  for (const auto& item : value->transactions_) {
    result.transactions.emplace_back(Convert<schemas::v2::TransactionExt>(item));
  }
  return result;
}

template <typename To>
To Convert(const tonlib_api::object_ptr<tonlib_api::raw_transactions>&) {
  throw std::logic_error("Not implemented");
}

template <>
inline schemas::v2::TransactionsStd Convert<schemas::v2::TransactionsStd>(
  const tonlib_api::object_ptr<tonlib_api::raw_transactions>& value
) {
  schemas::v2::TransactionsStd result;
  for (const auto& tx : value->transactions_) {
    result.transactions.emplace_back(Convert<schemas::v2::TransactionStd>(tx));
  }
  result.previous_transaction_id = Convert(value->previous_transaction_id_);
  return result;
}

template <>
inline schemas::v2::Transactions Convert<schemas::v2::Transactions>(
  const tonlib_api::object_ptr<tonlib_api::raw_transactions>& value
) {
  schemas::v2::Transactions result;
  for (const auto& tx : value->transactions_) {
    result.emplace_back(Convert<schemas::v2::Transaction>(tx));
  }
  return result;
}
}  // namespace ton_http::converters
