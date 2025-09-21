#pragma once

#include "v2_fwd.hpp"


#include <fmt/core.h>
#include <cstdint>
#include <optional>
#include <string>
#include <userver/chaotic/io/std/int64_t.hpp>
#include <userver/chaotic/io/std/uint64_t.hpp>
#include <userver/chaotic/io/std/vector.hpp>
#include <userver/chaotic/io/ton_http/types/bytes.hpp>
#include <userver/chaotic/io/ton_http/types/int256.hpp>
#include <userver/chaotic/io/ton_http/types/ton_addr.hpp>
#include <userver/chaotic/io/ton_http/types/ton_hash.hpp>
#include <userver/chaotic/oneof_with_discriminator.hpp>
#include <userver/formats/json/serialize_variant.hpp>
#include <userver/formats/json/value.hpp>
#include <userver/formats/parse/variant.hpp>
#include <variant>


#include <userver/chaotic/type_bundle_hpp.hpp>


namespace ton_http {
namespace schemas {
namespace v2 {


struct AccountAddress {
  enum class _Type {
    kAccountaddress,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kAccountaddress,
  };


  ::ton_http::schemas::v2::AccountAddress::_Type _type{::ton_http::schemas::v2::AccountAddress::_Type::kAccountaddress};
  std::optional<ton_http::types::bytes> account_address{};
};


bool operator==(const ::ton_http::schemas::v2::AccountAddress& lhs, const ::ton_http::schemas::v2::AccountAddress& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountAddress::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountAddress& value
);


AccountAddress::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type>
);


AccountAddress Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress>
);


AccountAddress::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type>
);


AccountAddress::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AccountAddress::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AccountAddress& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::AccountAddress::_Type value);


enum class AccountStateEnum {
  kUninitialized,
  kActive,
  kFrozen,
};

static constexpr AccountStateEnum kAccountStateEnumValues[] = {
    AccountStateEnum::kUninitialized,
    AccountStateEnum::kActive,
    AccountStateEnum::kFrozen,
};


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateEnum& value
);


AccountStateEnum Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum>
);


AccountStateEnum FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum>
);


AccountStateEnum Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AccountStateEnum& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::AccountStateEnum value);


using Bytes = std::string;


using TonHash = std::string;


struct AccountStateRaw {
  enum class _Type {
    kRawAccountstate,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kRawAccountstate,
  };


  ::ton_http::schemas::v2::AccountStateRaw::_Type _type{
      ::ton_http::schemas::v2::AccountStateRaw::_Type::kRawAccountstate
  };
  ton_http::types::bytes code{};
  ton_http::types::bytes data{};
  ton_http::types::ton_hash frozen_hash{};
};


bool operator==(
    const ::ton_http::schemas::v2::AccountStateRaw& lhs, const ::ton_http::schemas::v2::AccountStateRaw& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRaw::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRaw& value
);


AccountStateRaw::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type>
);


AccountStateRaw Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw>
);


AccountStateRaw::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type>
);


AccountStateRaw::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AccountStateRaw::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AccountStateRaw& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::AccountStateRaw::_Type value);


using Int256 = std::string;


using AddressBalance = std::string;


struct ExtraCurrencyBalance {
  enum class _Type {
    kExtracurrency,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kExtracurrency,
  };


  ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type _type{
      ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type::kExtracurrency
  };
  std::int32_t id{};
  ton_http::types::int256 amount{};
};


bool operator==(
    const ::ton_http::schemas::v2::ExtraCurrencyBalance& lhs, const ::ton_http::schemas::v2::ExtraCurrencyBalance& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtraCurrencyBalance& value
);


ExtraCurrencyBalance::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>
);


ExtraCurrencyBalance Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance>
);


ExtraCurrencyBalance::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>
);


ExtraCurrencyBalance::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtraCurrencyBalance& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ExtraCurrencyBalance::_Type value);


// Internal transaction identifier.
struct InternalTransactionId {
  enum class _Type {
    kInternalTransactionid,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kInternalTransactionid,
  };


  ::ton_http::schemas::v2::InternalTransactionId::_Type _type{
      ::ton_http::schemas::v2::InternalTransactionId::_Type::kInternalTransactionid
  };
  std::uint64_t lt{};
  ton_http::types::ton_hash hash{};
};


bool operator==(
    const ::ton_http::schemas::v2::InternalTransactionId& lhs, const ::ton_http::schemas::v2::InternalTransactionId& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::InternalTransactionId::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::InternalTransactionId& value
);


InternalTransactionId::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type>
);


InternalTransactionId Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId>
);


InternalTransactionId::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type>
);


InternalTransactionId::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::InternalTransactionId::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::InternalTransactionId& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::InternalTransactionId::_Type value);


// Extended block identifier.
struct TonBlockIdExt {
  enum class _Type {
    kTonBlockidext,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kTonBlockidext,
  };


  ::ton_http::schemas::v2::TonBlockIdExt::_Type _type{::ton_http::schemas::v2::TonBlockIdExt::_Type::kTonBlockidext};
  int workchain{};
  std::int64_t shard{};
  int seqno{};
  ton_http::types::ton_hash root_hash{};
  ton_http::types::ton_hash file_hash{};
};


