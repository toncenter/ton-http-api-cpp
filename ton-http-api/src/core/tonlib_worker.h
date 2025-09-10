#pragma once
#include "tonlib-multiclient/multi_client.h"
#include "tonlib-multiclient/request.h"
#include "userver/engine/future.hpp"
#include "types.hpp"

namespace ton_http::core {
class TonlibWorker {
public:
  explicit TonlibWorker(const multiclient::MultiClientConfig& config) : tonlib_(config) {};
  ~TonlibWorker() = default;

  [[nodiscard]] td::Result<ConsensusBlockResult> getConsensusBlock(multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<DetectAddressResult> detectAddress(const std::string& address, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<std::string> packAddress(const std::string& address, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<std::string> unpackAddress(const std::string& address, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<DetectHashResult> detectHash(const std::string& hash, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> getTokenData(
    const std::string& address,
    bool skip_verification = false,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getMasterchainInfo::ReturnType>
    getMasterchainInfo(multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getMasterchainBlockSignatures::ReturnType>
    getMasterchainBlockSignatures(ton::BlockSeqno seqno, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getAccountState::ReturnType>
    getAddressInformation(const std::string& address, std::optional<std::int32_t> seqno = std::nullopt, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::getAccountState::ReturnType>
    getExtendedAddressInformation(const std::string& address, std::optional<std::int32_t> seqno = std::nullopt, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_lookupBlock::ReturnType> lookupBlock(const ton::WorkchainId& workchain,
    const ton::ShardId& shard, const std::optional<ton::BlockSeqno>& seqno = std::nullopt,
    const std::optional<ton::LogicalTime>& lt = std::nullopt,
    const std::optional<ton::UnixTime>& unixtime = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getShardBlockProof::ReturnType> getShardBlockProof(const ton::WorkchainId& workchain,
    const ton::ShardId& shard,
    const ton::BlockSeqno& seqno,
    const std::optional<ton::BlockSeqno>& from_seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getShards::ReturnType> getShards(std::optional<ton::BlockSeqno> mc_seqno = std::nullopt,
    std::optional<ton::LogicalTime> lt = std::nullopt,
    std::optional<ton::UnixTime> unixtime = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getBlockHeader::ReturnType> getBlockHeader(
      const ton::WorkchainId& workchain,
      const ton::ShardId& shard,
      const ton::BlockSeqno& seqno,
      const std::string& root_hash = "",
      const std::string& file_hash = "",
      multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getOutMsgQueueSizes::ReturnType> getOutMsgQueueSizes(multiclient::SessionPtr session = nullptr) const;

  [[nodiscard]] td::Result<tonlib_api::getConfigParam::ReturnType> getConfigParam(const std::int32_t& param,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::getConfigParam::ReturnType> getConfigAll(std::optional<ton::BlockSeqno> seqno = std::nullopt, multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::smc_getLibraries::ReturnType> getLibraries(
    std::vector<std::string> libs,
    multiclient::SessionPtr session = nullptr) const;

  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactions::ReturnType> raw_getBlockTransactions(const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
    size_t count,
    tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after = nullptr,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> raw_getBlockTransactionsExt(const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
    size_t count,
    tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after = nullptr,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactions::ReturnType> raw_getTransactions(
    const std::string& account_address,
    const ton::LogicalTime& from_transaction_lt,
    const std::string& from_transaction_hash,
    const std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> raw_getTransactionsV2(
    const std::string& account_address,
    const ton::LogicalTime& from_transaction_lt,
    const std::string& from_transaction_hash,
    const size_t count,
    const bool try_decode_messages,
    const std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr) const;

  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactions::ReturnType> getBlockTransactions(
    const ton::WorkchainId& workchain,
    const ton::ShardId& shard,
    const ton::BlockSeqno& seqno,
    const size_t count = 40,
    const std::string& root_hash = "",
    const std::string& file_hash = "",
    const std::optional<ton::LogicalTime>& after_lt = std::nullopt,
    const std::string& after_hash = "",
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> getBlockTransactionsExt(
    const ton::WorkchainId& workchain,
    const ton::ShardId& shard,
    const ton::BlockSeqno& seqno,
    const size_t count = 40,
    const std::string& root_hash = "",
    const std::string& file_hash = "",
    const std::optional<ton::LogicalTime>& after_lt = std::nullopt,
    const std::string& after_hash = "",
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> getTransactions(
    const std::string& account_address,
    std::optional<ton::LogicalTime> from_transaction_lt,
    std::string from_transaction_hash,
    ton::LogicalTime to_transaction_lt = 0,
    size_t count = 10,
    size_t chunk_size = 30,
    bool try_decode_messages = true,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> tryLocateTransactionByIncomingMessage(
    const std::string& source,
    const std::string& destination,
    ton::LogicalTime created_lt,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> tryLocateTransactionByOutgoingMessage(
      const std::string& source,
      const std::string& destination,
      ton::LogicalTime created_lt,
      multiclient::SessionPtr session = nullptr) const;

  [[nodiscard]] td::Result<tonlib_api::raw_sendMessage::ReturnType> raw_sendMessage(
    const std::string& boc,
    multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] td::Result<tonlib_api::raw_sendMessageReturnHash::ReturnType> raw_sendMessageReturnHash(
    const std::string& boc,
    multiclient::SessionPtr session = nullptr) const;

  [[nodiscard]] td::Result<tonlib_api::smc_load::ReturnType> loadContract(
    const std::string& address,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::smc_forget::ReturnType> forgetContract(
    std::int64_t id,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<RunGetMethodResult> runGetMethod(
    const std::string& address,
    const std::string& method_name,
    const std::vector<std::string>& stack,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::query_estimateFees::ReturnType> queryEstimateFees(
    const std::string& account_address,
    const std::string& body,
    const std::string& init_code = "",
    const std::string& init_data = "",
    bool ignore_chksig = true,
    multiclient::SessionPtr session = nullptr
  ) const;
private:
  multiclient::MultiClient tonlib_;

  [[nodiscard]] td::Result<TokenDataResultPtr> checkJettonMaster(
    const std::string& address,
    bool skip_verification = false,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkJettonWallet(
    const std::string& address,
    bool skip_verification = false,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkNFTCollection(
    const std::string& address,
    bool skip_verification = false,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkNFTItem(
    const std::string& address,
    bool skip_verification = false,
    std::optional<ton::BlockSeqno> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  template<typename T>
  td::Result<typename T::ReturnType> send_request_function(multiclient::RequestFunction<T>&& request, bool retry_archival = false) const {
    auto result = tonlib_.send_request_function<T, userver::engine::Promise>(request);
    if (result.is_ok() || !retry_archival) {
      return std::move(result);
    }
    auto error = result.move_as_error();

    // retry request with archival
    {
      request.parameters.archival = true;
      auto r_session = tonlib_.get_session(request.parameters, std::move(request.session));
      if (r_session.is_error()) {
        return r_session.move_as_error();
      }
      request.session = r_session.move_as_ok();
    }

    result = tonlib_.send_request_function<T, userver::engine::Promise>(request);
    if (result.is_error()) {
      auto error_archival = result.move_as_error();
      LOG(WARNING) << error_archival.code() << " " << error_archival.message();
      if (error_archival.code() == -3) {
        return std::move(error);
      }
      return std::move(error_archival);
    }
    return std::move(result);
  }
};
}
