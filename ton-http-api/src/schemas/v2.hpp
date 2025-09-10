#pragma once

#include "v2_fwd.hpp"


#include <fmt/core.h>
#include <cstdint>
#include <optional>
#include <string>
#include <userver/chaotic/io/std/vector.hpp>
#include <userver/chaotic/io/ton_http/types/shard_id.hpp>
#include <userver/chaotic/io/ton_http/types/ton_addr.hpp>
#include <userver/chaotic/io/ton_http/types/ton_hash.hpp>
#include <userver/chaotic/oneof_with_discriminator.hpp>
#include <userver/formats/json/serialize_variant.hpp>
#include <userver/formats/parse/variant.hpp>
#include <variant>


#include <userver/chaotic/type_bundle_hpp.hpp>


namespace ton_http {
namespace schemas {
namespace v2 {


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
struct DetectAddressResult {
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


  std::string _type{"utils.detectAddress"};
  std::string raw_form{};
  ::ton_http::schemas::v2::DetectAddressBase64Variant bounceable{};
  ::ton_http::schemas::v2::DetectAddressBase64Variant non_bounceable{};
  ::ton_http::schemas::v2::DetectAddressResult::Given_Type given_type{};
  bool test_only{};
};


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressResult& lhs, const ::ton_http::schemas::v2::DetectAddressResult& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressResult::Given_Type& value
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressResult& value
);


DetectAddressResult::Given_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type>
);


DetectAddressResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult>
);


DetectAddressResult::Given_Type FromString(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type>
);


DetectAddressResult::Given_Type Parse(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddressResult::Given_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddressResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


std::string ToString(::ton_http::schemas::v2::DetectAddressResult::Given_Type value);


struct DetectHashResult {
  std::string _type{"utils.detectHash"};
  std::optional<std::string> b64{};
  std::optional<std::string> b64url{};
  std::optional<std::string> hex{};
};


bool operator==(
    const ::ton_http::schemas::v2::DetectHashResult& lhs, const ::ton_http::schemas::v2::DetectHashResult& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHashResult& value
);


DetectHashResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHashResult>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectHashResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


using TonShardId = std::string;


using TonHash = std::string;


// Extended block identifier.
struct TonBlockIdExt {
  std::string _type{"ton.blockIdExt"};
  int workchain{};
  ton_http::types::shard_id shard{};
  int seqno{};
  ton_http::types::ton_hash root_hash{};
  ton_http::types::ton_hash file_hash{};
};


bool operator==(const ::ton_http::schemas::v2::TonBlockIdExt& lhs, const ::ton_http::schemas::v2::TonBlockIdExt& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt& value
);


TonBlockIdExt Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonBlockIdExt& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


// Information about the latest masterchain block.
struct MasterchainInfoResult {
  std::string _type{"blocks.masterchainInfo"};
  ::ton_http::schemas::v2::TonBlockIdExt last{};
  ton_http::types::ton_hash state_root_hash{};
  ::ton_http::schemas::v2::TonBlockIdExt init{};
};


bool operator==(
    const ::ton_http::schemas::v2::MasterchainInfoResult& lhs, const ::ton_http::schemas::v2::MasterchainInfoResult& rhs
);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfoResult& value
);


MasterchainInfoResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfoResult>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::MasterchainInfoResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


using TonAddr = std::string;


[[maybe_unused]] static constexpr USERVER_NAMESPACE::chaotic::OneOfStringSettings kTonObject_Settings = {
    "@type", USERVER_NAMESPACE::utils::TrivialSet([](auto selector) {
      return selector().template Type<std::string_view>().Case("ton.blockIdExt").Case("blocks.masterchainInfo");
    })
};


using TonObject = std::variant<::ton_http::schemas::v2::TonBlockIdExt, ::ton_http::schemas::v2::MasterchainInfoResult>;


// TonResponse
struct TonResponse {
  using Result =
      std::variant<std::string, ::ton_http::schemas::v2::TonObject, std::vector<::ton_http::schemas::v2::TonObject>>;


  bool ok{};
  std::optional<::ton_http::schemas::v2::TonResponse::Result> result{};
  std::optional<std::string> error{};
  std::optional<int> code{};
  std::string _extra{};
};


bool operator==(const ::ton_http::schemas::v2::TonResponse& lhs, const ::ton_http::schemas::v2::TonResponse& rhs);


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonResponse& value
);


TonResponse Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonResponse>
);


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::TonResponse& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
);


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http


template <>
struct fmt::formatter<::ton_http::schemas::v2::DetectAddressResult::Given_Type> {
  fmt::format_context::iterator format(
      const ::ton_http::schemas::v2::DetectAddressResult::Given_Type&, fmt::format_context&
  ) const;

  constexpr fmt::format_parse_context::iterator parse(fmt::format_parse_context& ctx) {
    return ctx.begin();
  }
};