bool operator==(const ::ton_http::schemas::v2::TonBlockIdExt& lhs, const ::ton_http::schemas::v2::TonBlockIdExt& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt& value
);


TonBlockIdExt::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type>
);


TonBlockIdExt Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt>
);


TonBlockIdExt::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type>
);


TonBlockIdExt::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonBlockIdExt::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonBlockIdExt& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::TonBlockIdExt::_Type value);


struct AddressInformation {
  enum class _Type {
    kRawFullaccountstate,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kRawFullaccountstate,
  };


  ::ton_http::schemas::v2::AddressInformation::_Type _type{
      ::ton_http::schemas::v2::AddressInformation::_Type::kRawFullaccountstate
  };
  ton_http::types::int256 balance{};
  std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance> extra_currencies{};
  ::ton_http::schemas::v2::InternalTransactionId last_transaction_id{};
  ::ton_http::schemas::v2::TonBlockIdExt block_id{};
  ton_http::types::bytes code{};
  ton_http::types::bytes data{};
  ton_http::types::ton_hash frozen_hash{};
  int sync_utime{};
  ::ton_http::schemas::v2::AccountStateEnum state{};
  std::optional<bool> suspended{};
};


bool operator==(
    const ::ton_http::schemas::v2::AddressInformation& lhs, const ::ton_http::schemas::v2::AddressInformation& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressInformation::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressInformation& value
);


AddressInformation::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type>
);


AddressInformation Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation>
);


AddressInformation::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type>
);


AddressInformation::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AddressInformation::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::AddressInformation& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::AddressInformation::_Type value);


using AddressState = ::ton_http::schemas::v2::AccountStateEnum;


// Block header information.
struct BlockHeader {
  enum class _Type {
    kBlocksHeader,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksHeader,
  };


  ::ton_http::schemas::v2::BlockHeader::_Type _type{::ton_http::schemas::v2::BlockHeader::_Type::kBlocksHeader};
  ::ton_http::schemas::v2::TonBlockIdExt id{};
  int global_id{};
  int version{};
  bool after_merge{};
  bool after_split{};
  bool before_split{};
  bool want_merge{};
  bool want_split{};
  int validator_list_hash_short{};
  int catchain_seqno{};
  int min_ref_mc_seqno{};
  bool is_key_block{};
  int prev_key_block_seqno{};
  std::uint64_t start_lt{};
  std::uint64_t end_lt{};
  int gen_utime{};
  std::vector<::ton_http::schemas::v2::TonBlockIdExt> prev_blocks{};


  USERVER_NAMESPACE::formats::json::Value extra;
};


bool operator==(const ::ton_http::schemas::v2::BlockHeader& lhs, const ::ton_http::schemas::v2::BlockHeader& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockHeader::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockHeader& value
);


BlockHeader::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type>
);


BlockHeader Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader>
);


BlockHeader::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type>
);


BlockHeader::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockHeader::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockHeader& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::BlockHeader::_Type value);


struct BlockLinkBack {
  enum class _Type {
    kBlocksBlocklinkback,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksBlocklinkback,
  };


  ::ton_http::schemas::v2::BlockLinkBack::_Type _type{
      ::ton_http::schemas::v2::BlockLinkBack::_Type::kBlocksBlocklinkback
  };
  bool to_key_block{};
  ::ton_http::schemas::v2::TonBlockIdExt from{};
  ::ton_http::schemas::v2::TonBlockIdExt to{};
  ton_http::types::bytes dest_proof{};
  ton_http::types::bytes proof{};
  ton_http::types::bytes state_proof{};
};


bool operator==(const ::ton_http::schemas::v2::BlockLinkBack& lhs, const ::ton_http::schemas::v2::BlockLinkBack& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockLinkBack::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockLinkBack& value
);


BlockLinkBack::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type>
);


BlockLinkBack Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack>
);


BlockLinkBack::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type>
);


BlockLinkBack::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockLinkBack::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockLinkBack& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::BlockLinkBack::_Type value);


struct BlockSignature {
  enum class _Type {
    kBlocksSignature,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksSignature,
  };


  ::ton_http::schemas::v2::BlockSignature::_Type _type{
      ::ton_http::schemas::v2::BlockSignature::_Type::kBlocksSignature
  };
  ton_http::types::ton_hash node_id_short{};
  ton_http::types::bytes signature{};
};


bool operator==(const ::ton_http::schemas::v2::BlockSignature& lhs, const ::ton_http::schemas::v2::BlockSignature& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockSignature::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockSignature& value
);


BlockSignature::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type>
);


BlockSignature Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature>
);


BlockSignature::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type>
);


BlockSignature::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockSignature::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockSignature& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::BlockSignature::_Type value);


using TonAddr = std::string;


// Short transaction identifier
struct ShortTxId {
  enum class _Type {
    kBlocksShorttxid,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksShorttxid,
  };


