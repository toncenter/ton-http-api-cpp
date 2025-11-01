#include "tonlib_worker.h"
#include "utils/common.hpp"

namespace ton_http::core {
td::Result<tonlib_api::blocks_getTransactions::ReturnType> TonlibWorker::raw_getBlockTransactions(
  const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
  size_t count,
  tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getTransactions>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [w = blk_id->workchain_,
       sh = blk_id->shard_,
       s = blk_id->seqno_,
       r = blk_id->root_hash_,
       f = blk_id->file_hash_,
       c = count] {
        std::int32_t mode = 7;
        return tonlib_api::make_object<tonlib_api::blocks_getTransactions>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, sh, s, r, f), mode, c, nullptr
        );
      },
    .session = session
  };
  if (after) {
    request.request_creator = [w = blk_id->workchain_,
                               sh = blk_id->shard_,
                               s = blk_id->seqno_,
                               r = blk_id->root_hash_,
                               f = blk_id->file_hash_,
                               a = after->account_,
                               l = after->lt_,
                               c = count] {
      std::int32_t mode = 7 + 128;
      return tonlib_api::make_object<tonlib_api::blocks_getTransactions>(
        tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, sh, s, r, f),
        mode,
        c,
        tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(a, l)
      );
    };
  }
  return send_request_function(std::move(request), !archival.has_value());
}
td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> TonlibWorker::raw_getBlockTransactionsExt(
  const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
  size_t count,
  tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::blocks_getTransactionsExt>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [w = blk_id->workchain_,
       sh = blk_id->shard_,
       s = blk_id->seqno_,
       r = blk_id->root_hash_,
       f = blk_id->file_hash_,
       c = count] {
        std::int32_t mode = 7;
        return tonlib_api::make_object<tonlib_api::blocks_getTransactionsExt>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, sh, s, r, f), mode, c, nullptr
        );
      },
    .session = session
  };
  if (after) {
    request.request_creator = [w = blk_id->workchain_,
                               sh = blk_id->shard_,
                               s = blk_id->seqno_,
                               r = blk_id->root_hash_,
                               f = blk_id->file_hash_,
                               a = after->account_,
                               l = after->lt_,
                               c = count] {
      std::int32_t mode = 7 + 128;
      return tonlib_api::make_object<tonlib_api::blocks_getTransactionsExt>(
        tonlib_api::make_object<tonlib_api::ton_blockIdExt>(w, sh, s, r, f),
        mode,
        c,
        tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(a, l)
      );
    };
  }
  return send_request_function(std::move(request), !archival.has_value());
}
td::Result<tonlib_api::raw_getTransactions::ReturnType> TonlibWorker::raw_getTransactions(
  const std::string& account_address,
  const std::int64_t& from_transaction_lt,
  const std::string& from_transaction_hash,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::raw_getTransactions>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [a = account_address, fl = from_transaction_lt, fh = from_transaction_hash] {
        return tonlib_api::make_object<tonlib_api::raw_getTransactions>(
          nullptr,
          tonlib_api::make_object<tonlib_api::accountAddress>(a),
          tonlib_api::make_object<tonlib_api::internal_transactionId>(fl, fh)
        );
      },
    .session = session
  };
  return send_request_function(std::move(request), !archival.has_value());
}
td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> TonlibWorker::raw_getTransactionsV2(
  const std::string& account_address,
  const std::int64_t& from_transaction_lt,
  const std::string& from_transaction_hash,
  size_t count,
  bool try_decode_messages,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::raw_getTransactionsV2>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator =
      [a = account_address, fl = from_transaction_lt, fh = from_transaction_hash, c = count, dm = try_decode_messages] {
        return tonlib_api::make_object<tonlib_api::raw_getTransactionsV2>(
          nullptr,
          tonlib_api::make_object<tonlib_api::accountAddress>(a),
          tonlib_api::make_object<tonlib_api::internal_transactionId>(fl, fh),
          c,
          dm
        );
      },
    .session = session
  };
  return send_request_function(std::move(request), !archival.has_value());
}
td::Result<tonlib_api::blocks_getTransactions::ReturnType> TonlibWorker::getBlockTransactions(
  const std::int32_t& workchain,
  const std::int64_t& shard,
  const std::int32_t& seqno,
  size_t count,
  const std::string& root_hash,
  const std::string& file_hash,
  const std::optional<std::int64_t>& after_lt,
  const std::string& after_hash,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }

  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> blk_id = nullptr;
  if (!root_hash.empty() && !file_hash.empty()) {
    blk_id = tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain, shard, seqno, root_hash, file_hash);
  } else {
    TRY_RESULT_ASSIGN(blk_id, lookupBlock(workchain, shard, seqno, std::nullopt, std::nullopt, session));
  }

  tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId> after;
  if (after_lt.has_value()) {
    after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(after_hash, after_lt.value());
  } else {
    const std::string zero_hash = td::Bits256::zero().as_slice().str();
    after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(zero_hash, 0);
  }

  size_t left_count = count;
  bool is_finished = false;

  tonlib_api::object_ptr<tonlib_api::blocks_transactions> txs =
    tonlib_api::make_object<tonlib_api::blocks_transactions>(
      nullptr, 0, true, std::vector<tonlib_api::object_ptr<tonlib_api::blocks_shortTxId>>{}
    );
  txs->transactions_.reserve(count);
  while (!is_finished) {
    constexpr size_t CHUNK_SIZE = 256;
    size_t chunk_size = (left_count > CHUNK_SIZE ? CHUNK_SIZE : left_count);
    TRY_RESULT(local, raw_getBlockTransactions(blk_id, chunk_size, std::move(after), archival, session));

    txs->id_ = std::move(local->id_);
    txs->incomplete_ = local->incomplete_;
    left_count -= local->transactions_.size();
    if (!local->transactions_.empty()) {
      auto last_idx = local->transactions_.size() - 1;
      after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(
        local->transactions_[last_idx]->account_, local->transactions_[last_idx]->lt_
      );
    }

    std::ranges::copy(
      std::make_move_iterator(local->transactions_.begin()),
      std::make_move_iterator(local->transactions_.end()),
      std::back_inserter(txs->transactions_)
    );
    is_finished = left_count <= 0 || !local->incomplete_;
  }
  txs->req_count_ = static_cast<std::int32_t>(count);
  return std::move(txs);
}
td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> TonlibWorker::getBlockTransactionsExt(
  const std::int32_t& workchain,
  const std::int64_t& shard,
  const std::int32_t& seqno,
  size_t count,
  const std::string& root_hash,
  const std::string& file_hash,
  const std::optional<std::int64_t>& after_lt,
  const std::string& after_hash,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }

  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> blk_id = nullptr;
  if (!root_hash.empty() && !file_hash.empty()) {
    blk_id = tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain, shard, seqno, root_hash, file_hash);
  } else {
    TRY_RESULT_ASSIGN(blk_id, lookupBlock(workchain, shard, seqno, std::nullopt, std::nullopt, session));
  }

  tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId> after;
  if (after_lt.has_value()) {
    after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(after_hash, after_lt.value());
  } else {
    const std::string zero_hash = td::Bits256::zero().as_slice().str();
    after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(zero_hash, 0);
  }

  size_t left_count = count;
  bool is_finished = false;

  tonlib_api::object_ptr<tonlib_api::blocks_transactionsExt> txs =
    tonlib_api::make_object<tonlib_api::blocks_transactionsExt>(
      nullptr, 0, true, std::vector<tonlib_api::object_ptr<tonlib_api::raw_transaction>>{}
    );
  txs->transactions_.reserve(count);
  while (!is_finished) {
    constexpr size_t CHUNK_SIZE = 256;
    size_t chunk_size = (left_count > CHUNK_SIZE ? CHUNK_SIZE : left_count);
    TRY_RESULT(local, raw_getBlockTransactionsExt(blk_id, chunk_size, std::move(after), archival, session));
    txs->id_ = std::move(local->id_);
    txs->incomplete_ = local->incomplete_;
    left_count -= local->transactions_.size();
    if (!local->transactions_.empty()) {
      auto last_idx = local->transactions_.size() - 1;
      TRY_RESULT(std_address, block::StdAddress::parse(local->transactions_[last_idx]->address_->account_address_));
      after = tonlib_api::make_object<tonlib_api::blocks_accountTransactionId>(
        std_address.addr.as_slice().str(), local->transactions_[last_idx]->transaction_id_->lt_
      );
    }

    std::ranges::copy(
      std::make_move_iterator(local->transactions_.begin()),
      std::make_move_iterator(local->transactions_.end()),
      std::back_inserter(txs->transactions_)
    );
    is_finished = (left_count <= 0) || !local->incomplete_;
  }
  txs->req_count_ = static_cast<std::int32_t>(count);
  return std::move(txs);
}
td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> TonlibWorker::getTransactions(
  const std::string& account_address,
  std::optional<std::int64_t> from_transaction_lt,
  std::string from_transaction_hash,
  std::int64_t to_transaction_lt,
  size_t count,
  size_t chunk_size,
  bool try_decode_messages,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = archival};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }

  if (!(from_transaction_lt.has_value() && !from_transaction_hash.empty())) {
    TRY_RESULT(account_state, getAddressInformation(account_address, std::nullopt, session));
    from_transaction_lt = account_state->last_transaction_id_->lt_;
    from_transaction_hash = account_state->last_transaction_id_->hash_;
  }

  bool reach_lt = false;
  size_t tx_count = 0;
  auto current_lt = from_transaction_lt.value();
  auto current_hash = from_transaction_hash;

  tonlib_api::object_ptr<tonlib_api::raw_transactions> txs = tonlib_api::make_object<tonlib_api::raw_transactions>();
  while (!reach_lt && tx_count < count) {
    size_t local_chunk_size = (count - tx_count > chunk_size ? chunk_size : count - tx_count);
    TRY_RESULT(
      local,
      raw_getTransactionsV2(
        account_address, current_lt, current_hash, local_chunk_size, try_decode_messages, archival, session
      )
    );
    for (auto& tx : local->transactions_) {
      if (tx->transaction_id_->lt_ <= to_transaction_lt) {
        reach_lt = true;
      } else {
        ++tx_count;
      }
    }

    // it seems that previous_transaction_id_ is always not nullptr however, I'll leave it as it was in a Python version
    if (auto& next_tx = local->previous_transaction_id_; next_tx) {
      current_lt = next_tx->lt_;
      current_hash = next_tx->hash_;
    } else {
      reach_lt = true;
    }
    if (current_lt == 0) {
      reach_lt = true;
    }
    std::copy(
      std::move_iterator(local->transactions_.begin()),
      std::move_iterator(local->transactions_.end()),
      std::back_inserter(txs->transactions_)
    );
    if (local->previous_transaction_id_) {
      txs->previous_transaction_id_ = std::move(local->previous_transaction_id_);
    }
  }
  if (txs->transactions_.size() > tx_count) {
    txs->transactions_.resize(tx_count);
  }
  return std::move(txs);
}
td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> TonlibWorker::tryLocateTransactionByIncomingMessage(
  const std::string& source, const std::string& destination, std::int64_t created_lt, multiclient::SessionPtr session
) const {
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }

  TRY_RESULT_PREFIX(src, block::StdAddress::parse(source), "failed to parse source: ");
  TRY_RESULT_PREFIX(dest, block::StdAddress::parse(destination), "failed to parse destination: ");
  auto workchain = dest.workchain;
  TRY_RESULT_PREFIX(
    shards, getShards(std::nullopt, created_lt, std::nullopt, session), "failed to get shards at create_lt: "
  );
  for (auto& shard : shards->shards_) {
    auto shard_id = shard->shard_;
    for (auto i = 0; i < 3; ++i) {
      auto lt = created_lt + 1000000 * i;
      TRY_RESULT_PREFIX(
        block,
        lookupBlock(workchain, shard_id, std::nullopt, lt, std::nullopt, session),
        "failed to lookup block by given lt: "
      );
      constexpr size_t tx_count = 40;
      TRY_RESULT_PREFIX(
        blk_txs,
        getBlockTransactions(
          block->workchain_,
          block->shard_,
          block->seqno_,
          tx_count,
          block->root_hash_,
          block->file_hash_,
          std::nullopt,
          "",
          std::nullopt,
          session
        ),
        "failed to get transactions for block: "
      );

      tonlib_api::object_ptr<tonlib_api::blocks_shortTxId> candidate = nullptr;
      size_t tx_found = 0;
      for (auto& tx : blk_txs->transactions_) {
        auto tx_addr_str = std::to_string(block->workchain_) + ":" + td::hex_encode(tx->account_);
        if (auto tx_addr = block::StdAddress::parse(tx_addr_str).move_as_ok();
            dest.addr == tx_addr.addr && (candidate == nullptr || candidate->lt_ < tx->lt_)) {
          ++tx_found;
          candidate = std::move(tx);
        }
      }
      if (candidate != nullptr) {
        constexpr size_t min_tx_found = 10;
        TRY_RESULT_PREFIX(
          candidate_txs,
          getTransactions(
            destination,
            candidate->lt_,
            candidate->hash_,
            std::max(tx_found, min_tx_found),
            10,
            30,
            true,
            std::nullopt,
            session
          ),
          "failed to get candidate transactions: "
        );
        for (auto& candidate_tx : candidate_txs->transactions_) {
          if (auto& in_msg = candidate_tx->in_msg_;
              in_msg && in_msg->source_ && !in_msg->source_->account_address_.empty()) {
            TRY_RESULT_PREFIX(
              tx_src_addr,
              block::StdAddress::parse(in_msg->source_->account_address_),
              "failed to parse source address: "
            );
            if (src.workchain == tx_src_addr.workchain && src.addr == tx_src_addr.addr &&
                in_msg->created_lt_ == created_lt) {
              std::vector<tonlib_api::object_ptr<tonlib_api::raw_transaction>> tx_vec;
              tx_vec.emplace_back(std::move(candidate_tx));
              const std::string zero_hash = td::Bits256::zero().as_slice().str();
              auto prev_tx = tonlib_api::make_object<tonlib_api::internal_transactionId>(0, zero_hash);
              return tonlib_api::make_object<tonlib_api::raw_transactions>(std::move(tx_vec), std::move(prev_tx));
            }
          }
        }
      }
    }
  }
  return td::Status::Error(404, "transaction was not found");
}

