#pragma once

#include "v2.hpp"

#include <userver/chaotic/array.hpp>
#include <userver/chaotic/exception.hpp>
#include <userver/chaotic/object.hpp>
#include <userver/chaotic/primitive.hpp>
#include <userver/chaotic/validators.hpp>
#include <userver/chaotic/variant.hpp>
#include <userver/chaotic/with_type.hpp>
#include <userver/formats/json/serialize_variant.hpp>
#include <userver/formats/parse/common_containers.hpp>
#include <userver/formats/serialize/common_containers.hpp>
#include <userver/utils/trivial_map.hpp>


namespace ton_http {
namespace schemas {
namespace v2 {


static constexpr USERVER_NAMESPACE::utils::TrivialSet
    k__ton_http__schemas__v2__DetectAddressBase64Variant_PropertiesNames = [](auto selector) {
      return selector().template Type<std::string_view>().Case("b64").Case("b64url");
    };


template <typename Value>
::ton_http::schemas::v2::DetectAddressBase64Variant Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectAddressBase64Variant res;

  res.b64 = value["b64"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.b64url = value["b64url"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__DetectAddressBase64Variant_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
    k__ton_http__schemas__v2__DetectAddressResult__Given_Type_Mapping = [](auto selector) {
      return selector()
          .template Type<::ton_http::schemas::v2::DetectAddressResult::Given_Type, std::string_view>()
          .Case(::ton_http::schemas::v2::DetectAddressResult::Given_Type::kRawForm, "raw_form")
          .Case(::ton_http::schemas::v2::DetectAddressResult::Given_Type::kFriendlyBounceable, "friendly_bounceable")
          .Case(
              ::ton_http::schemas::v2::DetectAddressResult::Given_Type::kFriendlyNonBounceable,
              "friendly_non_bounceable"
          );
    };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectAddressResult_PropertiesNames =
    [](auto selector) {
      return selector()
          .template Type<std::string_view>()
          .Case("@type")
          .Case("raw_form")
          .Case("bounceable")
          .Case("non_bounceable")
          .Case("given_type")
          .Case("test_only");
    };


template <typename Value>
::ton_http::schemas::v2::DetectAddressResult::Given_Type Parse(
    Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult::Given_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DetectAddressResult__Given_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
      fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddressResult::Given_Type", value),
      val
  );
}


template <typename Value>
::ton_http::schemas::v2::DetectAddressResult Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressResult>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectAddressResult res;

  res._type = value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("utils.detectAddress");
  res.raw_form = value["raw_form"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.bounceable =
      value["bounceable"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>>();
  res.non_bounceable =
      value["non_bounceable"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>>();
  res.given_type =
      value["given_type"]
          .template As<
              USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressResult::Given_Type>>();
  res.test_only = value["test_only"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__DetectAddressResult_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectHashResult_PropertiesNames =
    [](auto selector) {
      return selector().template Type<std::string_view>().Case("@type").Case("b64").Case("b64url").Case("hex");
    };


template <typename Value>
::ton_http::schemas::v2::DetectHashResult Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHashResult>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectHashResult res;

  res._type = value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("utils.detectHash");
  res.b64 = value["b64"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.b64url = value["b64url"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.hex = value["hex"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__DetectHashResult_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonBlockIdExt_PropertiesNames =
    [](auto selector) {
      return selector()
          .template Type<std::string_view>()
          .Case("@type")
          .Case("workchain")
          .Case("shard")
          .Case("seqno")
          .Case("root_hash")
          .Case("file_hash");
    };


template <typename Value>
::ton_http::schemas::v2::TonBlockIdExt Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonBlockIdExt res;

  res._type = value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("ton.blockIdExt");
  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.shard =
      value["shard"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::shard_id>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.root_hash =
      value["root_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.file_hash =
      value["file_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__TonBlockIdExt_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MasterchainInfoResult_PropertiesNames =
    [](auto selector) {
      return selector()
          .template Type<std::string_view>()
          .Case("@type")
          .Case("last")
          .Case("state_root_hash")
          .Case("init");
    };


template <typename Value>
::ton_http::schemas::v2::MasterchainInfoResult Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfoResult>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MasterchainInfoResult res;

  res._type = value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("blocks.masterchainInfo");
  res.last = value["last"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.state_root_hash =
      value["state_root_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.init = value["init"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__MasterchainInfoResult_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonResponse_PropertiesNames =
    [](auto selector) {
      return selector().template Type<std::string_view>().Case("ok").Case("result").Case("error").Case("code").Case(
          "@extra"
      );
    };


template <typename Value>
::ton_http::schemas::v2::TonResponse Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonResponse>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonResponse res;

  res.ok = value["ok"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.result = value["result"]
                   .template As<std::optional<USERVER_NAMESPACE::chaotic::Variant<
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
                           std::vector<::ton_http::schemas::v2::TonObject>>>>>();
  res.error = value["error"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.code = value["code"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<int>>>();
  res._extra = value["@extra"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__TonResponse_PropertiesNames
  );

  return res;
}


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http