  ::ton_http::schemas::v2::ShortTxId::_Type _type{::ton_http::schemas::v2::ShortTxId::_Type::kBlocksShorttxid};
  int mode{};
  ton_http::types::ton_addr account{};
  std::uint64_t lt{};
  ton_http::types::ton_hash hash{};
};


bool operator==(const ::ton_http::schemas::v2::ShortTxId& lhs, const ::ton_http::schemas::v2::ShortTxId& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShortTxId::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShortTxId& value
);


ShortTxId::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type>
);


ShortTxId Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId>
);


ShortTxId::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type>
);


ShortTxId::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShortTxId::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShortTxId& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ShortTxId::_Type value);


// Block transactions information
struct BlockTransactions {
  enum class _Type {
    kBlocksTransactions,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksTransactions,
  };


  ::ton_http::schemas::v2::BlockTransactions::_Type _type{
      ::ton_http::schemas::v2::BlockTransactions::_Type::kBlocksTransactions
  };
  ::ton_http::schemas::v2::TonBlockIdExt id{};
  int req_count{};
  bool incomplete{};
  std::vector<::ton_http::schemas::v2::ShortTxId> transactions{};
};


bool operator==(
    const ::ton_http::schemas::v2::BlockTransactions& lhs, const ::ton_http::schemas::v2::BlockTransactions& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockTransactions::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockTransactions& value
);


BlockTransactions::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type>
);


BlockTransactions Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions>
);


BlockTransactions::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type>
);


BlockTransactions::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockTransactions::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::BlockTransactions& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::BlockTransactions::_Type value);


struct TvmCell {
  enum class _Type {
    kTvmCell,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kTvmCell,
  };


  ::ton_http::schemas::v2::TvmCell::_Type _type{::ton_http::schemas::v2::TvmCell::_Type::kTvmCell};
  ton_http::types::bytes bytes{};
};


bool operator==(const ::ton_http::schemas::v2::TvmCell& lhs, const ::ton_http::schemas::v2::TvmCell& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TvmCell::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TvmCell& value
);


TvmCell::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type>
);


TvmCell Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell>
);


TvmCell::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type>
);


TvmCell::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TvmCell::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TvmCell& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::TvmCell::_Type value);


struct ConfigInfo {
  enum class _Type {
    kConfiginfo,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kConfiginfo,
  };


  ::ton_http::schemas::v2::ConfigInfo::_Type _type{::ton_http::schemas::v2::ConfigInfo::_Type::kConfiginfo};
  ::ton_http::schemas::v2::TvmCell config{};
};


bool operator==(const ::ton_http::schemas::v2::ConfigInfo& lhs, const ::ton_http::schemas::v2::ConfigInfo& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConfigInfo::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConfigInfo& value
);


ConfigInfo::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type>
);


ConfigInfo Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo>
);


ConfigInfo::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type>
);


ConfigInfo::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ConfigInfo::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ConfigInfo& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ConfigInfo::_Type value);


struct ConsensusBlock {
  enum class _Type {
    kExtConsensusblock,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kExtConsensusblock,
  };


  ::ton_http::schemas::v2::ConsensusBlock::_Type _type{
      ::ton_http::schemas::v2::ConsensusBlock::_Type::kExtConsensusblock
  };
  std::int32_t consensus_block{};
  std::int32_t timestamp{};
};


bool operator==(const ::ton_http::schemas::v2::ConsensusBlock& lhs, const ::ton_http::schemas::v2::ConsensusBlock& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConsensusBlock::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConsensusBlock& value
);


ConsensusBlock::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type>
);


ConsensusBlock Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock>
);


ConsensusBlock::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type>
);


ConsensusBlock::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ConsensusBlock::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ConsensusBlock& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ConsensusBlock::_Type value);


// Base64 form of address variant
struct DetectAddressBase64Variant {
  std::string b64{};
  std::string b64url{};
};


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressBase64Variant& lhs,
    const ::ton_http::schemas::v2::DetectAddressBase64Variant& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressBase64Variant& value
);


DetectAddressBase64Variant Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddressBase64Variant& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


// Information about the address.
struct DetectAddress {
  enum class _Type {
    kUtilsDetectedaddress,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kUtilsDetectedaddress,
  };


  enum class Given_Type {
    kRawForm,
    kFriendlyBounceable,
    kFriendlyNonBounceable,
  };

  static constexpr Given_Type kGiven_TypeValues[] = {
      Given_Type::kRawForm,
      Given_Type::kFriendlyBounceable,
      Given_Type::kFriendlyNonBounceable,
  };


  ::ton_http::schemas::v2::DetectAddress::_Type _type{
      ::ton_http::schemas::v2::DetectAddress::_Type::kUtilsDetectedaddress
  };
  std::string raw_form{};
  ::ton_http::schemas::v2::DetectAddressBase64Variant bounceable{};
  ::ton_http::schemas::v2::DetectAddressBase64Variant non_bounceable{};
  ::ton_http::schemas::v2::DetectAddress::Given_Type given_type{};
  bool test_only{};
};