td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> TonlibWorker::tryLocateTransactionByOutgoingMessage(
  const std::string& source, const std::string& destination, std::int64_t created_lt, multiclient::SessionPtr session
) const {
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }

  TRY_RESULT_PREFIX(src, block::StdAddress::parse(source), "failed to parse source: ");
  TRY_RESULT_PREFIX(dest, block::StdAddress::parse(destination), "failed to parse destination: ");
  auto workchain = src.workchain;
  TRY_RESULT_PREFIX(
    shards, getShards(std::nullopt, created_lt, std::nullopt, session), "failed to get shards at create_lt: "
  );
  for (auto& shard : shards->shards_) {
    auto shard_id = shard->shard_;
    TRY_RESULT_PREFIX(
      block,
      lookupBlock(workchain, shard_id, std::nullopt, created_lt, std::nullopt, session),
      "failed to lookup block by given lt: "
    );
    constexpr size_t tx_count = 40;
    TRY_RESULT_PREFIX(
      blk_txs,
      getBlockTransactions(
        block->workchain_,
        block->shard_,
        block->seqno_,
        tx_count,
        block->root_hash_,
        block->file_hash_,
        std::nullopt,
        "",
        std::nullopt,
        session
      ),
      "failed to get transactions for block: "
    );

    tonlib_api::object_ptr<tonlib_api::blocks_shortTxId> candidate = nullptr;
    size_t tx_found = 0;
    for (auto& tx : blk_txs->transactions_) {
      auto tx_addr_str = std::to_string(block->workchain_) + ":" + td::hex_encode(tx->account_);
      TRY_RESULT_PREFIX(tx_addr, block::StdAddress::parse(tx_addr_str), "failed to parse transaction address: ");
      if (src.addr == tx_addr.addr && (candidate == nullptr || candidate->lt_ < tx->lt_)) {
        ++tx_found;
        candidate = std::move(tx);
      }
    }
    if (candidate != nullptr) {
      constexpr size_t min_tx_found = 10;
      TRY_RESULT_PREFIX(
        candidate_txs,
        getTransactions(
          source,
          candidate->lt_,
          candidate->hash_,
          std::max(tx_found, min_tx_found),
          10,
          30,
          true,
          std::nullopt,
          session
        ),
        "failed to get candidate transactions: "
      );
      for (auto& candidate_tx : candidate_txs->transactions_) {
        for (auto& out_msg : candidate_tx->out_msgs_) {
          if (out_msg && out_msg->destination_ && !out_msg->destination_->account_address_.empty()) {
            TRY_RESULT_PREFIX(
              tx_dest_addr,
              block::StdAddress::parse(out_msg->destination_->account_address_),
              "failed to parse destination address: "
            );
            if (dest.workchain == tx_dest_addr.workchain && dest.addr == tx_dest_addr.addr &&
                out_msg->created_lt_ == created_lt) {
              std::vector<tonlib_api::object_ptr<tonlib_api::raw_transaction>> tx_vec;
              tx_vec.emplace_back(std::move(candidate_tx));
              const std::string zero_hash = td::Bits256::zero().as_slice().str();
              auto prev_tx = tonlib_api::make_object<tonlib_api::internal_transactionId>(0, zero_hash);
              return tonlib_api::make_object<tonlib_api::raw_transactions>(std::move(tx_vec), std::move(prev_tx));
            }
          }
        }
      }
    }
  }
  return td::Status::Error(404, "transaction was not found");
}
}  // namespace ton_http::core
