#pragma once
#include "tonlib-multiclient/multi_client.h"
#include "tonlib-multiclient/request.h"
#include "types.hpp"
#include "userver/engine/future.hpp"

namespace ton_http::core {
class TonlibWorker {
public:
  explicit TonlibWorker(const multiclient::MultiClientConfig& config) : tonlib_(config) {};
  ~TonlibWorker() = default;

  [[nodiscard]] td::Result<ConsensusBlockResult> getConsensusBlock(multiclient::SessionPtr session = nullptr) const;
  [[nodiscard]] static td::Result<DetectAddressResult> detectAddress(
    const std::string& address, multiclient::SessionPtr session = nullptr
  );
  [[nodiscard]] static td::Result<std::string> packAddress(
    const std::string& address, multiclient::SessionPtr session = nullptr
  );
  [[nodiscard]] static td::Result<std::string> unpackAddress(
    const std::string& address, multiclient::SessionPtr session = nullptr
  );
  [[nodiscard]] static td::Result<DetectHashResult> detectHash(
    const std::string& hash, multiclient::SessionPtr session = nullptr
  );
  [[nodiscard]] td::Result<TokenDataResultPtr> getTokenData(
    const std::string& address,
    bool skip_verification = false,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getMasterchainInfo::ReturnType> getMasterchainInfo(
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getMasterchainBlockSignatures::ReturnType> getMasterchainBlockSignatures(
    std::int32_t seqno, multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getAccountState::ReturnType> getAddressInformation(
    const std::string& address,
    std::optional<std::int32_t> seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::getAccountState::ReturnType> getExtendedAddressInformation(
    const std::string& address,
    std::optional<std::int32_t> seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_lookupBlock::ReturnType> lookupBlock(
    const std::int32_t& workchain,
    const std::int64_t& shard,
    const std::optional<std::int32_t>& seqno = std::nullopt,
    const std::optional<std::int64_t>& lt = std::nullopt,
    const std::optional<std::int32_t>& unixtime = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getShardBlockProof::ReturnType> getShardBlockProof(
    const std::int32_t& workchain,
    const std::int64_t& shard,
    const std::int32_t& seqno,
    const std::optional<std::int32_t>& from_seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getShards::ReturnType> getShards(
    std::optional<std::int32_t> mc_seqno = std::nullopt,
    std::optional<std::int64_t> lt = std::nullopt,
    std::optional<std::int32_t> unixtime = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getBlockHeader::ReturnType> getBlockHeader(
    const std::int32_t& workchain,
    const std::int64_t& shard,
    const std::int32_t& seqno,
    const std::string& root_hash = "",
    const std::string& file_hash = "",
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getOutMsgQueueSizes::ReturnType> getOutMsgQueueSizes(
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::getConfigParam::ReturnType> getConfigParam(
    const std::int32_t& param,
    std::optional<std::int32_t> seqno = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::getConfigParam::ReturnType> getConfigAll(
    std::optional<std::int32_t> seqno = std::nullopt, multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::smc_getLibraries::ReturnType> getLibraries(
    std::vector<std::string> libs, multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactions::ReturnType> getBlockTransactions(
    const std::int32_t& workchain,
    const std::int64_t& shard,
    const std::int32_t& seqno,
    size_t count = 40,
    const std::string& root_hash = "",
    const std::string& file_hash = "",
    const std::optional<std::int64_t>& after_lt = std::nullopt,
    const std::string& after_hash = "",
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> getBlockTransactionsExt(
    const std::int32_t& workchain,
    const std::int64_t& shard,
    const std::int32_t& seqno,
    size_t count = 40,
    const std::string& root_hash = "",
    const std::string& file_hash = "",
    const std::optional<std::int64_t>& after_lt = std::nullopt,
    const std::string& after_hash = "",
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> getTransactions(
    const std::string& account_address,
    std::optional<std::int64_t> from_transaction_lt,
    std::string from_transaction_hash,
    std::int64_t to_transaction_lt = 0,
    size_t count = 10,
    size_t chunk_size = 30,
    bool try_decode_messages = true,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> tryLocateTransactionByIncomingMessage(
    const std::string& source,
    const std::string& destination,
    std::int64_t created_lt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> tryLocateTransactionByOutgoingMessage(
    const std::string& source,
    const std::string& destination,
    std::int64_t created_lt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::raw_sendMessage::ReturnType> raw_sendMessage(
    const std::string& boc, multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::raw_sendMessageReturnHash::ReturnType> raw_sendMessageReturnHash(
    const std::string& boc, multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::smc_load::ReturnType> loadContract(
    const std::string& address,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<tonlib_api::smc_forget::ReturnType> forgetContract(
    std::int64_t id, std::optional<bool> archival = std::nullopt, multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<RunGetMethodResult> runGetMethod(
    const std::string& address,
    const std::string& method_name,
    const std::vector<std::string>& stack,
    std::optional<std::int32_t> seqno = std::nullopt,
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


  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactions::ReturnType> raw_getBlockTransactions(
    const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
    size_t count,
    tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after = nullptr,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::blocks_getTransactionsExt::ReturnType> raw_getBlockTransactionsExt(
    const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& blk_id,
    size_t count,
    tonlib_api::object_ptr<tonlib_api::blocks_accountTransactionId>&& after = nullptr,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactions::ReturnType> raw_getTransactions(
    const std::string& account_address,
    const std::int64_t& from_transaction_lt,
    const std::string& from_transaction_hash,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<tonlib_api::raw_getTransactionsV2::ReturnType> raw_getTransactionsV2(
    const std::string& account_address,
    const std::int64_t& from_transaction_lt,
    const std::string& from_transaction_hash,
    size_t count,
    bool try_decode_messages,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<RunGetMethodResult> runGetMethod_impl(
    std::int64_t smc_id,
    const std::string& method_name,
    const std::vector<std::string>& stack,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  [[nodiscard]] td::Result<TokenDataResultPtr> checkJettonMaster(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification = false,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkJettonWallet(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification = false,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkNFTCollection(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification = false,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;
  [[nodiscard]] td::Result<TokenDataResultPtr> checkNFTItem(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification = false,
    std::optional<std::int32_t> seqno = std::nullopt,
    std::optional<bool> archival = std::nullopt,
    multiclient::SessionPtr session = nullptr
  ) const;

  template <typename T>
  td::Result<typename T::ReturnType> send_request_function(
    multiclient::RequestFunction<T>&& request, bool retry_archival = false
  ) const {
    if (!request.session->is_valid()) {
      TRY_RESULT_ASSIGN(request.session, tonlib_.get_session(request.parameters, std::move(request.session)));
    }

    auto result = tonlib_.send_request_function<T, userver::engine::Promise>(request);
    if (result.is_ok() || !retry_archival) {
      return std::move(result);
    }
    auto error = result.move_as_error();

    if (request.parameters.archival.has_value() && request.parameters.archival.value()) {
      return std::move(error);
    }

    // retry request with archival
    request.parameters.archival = true;
    TRY_RESULT_ASSIGN(request.session, tonlib_.get_session(request.parameters, std::move(request.session)));
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
}  // namespace ton_http::core