bool operator==(const ::ton_http::schemas::v2::DetectAddress& lhs, const ::ton_http::schemas::v2::DetectAddress& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress::Given_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress& value
);


DetectAddress::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type>
);


DetectAddress::Given_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type>
);


DetectAddress Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress>
);


DetectAddress::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type>
);


DetectAddress::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type>
);


DetectAddress::Given_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type>
);


DetectAddress::Given_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddress::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddress::Given_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddress& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::DetectAddress::_Type value);


std::string ToString(::ton_http::schemas::v2::DetectAddress::Given_Type value);


struct DetectAddressRequest {
  ton_http::types::ton_addr address{};
};


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressRequest& lhs, const ::ton_http::schemas::v2::DetectAddressRequest& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressRequest& value
);


DetectAddressRequest Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressRequest>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddressRequest& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


struct DetectHash {
  enum class _Type {
    kUtilsDetectedhash,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kUtilsDetectedhash,
  };


  ::ton_http::schemas::v2::DetectHash::_Type _type{::ton_http::schemas::v2::DetectHash::_Type::kUtilsDetectedhash};
  std::string b64{};
  std::string b64url{};
  std::string hex{};
};


bool operator==(const ::ton_http::schemas::v2::DetectHash& lhs, const ::ton_http::schemas::v2::DetectHash& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHash::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHash& value
);


DetectHash::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type>
);


DetectHash Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash>
);


DetectHash::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type>
);


DetectHash::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectHash::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectHash& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::DetectHash::_Type value);


struct EmptyRequest {};


bool operator==(const ::ton_http::schemas::v2::EmptyRequest& lhs, const ::ton_http::schemas::v2::EmptyRequest& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::EmptyRequest& value
);


EmptyRequest Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::EmptyRequest>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::EmptyRequest& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


struct MsgDataRaw {
  enum class _Type {
    kMsgDataraw,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kMsgDataraw,
  };


  ::ton_http::schemas::v2::MsgDataRaw::_Type _type{::ton_http::schemas::v2::MsgDataRaw::_Type::kMsgDataraw};
  std::optional<ton_http::types::bytes> body{};
  std::optional<ton_http::types::bytes> init_state{};
};


bool operator==(const ::ton_http::schemas::v2::MsgDataRaw& lhs, const ::ton_http::schemas::v2::MsgDataRaw& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataRaw::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataRaw& value
);


MsgDataRaw::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type>
);


MsgDataRaw Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw>
);


MsgDataRaw::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type>
);


MsgDataRaw::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataRaw::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataRaw& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MsgDataRaw::_Type value);


struct MsgDataText {
  enum class _Type {
    kMsgDatatext,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kMsgDatatext,
  };


  ::ton_http::schemas::v2::MsgDataText::_Type _type{::ton_http::schemas::v2::MsgDataText::_Type::kMsgDatatext};
  std::optional<std::string> text{};
};


bool operator==(const ::ton_http::schemas::v2::MsgDataText& lhs, const ::ton_http::schemas::v2::MsgDataText& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataText::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataText& value
);


MsgDataText::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type>
);


MsgDataText Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText>
);


MsgDataText::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type>
);


MsgDataText::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataText::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataText& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MsgDataText::_Type value);


struct MsgDataDecryptedText {
  enum class _Type {
    kMsgDatadecryptedtext,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kMsgDatadecryptedtext,
  };


  ::ton_http::schemas::v2::MsgDataDecryptedText::_Type _type{
      ::ton_http::schemas::v2::MsgDataDecryptedText::_Type::kMsgDatadecryptedtext
  };
  std::optional<std::string> text{};
};


bool operator==(
    const ::ton_http::schemas::v2::MsgDataDecryptedText& lhs, const ::ton_http::schemas::v2::MsgDataDecryptedText& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataDecryptedText& value
);


MsgDataDecryptedText::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>
);


MsgDataDecryptedText Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText>
);


MsgDataDecryptedText::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>
);


MsgDataDecryptedText::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataDecryptedText& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MsgDataDecryptedText::_Type value);


struct MsgDataEncryptedText {
  enum class _Type {
    kMsgDataencryptedtext,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kMsgDataencryptedtext,
  };


  ::ton_http::schemas::v2::MsgDataEncryptedText::_Type _type{
      ::ton_http::schemas::v2::MsgDataEncryptedText::_Type::kMsgDataencryptedtext
  };
  std::optional<std::string> text{};
};


bool operator==(
    const ::ton_http::schemas::v2::MsgDataEncryptedText& lhs, const ::ton_http::schemas::v2::MsgDataEncryptedText& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataEncryptedText& value
);


MsgDataEncryptedText::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>
);


MsgDataEncryptedText Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText>
);


MsgDataEncryptedText::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>
);


MsgDataEncryptedText::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MsgDataEncryptedText& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MsgDataEncryptedText::_Type value);


struct ExtMessage {
  enum class _Type {
    kExtMessage,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kExtMessage,
  };


