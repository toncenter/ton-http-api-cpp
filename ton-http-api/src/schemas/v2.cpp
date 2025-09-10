#include "v2.hpp"

#include <userver/chaotic/type_bundle_cpp.hpp>

#include "v2_parsers.ipp"


namespace ton_http {
namespace schemas {
namespace v2 {


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressBase64Variant& lhs,
    const ::ton_http::schemas::v2::DetectAddressBase64Variant& rhs
) {
  return lhs.b64 == rhs.b64 && lhs.b64url == rhs.b64url && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressBase64Variant& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectAddressBase64Variant Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::DetectAddressBase64Variant& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["b64"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64};

  vb["b64url"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64url};


  return vb.ExtractValue();
}


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressResult& lhs, const ::ton_http::schemas::v2::DetectAddressResult& rhs
) {
  return lhs._type == rhs._type && lhs.raw_form == rhs.raw_form && lhs.bounceable == rhs.bounceable &&
      lhs.non_bounceable == rhs.non_bounceable && lhs.given_type == rhs.given_type && lhs.test_only == rhs.test_only &&
      true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressResult::Given_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressResult& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectAddressResult::Given_Type Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DetectAddressResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DetectAddressResult::Given_Type FromString(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type>
) {
  const auto result = k__ton_http__schemas__v2__DetectAddressResult__Given_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
      fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddressResult::Given_Type", value)
  );
}

::ton_http::schemas::v2::DetectAddressResult::Given_Type Parse(
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    const ::ton_http::schemas::v2::DetectAddressResult::Given_Type& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::DetectAddressResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._type};

  vb["raw_form"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.raw_form};

  vb["bounceable"] =
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>{value.bounceable};

  vb["non_bounceable"] =
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>{value.non_bounceable};

  vb["given_type"] =
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressResult::Given_Type>{value.given_type};

  vb["test_only"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.test_only};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DetectAddressResult::Given_Type value) {
  const auto result = k__ton_http__schemas__v2__DetectAddressResult__Given_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
    const ::ton_http::schemas::v2::DetectHashResult& lhs, const ::ton_http::schemas::v2::DetectHashResult& rhs
) {
  return lhs._type == rhs._type && lhs.b64 == rhs.b64 && lhs.b64url == rhs.b64url && lhs.hex == rhs.hex && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHashResult& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectHashResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHashResult> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::DetectHashResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._type};

  if (value.b64) {
    vb["b64"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.b64};
  }

  if (value.b64url) {
    vb["b64url"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.b64url};
  }

  if (value.hex) {
    vb["hex"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.hex};
  }


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::TonBlockIdExt& lhs, const ::ton_http::schemas::v2::TonBlockIdExt& rhs) {
  return lhs._type == rhs._type && lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno &&
      lhs.root_hash == rhs.root_hash && lhs.file_hash == rhs.file_hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TonBlockIdExt Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::TonBlockIdExt& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._type};

  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.workchain};

  vb["shard"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::shard_id>{value.shard};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.seqno};

  vb["root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.root_hash};

  vb["file_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.file_hash};


  return vb.ExtractValue();
}


bool operator==(
    const ::ton_http::schemas::v2::MasterchainInfoResult& lhs, const ::ton_http::schemas::v2::MasterchainInfoResult& rhs
) {
  return lhs._type == rhs._type && lhs.last == rhs.last && lhs.state_root_hash == rhs.state_root_hash &&
      lhs.init == rhs.init && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfoResult& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MasterchainInfoResult Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfoResult> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::MasterchainInfoResult& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._type};

  vb["last"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.last};

  vb["state_root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.state_root_hash};

  vb["init"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.init};


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::TonResponse& lhs, const ::ton_http::schemas::v2::TonResponse& rhs) {
  return lhs.ok == rhs.ok && lhs.result == rhs.result && lhs.error == rhs.error && lhs.code == rhs.code &&
      lhs._extra == rhs._extra && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonResponse& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TonResponse Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonResponse> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::TonResponse& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["ok"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.ok};

  if (value.result) {
    vb["result"] = USERVER_NAMESPACE::chaotic::Variant<
        USERVER_NAMESPACE::chaotic::Primitive<std::string>,
        USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
            &::ton_http::schemas::v2::kTonObject_Settings,
            USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
            USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfoResult>>,
        USERVER_NAMESPACE::chaotic::Array<
            USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                &::ton_http::schemas::v2::kTonObject_Settings,
                USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
                USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfoResult>>,
            std::vector<::ton_http::schemas::v2::TonObject>>>{*value.result};
  }

  if (value.error) {
    vb["error"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.error};
  }

  if (value.code) {
    vb["code"] = USERVER_NAMESPACE::chaotic::Primitive<int>{*value.code};
  }

  vb["@extra"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._extra};


  return vb.ExtractValue();
}


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DetectAddressResult::Given_Type>::format(
    const ::ton_http::schemas::v2::DetectAddressResult::Given_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}

