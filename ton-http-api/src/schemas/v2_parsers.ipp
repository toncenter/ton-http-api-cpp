#pragma once

#include "v2.hpp"

#include <userver/chaotic/array.hpp>
#include <userver/chaotic/exception.hpp>
#include <userver/chaotic/object.hpp>
#include <userver/chaotic/primitive.hpp>
#include <userver/chaotic/validators.hpp>
#include <userver/chaotic/variant.hpp>
#include <userver/chaotic/with_type.hpp>
#include <userver/formats/common/merge.hpp>
#include <userver/formats/json/serialize_variant.hpp>
#include <userver/formats/parse/common_containers.hpp>
#include <userver/formats/serialize/common_containers.hpp>
#include <userver/utils/trivial_map.hpp>


namespace ton_http {
namespace schemas {
namespace v2 {


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountAddress___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountAddress::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountAddress::_Type::kAccountaddress, "accountAddress"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountAddress_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("account_address");
  };


template <typename Value>
::ton_http::schemas::v2::AccountAddress::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountAddress::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountAddress Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountAddress res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress::_Type>>(
      ::ton_http::schemas::v2::AccountAddress::_Type::kAccountaddress
    );
  res.account_address =
    value["account_address"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountAddress_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateRaw___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateRaw::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateRaw::_Type::kRawAccountstate, "raw.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateRaw_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("code").Case("data").Case("frozen_hash");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateRaw::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateRaw___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateRaw::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateRaw Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateRaw res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw::_Type>>(
      ::ton_http::schemas::v2::AccountStateRaw::_Type::kRawAccountstate
    );
  res.code = value["code"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.frozen_hash =
    value["frozen_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateRaw_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateWalletV3___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateWalletV3::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateWalletV3::_Type::kWalletV3Accountstate, "wallet.v3.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateWalletV3_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("wallet_id").Case("seqno");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletV3::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV3___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletV3::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletV3 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateWalletV3 res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV3::_Type>>(
        ::ton_http::schemas::v2::AccountStateWalletV3::_Type::kWalletV3Accountstate
      );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateWalletV3_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateWalletV4___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateWalletV4::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateWalletV4::_Type::kWalletV4Accountstate, "wallet.v4.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateWalletV4_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("wallet_id").Case("seqno");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletV4::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV4___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletV4::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletV4 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateWalletV4 res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV4::_Type>>(
        ::ton_http::schemas::v2::AccountStateWalletV4::_Type::kWalletV4Accountstate
      );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateWalletV4_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__AccountStateWalletHighloadV1___Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type, std::string_view>()
      .Case(
        ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type::kWalletHighloadV1Accountstate,
        "wallet.highload.v1.accountState"
      );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__AccountStateWalletHighloadV1_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("wallet_id").Case("seqno");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV1___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletHighloadV1 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateWalletHighloadV1 res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type>>(
        ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type::kWalletHighloadV1Accountstate
      );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateWalletHighloadV1_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__AccountStateWalletHighloadV2___Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type, std::string_view>()
      .Case(
        ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type::kWalletHighloadV2Accountstate,
        "wallet.highload.v2.accountState"
      );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__AccountStateWalletHighloadV2_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("wallet_id");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV2___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateWalletHighloadV2 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateWalletHighloadV2 res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type>>(
        ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type::kWalletHighloadV2Accountstate
      );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateWalletHighloadV2_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateDns___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateDns::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateDns::_Type::kDnsAccountstate, "dns.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateDns_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("wallet_id");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateDns::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateDns___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateDns::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateDns Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateDns res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateDns::_Type>>(
      ::ton_http::schemas::v2::AccountStateDns::_Type::kDnsAccountstate
    );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateDns_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__RWalletLimit___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::RWalletLimit::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::RWalletLimit::_Type::kRwalletLimit, "rwallet.limit"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__RWalletLimit_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("seconds").Case("value");
  };


template <typename Value>
::ton_http::schemas::v2::RWalletLimit::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__RWalletLimit___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::RWalletLimit::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::RWalletLimit Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::RWalletLimit res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletLimit::_Type>>(
      ::ton_http::schemas::v2::RWalletLimit::_Type::kRwalletLimit
    );
  res.seconds = value["seconds"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.value = value["value"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__RWalletLimit_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__RWalletConfig___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::RWalletConfig::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::RWalletConfig::_Type::kRwalletConfig, "rwallet.config"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__RWalletConfig_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("start_at").Case("limits");
  };


template <typename Value>
::ton_http::schemas::v2::RWalletConfig::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__RWalletConfig___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::RWalletConfig::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::RWalletConfig Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::RWalletConfig res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletConfig::_Type>>(
      ::ton_http::schemas::v2::RWalletConfig::_Type::kRwalletConfig
    );
  res.start_at = value["start_at"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.limits = value["limits"]
                 .template As<USERVER_NAMESPACE::chaotic::Array<
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletLimit>,
                   std::vector<::ton_http::schemas::v2::RWalletLimit>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__RWalletConfig_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateRWallet___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateRWallet::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateRWallet::_Type::kRwalletAccountstate, "rwallet.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateRWallet_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("wallet_id")
      .Case("seqno")
      .Case("unlocked_balance")
      .Case("config");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateRWallet::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateRWallet___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateRWallet::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateRWallet Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateRWallet res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRWallet::_Type>>(
        ::ton_http::schemas::v2::AccountStateRWallet::_Type::kRwalletAccountstate
      );
  res.wallet_id = value["wallet_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.unlocked_balance = value["unlocked_balance"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.config =
    value["config"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletConfig>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateRWallet_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__PChanConfig___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::PChanConfig::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::PChanConfig::_Type::kPchanConfig, "pchan.config"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__PChanConfig_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("alice_public_key")
      .Case("alice_address")
      .Case("bob_public_key")
      .Case("bob_address")
      .Case("init_timeout")
      .Case("close_timeout")
      .Case("channel_id");
  };


template <typename Value>
::ton_http::schemas::v2::PChanConfig::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__PChanConfig___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanConfig::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::PChanConfig Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::PChanConfig res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanConfig::_Type>>(
      ::ton_http::schemas::v2::PChanConfig::_Type::kPchanConfig
    );
  res.alice_public_key = value["alice_public_key"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.alice_address = value["alice_address"]
                        .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.bob_public_key = value["bob_public_key"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.bob_address =
    value["bob_address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.init_timeout = value["init_timeout"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.close_timeout = value["close_timeout"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.channel_id = value["channel_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__PChanConfig_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__PChanStateInit___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::PChanStateInit::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::PChanStateInit::_Type::kPchanStateinit, "pchan.stateInit"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__PChanStateInit_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("signed_A")
      .Case("signed_B")
      .Case("min_A")
      .Case("min_B")
      .Case("expire_at")
      .Case("A")
      .Case("B");
  };


template <typename Value>
::ton_http::schemas::v2::PChanStateInit::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__PChanStateInit___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStateInit::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::PChanStateInit Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::PChanStateInit res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateInit::_Type>>(
      ::ton_http::schemas::v2::PChanStateInit::_Type::kPchanStateinit
    );
  res.signed_A = value["signed_A"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.signed_B = value["signed_B"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.min_A = value["min_A"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.min_B = value["min_B"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.expire_at = value["expire_at"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.A = value["A"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.B = value["B"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__PChanStateInit_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__PChanStateClose___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::PChanStateClose::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::PChanStateClose::_Type::kPchanStateclose, "pchan.stateClose"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__PChanStateClose_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("signed_A")
      .Case("signed_B")
      .Case("min_A")
      .Case("min_B")
      .Case("expire_at")
      .Case("A")
      .Case("B");
  };


template <typename Value>
::ton_http::schemas::v2::PChanStateClose::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__PChanStateClose___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStateClose::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::PChanStateClose Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::PChanStateClose res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateClose::_Type>>(
      ::ton_http::schemas::v2::PChanStateClose::_Type::kPchanStateclose
    );
  res.signed_A = value["signed_A"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.signed_B = value["signed_B"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.min_A = value["min_A"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.min_B = value["min_B"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.expire_at = value["expire_at"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.A = value["A"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.B = value["B"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__PChanStateClose_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__PChanStatePayout___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::PChanStatePayout::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::PChanStatePayout::_Type::kPchanStatepayout, "pchan.statePayout"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__PChanStatePayout_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("A").Case("B");
  };


template <typename Value>
::ton_http::schemas::v2::PChanStatePayout::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__PChanStatePayout___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStatePayout::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::PChanStatePayout Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::PChanStatePayout res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStatePayout::_Type>>(
      ::ton_http::schemas::v2::PChanStatePayout::_Type::kPchanStatepayout
    );
  res.A = value["A"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.B = value["B"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__PChanStatePayout_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStatePChan___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStatePChan::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStatePChan::_Type::kPchanAccountstate, "pchan.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStatePChan_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("config").Case("state").Case("description");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStatePChan::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStatePChan___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStatePChan::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStatePChan Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStatePChan res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStatePChan::_Type>>(
                  ::ton_http::schemas::v2::AccountStatePChan::_Type::kPchanAccountstate
                );
  res.config =
    value["config"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanConfig>>();
  res.state = value["state"]
                .template As<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                  &::ton_http::schemas::v2::kPChanState_Settings,
                  USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateInit>,
                  USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateClose>,
                  USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStatePayout>>>();
  res.description = value["description"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStatePChan_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateUninited___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AccountStateUninited::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AccountStateUninited::_Type::kUninitedAccountstate, "uninited.accountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AccountStateUninited_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("frozen_hash");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateUninited::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateUninited___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateUninited::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AccountStateUninited Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AccountStateUninited res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateUninited::_Type>>(
        ::ton_http::schemas::v2::AccountStateUninited::_Type::kUninitedAccountstate
      );
  res.frozen_hash =
    value["frozen_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AccountStateUninited_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AccountStateEnum_Mapping =
  [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::AccountStateEnum, std::string_view>()
      .Case(::ton_http::schemas::v2::AccountStateEnum::kUninitialized, "uninitialized")
      .Case(::ton_http::schemas::v2::AccountStateEnum::kActive, "active")
      .Case(::ton_http::schemas::v2::AccountStateEnum::kFrozen, "frozen");
  };


template <typename Value>
::ton_http::schemas::v2::AccountStateEnum Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AccountStateEnum_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateEnum", value), val
  );
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__AddressWithSeqnoRequest_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("address").Case("seqno");
  };


template <typename Value>
::ton_http::schemas::v2::AddressWithSeqnoRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressWithSeqnoRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AddressWithSeqnoRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.seqno = value["seqno"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AddressWithSeqnoRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ExtraCurrencyBalance___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type::kExtracurrency, "extraCurrency"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ExtraCurrencyBalance_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("id").Case("amount");
  };


template <typename Value>
::ton_http::schemas::v2::ExtraCurrencyBalance::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ExtraCurrencyBalance___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ExtraCurrencyBalance Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ExtraCurrencyBalance res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>>(
        ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type::kExtracurrency
      );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.amount =
    value["amount"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ExtraCurrencyBalance_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__InternalTransactionId___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::InternalTransactionId::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::InternalTransactionId::_Type::kInternalTransactionid, "internal.transactionId"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__InternalTransactionId_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("lt").Case("hash");
  };


template <typename Value>
::ton_http::schemas::v2::InternalTransactionId::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__InternalTransactionId___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::InternalTransactionId::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::InternalTransactionId Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::InternalTransactionId res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId::_Type>>(
        ::ton_http::schemas::v2::InternalTransactionId::_Type::kInternalTransactionid
      );
  res.lt =
    value["lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__InternalTransactionId_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TonBlockIdExt___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::TonBlockIdExt::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::TonBlockIdExt::_Type::kTonBlockidext, "ton.blockIdExt"
    );
  };


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
::ton_http::schemas::v2::TonBlockIdExt::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TonBlockIdExt___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TonBlockIdExt::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TonBlockIdExt Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonBlockIdExt res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt::_Type>>(
      ::ton_http::schemas::v2::TonBlockIdExt::_Type::kTonBlockidext
    );
  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.shard =
    value["shard"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__AddressInformation___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::AddressInformation::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::AddressInformation::_Type::kRawFullaccountstate, "raw.fullAccountState"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AddressInformation_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("balance")
      .Case("extra_currencies")
      .Case("last_transaction_id")
      .Case("block_id")
      .Case("code")
      .Case("data")
      .Case("frozen_hash")
      .Case("sync_utime")
      .Case("state")
      .Case("suspended");
  };


template <typename Value>
::ton_http::schemas::v2::AddressInformation::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__AddressInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AddressInformation::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::AddressInformation Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AddressInformation res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AddressInformation::_Type>>(
                  ::ton_http::schemas::v2::AddressInformation::_Type::kRawFullaccountstate
                );
  res.balance =
    value["balance"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.extra_currencies = value["extra_currencies"]
                           .template As<USERVER_NAMESPACE::chaotic::Array<
                             USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
                             std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>>();
  res.last_transaction_id =
    value["last_transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.block_id =
    value["block_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.code = value["code"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.frozen_hash =
    value["frozen_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.sync_utime = value["sync_utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.state =
    value["state"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>>();
  res.suspended = value["suspended"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AddressInformation_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__AddressRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("address");
  };


template <typename Value>
::ton_http::schemas::v2::AddressRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::AddressRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__AddressRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__BlockHeader___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::BlockHeader::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::BlockHeader::_Type::kBlocksHeader, "blocks.header"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockHeader_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("id")
      .Case("global_id")
      .Case("version")
      .Case("after_merge")
      .Case("after_split")
      .Case("before_split")
      .Case("want_merge")
      .Case("want_split")
      .Case("validator_list_hash_short")
      .Case("catchain_seqno")
      .Case("min_ref_mc_seqno")
      .Case("is_key_block")
      .Case("prev_key_block_seqno")
      .Case("start_lt")
      .Case("end_lt")
      .Case("gen_utime")
      .Case("prev_blocks");
  };


template <typename Value>
::ton_http::schemas::v2::BlockHeader::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__BlockHeader___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockHeader::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::BlockHeader Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockHeader res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockHeader::_Type>>(
      ::ton_http::schemas::v2::BlockHeader::_Type::kBlocksHeader
    );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.global_id = value["global_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.version = value["version"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.after_merge = value["after_merge"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.after_split = value["after_split"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.before_split = value["before_split"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.want_merge = value["want_merge"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.want_split = value["want_split"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.validator_list_hash_short =
    value["validator_list_hash_short"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.catchain_seqno = value["catchain_seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.min_ref_mc_seqno = value["min_ref_mc_seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.is_key_block = value["is_key_block"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.prev_key_block_seqno = value["prev_key_block_seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.start_lt =
    value["start_lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.end_lt =
    value["end_lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.gen_utime = value["gen_utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.prev_blocks = value["prev_blocks"]
                      .template As<USERVER_NAMESPACE::chaotic::Array<
                        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
                        std::vector<::ton_http::schemas::v2::TonBlockIdExt>>>();


  res.extra = USERVER_NAMESPACE::chaotic::ExtractAdditionalPropertiesTrue(
    value, k__ton_http__schemas__v2__BlockHeader_PropertiesNames
  );


  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockHeaderRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("workchain")
      .Case("shard")
      .Case("seqno")
      .Case("root_hash")
      .Case("file_hash");
  };


template <typename Value>
::ton_http::schemas::v2::BlockHeaderRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeaderRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockHeaderRequest res;

  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.shard =
    value["shard"]
      .template As<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.root_hash =
    value["root_hash"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>>();
  res.file_hash =
    value["file_hash"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockHeaderRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__BlockLinkBack___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::BlockLinkBack::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::BlockLinkBack::_Type::kBlocksBlocklinkback, "blocks.blockLinkBack"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockLinkBack_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("to_key_block")
      .Case("from")
      .Case("to")
      .Case("dest_proof")
      .Case("proof")
      .Case("state_proof");
  };


template <typename Value>
::ton_http::schemas::v2::BlockLinkBack::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__BlockLinkBack___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockLinkBack::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::BlockLinkBack Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockLinkBack res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockLinkBack::_Type>>(
      ::ton_http::schemas::v2::BlockLinkBack::_Type::kBlocksBlocklinkback
    );
  res.to_key_block = value["to_key_block"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.from = value["from"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.to = value["to"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.dest_proof =
    value["dest_proof"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.proof = value["proof"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.state_proof =
    value["state_proof"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockLinkBack_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__BlockSignature___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::BlockSignature::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::BlockSignature::_Type::kBlocksSignature, "blocks.signature"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockSignature_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("node_id_short").Case("signature");
  };


template <typename Value>
::ton_http::schemas::v2::BlockSignature::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__BlockSignature___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockSignature::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::BlockSignature Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockSignature res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockSignature::_Type>>(
      ::ton_http::schemas::v2::BlockSignature::_Type::kBlocksSignature
    );
  res.node_id_short =
    value["node_id_short"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.signature =
    value["signature"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockSignature_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ShortTxId___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ShortTxId::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ShortTxId::_Type::kBlocksShorttxid, "blocks.shortTxId"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ShortTxId_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("mode").Case("account").Case("lt").Case(
      "hash"
    );
  };


template <typename Value>
::ton_http::schemas::v2::ShortTxId::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ShortTxId___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShortTxId::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ShortTxId Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ShortTxId res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShortTxId::_Type>>(
      ::ton_http::schemas::v2::ShortTxId::_Type::kBlocksShorttxid
    );
  res.mode = value["mode"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.account =
    value["account"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.lt =
    value["lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ShortTxId_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__BlockTransactions___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::BlockTransactions::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::BlockTransactions::_Type::kBlocksTransactions, "blocks.transactions"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockTransactions_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("id")
      .Case("req_count")
      .Case("incomplete")
      .Case("transactions");
  };


template <typename Value>
::ton_http::schemas::v2::BlockTransactions::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__BlockTransactions___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockTransactions::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::BlockTransactions Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockTransactions res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactions::_Type>>(
                  ::ton_http::schemas::v2::BlockTransactions::_Type::kBlocksTransactions
                );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.req_count = value["req_count"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.incomplete = value["incomplete"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.transactions = value["transactions"]
                       .template As<USERVER_NAMESPACE::chaotic::Array<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShortTxId>,
                         std::vector<::ton_http::schemas::v2::ShortTxId>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockTransactions_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MsgDataRaw___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MsgDataRaw::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MsgDataRaw::_Type::kMsgDataraw, "msg.dataRaw"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MsgDataRaw_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("body").Case("init_state");
  };


template <typename Value>
::ton_http::schemas::v2::MsgDataRaw::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MsgDataRaw___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataRaw::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MsgDataRaw Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MsgDataRaw res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw::_Type>>(
      ::ton_http::schemas::v2::MsgDataRaw::_Type::kMsgDataraw
    );
  res.body =
    value["body"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>>();
  res.init_state =
    value["init_state"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MsgDataRaw_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MsgDataText___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MsgDataText::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MsgDataText::_Type::kMsgDatatext, "msg.dataText"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MsgDataText_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("text");
  };


template <typename Value>
::ton_http::schemas::v2::MsgDataText::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MsgDataText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataText::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MsgDataText Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MsgDataText res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText::_Type>>(
      ::ton_http::schemas::v2::MsgDataText::_Type::kMsgDatatext
    );
  res.text = value["text"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MsgDataText_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MsgDataDecryptedText___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MsgDataDecryptedText::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MsgDataDecryptedText::_Type::kMsgDatadecryptedtext, "msg.dataDecryptedText"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MsgDataDecryptedText_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("text");
  };


template <typename Value>
::ton_http::schemas::v2::MsgDataDecryptedText::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MsgDataDecryptedText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataDecryptedText::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MsgDataDecryptedText Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MsgDataDecryptedText res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>>(
        ::ton_http::schemas::v2::MsgDataDecryptedText::_Type::kMsgDatadecryptedtext
      );
  res.text = value["text"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MsgDataDecryptedText_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MsgDataEncryptedText___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MsgDataEncryptedText::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MsgDataEncryptedText::_Type::kMsgDataencryptedtext, "msg.dataEncryptedText"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MsgDataEncryptedText_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("text");
  };


template <typename Value>
::ton_http::schemas::v2::MsgDataEncryptedText::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MsgDataEncryptedText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataEncryptedText::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MsgDataEncryptedText Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MsgDataEncryptedText res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>>(
        ::ton_http::schemas::v2::MsgDataEncryptedText::_Type::kMsgDataencryptedtext
      );
  res.text = value["text"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MsgDataEncryptedText_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MessageStd___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MessageStd::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MessageStd::_Type::kRawMessage, "raw.message"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MessageStd_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("hash")
      .Case("source")
      .Case("destination")
      .Case("value")
      .Case("extra_currencies")
      .Case("fwd_fee")
      .Case("ihr_fee")
      .Case("created_lt")
      .Case("body_hash")
      .Case("msg_data");
  };


template <typename Value>
::ton_http::schemas::v2::MessageStd::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MessageStd::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MessageStd___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MessageStd::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MessageStd Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MessageStd>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MessageStd res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MessageStd::_Type>>(
      ::ton_http::schemas::v2::MessageStd::_Type::kRawMessage
    );
  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.source =
    value["source"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.destination =
    value["destination"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.value = value["value"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.extra_currencies = value["extra_currencies"]
                           .template As<USERVER_NAMESPACE::chaotic::Array<
                             USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
                             std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>>();
  res.fwd_fee =
    value["fwd_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.ihr_fee =
    value["ihr_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.created_lt =
    value["created_lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.body_hash =
    value["body_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.msg_data = value["msg_data"]
                   .template As<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                     &::ton_http::schemas::v2::kMsgData_Settings,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MessageStd_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TransactionStd___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::TransactionStd::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::TransactionStd::_Type::kRawTransaction, "raw.transaction"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TransactionStd_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("utime")
      .Case("data")
      .Case("transaction_id")
      .Case("fee")
      .Case("storage_fee")
      .Case("other_fee")
      .Case("in_msg")
      .Case("out_msgs");
  };


template <typename Value>
::ton_http::schemas::v2::TransactionStd::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionStd::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TransactionStd___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TransactionStd::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TransactionStd Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionStd>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TransactionStd res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionStd::_Type>>(
      ::ton_http::schemas::v2::TransactionStd::_Type::kRawTransaction
    );
  res.address =
    value["address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.utime = value["utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.transaction_id =
    value["transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.fee = value["fee"]
              .template As<USERVER_NAMESPACE::chaotic::
                             WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.storage_fee =
    value["storage_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.other_fee =
    value["other_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.in_msg =
    value["in_msg"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MessageStd>>>();
  res.out_msgs = value["out_msgs"]
                   .template As<USERVER_NAMESPACE::chaotic::Array<
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MessageStd>,
                     std::vector<::ton_http::schemas::v2::MessageStd>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TransactionStd_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TransactionExt__P1___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::TransactionExt__P1::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::TransactionExt__P1::_Type::kRawTransactionext, "raw.transactionExt"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TransactionExt__P1_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("account");
  };


template <typename Value>
::ton_http::schemas::v2::TransactionExt__P1::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionExt__P1::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TransactionExt__P1___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TransactionExt__P1::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TransactionExt__P1 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionExt__P1>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TransactionExt__P1 res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionExt__P1::_Type>>(
                  ::ton_http::schemas::v2::TransactionExt__P1::_Type::kRawTransactionext
                );
  res.account =
    value["account"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TransactionExt__P1_PropertiesNames
  );

  return res;
}


template <typename Value>
::ton_http::schemas::v2::TransactionExt Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionExt>
) {
  return ::ton_http::schemas::v2::TransactionExt(
    value.template As<::ton_http::schemas::v2::TransactionStd>(),
    value.template As<::ton_http::schemas::v2::TransactionExt__P1>()
  );
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__BlockTransactionsExt___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::BlockTransactionsExt::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::BlockTransactionsExt::_Type::kBlocksTransactionsext, "blocks.transactionsExt"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__BlockTransactionsExt_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("id")
      .Case("req_count")
      .Case("incomplete")
      .Case("transactions");
  };


template <typename Value>
::ton_http::schemas::v2::BlockTransactionsExt::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactionsExt::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__BlockTransactionsExt___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockTransactionsExt::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::BlockTransactionsExt Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactionsExt>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockTransactionsExt res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactionsExt::_Type>>(
        ::ton_http::schemas::v2::BlockTransactionsExt::_Type::kBlocksTransactionsext
      );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.req_count = value["req_count"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.incomplete = value["incomplete"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.transactions = value["transactions"]
                       .template As<USERVER_NAMESPACE::chaotic::Array<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionExt>,
                         std::vector<::ton_http::schemas::v2::TransactionExt>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockTransactionsExt_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__BlockTransactionsRequest_PropertiesNames = [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("workchain")
      .Case("shard")
      .Case("seqno")
      .Case("root_hash")
      .Case("file_hash")
      .Case("after_lt")
      .Case("after_hash")
      .Case("count");
  };


template <typename Value>
::ton_http::schemas::v2::BlockTransactionsRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactionsRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::BlockTransactionsRequest res;

  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.shard =
    value["shard"]
      .template As<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.root_hash =
    value["root_hash"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>>();
  res.file_hash =
    value["file_hash"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>>();
  res.after_lt =
    value["after_lt"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>>();
  res.after_hash = value["after_hash"]
                     .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
                       USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                       ton_http::types::ton_addr_without_workchain>>>();
  res.count = value["count"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>(40);


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__BlockTransactionsRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__EmptyRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>();
  };


template <typename Value>
::ton_http::schemas::v2::EmptyRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::EmptyRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::EmptyRequest res;


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__EmptyRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TvmCell___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::TvmCell::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::TvmCell::_Type::kTvmCell, "tvm.cell"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TvmCell_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("bytes");
  };


template <typename Value>
::ton_http::schemas::v2::TvmCell::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TvmCell___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TvmCell::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TvmCell Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TvmCell res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TvmCell::_Type>>(
      ::ton_http::schemas::v2::TvmCell::_Type::kTvmCell
    );
  res.bytes = value["bytes"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(value, k__ton_http__schemas__v2__TvmCell_PropertiesNames);

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ConfigInfo___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ConfigInfo::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ConfigInfo::_Type::kConfiginfo, "configInfo"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ConfigInfo_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("config");
  };


template <typename Value>
::ton_http::schemas::v2::ConfigInfo::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ConfigInfo___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ConfigInfo::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ConfigInfo Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ConfigInfo res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConfigInfo::_Type>>(
      ::ton_http::schemas::v2::ConfigInfo::_Type::kConfiginfo
    );
  res.config = value["config"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TvmCell>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ConfigInfo_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ConfigParamRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("param");
  };


template <typename Value>
::ton_http::schemas::v2::ConfigParamRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigParamRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ConfigParamRequest res;

  res.param = value["param"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ConfigParamRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ConsensusBlock___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ConsensusBlock::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ConsensusBlock::_Type::kExtBlocksConsensusblock, "ext.blocks.consensusBlock"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ConsensusBlock_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("consensus_block").Case("timestamp");
  };


template <typename Value>
::ton_http::schemas::v2::ConsensusBlock::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ConsensusBlock___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ConsensusBlock::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ConsensusBlock Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ConsensusBlock res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConsensusBlock::_Type>>(
      ::ton_http::schemas::v2::ConsensusBlock::_Type::kExtBlocksConsensusblock
    );
  res.consensus_block = value["consensus_block"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.timestamp = value["timestamp"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ConsensusBlock_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__DetectAddressBase64Variant___Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type, std::string_view>()
      .Case(
        ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type::kExtUtilsDetectedaddressvariant,
        "ext.utils.detectedAddressVariant"
      );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__DetectAddressBase64Variant_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("b64").Case("b64url");
  };


template <typename Value>
::ton_http::schemas::v2::DetectAddressBase64Variant::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DetectAddressBase64Variant___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::DetectAddressBase64Variant Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectAddressBase64Variant res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type>>(
        ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type::kExtUtilsDetectedaddressvariant
      );
  res.b64 = value["b64"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.b64url = value["b64url"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DetectAddressBase64Variant_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DetectAddress___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DetectAddress::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DetectAddress::_Type::kExtUtilsDetectedaddress, "ext.utils.detectedAddress"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DetectAddress__Given_Type_Mapping =
  [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::DetectAddress::Given_Type, std::string_view>()
      .Case(::ton_http::schemas::v2::DetectAddress::Given_Type::kRawForm, "raw_form")
      .Case(::ton_http::schemas::v2::DetectAddress::Given_Type::kFriendlyBounceable, "friendly_bounceable")
      .Case(::ton_http::schemas::v2::DetectAddress::Given_Type::kFriendlyNonBounceable, "friendly_non_bounceable");
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectAddress_PropertiesNames =
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
::ton_http::schemas::v2::DetectAddress::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DetectAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddress::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DetectAddress::Given_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DetectAddress__Given_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddress::Given_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DetectAddress Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectAddress res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress::_Type>>(
      ::ton_http::schemas::v2::DetectAddress::_Type::kExtUtilsDetectedaddress
    );
  res.raw_form = value["raw_form"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.bounceable =
    value["bounceable"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>>();
  res.non_bounceable =
    value["non_bounceable"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>>();
  res.given_type =
    value["given_type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress::Given_Type>>();
  res.test_only = value["test_only"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DetectAddress_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DetectHash___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DetectHash::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DetectHash::_Type::kExtUtilsDetectedhash, "ext.utils.detectedHash"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectHash_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("b64").Case("b64url").Case("hex");
  };


template <typename Value>
::ton_http::schemas::v2::DetectHash::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DetectHash___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectHash::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DetectHash Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectHash res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash::_Type>>(
      ::ton_http::schemas::v2::DetectHash::_Type::kExtUtilsDetectedhash
    );
  res.b64 = value["b64"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.b64url = value["b64url"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.hex = value["hex"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DetectHash_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectHashRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("hash");
  };


template <typename Value>
::ton_http::schemas::v2::DetectHashRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHashRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectHashRequest res;

  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DetectHashRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__DnsRecordStorageAddress___Type_Mapping = [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type::kDnsStorageAddress, "dns_storage_address"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__DnsRecordStorageAddress_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("bag_id");
  };


template <typename Value>
::ton_http::schemas::v2::DnsRecordStorageAddress::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DnsRecordStorageAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DnsRecordStorageAddress Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsRecordStorageAddress res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type>>(
        ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type::kDnsStorageAddress
      );
  res.bag_id =
    value["bag_id"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DnsRecordStorageAddress_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__SmcAddr___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::SmcAddr::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::SmcAddr::_Type::kAddrStd, "addr_std"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__SmcAddr_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("workchain_id").Case("address");
  };


template <typename Value>
::ton_http::schemas::v2::SmcAddr::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__SmcAddr___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::SmcAddr::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::SmcAddr Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::SmcAddr res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr::_Type>>(
      ::ton_http::schemas::v2::SmcAddr::_Type::kAddrStd
    );
  res.workchain_id = value["workchain_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(value, k__ton_http__schemas__v2__SmcAddr_PropertiesNames);

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DnsRecordSmcAddress___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type::kDnsSmcAddress, "dns_smc_address"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DnsRecordSmcAddress_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("smc_addr");
  };


template <typename Value>
::ton_http::schemas::v2::DnsRecordSmcAddress::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DnsRecordSmcAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DnsRecordSmcAddress Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsRecordSmcAddress res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type>>(
        ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type::kDnsSmcAddress
      );
  res.smc_addr =
    value["smc_addr"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DnsRecordSmcAddress_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DnsRecordAdnlAddress___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type::kDnsAdnlAddress, "dns_adnl_address"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DnsRecordAdnlAddress_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("adnl_addr");
  };


template <typename Value>
::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DnsRecordAdnlAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DnsRecordAdnlAddress Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsRecordAdnlAddress res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type>>(
        ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type::kDnsAdnlAddress
      );
  res.adnl_addr =
    value["adnl_addr"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DnsRecordAdnlAddress_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DnsRecordNextResolver___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::DnsRecordNextResolver::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::DnsRecordNextResolver::_Type::kDnsNextResolver, "dns_next_resolver"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DnsRecordNextResolver_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("resolver");
  };


template <typename Value>
::ton_http::schemas::v2::DnsRecordNextResolver::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__DnsRecordNextResolver___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordNextResolver::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::DnsRecordNextResolver Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsRecordNextResolver res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver::_Type>>(
        ::ton_http::schemas::v2::DnsRecordNextResolver::_Type::kDnsNextResolver
      );
  res.resolver =
    value["resolver"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DnsRecordNextResolver_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DnsRecordSet_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("dns_next_resolver")
      .Case("wallet")
      .Case("site")
      .Case("storage");
  };


template <typename Value>
::ton_http::schemas::v2::DnsRecordSet Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSet>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsRecordSet res;

  res.dns_next_resolver =
    value["dns_next_resolver"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
        &::ton_http::schemas::v2::kDnsRecord_Settings,
        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>>>();
  res.wallet = value["wallet"]
                 .template As<std::optional<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                   &::ton_http::schemas::v2::kDnsRecord_Settings,
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>>>();
  res.site = value["site"]
               .template As<std::optional<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                 &::ton_http::schemas::v2::kDnsRecord_Settings,
                 USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
                 USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
                 USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
                 USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>>>();
  res.storage = value["storage"]
                  .template As<std::optional<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                    &::ton_http::schemas::v2::kDnsRecord_Settings,
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>>>();


  res.extra = USERVER_NAMESPACE::chaotic::ExtractAdditionalPropertiesTrue(
    value, k__ton_http__schemas__v2__DnsRecordSet_PropertiesNames
  );


  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DnsContent_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("domain").Case("data");
  };


template <typename Value>
::ton_http::schemas::v2::DnsContent Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsContent>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DnsContent res;

  res.domain = value["domain"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.data = value["data"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSet>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__DnsContent_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__EstimateFeeRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("address")
      .Case("body")
      .Case("init_code")
      .Case("init_data")
      .Case("ignore_chksig");
  };


template <typename Value>
::ton_http::schemas::v2::EstimateFeeRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::EstimateFeeRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::EstimateFeeRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.body = value["body"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.init_code =
    value["init_code"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>("");
  res.init_data =
    value["init_data"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>("");
  res.ignore_chksig = value["ignore_chksig"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>(true);


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__EstimateFeeRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__ExtendedAddressInformation___Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::ExtendedAddressInformation::_Type, std::string_view>()
      .Case(::ton_http::schemas::v2::ExtendedAddressInformation::_Type::kFullaccountstate, "fullAccountState");
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__ExtendedAddressInformation_PropertiesNames = [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("balance")
      .Case("extra_currencies")
      .Case("last_transaction_id")
      .Case("block_id")
      .Case("sync_utime")
      .Case("account_state")
      .Case("revision");
  };


template <typename Value>
::ton_http::schemas::v2::ExtendedAddressInformation::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ExtendedAddressInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtendedAddressInformation::_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::ExtendedAddressInformation Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ExtendedAddressInformation res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>>(
        ::ton_http::schemas::v2::ExtendedAddressInformation::_Type::kFullaccountstate
      );
  res.address =
    value["address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.balance =
    value["balance"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.extra_currencies = value["extra_currencies"]
                           .template As<USERVER_NAMESPACE::chaotic::Array<
                             USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
                             std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>>();
  res.last_transaction_id =
    value["last_transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.block_id =
    value["block_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.sync_utime = value["sync_utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>();
  res.account_state = value["account_state"]
                        .template As<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                          &::ton_http::schemas::v2::kAccountState_Settings,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV3>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV4>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV1>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV2>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateDns>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRWallet>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStatePChan>,
                          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateUninited>>>();
  res.revision = value["revision"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ExtendedAddressInformation_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TokenContentDict_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>();
  };


template <typename Value>
::ton_http::schemas::v2::TokenContentDict Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContentDict>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TokenContentDict res;


  res.extra = USERVER_NAMESPACE::chaotic::ExtractAdditionalPropertiesTrue(
    value, k__ton_http__schemas__v2__TokenContentDict_PropertiesNames
  );


  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TokenContent__Type_Mapping =
  [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::TokenContent::Type, std::string_view>()
      .Case(::ton_http::schemas::v2::TokenContent::Type::kOnchain, "onchain")
      .Case(::ton_http::schemas::v2::TokenContent::Type::kOffchain, "offchain");
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TokenContent_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("type").Case("data");
  };


template <typename Value>
::ton_http::schemas::v2::TokenContent::Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent::Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TokenContent__Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TokenContent::Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TokenContent Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TokenContent res;

  res.type =
    value["type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent::Type>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::Variant<
                 USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                 USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContentDict>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TokenContent_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__JettonMasterData___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::JettonMasterData::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::JettonMasterData::_Type::kExtTokensJettonmasterdata, "ext.tokens.jettonMasterData"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__JettonMasterData__Contract_Type_Mapping = [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::JettonMasterData::Contract_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::JettonMasterData::Contract_Type::kJettonMaster, "jetton_master"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__JettonMasterData_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("contract_type")
      .Case("total_supply")
      .Case("mintable")
      .Case("admin_address")
      .Case("jetton_content")
      .Case("jetton_wallet_code");
  };


template <typename Value>
::ton_http::schemas::v2::JettonMasterData::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__JettonMasterData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonMasterData::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::JettonMasterData::Contract_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::Contract_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__JettonMasterData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonMasterData::Contract_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::JettonMasterData Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JettonMasterData res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData::_Type>>(
      ::ton_http::schemas::v2::JettonMasterData::_Type::kExtTokensJettonmasterdata
    );
  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.contract_type =
    value["contract_type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData::Contract_Type>>(
        ::ton_http::schemas::v2::JettonMasterData::Contract_Type::kJettonMaster
      );
  res.total_supply =
    value["total_supply"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.mintable = value["mintable"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.admin_address =
    value["admin_address"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();
  res.jetton_content =
    value["jetton_content"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>>();
  res.jetton_wallet_code =
    value["jetton_wallet_code"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__JettonMasterData_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__JettonWalletData___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::JettonWalletData::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::JettonWalletData::_Type::kExtTokensJettonwalletdata, "ext.tokens.jettonWalletData"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__JettonWalletData__Contract_Type_Mapping = [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::JettonWalletData::Contract_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::JettonWalletData::Contract_Type::kJettonWallet, "jetton_wallet"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__JettonWalletData_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("contract_type")
      .Case("balance")
      .Case("owner")
      .Case("jetton")
      .Case("mintless_is_claimed")
      .Case("jetton_wallet_code");
  };


template <typename Value>
::ton_http::schemas::v2::JettonWalletData::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__JettonWalletData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonWalletData::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::JettonWalletData::Contract_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::Contract_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__JettonWalletData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonWalletData::Contract_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::JettonWalletData Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JettonWalletData res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData::_Type>>(
      ::ton_http::schemas::v2::JettonWalletData::_Type::kExtTokensJettonwalletdata
    );
  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.contract_type =
    value["contract_type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData::Contract_Type>>(
        ::ton_http::schemas::v2::JettonWalletData::Contract_Type::kJettonWallet
      );
  res.balance =
    value["balance"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.owner =
    value["owner"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.jetton =
    value["jetton"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.mintless_is_claimed =
    value["mintless_is_claimed"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();
  res.jetton_wallet_code =
    value["jetton_wallet_code"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__JettonWalletData_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonlibErrorResponse_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("ok")
      .Case("error")
      .Case("code")
      .Case("@extra")
      .Case("jsonrpc")
      .Case("id");
  };


template <typename Value>
::ton_http::schemas::v2::TonlibErrorResponse Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibErrorResponse>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonlibErrorResponse res;

  res.ok = value["ok"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>(false);
  res.error = value["error"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.code = value["code"]
               .template As<USERVER_NAMESPACE::chaotic::Primitive<
                 int,
                 USERVER_NAMESPACE::chaotic::Minimum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMinimum>,
                 USERVER_NAMESPACE::chaotic::Maximum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMaximum>>>();
  res._extra = value["@extra"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.jsonrpc = value["jsonrpc"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.id = value["id"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TonlibErrorResponse_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__JsonRpcErrorResponse__P0_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("jsonrpc").Case("id");
  };


template <typename Value>
::ton_http::schemas::v2::JsonRpcErrorResponse__P0 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcErrorResponse__P0>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JsonRpcErrorResponse__P0 res;

  res.jsonrpc = value["jsonrpc"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("2.0");
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__JsonRpcErrorResponse__P0_PropertiesNames
  );

  return res;
}


template <typename Value>
::ton_http::schemas::v2::JsonRpcErrorResponse Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcErrorResponse>
) {
  return ::ton_http::schemas::v2::JsonRpcErrorResponse(
    value.template As<::ton_http::schemas::v2::JsonRpcErrorResponse__P0>(),
    value.template As<::ton_http::schemas::v2::TonlibErrorResponse>()
  );
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__JsonRpcRequest__Params_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>();
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__JsonRpcRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("jsonrpc").Case("id").Case("method").Case("params");
  };


template <typename Value>
::ton_http::schemas::v2::JsonRpcRequest::Params Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcRequest::Params>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JsonRpcRequest::Params res;


  res.extra = USERVER_NAMESPACE::chaotic::ExtractAdditionalPropertiesTrue(
    value, k__ton_http__schemas__v2__JsonRpcRequest__Params_PropertiesNames
  );


  return res;
}


template <typename Value>
::ton_http::schemas::v2::JsonRpcRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JsonRpcRequest res;

  res.jsonrpc = value["jsonrpc"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("2.0");
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.method = value["method"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.params = value["params"]
                 .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JsonRpcRequest::Params>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__JsonRpcRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__WalletInformation___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::WalletInformation::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::WalletInformation::_Type::kExtAccountsWalletinformation, "ext.accounts.walletInformation"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__WalletInformation__Wallet_Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::WalletInformation::Wallet_Type, std::string_view>()
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV1R1, "wallet v1 r1")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV1R2, "wallet v1 r2")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV1R3, "wallet v1 r3")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV2R1, "wallet v2 r1")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV2R2, "wallet v2 r2")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV3R1, "wallet v3 r1")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV3R2, "wallet v3 r2")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV4R1, "wallet v4 r1")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV4R2, "wallet v4 r2")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV5Beta, "wallet v5 beta")
      .Case(::ton_http::schemas::v2::WalletInformation::Wallet_Type::kWalletV5R1, "wallet v5 r1");
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__WalletInformation_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("wallet")
      .Case("balance")
      .Case("account_state")
      .Case("last_transaction_id")
      .Case("wallet_type")
      .Case("seqno")
      .Case("wallet_id")
      .Case("is_signature_allowed");
  };


template <typename Value>
::ton_http::schemas::v2::WalletInformation::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__WalletInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::WalletInformation::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::WalletInformation::Wallet_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__WalletInformation__Wallet_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::WalletInformation::Wallet_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::WalletInformation Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::WalletInformation res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation::_Type>>(
                  ::ton_http::schemas::v2::WalletInformation::_Type::kExtAccountsWalletinformation
                );
  res.wallet = value["wallet"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.balance =
    value["balance"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.account_state =
    value["account_state"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>>();
  res.last_transaction_id =
    value["last_transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.wallet_type =
    value["wallet_type"]
      .template As<std::optional<
        USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation::Wallet_Type>>>();
  res.seqno = value["seqno"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>>>();
  res.wallet_id = value["wallet_id"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<int>>>();
  res.is_signature_allowed =
    value["is_signature_allowed"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__WalletInformation_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__NftCollectionData___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::NftCollectionData::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::NftCollectionData::_Type::kExtTokensNftcollectiondata, "ext.tokens.nftCollectionData"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__NftCollectionData__Contract_Type_Mapping = [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::NftCollectionData::Contract_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::NftCollectionData::Contract_Type::kNftCollection, "nft_collection"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__NftCollectionData_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("contract_type")
      .Case("next_item_index")
      .Case("owner_address")
      .Case("collection_content");
  };


template <typename Value>
::ton_http::schemas::v2::NftCollectionData::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__NftCollectionData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftCollectionData::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::NftCollectionData::Contract_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::Contract_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__NftCollectionData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftCollectionData::Contract_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::NftCollectionData Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::NftCollectionData res;

  res._type = value["@type"]
                .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData::_Type>>(
                  ::ton_http::schemas::v2::NftCollectionData::_Type::kExtTokensNftcollectiondata
                );
  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.contract_type =
    value["contract_type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData::Contract_Type>>(
        ::ton_http::schemas::v2::NftCollectionData::Contract_Type::kNftCollection
      );
  res.next_item_index =
    value["next_item_index"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.owner_address =
    value["owner_address"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();
  res.collection_content =
    value["collection_content"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__NftCollectionData_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__NftItemData___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::NftItemData::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::NftItemData::_Type::kExtTokensNftitemdata, "ext.tokens.nftItemData"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__NftItemData__Contract_Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::NftItemData::Contract_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::NftItemData::Contract_Type::kNftItem, "nft_item"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__NftItemData_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("contract_type")
      .Case("init")
      .Case("index")
      .Case("collection_address")
      .Case("owner_address")
      .Case("content");
  };


template <typename Value>
::ton_http::schemas::v2::NftItemData::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__NftItemData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftItemData::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::NftItemData::Contract_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::Contract_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__NftItemData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftItemData::Contract_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::NftItemData Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::NftItemData res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData::_Type>>(
      ::ton_http::schemas::v2::NftItemData::_Type::kExtTokensNftitemdata
    );
  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.contract_type =
    value["contract_type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData::Contract_Type>>(
        ::ton_http::schemas::v2::NftItemData::Contract_Type::kNftItem
      );
  res.init = value["init"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>();
  res.index = value["index"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.collection_address =
    value["collection_address"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();
  res.owner_address =
    value["owner_address"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>>();
  res.content = value["content"]
                  .template As<USERVER_NAMESPACE::chaotic::Variant<
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>,
                    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsContent>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__NftItemData_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MasterchainInfo___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::MasterchainInfo::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::MasterchainInfo::_Type::kBlocksMasterchaininfo, "blocks.masterchainInfo"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MasterchainInfo_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("last").Case("state_root_hash").Case("init");
  };


template <typename Value>
::ton_http::schemas::v2::MasterchainInfo::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MasterchainInfo___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MasterchainInfo::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::MasterchainInfo Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MasterchainInfo res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo::_Type>>(
      ::ton_http::schemas::v2::MasterchainInfo::_Type::kBlocksMasterchaininfo
    );
  res.last = value["last"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.state_root_hash =
    value["state_root_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.init = value["init"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MasterchainInfo_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
  k__ton_http__schemas__v2__MasterchainBlockSignatures___Type_Mapping = [](auto selector) {
    return selector()
      .template Type<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type, std::string_view>()
      .Case(
        ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type::kBlocksBlocksignatures, "blocks.blockSignatures"
      );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet
  k__ton_http__schemas__v2__MasterchainBlockSignatures_PropertiesNames = [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("id").Case("signatures");
  };


template <typename Value>
::ton_http::schemas::v2::MasterchainBlockSignatures::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__MasterchainBlockSignatures___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type", value),
    val
  );
}


template <typename Value>
::ton_http::schemas::v2::MasterchainBlockSignatures Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::MasterchainBlockSignatures res;

  res._type =
    value["@type"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>>(
        ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type::kBlocksBlocksignatures
      );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.signatures = value["signatures"]
                     .template As<USERVER_NAMESPACE::chaotic::Array<
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockSignature>,
                       std::vector<::ton_http::schemas::v2::BlockSignature>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__MasterchainBlockSignatures_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ShardBlockLink___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ShardBlockLink::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ShardBlockLink::_Type::kBlocksShardblocklink, "blocks.shardBlockLink"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ShardBlockLink_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("id").Case("proof");
  };


template <typename Value>
::ton_http::schemas::v2::ShardBlockLink::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ShardBlockLink___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShardBlockLink::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ShardBlockLink Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ShardBlockLink res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockLink::_Type>>(
      ::ton_http::schemas::v2::ShardBlockLink::_Type::kBlocksShardblocklink
    );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.proof = value["proof"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ShardBlockLink_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ShardBlockProof___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::ShardBlockProof::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::ShardBlockProof::_Type::kBlocksShardblockproof, "blocks.shardBlockProof"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ShardBlockProof_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("from").Case("mc_id").Case("links").Case(
      "mc_proof"
    );
  };


template <typename Value>
::ton_http::schemas::v2::ShardBlockProof::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ShardBlockProof___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShardBlockProof::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ShardBlockProof Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ShardBlockProof res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof::_Type>>(
      ::ton_http::schemas::v2::ShardBlockProof::_Type::kBlocksShardblockproof
    );
  res.from = value["from"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.mc_id =
    value["mc_id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.links = value["links"]
                .template As<USERVER_NAMESPACE::chaotic::Array<
                  USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockLink>,
                  std::vector<::ton_http::schemas::v2::ShardBlockLink>>>();
  res.mc_proof = value["mc_proof"]
                   .template As<USERVER_NAMESPACE::chaotic::Array<
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockLinkBack>,
                     std::vector<::ton_http::schemas::v2::BlockLinkBack>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ShardBlockProof_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__Shards___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::Shards::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::Shards::_Type::kBlocksShards, "blocks.shards"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__Shards_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("shards");
  };


template <typename Value>
::ton_http::schemas::v2::Shards::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__Shards___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Shards::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::Shards Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::Shards res;

  res._type = value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Shards::_Type>>(
    ::ton_http::schemas::v2::Shards::_Type::kBlocksShards
  );
  res.shards = value["shards"]
                 .template As<USERVER_NAMESPACE::chaotic::Array<
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
                   std::vector<::ton_http::schemas::v2::TonBlockIdExt>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(value, k__ton_http__schemas__v2__Shards_PropertiesNames);

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__OutMsgQueueSize___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::OutMsgQueueSize::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::OutMsgQueueSize::_Type::kBlocksOutmsgqueuesize, "blocks.outMsgQueueSize"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__OutMsgQueueSize_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("id").Case("size");
  };


template <typename Value>
::ton_http::schemas::v2::OutMsgQueueSize::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSize___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::OutMsgQueueSize::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::OutMsgQueueSize Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::OutMsgQueueSize res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSize::_Type>>(
      ::ton_http::schemas::v2::OutMsgQueueSize::_Type::kBlocksOutmsgqueuesize
    );
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>>();
  res.size = value["size"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__OutMsgQueueSize_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__OutMsgQueueSizes___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::OutMsgQueueSizes::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::OutMsgQueueSizes::_Type::kBlocksOutmsgqueuesizes, "blocks.outMsgQueueSizes"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__OutMsgQueueSizes_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("shards").Case("ext_msg_queue_size_limit");
  };


template <typename Value>
::ton_http::schemas::v2::OutMsgQueueSizes::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSizes___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::OutMsgQueueSizes::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::OutMsgQueueSizes Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::OutMsgQueueSizes res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>>(
      ::ton_http::schemas::v2::OutMsgQueueSizes::_Type::kBlocksOutmsgqueuesizes
    );
  res.shards = value["shards"]
                 .template As<USERVER_NAMESPACE::chaotic::Array<
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSize>,
                   std::vector<::ton_http::schemas::v2::OutMsgQueueSize>>>();
  res.ext_msg_queue_size_limit =
    value["ext_msg_queue_size_limit"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__OutMsgQueueSizes_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__Message___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::Message::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::Message::_Type::kExtMessage, "ext.message"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__Message_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("hash")
      .Case("source")
      .Case("destination")
      .Case("value")
      .Case("extra_currencies")
      .Case("fwd_fee")
      .Case("ihr_fee")
      .Case("created_lt")
      .Case("body_hash")
      .Case("msg_data")
      .Case("message")
      .Case("message_decode_error");
  };


template <typename Value>
::ton_http::schemas::v2::Message::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__Message___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Message::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::Message Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::Message res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message::_Type>>(
      ::ton_http::schemas::v2::Message::_Type::kExtMessage
    );
  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.source =
    value["source"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.destination =
    value["destination"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.value = value["value"]
                .template As<USERVER_NAMESPACE::chaotic::
                               WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.extra_currencies = value["extra_currencies"]
                           .template As<USERVER_NAMESPACE::chaotic::Array<
                             USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
                             std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>>();
  res.fwd_fee =
    value["fwd_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.ihr_fee =
    value["ihr_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.created_lt =
    value["created_lt"]
      .template As<
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>>();
  res.body_hash =
    value["body_hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.msg_data = value["msg_data"]
                   .template As<USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                     &::ton_http::schemas::v2::kMsgData_Settings,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>>();
  res.message = value["message"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.message_decode_error =
    value["message_decode_error"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(value, k__ton_http__schemas__v2__Message_PropertiesNames);

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__Transaction___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::Transaction::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::Transaction::_Type::kExtTransaction, "ext.transaction"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__Transaction_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("address")
      .Case("account")
      .Case("utime")
      .Case("data")
      .Case("transaction_id")
      .Case("fee")
      .Case("storage_fee")
      .Case("other_fee")
      .Case("in_msg")
      .Case("out_msgs");
  };


template <typename Value>
::ton_http::schemas::v2::Transaction::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__Transaction___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Transaction::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::Transaction Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::Transaction res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Transaction::_Type>>(
      ::ton_http::schemas::v2::Transaction::_Type::kExtTransaction
    );
  res.address =
    value["address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.account =
    value["account"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.utime = value["utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.transaction_id =
    value["transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.fee = value["fee"]
              .template As<USERVER_NAMESPACE::chaotic::
                             WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.storage_fee =
    value["storage_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.other_fee =
    value["other_fee"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>>();
  res.in_msg = value["in_msg"]
                 .template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>>>();
  res.out_msgs = value["out_msgs"]
                   .template As<USERVER_NAMESPACE::chaotic::Array<
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>,
                     std::vector<::ton_http::schemas::v2::Message>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__Transaction_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__TransactionsStd___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::TransactionsStd::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::TransactionsStd::_Type::kRawTransactions, "raw.transactions"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TransactionsStd_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("@type")
      .Case("transactions")
      .Case("previous_transaction_id");
  };


template <typename Value>
::ton_http::schemas::v2::TransactionsStd::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionsStd::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__TransactionsStd___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TransactionsStd::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::TransactionsStd Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionsStd>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TransactionsStd res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionsStd::_Type>>(
      ::ton_http::schemas::v2::TransactionsStd::_Type::kRawTransactions
    );
  res.transactions = value["transactions"]
                       .template As<USERVER_NAMESPACE::chaotic::Array<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionStd>,
                         std::vector<::ton_http::schemas::v2::TransactionStd>>>();
  res.previous_transaction_id =
    value["previous_transaction_id"]
      .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TransactionsStd_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonlibResponse_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("ok").Case("result").Case("@extra").Case("jsonrpc").Case(
      "id"
    );
  };


template <typename Value>
::ton_http::schemas::v2::TonlibResponse Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibResponse>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonlibResponse res;

  res.ok = value["ok"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>(true);
  res.result = value["result"]
                 .template As<USERVER_NAMESPACE::chaotic::Variant<
                   USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>,
                   USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                     &::ton_http::schemas::v2::kTonlibObject_Settings,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AddressInformation>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtendedAddressInformation>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainBlockSignatures>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConsensusBlock>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Shards>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockHeader>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSizes>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactions>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactionsExt>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Transaction>,
                     USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionsStd>>,
                   USERVER_NAMESPACE::chaotic::Array<
                     USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                       &::ton_http::schemas::v2::kTonlibObject_Settings,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AddressInformation>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtendedAddressInformation>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainBlockSignatures>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConsensusBlock>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Shards>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockHeader>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSizes>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactions>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactionsExt>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Transaction>,
                       USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TransactionsStd>>,
                     std::vector<::ton_http::schemas::v2::TonlibObject>>>>();
  res._extra = value["@extra"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.jsonrpc = value["jsonrpc"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.id = value["id"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TonlibResponse_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__JsonRpcResponse__P0_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("jsonrpc").Case("id");
  };


template <typename Value>
::ton_http::schemas::v2::JsonRpcResponse__P0 Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcResponse__P0>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::JsonRpcResponse__P0 res;

  res.jsonrpc = value["jsonrpc"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>("2.0");
  res.id = value["id"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__JsonRpcResponse__P0_PropertiesNames
  );

  return res;
}


template <typename Value>
::ton_http::schemas::v2::JsonRpcResponse Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcResponse>
) {
  return ::ton_http::schemas::v2::JsonRpcResponse(
    value.template As<::ton_http::schemas::v2::JsonRpcResponse__P0>(),
    value.template As<::ton_http::schemas::v2::TonlibResponse>()
  );
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__LibrariesRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("libraries");
  };


template <typename Value>
::ton_http::schemas::v2::LibrariesRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibrariesRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::LibrariesRequest res;

  res.libraries = value["libraries"]
                    .template As<USERVER_NAMESPACE::chaotic::Array<
                      USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>,
                      std::vector<ton_http::types::ton_hash>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__LibrariesRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__LibraryEntry___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::LibraryEntry::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::LibraryEntry::_Type::kSmcLibraryentry, "smc.libraryEntry"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__LibraryEntry_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("hash").Case("data");
  };


template <typename Value>
::ton_http::schemas::v2::LibraryEntry::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__LibraryEntry___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::LibraryEntry::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::LibraryEntry Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::LibraryEntry res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryEntry::_Type>>(
      ::ton_http::schemas::v2::LibraryEntry::_Type::kSmcLibraryentry
    );
  res.hash =
    value["hash"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.data = value["data"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__LibraryEntry_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__LibraryResult___Type_Mapping =
  [](auto selector) {
    return selector().template Type<::ton_http::schemas::v2::LibraryResult::_Type, std::string_view>().Case(
      ::ton_http::schemas::v2::LibraryResult::_Type::kSmcLibraryresult, "smc.libraryResult"
    );
  };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__LibraryResult_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("@type").Case("result");
  };


template <typename Value>
::ton_http::schemas::v2::LibraryResult::_Type Parse(
  Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__LibraryResult___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::LibraryResult::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::LibraryResult Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::LibraryResult res;

  res._type =
    value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryResult::_Type>>(
      ::ton_http::schemas::v2::LibraryResult::_Type::kSmcLibraryresult
    );
  res.result = value["result"]
                 .template As<USERVER_NAMESPACE::chaotic::Array<
                   USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryEntry>,
                   std::vector<::ton_http::schemas::v2::LibraryEntry>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__LibraryResult_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__LookupBlockRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("workchain")
      .Case("shard")
      .Case("seqno")
      .Case("lt")
      .Case("unixtime");
  };


template <typename Value>
::ton_http::schemas::v2::LookupBlockRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LookupBlockRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::LookupBlockRequest res;

  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.shard =
    value["shard"]
      .template As<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>();
  res.seqno = value["seqno"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>>();
  res.lt =
    value["lt"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>>();
  res.unixtime = value["unixtime"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__LookupBlockRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__SeqnoRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("seqno");
  };


template <typename Value>
::ton_http::schemas::v2::SeqnoRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SeqnoRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::SeqnoRequest res;

  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__SeqnoRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__RunGetMethodRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("address").Case("method").Case("stack");
  };


template <typename Value>
::ton_http::schemas::v2::RunGetMethodRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RunGetMethodRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::RunGetMethodRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.method = value["method"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.stack = value["stack"]
                .template As<USERVER_NAMESPACE::chaotic::
                               Array<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::vector<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__RunGetMethodRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__SendBocRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("boc");
  };


template <typename Value>
::ton_http::schemas::v2::SendBocRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SendBocRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::SendBocRequest res;

  res.boc = value["boc"]
              .template As<USERVER_NAMESPACE::chaotic::
                             WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__SendBocRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__SendQueryRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("address")
      .Case("body")
      .Case("init_code")
      .Case("init_data");
  };


template <typename Value>
::ton_http::schemas::v2::SendQueryRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SendQueryRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::SendQueryRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.body = value["body"]
               .template As<USERVER_NAMESPACE::chaotic::
                              WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.init_code =
    value["init_code"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>("");
  res.init_data =
    value["init_data"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>("");


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__SendQueryRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ShardBlockProofRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("workchain")
      .Case("shard")
      .Case("seqno")
      .Case("from_seqno");
  };


template <typename Value>
::ton_http::schemas::v2::ShardBlockProofRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProofRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ShardBlockProofRequest res;

  res.workchain = value["workchain"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.shard =
    value["shard"]
      .template As<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>();
  res.seqno = value["seqno"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.from_seqno =
    value["from_seqno"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__ShardBlockProofRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TransactionsRequest_PropertiesNames =
  [](auto selector) {
    return selector()
      .template Type<std::string_view>()
      .Case("address")
      .Case("lt")
      .Case("hash")
      .Case("to_lt")
      .Case("archival")
      .Case("limit");
  };


template <typename Value>
::ton_http::schemas::v2::TransactionsRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionsRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TransactionsRequest res;

  res.address =
    value["address"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.lt =
    value["lt"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>>();
  res.hash =
    value["hash"]
      .template As<
        std::optional<USERVER_NAMESPACE::chaotic::
                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>>();
  res.to_lt =
    value["to_lt"]
      .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>>();
  res.archival = value["archival"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();
  res.limit = value["limit"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>(10);


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TransactionsRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TryLocateTxRequest_PropertiesNames =
  [](auto selector) {
    return selector().template Type<std::string_view>().Case("source").Case("destination").Case("created_lt");
  };


template <typename Value>
::ton_http::schemas::v2::TryLocateTxRequest Parse(
  Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TryLocateTxRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TryLocateTxRequest res;

  res.source =
    value["source"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.destination =
    value["destination"]
      .template As<USERVER_NAMESPACE::chaotic::
                     WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.created_lt =
    value["created_lt"]
      .template As<USERVER_NAMESPACE::chaotic::WithType<
        USERVER_NAMESPACE::chaotic::Variant<
          USERVER_NAMESPACE::chaotic::Primitive<std::string>,
          USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
        std::int64_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
    value, k__ton_http__schemas__v2__TryLocateTxRequest_PropertiesNames
  );

  return res;
}


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http