  using Msg_Data = std::variant<
      ::ton_http::schemas::v2::MsgDataRaw,
      ::ton_http::schemas::v2::MsgDataText,
      ::ton_http::schemas::v2::MsgDataDecryptedText,
      ::ton_http::schemas::v2::MsgDataEncryptedText>;


  ::ton_http::schemas::v2::ExtMessage::_Type _type{::ton_http::schemas::v2::ExtMessage::_Type::kExtMessage};
  ton_http::types::ton_hash hash{};
  ton_http::types::ton_addr source{};
  ton_http::types::ton_addr destination{};
  ton_http::types::int256 value{};
  std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance> extra_currencies{};
  ton_http::types::int256 fwd_fee{};
  ton_http::types::int256 ihr_fee{};
  std::uint64_t created_lt{};
  ton_http::types::ton_hash body_hash{};
  ::ton_http::schemas::v2::ExtMessage::Msg_Data msg_data{};
  std::optional<std::string> message{};
  std::optional<std::string> message_decode_error{};
};


bool operator==(const ::ton_http::schemas::v2::ExtMessage& lhs, const ::ton_http::schemas::v2::ExtMessage& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtMessage::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtMessage& value
);


ExtMessage::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type>
);


ExtMessage Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage>
);


ExtMessage::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type>
);


ExtMessage::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtMessage::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtMessage& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ExtMessage::_Type value);


struct ExtTransaction {
  enum class _Type {
    kExtTransaction,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kExtTransaction,
  };


  ::ton_http::schemas::v2::ExtTransaction::_Type _type{::ton_http::schemas::v2::ExtTransaction::_Type::kExtTransaction};
  ::ton_http::schemas::v2::AccountAddress address{};
  int utime{};
  ton_http::types::bytes data{};
  ::ton_http::schemas::v2::InternalTransactionId transaction_id{};
  ton_http::types::int256 fee{};
  ton_http::types::int256 storage_fee{};
  ton_http::types::int256 other_fee{};
  ::ton_http::schemas::v2::ExtMessage in_msg{};
  std::vector<::ton_http::schemas::v2::ExtMessage> out_msgs{};
};


bool operator==(const ::ton_http::schemas::v2::ExtTransaction& lhs, const ::ton_http::schemas::v2::ExtTransaction& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtTransaction::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtTransaction& value
);


ExtTransaction::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type>
);


ExtTransaction Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction>
);


ExtTransaction::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type>
);


ExtTransaction::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtTransaction::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtTransaction& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ExtTransaction::_Type value);


struct ExtendedAddressInformation {
  enum class _Type {
    kFullaccountstate,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kFullaccountstate,
  };


  ::ton_http::schemas::v2::ExtendedAddressInformation::_Type _type{
      ::ton_http::schemas::v2::ExtendedAddressInformation::_Type::kFullaccountstate
  };
  ::ton_http::schemas::v2::AccountAddress address{};
  ton_http::types::int256 balance{};
  std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance> extra_currencies{};
  ::ton_http::schemas::v2::InternalTransactionId last_transaction_id{};
  ::ton_http::schemas::v2::TonBlockIdExt block_id{};
  int sync_utime{};
  ::ton_http::schemas::v2::AccountStateRaw account_state{};
  int revision{};
};


bool operator==(
    const ::ton_http::schemas::v2::ExtendedAddressInformation& lhs,
    const ::ton_http::schemas::v2::ExtendedAddressInformation& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtendedAddressInformation& value
);


ExtendedAddressInformation::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>
);


ExtendedAddressInformation Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation>
);


ExtendedAddressInformation::_Type FromString(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>
);


ExtendedAddressInformation::_Type Parse(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ExtendedAddressInformation& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ExtendedAddressInformation::_Type value);


struct LibraryEntry {
  enum class _Type {
    kSmcLibraryentry,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kSmcLibraryentry,
  };


  ::ton_http::schemas::v2::LibraryEntry::_Type _type{::ton_http::schemas::v2::LibraryEntry::_Type::kSmcLibraryentry};
  ton_http::types::ton_hash hash{};
  ton_http::types::bytes data{};
};


bool operator==(const ::ton_http::schemas::v2::LibraryEntry& lhs, const ::ton_http::schemas::v2::LibraryEntry& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryEntry::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryEntry& value
);


LibraryEntry::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type>
);


LibraryEntry Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry>
);


LibraryEntry::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type>
);


LibraryEntry::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::LibraryEntry::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::LibraryEntry& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::LibraryEntry::_Type value);


struct LibraryResult {
  enum class _Type {
    kSmcLibraryresult,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kSmcLibraryresult,
  };


  ::ton_http::schemas::v2::LibraryResult::_Type _type{::ton_http::schemas::v2::LibraryResult::_Type::kSmcLibraryresult};
  std::vector<::ton_http::schemas::v2::LibraryEntry> result{};
};


bool operator==(const ::ton_http::schemas::v2::LibraryResult& lhs, const ::ton_http::schemas::v2::LibraryResult& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryResult::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryResult& value
);


LibraryResult::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type>
);


LibraryResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult>
);


LibraryResult::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type>
);


LibraryResult::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::LibraryResult::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::LibraryResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::LibraryResult::_Type value);


using LookupBlock = ::ton_http::schemas::v2::TonBlockIdExt;


struct MasterchainBlockSignatures {
  enum class _Type {
    kBlocksBlocksignatures,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksBlocksignatures,
  };


  ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type _type{
      ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type::kBlocksBlocksignatures
  };
  ::ton_http::schemas::v2::TonBlockIdExt id{};
  std::vector<::ton_http::schemas::v2::BlockSignature> signatures{};
};


bool operator==(
    const ::ton_http::schemas::v2::MasterchainBlockSignatures& lhs,
    const ::ton_http::schemas::v2::MasterchainBlockSignatures& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainBlockSignatures& value
);


MasterchainBlockSignatures::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>
);


MasterchainBlockSignatures Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures>
);


MasterchainBlockSignatures::_Type FromString(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>
);


MasterchainBlockSignatures::_Type Parse(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MasterchainBlockSignatures& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MasterchainBlockSignatures::_Type value);


// Information about the latest masterchain block.
struct MasterchainInfo {
  enum class _Type {
    kBlocksMasterchaininfo,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksMasterchaininfo,
  };


  ::ton_http::schemas::v2::MasterchainInfo::_Type _type{
      ::ton_http::schemas::v2::MasterchainInfo::_Type::kBlocksMasterchaininfo
  };
  ::ton_http::schemas::v2::TonBlockIdExt last{};
  ton_http::types::ton_hash state_root_hash{};
  ::ton_http::schemas::v2::TonBlockIdExt init{};
};


bool operator==(
    const ::ton_http::schemas::v2::MasterchainInfo& lhs, const ::ton_http::schemas::v2::MasterchainInfo& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfo::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfo& value
);


MasterchainInfo::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type>
);


MasterchainInfo Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo>
);


MasterchainInfo::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type>
);


MasterchainInfo::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MasterchainInfo::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MasterchainInfo& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::MasterchainInfo::_Type value);


using MasterchainInfoRequest = ::ton_http::schemas::v2::EmptyRequest;


struct Message {
  enum class _Type {
    kRawMessage,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kRawMessage,
  };


  using Msg_Data = std::variant<
      ::ton_http::schemas::v2::MsgDataRaw,
      ::ton_http::schemas::v2::MsgDataText,
      ::ton_http::schemas::v2::MsgDataDecryptedText,
      ::ton_http::schemas::v2::MsgDataEncryptedText>;


  ::ton_http::schemas::v2::Message::_Type _type{::ton_http::schemas::v2::Message::_Type::kRawMessage};
  ton_http::types::ton_hash hash{};
  ::ton_http::schemas::v2::AccountAddress source{};
  ::ton_http::schemas::v2::AccountAddress destination{};
  ton_http::types::int256 value{};
  std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance> extra_currencies{};
  ton_http::types::int256 fwd_fee{};
  ton_http::types::int256 ihr_fee{};
  std::uint64_t created_lt{};
  ton_http::types::ton_hash body_hash{};
  ::ton_http::schemas::v2::Message::Msg_Data msg_data{};
};


bool operator==(const ::ton_http::schemas::v2::Message& lhs, const ::ton_http::schemas::v2::Message& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Message::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Message& value
);


Message::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type>
);


Message Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message>
);


Message::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type>
);


Message::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Message::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Message& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::Message::_Type value);


struct OutMsgQueueSize {
  enum class _Type {
    kBlocksOutmsgqueuesize,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksOutmsgqueuesize,
  };


  ::ton_http::schemas::v2::OutMsgQueueSize::_Type _type{
      ::ton_http::schemas::v2::OutMsgQueueSize::_Type::kBlocksOutmsgqueuesize
  };
  ::ton_http::schemas::v2::TonBlockIdExt id{};
  int size{};
};


bool operator==(
    const ::ton_http::schemas::v2::OutMsgQueueSize& lhs, const ::ton_http::schemas::v2::OutMsgQueueSize& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSize::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSize& value
);


OutMsgQueueSize::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type>
);


OutMsgQueueSize Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize>
);


OutMsgQueueSize::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type>
);


OutMsgQueueSize::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::OutMsgQueueSize::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::OutMsgQueueSize& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::OutMsgQueueSize::_Type value);


struct OutMsgQueueSizes {
  enum class _Type {
    kBlocksOutmsgqueuesizes,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksOutmsgqueuesizes,
  };


  ::ton_http::schemas::v2::OutMsgQueueSizes::_Type _type{
      ::ton_http::schemas::v2::OutMsgQueueSizes::_Type::kBlocksOutmsgqueuesizes
  };
  std::vector<::ton_http::schemas::v2::OutMsgQueueSize> shards{};
  int ext_msg_queue_size_limit{};
};


bool operator==(
    const ::ton_http::schemas::v2::OutMsgQueueSizes& lhs, const ::ton_http::schemas::v2::OutMsgQueueSizes& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSizes& value
);


OutMsgQueueSizes::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>
);


OutMsgQueueSizes Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes>
);


OutMsgQueueSizes::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>
);


OutMsgQueueSizes::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::OutMsgQueueSizes& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::OutMsgQueueSizes::_Type value);


using PackAddress = std::string;


struct ShardBlockLink {
  enum class _Type {
    kBlocksShardblocklink,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksShardblocklink,
  };


  ::ton_http::schemas::v2::ShardBlockLink::_Type _type{
      ::ton_http::schemas::v2::ShardBlockLink::_Type::kBlocksShardblocklink
  };
  ::ton_http::schemas::v2::TonBlockIdExt id{};
  ton_http::types::bytes proof{};
};


bool operator==(const ::ton_http::schemas::v2::ShardBlockLink& lhs, const ::ton_http::schemas::v2::ShardBlockLink& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockLink::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockLink& value
);


ShardBlockLink::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type>
);


ShardBlockLink Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink>
);


ShardBlockLink::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type>
);


ShardBlockLink::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShardBlockLink::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShardBlockLink& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ShardBlockLink::_Type value);


struct ShardBlockProof {
  enum class _Type {
    kBlocksShardblockproof,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksShardblockproof,
  };


  ::ton_http::schemas::v2::ShardBlockProof::_Type _type{
      ::ton_http::schemas::v2::ShardBlockProof::_Type::kBlocksShardblockproof
  };
  ::ton_http::schemas::v2::TonBlockIdExt from{};
  ::ton_http::schemas::v2::TonBlockIdExt mc_id{};
  std::vector<::ton_http::schemas::v2::ShardBlockLink> links{};
  std::vector<::ton_http::schemas::v2::BlockLinkBack> mc_proof{};
};


bool operator==(
    const ::ton_http::schemas::v2::ShardBlockProof& lhs, const ::ton_http::schemas::v2::ShardBlockProof& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockProof::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockProof& value
);


ShardBlockProof::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type>
);


ShardBlockProof Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof>
);


ShardBlockProof::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type>
);


ShardBlockProof::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShardBlockProof::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::ShardBlockProof& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::ShardBlockProof::_Type value);


struct Shards {
  enum class _Type {
    kBlocksShards,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kBlocksShards,
  };


  ::ton_http::schemas::v2::Shards::_Type _type{::ton_http::schemas::v2::Shards::_Type::kBlocksShards};
  std::vector<::ton_http::schemas::v2::TonBlockIdExt> shards{};
};


bool operator==(const ::ton_http::schemas::v2::Shards& lhs, const ::ton_http::schemas::v2::Shards& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Shards::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Shards& value
);


Shards::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type>
);


Shards Parse(
    USERVER_NAMESPACE::formats::json::Value json, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards>
);


Shards::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type>
);


Shards::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Shards::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Shards& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::Shards::_Type value);


// TonlibErrorResponse
struct TonlibErrorResponse {
  static constexpr auto kCodeMinimum = 100;


  static constexpr auto kCodeMaximum = 600;


  bool ok{false};
  std::optional<std::string> error{};
  std::optional<int> code{};
  std::optional<std::string> _extra{};
};


bool operator==(
    const ::ton_http::schemas::v2::TonlibErrorResponse& lhs, const ::ton_http::schemas::v2::TonlibErrorResponse& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonlibErrorResponse& value
);


TonlibErrorResponse Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibErrorResponse>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonlibErrorResponse& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


[[maybe_unused]] static constexpr USERVER_NAMESPACE::chaotic::OneOfStringSettings kTonlibObject_Settings = {
    "@type", USERVER_NAMESPACE::utils::TrivialSet([](auto selector) {
      return selector()
          .template Type<std::string_view>()
          .Case("utils.detectAddress")
          .Case("blocks.masterchainInfo")
          .Case("utils.detectedHash");
    })
};


using TonlibObject = std::variant<
    ::ton_http::schemas::v2::DetectAddress,
    ::ton_http::schemas::v2::MasterchainInfo,
    ::ton_http::schemas::v2::DetectHash>;


// TonlibResponse
struct TonlibResponse {
  using Result = std::variant<std::string, ::ton_http::schemas::v2::TonlibObject>;


  bool ok{true};
  ::ton_http::schemas::v2::TonlibResponse::Result result{};
  std::string _extra{};
};


bool operator==(const ::ton_http::schemas::v2::TonlibResponse& lhs, const ::ton_http::schemas::v2::TonlibResponse& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonlibResponse& value
);


TonlibResponse Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibResponse>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonlibResponse& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


struct Transaction {
  enum class _Type {
    kRawTransaction,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kRawTransaction,
  };


  ::ton_http::schemas::v2::Transaction::_Type _type{::ton_http::schemas::v2::Transaction::_Type::kRawTransaction};
  ::ton_http::schemas::v2::AccountAddress address{};
  ton_http::types::ton_addr account{};
  int utime{};
  ton_http::types::bytes data{};
  ::ton_http::schemas::v2::InternalTransactionId transaction_id{};
  ton_http::types::int256 fee{};
  ton_http::types::int256 storage_fee{};
  ton_http::types::int256 other_fee{};
  ::ton_http::schemas::v2::Message in_msg{};
  std::vector<::ton_http::schemas::v2::Message> out_msgs{};
};


bool operator==(const ::ton_http::schemas::v2::Transaction& lhs, const ::ton_http::schemas::v2::Transaction& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Transaction::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Transaction& value
);


Transaction::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type>
);


Transaction Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction>
);


Transaction::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type>
);


Transaction::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Transaction::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::Transaction& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::Transaction::_Type value);


using UnpackAddress = std::string;


struct WalletInformation {
  enum class _Type {
    kWalletinformation,
  };

  static constexpr _Type k_TypeValues[] = {
      _Type::kWalletinformation,
  };


  enum class Wallet_Type {
    kWalletV1R1,
    kWalletV1R2,
    kWalletV1R3,
    kWalletV2R1,
    kWalletV2R2,
    kWalletV3R1,
    kWalletV3R2,
    kWalletV4R1,
    kWalletV4R2,
    kWalletV5Beta,
    kWalletV5R1,
  };

  static constexpr Wallet_Type kWallet_TypeValues[] = {
      Wallet_Type::kWalletV1R1,
      Wallet_Type::kWalletV1R2,
      Wallet_Type::kWalletV1R3,
      Wallet_Type::kWalletV2R1,
      Wallet_Type::kWalletV2R2,
      Wallet_Type::kWalletV3R1,
      Wallet_Type::kWalletV3R2,
      Wallet_Type::kWalletV4R1,
      Wallet_Type::kWalletV4R2,
      Wallet_Type::kWalletV5Beta,
      Wallet_Type::kWalletV5R1,
  };


  ::ton_http::schemas::v2::WalletInformation::_Type _type{
      ::ton_http::schemas::v2::WalletInformation::_Type::kWalletinformation
  };
  bool wallet{};
  ton_http::types::int256 balance{};
  ::ton_http::schemas::v2::AccountStateEnum account_state{};
  ::ton_http::schemas::v2::InternalTransactionId last_transaction_id{};
  std::optional<::ton_http::schemas::v2::WalletInformation::Wallet_Type> wallet_type{};
  std::optional<int> seqno{};
  std::optional<int> wallet_id{};
  std::optional<bool> is_signature_allowed{};
};


bool operator==(
    const ::ton_http::schemas::v2::WalletInformation& lhs, const ::ton_http::schemas::v2::WalletInformation& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation::_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation::Wallet_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation& value
);


WalletInformation::_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type>
);


WalletInformation::Wallet_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
);


WalletInformation Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation>
);


WalletInformation::_Type FromString(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type>
);


WalletInformation::_Type Parse(
    std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type>
);


WalletInformation::Wallet_Type FromString(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
);


WalletInformation::Wallet_Type Parse(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::WalletInformation::_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::WalletInformation::Wallet_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::WalletInformation& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::WalletInformation::_Type value);


std::string ToString(::ton_http::schemas::v2::WalletInformation::Wallet_Type value);


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http


template <>
struct fmt::formatter<::ton_http::schemas::v2::AccountAddress::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::AccountAddress::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::AccountStateEnum> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::AccountStateEnum&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::AccountStateRaw::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::AccountStateRaw::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::InternalTransactionId::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::InternalTransactionId::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::TonBlockIdExt::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::TonBlockIdExt::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::AddressInformation::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::AddressInformation::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::BlockHeader::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::BlockHeader::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::BlockLinkBack::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::BlockLinkBack::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::BlockSignature::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::BlockSignature::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ShortTxId::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::ShortTxId::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::BlockTransactions::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::BlockTransactions::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::TvmCell::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::TvmCell::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ConfigInfo::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::ConfigInfo::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ConsensusBlock::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ConsensusBlock::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::DetectAddress::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::DetectAddress::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::DetectAddress::Given_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::DetectAddress::Given_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::DetectHash::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::DetectHash::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MsgDataRaw::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::MsgDataRaw::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MsgDataText::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::MsgDataText::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MsgDataDecryptedText::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MsgDataEncryptedText::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ExtMessage::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::ExtMessage::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ExtTransaction::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ExtTransaction::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ExtendedAddressInformation::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::LibraryEntry::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::LibraryEntry::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::LibraryResult::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::LibraryResult::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::MasterchainInfo::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::MasterchainInfo::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::Message::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::Message::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::OutMsgQueueSize::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::OutMsgQueueSize::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::OutMsgQueueSizes::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ShardBlockLink::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ShardBlockLink::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::ShardBlockProof::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::ShardBlockProof::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::Shards::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::Shards::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::Transaction::_Type> {
  fmt::format_context::iterator format(const ::ton_http::schemas::v2::Transaction::_Type&, fmt::format_context&) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::WalletInformation::_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::WalletInformation::_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};


template <>
struct fmt::formatter<::ton_http::schemas::v2::WalletInformation::Wallet_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::WalletInformation::Wallet_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};

