#include "v2.hpp"

#include <userver/chaotic/type_bundle_cpp.hpp>

#include "v2_parsers.ipp"


namespace ton_http {
namespace schemas {
namespace v2 {


bool operator==(
  const ::ton_http::schemas::v2::AccountAddress& lhs, const ::ton_http::schemas::v2::AccountAddress& rhs
) {
  return lhs._type == rhs._type && lhs.account_address == rhs.account_address && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountAddress::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountAddress& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountAddress::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountAddress Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountAddress::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountAddress::_Type", value)
  );
}

::ton_http::schemas::v2::AccountAddress::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountAddress::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountAddress::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountAddress& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress::_Type>{value._type};

  if (value.account_address) {
    vb["account_address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{*value.account_address};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountAddress::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountAddress___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateRaw& lhs, const ::ton_http::schemas::v2::AccountStateRaw& rhs
) {
  return lhs._type == rhs._type && lhs.code == rhs.code && lhs.data == rhs.data && lhs.frozen_hash == rhs.frozen_hash &&
    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRaw::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRaw& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateRaw::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateRaw Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateRaw::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateRaw___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateRaw::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateRaw::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRaw::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateRaw::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateRaw& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw::_Type>{value._type};

  vb["code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.code
    };

  vb["data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.data
    };

  vb["frozen_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.frozen_hash
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateRaw::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateRaw___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateWalletV3& lhs, const ::ton_http::schemas::v2::AccountStateWalletV3& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && lhs.seqno == rhs.seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletV3::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletV3& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateWalletV3::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateWalletV3 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateWalletV3::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV3___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletV3::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateWalletV3::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV3::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateWalletV3::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateWalletV3& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV3::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateWalletV3::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV3___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateWalletV4& lhs, const ::ton_http::schemas::v2::AccountStateWalletV4& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && lhs.seqno == rhs.seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletV4::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletV4& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateWalletV4::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateWalletV4 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateWalletV4::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV4___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletV4::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateWalletV4::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletV4::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateWalletV4::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateWalletV4& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV4::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateWalletV4::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletV4___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV1& lhs,
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV1& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && lhs.seqno == rhs.seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletHighloadV1& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateWalletHighloadV1::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateWalletHighloadV1 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV1___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateWalletHighloadV1& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV1___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV2& lhs,
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV2& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateWalletHighloadV2& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateWalletHighloadV2::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateWalletHighloadV2 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV2___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateWalletHighloadV2& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateWalletHighloadV2___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateDns& lhs, const ::ton_http::schemas::v2::AccountStateDns& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateDns::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateDns& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateDns::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateDns Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateDns::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateDns___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateDns::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateDns::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateDns::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateDns::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateDns& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateDns::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateDns::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateDns___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::RWalletLimit& lhs, const ::ton_http::schemas::v2::RWalletLimit& rhs) {
  return lhs._type == rhs._type && lhs.seconds == rhs.seconds && lhs.value == rhs.value && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::RWalletLimit::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::RWalletLimit& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


RWalletLimit::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


RWalletLimit Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::RWalletLimit::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit::_Type>
) {
  const auto result = k__ton_http__schemas__v2__RWalletLimit___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::RWalletLimit::_Type", value)
  );
}

::ton_http::schemas::v2::RWalletLimit::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletLimit::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::RWalletLimit::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::RWalletLimit& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletLimit::_Type>{value._type};

  vb["seconds"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seconds};

  vb["value"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.value};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::RWalletLimit::_Type value) {
  const auto result = k__ton_http__schemas__v2__RWalletLimit___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::RWalletConfig& lhs, const ::ton_http::schemas::v2::RWalletConfig& rhs) {
  return lhs._type == rhs._type && lhs.start_at == rhs.start_at && lhs.limits == rhs.limits && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::RWalletConfig::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::RWalletConfig& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


RWalletConfig::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


RWalletConfig Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::RWalletConfig::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig::_Type>
) {
  const auto result = k__ton_http__schemas__v2__RWalletConfig___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::RWalletConfig::_Type", value)
  );
}

::ton_http::schemas::v2::RWalletConfig::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RWalletConfig::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::RWalletConfig::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::RWalletConfig& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletConfig::_Type>{value._type};

  vb["start_at"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.start_at};

  vb["limits"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletLimit>,
    std::vector<::ton_http::schemas::v2::RWalletLimit>>{value.limits};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::RWalletConfig::_Type value) {
  const auto result = k__ton_http__schemas__v2__RWalletConfig___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateRWallet& lhs, const ::ton_http::schemas::v2::AccountStateRWallet& rhs
) {
  return lhs._type == rhs._type && lhs.wallet_id == rhs.wallet_id && lhs.seqno == rhs.seqno &&
    lhs.unlocked_balance == rhs.unlocked_balance && lhs.config == rhs.config && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRWallet::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateRWallet& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateRWallet::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateRWallet Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateRWallet::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateRWallet___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateRWallet::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateRWallet::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateRWallet::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateRWallet::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateRWallet& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRWallet::_Type>{value._type};

  vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.wallet_id};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};

  vb["unlocked_balance"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.unlocked_balance};

  vb["config"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::RWalletConfig>{value.config};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateRWallet::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateRWallet___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::PChanConfig& lhs, const ::ton_http::schemas::v2::PChanConfig& rhs) {
  return lhs._type == rhs._type && lhs.alice_public_key == rhs.alice_public_key &&
    lhs.alice_address == rhs.alice_address && lhs.bob_public_key == rhs.bob_public_key &&
    lhs.bob_address == rhs.bob_address && lhs.init_timeout == rhs.init_timeout &&
    lhs.close_timeout == rhs.close_timeout && lhs.channel_id == rhs.channel_id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanConfig::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanConfig& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


PChanConfig::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


PChanConfig Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::PChanConfig::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig::_Type>
) {
  const auto result = k__ton_http__schemas__v2__PChanConfig___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanConfig::_Type", value)
  );
}

::ton_http::schemas::v2::PChanConfig::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanConfig::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::PChanConfig::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::PChanConfig& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanConfig::_Type>{value._type};

  vb["alice_public_key"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.alice_public_key};

  vb["alice_address"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.alice_address};

  vb["bob_public_key"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.bob_public_key};

  vb["bob_address"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.bob_address};

  vb["init_timeout"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.init_timeout};

  vb["close_timeout"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.close_timeout};

  vb["channel_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.channel_id};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::PChanConfig::_Type value) {
  const auto result = k__ton_http__schemas__v2__PChanConfig___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::PChanStateInit& lhs, const ::ton_http::schemas::v2::PChanStateInit& rhs
) {
  return lhs._type == rhs._type && lhs.signed_A == rhs.signed_A && lhs.signed_B == rhs.signed_B &&
    lhs.min_A == rhs.min_A && lhs.min_B == rhs.min_B && lhs.expire_at == rhs.expire_at && lhs.A == rhs.A &&
    lhs.B == rhs.B && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStateInit::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStateInit& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


PChanStateInit::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


PChanStateInit Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::PChanStateInit::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit::_Type>
) {
  const auto result = k__ton_http__schemas__v2__PChanStateInit___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStateInit::_Type", value)
  );
}

::ton_http::schemas::v2::PChanStateInit::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateInit::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::PChanStateInit::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::PChanStateInit& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateInit::_Type>{value._type};

  vb["signed_A"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.signed_A};

  vb["signed_B"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.signed_B};

  vb["min_A"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.min_A};

  vb["min_B"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.min_B};

  vb["expire_at"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.expire_at};

  vb["A"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.A};

  vb["B"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.B};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::PChanStateInit::_Type value) {
  const auto result = k__ton_http__schemas__v2__PChanStateInit___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::PChanStateClose& lhs, const ::ton_http::schemas::v2::PChanStateClose& rhs
) {
  return lhs._type == rhs._type && lhs.signed_A == rhs.signed_A && lhs.signed_B == rhs.signed_B &&
    lhs.min_A == rhs.min_A && lhs.min_B == rhs.min_B && lhs.expire_at == rhs.expire_at && lhs.A == rhs.A &&
    lhs.B == rhs.B && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStateClose::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStateClose& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


PChanStateClose::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


PChanStateClose Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::PChanStateClose::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose::_Type>
) {
  const auto result = k__ton_http__schemas__v2__PChanStateClose___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStateClose::_Type", value)
  );
}

::ton_http::schemas::v2::PChanStateClose::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStateClose::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::PChanStateClose::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::PChanStateClose& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateClose::_Type>{value._type};

  vb["signed_A"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.signed_A};

  vb["signed_B"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.signed_B};

  vb["min_A"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.min_A};

  vb["min_B"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.min_B};

  vb["expire_at"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.expire_at};

  vb["A"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.A};

  vb["B"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.B};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::PChanStateClose::_Type value) {
  const auto result = k__ton_http__schemas__v2__PChanStateClose___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::PChanStatePayout& lhs, const ::ton_http::schemas::v2::PChanStatePayout& rhs
) {
  return lhs._type == rhs._type && lhs.A == rhs.A && lhs.B == rhs.B && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStatePayout::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::PChanStatePayout& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


PChanStatePayout::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


PChanStatePayout Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::PChanStatePayout::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout::_Type>
) {
  const auto result = k__ton_http__schemas__v2__PChanStatePayout___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::PChanStatePayout::_Type", value)
  );
}

::ton_http::schemas::v2::PChanStatePayout::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::PChanStatePayout::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::PChanStatePayout::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::PChanStatePayout& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStatePayout::_Type>{value._type};

  vb["A"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.A};

  vb["B"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.B};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::PChanStatePayout::_Type value) {
  const auto result = k__ton_http__schemas__v2__PChanStatePayout___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStatePChan& lhs, const ::ton_http::schemas::v2::AccountStatePChan& rhs
) {
  return lhs._type == rhs._type && lhs.config == rhs.config && lhs.state == rhs.state &&
    lhs.description == rhs.description && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStatePChan::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStatePChan& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStatePChan::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStatePChan Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStatePChan::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStatePChan___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStatePChan::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStatePChan::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStatePChan::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStatePChan::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStatePChan& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStatePChan::_Type>{value._type};

  vb["config"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanConfig>{value.config};

  vb["state"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
    &::ton_http::schemas::v2::kPChanState_Settings,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateInit>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStateClose>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::PChanStatePayout>>{value.state};

  vb["description"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.description};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStatePChan::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStatePChan___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AccountStateUninited& lhs, const ::ton_http::schemas::v2::AccountStateUninited& rhs
) {
  return lhs._type == rhs._type && lhs.frozen_hash == rhs.frozen_hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateUninited::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateUninited& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AccountStateUninited::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AccountStateUninited Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateUninited::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateUninited___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateUninited::_Type", value)
  );
}

::ton_http::schemas::v2::AccountStateUninited::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateUninited::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateUninited::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AccountStateUninited& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateUninited::_Type>{value._type};

  vb["frozen_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.frozen_hash
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateUninited::_Type value) {
  const auto result = k__ton_http__schemas__v2__AccountStateUninited___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AccountStateEnum& value
) {
  return lh << ToString(value);
}


AccountStateEnum Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AccountStateEnum FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum>
) {
  const auto result = k__ton_http__schemas__v2__AccountStateEnum_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AccountStateEnum", value)
  );
}

::ton_http::schemas::v2::AccountStateEnum Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AccountStateEnum> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AccountStateEnum& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AccountStateEnum value) {
  const auto result = k__ton_http__schemas__v2__AccountStateEnum_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AddressWithSeqnoRequest& lhs,
  const ::ton_http::schemas::v2::AddressWithSeqnoRequest& rhs
) {
  return lhs.address == rhs.address && lhs.seqno == rhs.seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressWithSeqnoRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AddressWithSeqnoRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressWithSeqnoRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AddressWithSeqnoRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  if (value.seqno) {
    vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{*value.seqno};
  }


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::ExtraCurrencyBalance& lhs, const ::ton_http::schemas::v2::ExtraCurrencyBalance& rhs
) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.amount == rhs.amount && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtraCurrencyBalance& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ExtraCurrencyBalance::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ExtraCurrencyBalance Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ExtraCurrencyBalance::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ExtraCurrencyBalance___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type", value)
  );
}

::ton_http::schemas::v2::ExtraCurrencyBalance::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ExtraCurrencyBalance& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.id};

  vb["amount"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.amount
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ExtraCurrencyBalance::_Type value) {
  const auto result = k__ton_http__schemas__v2__ExtraCurrencyBalance___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::InternalTransactionId& lhs, const ::ton_http::schemas::v2::InternalTransactionId& rhs
) {
  return lhs._type == rhs._type && lhs.lt == rhs.lt && lhs.hash == rhs.hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::InternalTransactionId::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::InternalTransactionId& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


InternalTransactionId::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


InternalTransactionId Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::InternalTransactionId::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type>
) {
  const auto result = k__ton_http__schemas__v2__InternalTransactionId___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::InternalTransactionId::_Type", value)
  );
}

::ton_http::schemas::v2::InternalTransactionId::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::InternalTransactionId::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::InternalTransactionId::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::InternalTransactionId& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId::_Type>{value._type};

  vb["lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{value.lt};

  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::InternalTransactionId::_Type value) {
  const auto result = k__ton_http__schemas__v2__InternalTransactionId___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::TonBlockIdExt& lhs, const ::ton_http::schemas::v2::TonBlockIdExt& rhs) {
  return lhs._type == rhs._type && lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno &&
    lhs.root_hash == rhs.root_hash && lhs.file_hash == rhs.file_hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonBlockIdExt& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TonBlockIdExt::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


TonBlockIdExt Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::TonBlockIdExt::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type>
) {
  const auto result = k__ton_http__schemas__v2__TonBlockIdExt___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TonBlockIdExt::_Type", value)
  );
}

::ton_http::schemas::v2::TonBlockIdExt::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonBlockIdExt::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::TonBlockIdExt::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TonBlockIdExt& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt::_Type>{value._type};

  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.workchain};

  vb["shard"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>{value.shard};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.seqno};

  vb["root_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.root_hash
    };

  vb["file_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.file_hash
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::TonBlockIdExt::_Type value) {
  const auto result = k__ton_http__schemas__v2__TonBlockIdExt___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AddressInformation& lhs, const ::ton_http::schemas::v2::AddressInformation& rhs
) {
  return lhs._type == rhs._type && lhs.balance == rhs.balance && lhs.extra_currencies == rhs.extra_currencies &&
    lhs.last_transaction_id == rhs.last_transaction_id && lhs.block_id == rhs.block_id && lhs.code == rhs.code &&
    lhs.data == rhs.data && lhs.frozen_hash == rhs.frozen_hash && lhs.sync_utime == rhs.sync_utime &&
    lhs.state == rhs.state && lhs.suspended == rhs.suspended && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressInformation::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressInformation& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AddressInformation::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


AddressInformation Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::AddressInformation::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type>
) {
  const auto result = k__ton_http__schemas__v2__AddressInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::AddressInformation::_Type", value)
  );
}

::ton_http::schemas::v2::AddressInformation::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressInformation::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::AddressInformation::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AddressInformation& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AddressInformation::_Type>{value._type};

  vb["balance"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.balance
    };

  vb["extra_currencies"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
    std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>{value.extra_currencies};

  vb["last_transaction_id"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>{value.last_transaction_id};

  vb["block_id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.block_id};

  vb["code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.code
    };

  vb["data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.data
    };

  vb["frozen_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.frozen_hash
    };

  vb["sync_utime"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.sync_utime};

  vb["state"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>{value.state};

  if (value.suspended) {
    vb["suspended"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{*value.suspended};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::AddressInformation::_Type value) {
  const auto result = k__ton_http__schemas__v2__AddressInformation___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::AddressRequest& lhs, const ::ton_http::schemas::v2::AddressRequest& rhs
) {
  return lhs.address == rhs.address && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::AddressRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


AddressRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::AddressRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::AddressRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::BlockHeader& lhs, const ::ton_http::schemas::v2::BlockHeader& rhs) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.global_id == rhs.global_id && lhs.version == rhs.version &&
    lhs.after_merge == rhs.after_merge && lhs.after_split == rhs.after_split && lhs.before_split == rhs.before_split &&
    lhs.want_merge == rhs.want_merge && lhs.want_split == rhs.want_split &&
    lhs.validator_list_hash_short == rhs.validator_list_hash_short && lhs.catchain_seqno == rhs.catchain_seqno &&
    lhs.min_ref_mc_seqno == rhs.min_ref_mc_seqno && lhs.is_key_block == rhs.is_key_block &&
    lhs.prev_key_block_seqno == rhs.prev_key_block_seqno && lhs.start_lt == rhs.start_lt && lhs.end_lt == rhs.end_lt &&
    lhs.gen_utime == rhs.gen_utime && lhs.prev_blocks == rhs.prev_blocks && lhs.extra == rhs.extra &&

    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockHeader::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockHeader& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockHeader::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


BlockHeader Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::BlockHeader::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type>
) {
  const auto result = k__ton_http__schemas__v2__BlockHeader___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockHeader::_Type", value)
  );
}

::ton_http::schemas::v2::BlockHeader::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeader::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::BlockHeader::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockHeader& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = value.extra;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockHeader::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.id};

  vb["global_id"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.global_id};

  vb["version"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.version};

  vb["after_merge"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.after_merge};

  vb["after_split"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.after_split};

  vb["before_split"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.before_split};

  vb["want_merge"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.want_merge};

  vb["want_split"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.want_split};

  vb["validator_list_hash_short"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.validator_list_hash_short};

  vb["catchain_seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.catchain_seqno};

  vb["min_ref_mc_seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.min_ref_mc_seqno};

  vb["is_key_block"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.is_key_block};

  vb["prev_key_block_seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.prev_key_block_seqno};

  vb["start_lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{
      value.start_lt
    };

  vb["end_lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{
      value.end_lt
    };

  vb["gen_utime"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.gen_utime};

  vb["prev_blocks"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
    std::vector<::ton_http::schemas::v2::TonBlockIdExt>>{value.prev_blocks};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::BlockHeader::_Type value) {
  const auto result = k__ton_http__schemas__v2__BlockHeader___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::BlockHeaderRequest& lhs, const ::ton_http::schemas::v2::BlockHeaderRequest& rhs
) {
  return lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno &&
    lhs.root_hash == rhs.root_hash && lhs.file_hash == rhs.file_hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockHeaderRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockHeaderRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockHeaderRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockHeaderRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.workchain};

  vb["shard"] = USERVER_NAMESPACE::chaotic::WithType<
    USERVER_NAMESPACE::chaotic::Variant<
      USERVER_NAMESPACE::chaotic::Primitive<std::string>,
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
    std::int64_t>{value.shard};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};

  if (value.root_hash) {
    vb["root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.root_hash};
  }

  if (value.file_hash) {
    vb["file_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.file_hash};
  }


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::BlockLinkBack& lhs, const ::ton_http::schemas::v2::BlockLinkBack& rhs) {
  return lhs._type == rhs._type && lhs.to_key_block == rhs.to_key_block && lhs.from == rhs.from && lhs.to == rhs.to &&
    lhs.dest_proof == rhs.dest_proof && lhs.proof == rhs.proof && lhs.state_proof == rhs.state_proof && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockLinkBack::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockLinkBack& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockLinkBack::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


BlockLinkBack Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::BlockLinkBack::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type>
) {
  const auto result = k__ton_http__schemas__v2__BlockLinkBack___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockLinkBack::_Type", value)
  );
}

::ton_http::schemas::v2::BlockLinkBack::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockLinkBack::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::BlockLinkBack::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockLinkBack& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockLinkBack::_Type>{value._type};

  vb["to_key_block"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.to_key_block};

  vb["from"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.from};

  vb["to"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.to};

  vb["dest_proof"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.dest_proof
    };

  vb["proof"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.proof
    };

  vb["state_proof"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.state_proof
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::BlockLinkBack::_Type value) {
  const auto result = k__ton_http__schemas__v2__BlockLinkBack___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::BlockSignature& lhs, const ::ton_http::schemas::v2::BlockSignature& rhs
) {
  return lhs._type == rhs._type && lhs.node_id_short == rhs.node_id_short && lhs.signature == rhs.signature && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockSignature::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockSignature& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockSignature::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


BlockSignature Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::BlockSignature::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type>
) {
  const auto result = k__ton_http__schemas__v2__BlockSignature___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockSignature::_Type", value)
  );
}

::ton_http::schemas::v2::BlockSignature::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockSignature::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::BlockSignature::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockSignature& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockSignature::_Type>{value._type};

  vb["node_id_short"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.node_id_short
    };

  vb["signature"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.signature
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::BlockSignature::_Type value) {
  const auto result = k__ton_http__schemas__v2__BlockSignature___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::ShortTxId& lhs, const ::ton_http::schemas::v2::ShortTxId& rhs) {
  return lhs._type == rhs._type && lhs.mode == rhs.mode && lhs.account == rhs.account && lhs.lt == rhs.lt &&
    lhs.hash == rhs.hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShortTxId::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShortTxId& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ShortTxId::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ShortTxId Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ShortTxId::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ShortTxId___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShortTxId::_Type", value)
  );
}

::ton_http::schemas::v2::ShortTxId::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShortTxId::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ShortTxId::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ShortTxId& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShortTxId::_Type>{value._type};

  vb["mode"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.mode};

  vb["account"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.account
    };

  vb["lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{value.lt};

  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ShortTxId::_Type value) {
  const auto result = k__ton_http__schemas__v2__ShortTxId___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::BlockTransactions& lhs, const ::ton_http::schemas::v2::BlockTransactions& rhs
) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.req_count == rhs.req_count &&
    lhs.incomplete == rhs.incomplete && lhs.transactions == rhs.transactions && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockTransactions::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockTransactions& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockTransactions::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


BlockTransactions Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::BlockTransactions::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type>
) {
  const auto result = k__ton_http__schemas__v2__BlockTransactions___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::BlockTransactions::_Type", value)
  );
}

::ton_http::schemas::v2::BlockTransactions::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactions::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::BlockTransactions::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockTransactions& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockTransactions::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.id};

  vb["req_count"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.req_count};

  vb["incomplete"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.incomplete};

  vb["transactions"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShortTxId>,
    std::vector<::ton_http::schemas::v2::ShortTxId>>{value.transactions};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::BlockTransactions::_Type value) {
  const auto result = k__ton_http__schemas__v2__BlockTransactions___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::BlockTransactionsRequest& lhs,
  const ::ton_http::schemas::v2::BlockTransactionsRequest& rhs
) {
  return lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno &&
    lhs.root_hash == rhs.root_hash && lhs.file_hash == rhs.file_hash && lhs.after_lt == rhs.after_lt &&
    lhs.after_hash == rhs.after_hash && lhs.count == rhs.count && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::BlockTransactionsRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


BlockTransactionsRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::BlockTransactionsRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::BlockTransactionsRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.workchain};

  vb["shard"] = USERVER_NAMESPACE::chaotic::WithType<
    USERVER_NAMESPACE::chaotic::Variant<
      USERVER_NAMESPACE::chaotic::Primitive<std::string>,
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
    std::int64_t>{value.shard};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};

  if (value.root_hash) {
    vb["root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.root_hash};
  }

  if (value.file_hash) {
    vb["file_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.file_hash};
  }

  if (value.after_lt) {
    vb["after_lt"] = USERVER_NAMESPACE::chaotic::WithType<
      USERVER_NAMESPACE::chaotic::Variant<
        USERVER_NAMESPACE::chaotic::Primitive<std::string>,
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
      std::int64_t>{*value.after_lt};
  }

  if (value.after_hash) {
    vb["after_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.after_hash};
  }

  vb["count"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.count};


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::EmptyRequest& lhs, const ::ton_http::schemas::v2::EmptyRequest& rhs) {
  (void)lhs;
  (void)rhs;

  return

    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::EmptyRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


EmptyRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::EmptyRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::EmptyRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::TvmCell& lhs, const ::ton_http::schemas::v2::TvmCell& rhs) {
  return lhs._type == rhs._type && lhs.bytes == rhs.bytes && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TvmCell::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TvmCell& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TvmCell::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


TvmCell Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::TvmCell::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type>
) {
  const auto result = k__ton_http__schemas__v2__TvmCell___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TvmCell::_Type", value)
  );
}

::ton_http::schemas::v2::TvmCell::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TvmCell::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::TvmCell::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TvmCell& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TvmCell::_Type>{value._type};

  vb["bytes"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.bytes
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::TvmCell::_Type value) {
  const auto result = k__ton_http__schemas__v2__TvmCell___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::ConfigInfo& lhs, const ::ton_http::schemas::v2::ConfigInfo& rhs) {
  return lhs._type == rhs._type && lhs.config == rhs.config && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConfigInfo::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConfigInfo& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ConfigInfo::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ConfigInfo Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ConfigInfo::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ConfigInfo___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ConfigInfo::_Type", value)
  );
}

::ton_http::schemas::v2::ConfigInfo::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigInfo::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ConfigInfo::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ConfigInfo& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConfigInfo::_Type>{value._type};

  vb["config"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TvmCell>{value.config};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ConfigInfo::_Type value) {
  const auto result = k__ton_http__schemas__v2__ConfigInfo___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::ConfigParamRequest& lhs, const ::ton_http::schemas::v2::ConfigParamRequest& rhs
) {
  return lhs.param == rhs.param && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConfigParamRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ConfigParamRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConfigParamRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ConfigParamRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["param"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.param};


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::ConsensusBlock& lhs, const ::ton_http::schemas::v2::ConsensusBlock& rhs
) {
  return lhs._type == rhs._type && lhs.consensus_block == rhs.consensus_block && lhs.timestamp == rhs.timestamp && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConsensusBlock::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ConsensusBlock& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ConsensusBlock::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ConsensusBlock Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ConsensusBlock::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ConsensusBlock___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ConsensusBlock::_Type", value)
  );
}

::ton_http::schemas::v2::ConsensusBlock::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ConsensusBlock::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ConsensusBlock::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ConsensusBlock& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ConsensusBlock::_Type>{value._type};

  vb["consensus_block"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.consensus_block};

  vb["timestamp"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.timestamp};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ConsensusBlock::_Type value) {
  const auto result = k__ton_http__schemas__v2__ConsensusBlock___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::DetectAddressBase64Variant& lhs,
  const ::ton_http::schemas::v2::DetectAddressBase64Variant& rhs
) {
  return lhs._type == rhs._type && lhs.b64 == rhs.b64 && lhs.b64url == rhs.b64url && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressBase64Variant& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectAddressBase64Variant::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DetectAddressBase64Variant Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DetectAddressBase64Variant::_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DetectAddressBase64Variant___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type", value)
  );
}

::ton_http::schemas::v2::DetectAddressBase64Variant::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DetectAddressBase64Variant& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type>{value._type};

  vb["b64"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64};

  vb["b64url"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64url};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DetectAddressBase64Variant::_Type value) {
  const auto result = k__ton_http__schemas__v2__DetectAddressBase64Variant___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::DetectAddress& lhs, const ::ton_http::schemas::v2::DetectAddress& rhs) {
  return lhs._type == rhs._type && lhs.raw_form == rhs.raw_form && lhs.bounceable == rhs.bounceable &&
    lhs.non_bounceable == rhs.non_bounceable && lhs.given_type == rhs.given_type && lhs.test_only == rhs.test_only &&
    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress::Given_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddress& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectAddress::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DetectAddress::Given_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DetectAddress Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DetectAddress::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DetectAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddress::_Type", value)
  );
}

::ton_http::schemas::v2::DetectAddress::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::DetectAddress::Given_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type>
) {
  const auto result = k__ton_http__schemas__v2__DetectAddress__Given_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectAddress::Given_Type", value)
  );
}

::ton_http::schemas::v2::DetectAddress::Given_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddress::Given_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DetectAddress::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DetectAddress::Given_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DetectAddress& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress::_Type>{value._type};

  vb["raw_form"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.raw_form};

  vb["bounceable"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>{value.bounceable};

  vb["non_bounceable"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddressBase64Variant>{value.non_bounceable};

  vb["given_type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress::Given_Type>{value.given_type};

  vb["test_only"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.test_only};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DetectAddress::_Type value) {
  const auto result = k__ton_http__schemas__v2__DetectAddress___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::DetectAddress::Given_Type value) {
  const auto result = k__ton_http__schemas__v2__DetectAddress__Given_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::DetectHash& lhs, const ::ton_http::schemas::v2::DetectHash& rhs) {
  return lhs._type == rhs._type && lhs.b64 == rhs.b64 && lhs.b64url == rhs.b64url && lhs.hex == rhs.hex && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHash::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHash& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectHash::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DetectHash Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DetectHash::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DetectHash___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DetectHash::_Type", value)
  );
}

::ton_http::schemas::v2::DetectHash::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHash::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DetectHash::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DetectHash& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash::_Type>{value._type};

  vb["b64"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64};

  vb["b64url"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.b64url};

  vb["hex"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.hex};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DetectHash::_Type value) {
  const auto result = k__ton_http__schemas__v2__DetectHash___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::DetectHashRequest& lhs, const ::ton_http::schemas::v2::DetectHashRequest& rhs
) {
  return lhs.hash == rhs.hash && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectHashRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectHashRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectHashRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DetectHashRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::DnsRecordStorageAddress& lhs,
  const ::ton_http::schemas::v2::DnsRecordStorageAddress& rhs
) {
  return lhs._type == rhs._type && lhs.bag_id == rhs.bag_id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordStorageAddress& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsRecordStorageAddress::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DnsRecordStorageAddress Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DnsRecordStorageAddress::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DnsRecordStorageAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type", value)
  );
}

::ton_http::schemas::v2::DnsRecordStorageAddress::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsRecordStorageAddress& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type>{value._type};

  vb["bag_id"] = USERVER_NAMESPACE::chaotic::
    WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>{value.bag_id};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DnsRecordStorageAddress::_Type value) {
  const auto result = k__ton_http__schemas__v2__DnsRecordStorageAddress___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::SmcAddr& lhs, const ::ton_http::schemas::v2::SmcAddr& rhs) {
  return lhs._type == rhs._type && lhs.workchain_id == rhs.workchain_id && lhs.address == rhs.address && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::SmcAddr::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::SmcAddr& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


SmcAddr::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


SmcAddr Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::SmcAddr::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr::_Type>
) {
  const auto result = k__ton_http__schemas__v2__SmcAddr___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::SmcAddr::_Type", value)
  );
}

::ton_http::schemas::v2::SmcAddr::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SmcAddr::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::SmcAddr::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::SmcAddr& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr::_Type>{value._type};

  vb["workchain_id"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.workchain_id};

  vb["address"] = USERVER_NAMESPACE::chaotic::
    WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>{value.address};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::SmcAddr::_Type value) {
  const auto result = k__ton_http__schemas__v2__SmcAddr___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::DnsRecordSmcAddress& lhs, const ::ton_http::schemas::v2::DnsRecordSmcAddress& rhs
) {
  return lhs._type == rhs._type && lhs.smc_addr == rhs.smc_addr && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordSmcAddress& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsRecordSmcAddress::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DnsRecordSmcAddress Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DnsRecordSmcAddress::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DnsRecordSmcAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type", value)
  );
}

::ton_http::schemas::v2::DnsRecordSmcAddress::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsRecordSmcAddress& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type>{value._type};

  vb["smc_addr"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr>{value.smc_addr};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DnsRecordSmcAddress::_Type value) {
  const auto result = k__ton_http__schemas__v2__DnsRecordSmcAddress___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::DnsRecordAdnlAddress& lhs, const ::ton_http::schemas::v2::DnsRecordAdnlAddress& rhs
) {
  return lhs._type == rhs._type && lhs.adnl_addr == rhs.adnl_addr && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordAdnlAddress& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsRecordAdnlAddress::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DnsRecordAdnlAddress Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DnsRecordAdnlAddress___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type", value)
  );
}

::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsRecordAdnlAddress& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type>{value._type};

  vb["adnl_addr"] = USERVER_NAMESPACE::chaotic::
    WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash_hex>{value.adnl_addr};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type value) {
  const auto result = k__ton_http__schemas__v2__DnsRecordAdnlAddress___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::DnsRecordNextResolver& lhs, const ::ton_http::schemas::v2::DnsRecordNextResolver& rhs
) {
  return lhs._type == rhs._type && lhs.resolver == rhs.resolver && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordNextResolver::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordNextResolver& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsRecordNextResolver::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


DnsRecordNextResolver Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::DnsRecordNextResolver::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver::_Type>
) {
  const auto result = k__ton_http__schemas__v2__DnsRecordNextResolver___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::DnsRecordNextResolver::_Type", value)
  );
}

::ton_http::schemas::v2::DnsRecordNextResolver::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordNextResolver::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::DnsRecordNextResolver::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsRecordNextResolver& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver::_Type>{value._type};

  vb["resolver"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::SmcAddr>{value.resolver};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::DnsRecordNextResolver::_Type value) {
  const auto result = k__ton_http__schemas__v2__DnsRecordNextResolver___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::DnsRecordSet& lhs, const ::ton_http::schemas::v2::DnsRecordSet& rhs) {
  return lhs.dns_next_resolver == rhs.dns_next_resolver && lhs.wallet == rhs.wallet && lhs.site == rhs.site &&
    lhs.storage == rhs.storage && lhs.extra == rhs.extra &&

    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsRecordSet& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsRecordSet Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsRecordSet> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsRecordSet& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = value.extra;


  if (value.dns_next_resolver) {
    vb["dns_next_resolver"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
      &::ton_http::schemas::v2::kDnsRecord_Settings,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>{*value.dns_next_resolver};
  }

  if (value.wallet) {
    vb["wallet"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
      &::ton_http::schemas::v2::kDnsRecord_Settings,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>{*value.wallet};
  }

  if (value.site) {
    vb["site"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
      &::ton_http::schemas::v2::kDnsRecord_Settings,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>{*value.site};
  }

  if (value.storage) {
    vb["storage"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
      &::ton_http::schemas::v2::kDnsRecord_Settings,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordStorageAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSmcAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordAdnlAddress>,
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordNextResolver>>{*value.storage};
  }


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::DnsContent& lhs, const ::ton_http::schemas::v2::DnsContent& rhs) {
  return lhs.domain == rhs.domain && lhs.data == rhs.data && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DnsContent& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DnsContent Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DnsContent> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::DnsContent& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["domain"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.domain};

  vb["data"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsRecordSet>{value.data};


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::EstimateFeeRequest& lhs, const ::ton_http::schemas::v2::EstimateFeeRequest& rhs
) {
  return lhs.address == rhs.address && lhs.body == rhs.body && lhs.init_code == rhs.init_code &&
    lhs.init_data == rhs.init_data && lhs.ignore_chksig == rhs.ignore_chksig && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::EstimateFeeRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


EstimateFeeRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::EstimateFeeRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::EstimateFeeRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["body"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.body
    };

  vb["init_code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.init_code
    };

  vb["init_data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.init_data
    };

  vb["ignore_chksig"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.ignore_chksig};


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::MsgDataRaw& lhs, const ::ton_http::schemas::v2::MsgDataRaw& rhs) {
  return lhs._type == rhs._type && lhs.body == rhs.body && lhs.init_state == rhs.init_state && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataRaw::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataRaw& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MsgDataRaw::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MsgDataRaw Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MsgDataRaw::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MsgDataRaw___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataRaw::_Type", value)
  );
}

::ton_http::schemas::v2::MsgDataRaw::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataRaw::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MsgDataRaw::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MsgDataRaw& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw::_Type>{value._type};

  if (value.body) {
    vb["body"] =
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
        *value.body
      };
  }

  if (value.init_state) {
    vb["init_state"] =
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
        *value.init_state
      };
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MsgDataRaw::_Type value) {
  const auto result = k__ton_http__schemas__v2__MsgDataRaw___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::MsgDataText& lhs, const ::ton_http::schemas::v2::MsgDataText& rhs) {
  return lhs._type == rhs._type && lhs.text == rhs.text && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataText::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataText& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MsgDataText::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MsgDataText Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MsgDataText::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MsgDataText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataText::_Type", value)
  );
}

::ton_http::schemas::v2::MsgDataText::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataText::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MsgDataText::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MsgDataText& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText::_Type>{value._type};

  if (value.text) {
    vb["text"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.text};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MsgDataText::_Type value) {
  const auto result = k__ton_http__schemas__v2__MsgDataText___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::MsgDataDecryptedText& lhs, const ::ton_http::schemas::v2::MsgDataDecryptedText& rhs
) {
  return lhs._type == rhs._type && lhs.text == rhs.text && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataDecryptedText& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MsgDataDecryptedText::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MsgDataDecryptedText Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MsgDataDecryptedText::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MsgDataDecryptedText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataDecryptedText::_Type", value)
  );
}

::ton_http::schemas::v2::MsgDataDecryptedText::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MsgDataDecryptedText& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>{value._type};

  if (value.text) {
    vb["text"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.text};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MsgDataDecryptedText::_Type value) {
  const auto result = k__ton_http__schemas__v2__MsgDataDecryptedText___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::MsgDataEncryptedText& lhs, const ::ton_http::schemas::v2::MsgDataEncryptedText& rhs
) {
  return lhs._type == rhs._type && lhs.text == rhs.text && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MsgDataEncryptedText& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MsgDataEncryptedText::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MsgDataEncryptedText Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MsgDataEncryptedText::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MsgDataEncryptedText___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MsgDataEncryptedText::_Type", value)
  );
}

::ton_http::schemas::v2::MsgDataEncryptedText::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MsgDataEncryptedText& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>{value._type};

  if (value.text) {
    vb["text"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.text};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MsgDataEncryptedText::_Type value) {
  const auto result = k__ton_http__schemas__v2__MsgDataEncryptedText___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::ExtMessage& lhs, const ::ton_http::schemas::v2::ExtMessage& rhs) {
  return lhs._type == rhs._type && lhs.hash == rhs.hash && lhs.source == rhs.source &&
    lhs.destination == rhs.destination && lhs.value == rhs.value && lhs.extra_currencies == rhs.extra_currencies &&
    lhs.fwd_fee == rhs.fwd_fee && lhs.ihr_fee == rhs.ihr_fee && lhs.created_lt == rhs.created_lt &&
    lhs.body_hash == rhs.body_hash && lhs.msg_data == rhs.msg_data && lhs.message == rhs.message &&
    lhs.message_decode_error == rhs.message_decode_error && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtMessage::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtMessage& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ExtMessage::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ExtMessage Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ExtMessage::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ExtMessage___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtMessage::_Type", value)
  );
}

::ton_http::schemas::v2::ExtMessage::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ExtMessage::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ExtMessage& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage::_Type>{value._type};

  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };

  vb["source"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.source
    };

  vb["destination"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.destination
    };

  vb["value"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.value
    };

  vb["extra_currencies"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
    std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>{value.extra_currencies};

  vb["fwd_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.fwd_fee
    };

  vb["ihr_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.ihr_fee
    };

  vb["created_lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{
      value.created_lt
    };

  vb["body_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.body_hash
    };

  vb["msg_data"] = USERVER_NAMESPACE::chaotic::Variant<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>{value.msg_data};

  if (value.message) {
    vb["message"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.message};
  }

  if (value.message_decode_error) {
    vb["message_decode_error"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.message_decode_error};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ExtMessage::_Type value) {
  const auto result = k__ton_http__schemas__v2__ExtMessage___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::ExtTransaction& lhs, const ::ton_http::schemas::v2::ExtTransaction& rhs
) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.utime == rhs.utime && lhs.data == rhs.data &&
    lhs.transaction_id == rhs.transaction_id && lhs.fee == rhs.fee && lhs.storage_fee == rhs.storage_fee &&
    lhs.other_fee == rhs.other_fee && lhs.in_msg == rhs.in_msg && lhs.out_msgs == rhs.out_msgs && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtTransaction::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtTransaction& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ExtTransaction::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ExtTransaction Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ExtTransaction::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ExtTransaction___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtTransaction::_Type", value)
  );
}

::ton_http::schemas::v2::ExtTransaction::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ExtTransaction::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ExtTransaction& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtTransaction::_Type>{value._type};

  vb["address"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.address};

  vb["utime"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.utime};

  vb["data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.data
    };

  vb["transaction_id"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>{value.transaction_id};

  vb["fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.fee
    };

  vb["storage_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.storage_fee
    };

  vb["other_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.other_fee
    };

  vb["in_msg"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage>{value.in_msg};

  vb["out_msgs"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage>,
    std::vector<::ton_http::schemas::v2::ExtMessage>>{value.out_msgs};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ExtTransaction::_Type value) {
  const auto result = k__ton_http__schemas__v2__ExtTransaction___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::ExtendedAddressInformation& lhs,
  const ::ton_http::schemas::v2::ExtendedAddressInformation& rhs
) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.balance == rhs.balance &&
    lhs.extra_currencies == rhs.extra_currencies && lhs.last_transaction_id == rhs.last_transaction_id &&
    lhs.block_id == rhs.block_id && lhs.sync_utime == rhs.sync_utime && lhs.account_state == rhs.account_state &&
    lhs.revision == rhs.revision && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ExtendedAddressInformation& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ExtendedAddressInformation::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ExtendedAddressInformation Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ExtendedAddressInformation::_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ExtendedAddressInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtendedAddressInformation::_Type", value)
  );
}

::ton_http::schemas::v2::ExtendedAddressInformation::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtendedAddressInformation::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ExtendedAddressInformation& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>{value._type};

  vb["address"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.address};

  vb["balance"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.balance
    };

  vb["extra_currencies"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
    std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>{value.extra_currencies};

  vb["last_transaction_id"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>{value.last_transaction_id};

  vb["block_id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.block_id};

  vb["sync_utime"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{value.sync_utime};

  vb["account_state"] = USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
    &::ton_http::schemas::v2::kAccountState_Settings,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV3>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletV4>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV1>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateWalletHighloadV2>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateDns>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRWallet>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStatePChan>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateUninited>>{value.account_state};

  vb["revision"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.revision};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ExtendedAddressInformation::_Type value) {
  const auto result = k__ton_http__schemas__v2__ExtendedAddressInformation___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::TokenContentDict& lhs, const ::ton_http::schemas::v2::TokenContentDict& rhs
) {
  (void)lhs;
  (void)rhs;

  return

    lhs.extra == rhs.extra &&

    true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TokenContentDict& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TokenContentDict Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContentDict> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TokenContentDict& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = value.extra;


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::TokenContent& lhs, const ::ton_http::schemas::v2::TokenContent& rhs) {
  return lhs.type == rhs.type && lhs.data == rhs.data && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TokenContent::Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TokenContent& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TokenContent::Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent::Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


TokenContent Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::TokenContent::Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent::Type>
) {
  const auto result = k__ton_http__schemas__v2__TokenContent__Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::TokenContent::Type", value)
  );
}

::ton_http::schemas::v2::TokenContent::Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TokenContent::Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::TokenContent::Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TokenContent& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent::Type>{value.type};

  vb["data"] = USERVER_NAMESPACE::chaotic::Variant<
    USERVER_NAMESPACE::chaotic::Primitive<std::string>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContentDict>>{value.data};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::TokenContent::Type value) {
  const auto result = k__ton_http__schemas__v2__TokenContent__Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::JettonMasterData& lhs, const ::ton_http::schemas::v2::JettonMasterData& rhs
) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.contract_type == rhs.contract_type &&
    lhs.total_supply == rhs.total_supply && lhs.mintable == rhs.mintable && lhs.admin_address == rhs.admin_address &&
    lhs.jetton_content == rhs.jetton_content && lhs.jetton_wallet_code == rhs.jetton_wallet_code && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonMasterData::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonMasterData::Contract_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonMasterData& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


JettonMasterData::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JettonMasterData::Contract_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::Contract_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JettonMasterData Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::JettonMasterData::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::_Type>
) {
  const auto result = k__ton_http__schemas__v2__JettonMasterData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonMasterData::_Type", value)
  );
}

::ton_http::schemas::v2::JettonMasterData::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::JettonMasterData::Contract_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::Contract_Type>
) {
  const auto result = k__ton_http__schemas__v2__JettonMasterData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonMasterData::Contract_Type", value)
  );
}

::ton_http::schemas::v2::JettonMasterData::Contract_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonMasterData::Contract_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JettonMasterData::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JettonMasterData::Contract_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JettonMasterData& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData::_Type>{value._type};

  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["contract_type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonMasterData::Contract_Type>{
    value.contract_type
  };

  vb["total_supply"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.total_supply
    };

  vb["mintable"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.mintable};

  if (value.admin_address) {
    vb["admin_address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{*value.admin_address};
  }

  vb["jetton_content"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>{value.jetton_content};

  vb["jetton_wallet_code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.jetton_wallet_code
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::JettonMasterData::_Type value) {
  const auto result = k__ton_http__schemas__v2__JettonMasterData___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::JettonMasterData::Contract_Type value) {
  const auto result = k__ton_http__schemas__v2__JettonMasterData__Contract_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::JettonWalletData& lhs, const ::ton_http::schemas::v2::JettonWalletData& rhs
) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.contract_type == rhs.contract_type &&
    lhs.balance == rhs.balance && lhs.owner == rhs.owner && lhs.jetton == rhs.jetton &&
    lhs.mintless_is_claimed == rhs.mintless_is_claimed && lhs.jetton_wallet_code == rhs.jetton_wallet_code && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonWalletData::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonWalletData::Contract_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JettonWalletData& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


JettonWalletData::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JettonWalletData::Contract_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::Contract_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JettonWalletData Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::JettonWalletData::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::_Type>
) {
  const auto result = k__ton_http__schemas__v2__JettonWalletData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonWalletData::_Type", value)
  );
}

::ton_http::schemas::v2::JettonWalletData::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::JettonWalletData::Contract_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::Contract_Type>
) {
  const auto result = k__ton_http__schemas__v2__JettonWalletData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::JettonWalletData::Contract_Type", value)
  );
}

::ton_http::schemas::v2::JettonWalletData::Contract_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JettonWalletData::Contract_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JettonWalletData::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JettonWalletData::Contract_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JettonWalletData& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData::_Type>{value._type};

  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["contract_type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JettonWalletData::Contract_Type>{
    value.contract_type
  };

  vb["balance"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.balance
    };

  vb["owner"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.owner
    };

  vb["jetton"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.jetton
    };

  if (value.mintless_is_claimed) {
    vb["mintless_is_claimed"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{*value.mintless_is_claimed};
  }

  vb["jetton_wallet_code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.jetton_wallet_code
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::JettonWalletData::_Type value) {
  const auto result = k__ton_http__schemas__v2__JettonWalletData___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::JettonWalletData::Contract_Type value) {
  const auto result = k__ton_http__schemas__v2__JettonWalletData__Contract_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::TonlibErrorResponse& lhs, const ::ton_http::schemas::v2::TonlibErrorResponse& rhs
) {
  return lhs.ok == rhs.ok && lhs.error == rhs.error && lhs.code == rhs.code && lhs._extra == rhs._extra &&
    lhs.jsonrpc == rhs.jsonrpc && lhs.id == rhs.id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonlibErrorResponse& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TonlibErrorResponse Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibErrorResponse> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TonlibErrorResponse& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["ok"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.ok};

  vb["error"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.error};

  vb["code"] = USERVER_NAMESPACE::chaotic::Primitive<
    int,
    USERVER_NAMESPACE::chaotic::Minimum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMinimum>,
    USERVER_NAMESPACE::chaotic::Maximum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMaximum>>{value.code};

  if (value._extra) {
    vb["@extra"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value._extra};
  }

  if (value.jsonrpc) {
    vb["jsonrpc"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.jsonrpc};
  }

  if (value.id) {
    vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.id};
  }


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0& lhs,
  const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0& rhs
) {
  return lhs.jsonrpc == rhs.jsonrpc && lhs.id == rhs.id && true;
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcErrorResponse& lhs, const ::ton_http::schemas::v2::JsonRpcErrorResponse& rhs
) {
  return static_cast<const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0&>(lhs) ==
    static_cast<const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0&>(rhs) &&
    static_cast<const ::ton_http::schemas::v2::TonlibErrorResponse&>(lhs) ==
    static_cast<const ::ton_http::schemas::v2::TonlibErrorResponse&>(rhs);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcErrorResponse& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


JsonRpcErrorResponse__P0 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcErrorResponse__P0> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JsonRpcErrorResponse Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcErrorResponse> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JsonRpcErrorResponse__P0& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["jsonrpc"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.jsonrpc};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.id};


  return vb.ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JsonRpcErrorResponse& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;
  USERVER_NAMESPACE::formats::common::Merge(
    vb,
    USERVER_NAMESPACE::formats::json::ValueBuilder{
      static_cast<::ton_http::schemas::v2::JsonRpcErrorResponse__P0>(value)
    }
      .ExtractValue()
  );
  USERVER_NAMESPACE::formats::common::Merge(
    vb,
    USERVER_NAMESPACE::formats::json::ValueBuilder{static_cast<::ton_http::schemas::v2::TonlibErrorResponse>(value)}
      .ExtractValue()
  );
  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcRequest::Params& lhs, const ::ton_http::schemas::v2::JsonRpcRequest::Params& rhs
) {
  (void)lhs;
  (void)rhs;

  return

    lhs.extra == rhs.extra &&

    true;
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcRequest& lhs, const ::ton_http::schemas::v2::JsonRpcRequest& rhs
) {
  return lhs.jsonrpc == rhs.jsonrpc && lhs.id == rhs.id && lhs.method == rhs.method && lhs.params == rhs.params && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcRequest::Params& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


JsonRpcRequest::Params Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcRequest::Params> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JsonRpcRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JsonRpcRequest::Params& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = value.extra;


  return vb.ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JsonRpcRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["jsonrpc"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.jsonrpc};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.id};

  vb["method"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.method};

  vb["params"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::JsonRpcRequest::Params>{value.params};


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::WalletInformation& lhs, const ::ton_http::schemas::v2::WalletInformation& rhs
) {
  return lhs._type == rhs._type && lhs.wallet == rhs.wallet && lhs.balance == rhs.balance &&
    lhs.account_state == rhs.account_state && lhs.last_transaction_id == rhs.last_transaction_id &&
    lhs.wallet_type == rhs.wallet_type && lhs.seqno == rhs.seqno && lhs.wallet_id == rhs.wallet_id &&
    lhs.is_signature_allowed == rhs.is_signature_allowed && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation::Wallet_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::WalletInformation& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


WalletInformation::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


WalletInformation::Wallet_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


WalletInformation Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::WalletInformation::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type>
) {
  const auto result = k__ton_http__schemas__v2__WalletInformation___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::WalletInformation::_Type", value)
  );
}

::ton_http::schemas::v2::WalletInformation::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::WalletInformation::Wallet_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
) {
  const auto result = k__ton_http__schemas__v2__WalletInformation__Wallet_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::WalletInformation::Wallet_Type", value)
  );
}

::ton_http::schemas::v2::WalletInformation::Wallet_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::WalletInformation::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::WalletInformation::Wallet_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::WalletInformation& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation::_Type>{value._type};

  vb["wallet"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.wallet};

  vb["balance"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.balance
    };

  vb["account_state"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>{value.account_state};

  vb["last_transaction_id"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>{value.last_transaction_id};

  if (value.wallet_type) {
    vb["wallet_type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation::Wallet_Type>{
      *value.wallet_type
    };
  }

  if (value.seqno) {
    vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>{*value.seqno};
  }

  if (value.wallet_id) {
    vb["wallet_id"] = USERVER_NAMESPACE::chaotic::Primitive<int>{*value.wallet_id};
  }

  if (value.is_signature_allowed) {
    vb["is_signature_allowed"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{*value.is_signature_allowed};
  }


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::WalletInformation::_Type value) {
  const auto result = k__ton_http__schemas__v2__WalletInformation___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::WalletInformation::Wallet_Type value) {
  const auto result = k__ton_http__schemas__v2__WalletInformation__Wallet_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::NftCollectionData& lhs, const ::ton_http::schemas::v2::NftCollectionData& rhs
) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.contract_type == rhs.contract_type &&
    lhs.next_item_index == rhs.next_item_index && lhs.owner_address == rhs.owner_address &&
    lhs.collection_content == rhs.collection_content && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftCollectionData::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftCollectionData::Contract_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftCollectionData& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


NftCollectionData::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


NftCollectionData::Contract_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::Contract_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


NftCollectionData Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::NftCollectionData::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::_Type>
) {
  const auto result = k__ton_http__schemas__v2__NftCollectionData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftCollectionData::_Type", value)
  );
}

::ton_http::schemas::v2::NftCollectionData::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::NftCollectionData::Contract_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::Contract_Type>
) {
  const auto result = k__ton_http__schemas__v2__NftCollectionData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftCollectionData::Contract_Type", value)
  );
}

::ton_http::schemas::v2::NftCollectionData::Contract_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftCollectionData::Contract_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::NftCollectionData::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::NftCollectionData::Contract_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::NftCollectionData& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData::_Type>{value._type};

  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["contract_type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftCollectionData::Contract_Type>{
      value.contract_type
    };

  vb["next_item_index"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.next_item_index
    };

  if (value.owner_address) {
    vb["owner_address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{*value.owner_address};
  }

  vb["collection_content"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>{value.collection_content};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::NftCollectionData::_Type value) {
  const auto result = k__ton_http__schemas__v2__NftCollectionData___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::NftCollectionData::Contract_Type value) {
  const auto result = k__ton_http__schemas__v2__NftCollectionData__Contract_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::NftItemData& lhs, const ::ton_http::schemas::v2::NftItemData& rhs) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.contract_type == rhs.contract_type &&
    lhs.init == rhs.init && lhs.index == rhs.index && lhs.collection_address == rhs.collection_address &&
    lhs.owner_address == rhs.owner_address && lhs.content == rhs.content && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftItemData::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftItemData::Contract_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::NftItemData& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


NftItemData::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


NftItemData::Contract_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::Contract_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


NftItemData Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::NftItemData::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::_Type>
) {
  const auto result = k__ton_http__schemas__v2__NftItemData___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftItemData::_Type", value)
  );
}

::ton_http::schemas::v2::NftItemData::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::_Type> to
) {
  return FromString(value, to);
}


::ton_http::schemas::v2::NftItemData::Contract_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::Contract_Type>
) {
  const auto result = k__ton_http__schemas__v2__NftItemData__Contract_Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::NftItemData::Contract_Type", value)
  );
}

::ton_http::schemas::v2::NftItemData::Contract_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::NftItemData::Contract_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::NftItemData::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::NftItemData::Contract_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::NftItemData& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData::_Type>{value._type};

  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["contract_type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::NftItemData::Contract_Type>{value.contract_type};

  vb["init"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.init};

  vb["index"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.index
    };

  if (value.collection_address) {
    vb["collection_address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
        *value.collection_address
      };
  }

  if (value.owner_address) {
    vb["owner_address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{*value.owner_address};
  }

  vb["content"] = USERVER_NAMESPACE::chaotic::Variant<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TokenContent>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DnsContent>>{value.content};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::NftItemData::_Type value) {
  const auto result = k__ton_http__schemas__v2__NftItemData___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


std::string ToString(::ton_http::schemas::v2::NftItemData::Contract_Type value) {
  const auto result = k__ton_http__schemas__v2__NftItemData__Contract_Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::MasterchainInfo& lhs, const ::ton_http::schemas::v2::MasterchainInfo& rhs
) {
  return lhs._type == rhs._type && lhs.last == rhs.last && lhs.state_root_hash == rhs.state_root_hash &&
    lhs.init == rhs.init && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfo::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainInfo& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MasterchainInfo::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MasterchainInfo Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MasterchainInfo::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MasterchainInfo___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MasterchainInfo::_Type", value)
  );
}

::ton_http::schemas::v2::MasterchainInfo::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainInfo::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MasterchainInfo::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MasterchainInfo& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo::_Type>{value._type};

  vb["last"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.last};

  vb["state_root_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.state_root_hash
    };

  vb["init"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.init};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MasterchainInfo::_Type value) {
  const auto result = k__ton_http__schemas__v2__MasterchainInfo___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::MasterchainBlockSignatures& lhs,
  const ::ton_http::schemas::v2::MasterchainBlockSignatures& rhs
) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.signatures == rhs.signatures && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::MasterchainBlockSignatures& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


MasterchainBlockSignatures::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


MasterchainBlockSignatures Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::MasterchainBlockSignatures::_Type FromString(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>
) {
  const auto result = k__ton_http__schemas__v2__MasterchainBlockSignatures___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type", value)
  );
}

::ton_http::schemas::v2::MasterchainBlockSignatures::_Type Parse(
  std::string_view value,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::MasterchainBlockSignatures& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.id};

  vb["signatures"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockSignature>,
    std::vector<::ton_http::schemas::v2::BlockSignature>>{value.signatures};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::MasterchainBlockSignatures::_Type value) {
  const auto result = k__ton_http__schemas__v2__MasterchainBlockSignatures___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::ShardBlockLink& lhs, const ::ton_http::schemas::v2::ShardBlockLink& rhs
) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.proof == rhs.proof && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockLink::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockLink& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ShardBlockLink::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ShardBlockLink Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ShardBlockLink::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ShardBlockLink___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShardBlockLink::_Type", value)
  );
}

::ton_http::schemas::v2::ShardBlockLink::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockLink::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ShardBlockLink::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ShardBlockLink& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockLink::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.id};

  vb["proof"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.proof
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ShardBlockLink::_Type value) {
  const auto result = k__ton_http__schemas__v2__ShardBlockLink___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::ShardBlockProof& lhs, const ::ton_http::schemas::v2::ShardBlockProof& rhs
) {
  return lhs._type == rhs._type && lhs.from == rhs.from && lhs.mc_id == rhs.mc_id && lhs.links == rhs.links &&
    lhs.mc_proof == rhs.mc_proof && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockProof::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockProof& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ShardBlockProof::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


ShardBlockProof Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::ShardBlockProof::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type>
) {
  const auto result = k__ton_http__schemas__v2__ShardBlockProof___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ShardBlockProof::_Type", value)
  );
}

::ton_http::schemas::v2::ShardBlockProof::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProof::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::ShardBlockProof::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ShardBlockProof& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof::_Type>{value._type};

  vb["from"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.from};

  vb["mc_id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.mc_id};

  vb["links"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockLink>,
    std::vector<::ton_http::schemas::v2::ShardBlockLink>>{value.links};

  vb["mc_proof"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::BlockLinkBack>,
    std::vector<::ton_http::schemas::v2::BlockLinkBack>>{value.mc_proof};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::ShardBlockProof::_Type value) {
  const auto result = k__ton_http__schemas__v2__ShardBlockProof___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::TonlibResponse& lhs, const ::ton_http::schemas::v2::TonlibResponse& rhs
) {
  return lhs.ok == rhs.ok && lhs.result == rhs.result && lhs._extra == rhs._extra && lhs.jsonrpc == rhs.jsonrpc &&
    lhs.id == rhs.id && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TonlibResponse& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TonlibResponse Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibResponse> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TonlibResponse& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["ok"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.ok};

  vb["result"] = USERVER_NAMESPACE::chaotic::Variant<
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
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof>>>{value.result};

  vb["@extra"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._extra};

  if (value.jsonrpc) {
    vb["jsonrpc"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.jsonrpc};
  }

  if (value.id) {
    vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.id};
  }


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcResponse__P0& lhs, const ::ton_http::schemas::v2::JsonRpcResponse__P0& rhs
) {
  return lhs.jsonrpc == rhs.jsonrpc && lhs.id == rhs.id && true;
}


bool operator==(
  const ::ton_http::schemas::v2::JsonRpcResponse& lhs, const ::ton_http::schemas::v2::JsonRpcResponse& rhs
) {
  return static_cast<const ::ton_http::schemas::v2::JsonRpcResponse__P0&>(lhs) ==
    static_cast<const ::ton_http::schemas::v2::JsonRpcResponse__P0&>(rhs) &&
    static_cast<const ::ton_http::schemas::v2::TonlibResponse&>(lhs) ==
    static_cast<const ::ton_http::schemas::v2::TonlibResponse&>(rhs);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcResponse__P0& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::JsonRpcResponse& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


JsonRpcResponse__P0 Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcResponse__P0> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


JsonRpcResponse Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::JsonRpcResponse> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::JsonRpcResponse__P0& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["jsonrpc"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.jsonrpc};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.id};


  return vb.ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::JsonRpcResponse& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;
  USERVER_NAMESPACE::formats::common::Merge(
    vb,
    USERVER_NAMESPACE::formats::json::ValueBuilder{static_cast<::ton_http::schemas::v2::JsonRpcResponse__P0>(value)}
      .ExtractValue()
  );
  USERVER_NAMESPACE::formats::common::Merge(
    vb,
    USERVER_NAMESPACE::formats::json::ValueBuilder{static_cast<::ton_http::schemas::v2::TonlibResponse>(value)}
      .ExtractValue()
  );
  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::LibrariesRequest& lhs, const ::ton_http::schemas::v2::LibrariesRequest& rhs
) {
  return lhs.libraries == rhs.libraries && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibrariesRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


LibrariesRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibrariesRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::LibrariesRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["libraries"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>,
    std::vector<ton_http::types::ton_hash>>{value.libraries};


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::LibraryEntry& lhs, const ::ton_http::schemas::v2::LibraryEntry& rhs) {
  return lhs._type == rhs._type && lhs.hash == rhs.hash && lhs.data == rhs.data && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryEntry::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryEntry& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


LibraryEntry::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


LibraryEntry Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::LibraryEntry::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type>
) {
  const auto result = k__ton_http__schemas__v2__LibraryEntry___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::LibraryEntry::_Type", value)
  );
}

::ton_http::schemas::v2::LibraryEntry::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryEntry::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::LibraryEntry::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::LibraryEntry& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryEntry::_Type>{value._type};

  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };

  vb["data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.data
    };


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::LibraryEntry::_Type value) {
  const auto result = k__ton_http__schemas__v2__LibraryEntry___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::LibraryResult& lhs, const ::ton_http::schemas::v2::LibraryResult& rhs) {
  return lhs._type == rhs._type && lhs.result == rhs.result && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryResult::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LibraryResult& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


LibraryResult::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


LibraryResult Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::LibraryResult::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type>
) {
  const auto result = k__ton_http__schemas__v2__LibraryResult___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::LibraryResult::_Type", value)
  );
}

::ton_http::schemas::v2::LibraryResult::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LibraryResult::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::LibraryResult::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::LibraryResult& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryResult::_Type>{value._type};

  vb["result"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::LibraryEntry>,
    std::vector<::ton_http::schemas::v2::LibraryEntry>>{value.result};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::LibraryResult::_Type value) {
  const auto result = k__ton_http__schemas__v2__LibraryResult___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::LookupBlockRequest& lhs, const ::ton_http::schemas::v2::LookupBlockRequest& rhs
) {
  return lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno && lhs.lt == rhs.lt &&
    lhs.unixtime == rhs.unixtime && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::LookupBlockRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


LookupBlockRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::LookupBlockRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::LookupBlockRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.workchain};

  vb["shard"] = USERVER_NAMESPACE::chaotic::WithType<
    USERVER_NAMESPACE::chaotic::Variant<
      USERVER_NAMESPACE::chaotic::Primitive<std::string>,
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
    std::int64_t>{value.shard};

  if (value.seqno) {
    vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{*value.seqno};
  }

  if (value.lt) {
    vb["lt"] = USERVER_NAMESPACE::chaotic::WithType<
      USERVER_NAMESPACE::chaotic::Variant<
        USERVER_NAMESPACE::chaotic::Primitive<std::string>,
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
      std::int64_t>{*value.lt};
  }

  if (value.unixtime) {
    vb["unixtime"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{*value.unixtime};
  }


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::SeqnoRequest& lhs, const ::ton_http::schemas::v2::SeqnoRequest& rhs) {
  return lhs.seqno == rhs.seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::SeqnoRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


SeqnoRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SeqnoRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::SeqnoRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::Message& lhs, const ::ton_http::schemas::v2::Message& rhs) {
  return lhs._type == rhs._type && lhs.hash == rhs.hash && lhs.source == rhs.source &&
    lhs.destination == rhs.destination && lhs.value == rhs.value && lhs.extra_currencies == rhs.extra_currencies &&
    lhs.fwd_fee == rhs.fwd_fee && lhs.ihr_fee == rhs.ihr_fee && lhs.created_lt == rhs.created_lt &&
    lhs.body_hash == rhs.body_hash && lhs.msg_data == rhs.msg_data && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Message::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Message& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


Message::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


Message Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::Message::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type>
) {
  const auto result = k__ton_http__schemas__v2__Message___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Message::_Type", value)
  );
}

::ton_http::schemas::v2::Message::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Message::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::Message::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::Message& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message::_Type>{value._type};

  vb["hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.hash
    };

  vb["source"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.source};

  vb["destination"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.destination};

  vb["value"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.value
    };

  vb["extra_currencies"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtraCurrencyBalance>,
    std::vector<::ton_http::schemas::v2::ExtraCurrencyBalance>>{value.extra_currencies};

  vb["fwd_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.fwd_fee
    };

  vb["ihr_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.ihr_fee
    };

  vb["created_lt"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{
      value.created_lt
    };

  vb["body_hash"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{
      value.body_hash
    };

  vb["msg_data"] = USERVER_NAMESPACE::chaotic::Variant<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>{value.msg_data};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::Message::_Type value) {
  const auto result = k__ton_http__schemas__v2__Message___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::OutMsgQueueSize& lhs, const ::ton_http::schemas::v2::OutMsgQueueSize& rhs
) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.size == rhs.size && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSize::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSize& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


OutMsgQueueSize::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


OutMsgQueueSize Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::OutMsgQueueSize::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type>
) {
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSize___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::OutMsgQueueSize::_Type", value)
  );
}

::ton_http::schemas::v2::OutMsgQueueSize::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSize::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::OutMsgQueueSize::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::OutMsgQueueSize& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSize::_Type>{value._type};

  vb["id"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>{value.id};

  vb["size"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.size};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::OutMsgQueueSize::_Type value) {
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSize___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::OutMsgQueueSizes& lhs, const ::ton_http::schemas::v2::OutMsgQueueSizes& rhs
) {
  return lhs._type == rhs._type && lhs.shards == rhs.shards &&
    lhs.ext_msg_queue_size_limit == rhs.ext_msg_queue_size_limit && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::OutMsgQueueSizes& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


OutMsgQueueSizes::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


OutMsgQueueSizes Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::OutMsgQueueSizes::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>
) {
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSizes___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::OutMsgQueueSizes::_Type", value)
  );
}

::ton_http::schemas::v2::OutMsgQueueSizes::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::OutMsgQueueSizes::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::OutMsgQueueSizes& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>{value._type};

  vb["shards"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSize>,
    std::vector<::ton_http::schemas::v2::OutMsgQueueSize>>{value.shards};

  vb["ext_msg_queue_size_limit"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.ext_msg_queue_size_limit};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::OutMsgQueueSizes::_Type value) {
  const auto result = k__ton_http__schemas__v2__OutMsgQueueSizes___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::RunGetMethodRequest& lhs, const ::ton_http::schemas::v2::RunGetMethodRequest& rhs
) {
  return lhs.address == rhs.address && lhs.method == rhs.method && lhs.stack == rhs.stack && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::RunGetMethodRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


RunGetMethodRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::RunGetMethodRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::RunGetMethodRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["method"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value.method};

  vb["stack"] =
    USERVER_NAMESPACE::chaotic::Array<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::vector<std::string>>{
      value.stack
    };


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::SendBocRequest& lhs, const ::ton_http::schemas::v2::SendBocRequest& rhs
) {
  return lhs.boc == rhs.boc && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::SendBocRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


SendBocRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SendBocRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::SendBocRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["boc"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.boc
    };


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::SendQueryRequest& lhs, const ::ton_http::schemas::v2::SendQueryRequest& rhs
) {
  return lhs.address == rhs.address && lhs.body == rhs.body && lhs.init_code == rhs.init_code &&
    lhs.init_data == rhs.init_data && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::SendQueryRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


SendQueryRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::SendQueryRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::SendQueryRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  vb["body"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.body
    };

  vb["init_code"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.init_code
    };

  vb["init_data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.init_data
    };


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::ShardBlockProofRequest& lhs, const ::ton_http::schemas::v2::ShardBlockProofRequest& rhs
) {
  return lhs.workchain == rhs.workchain && lhs.shard == rhs.shard && lhs.seqno == rhs.seqno &&
    lhs.from_seqno == rhs.from_seqno && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::ShardBlockProofRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


ShardBlockProofRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ShardBlockProofRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::ShardBlockProofRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["workchain"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.workchain};

  vb["shard"] = USERVER_NAMESPACE::chaotic::WithType<
    USERVER_NAMESPACE::chaotic::Variant<
      USERVER_NAMESPACE::chaotic::Primitive<std::string>,
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
    std::int64_t>{value.shard};

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{value.seqno};

  if (value.from_seqno) {
    vb["from_seqno"] = USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>{*value.from_seqno};
  }


  return vb.ExtractValue();
}


bool operator==(const ::ton_http::schemas::v2::Shards& lhs, const ::ton_http::schemas::v2::Shards& rhs) {
  return lhs._type == rhs._type && lhs.shards == rhs.shards && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Shards::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Shards& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


Shards::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


Shards Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::Shards::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type>
) {
  const auto result = k__ton_http__schemas__v2__Shards___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Shards::_Type", value)
  );
}

::ton_http::schemas::v2::Shards::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Shards::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::Shards::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::Shards& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Shards::_Type>{value._type};

  vb["shards"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::TonBlockIdExt>,
    std::vector<::ton_http::schemas::v2::TonBlockIdExt>>{value.shards};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::Shards::_Type value) {
  const auto result = k__ton_http__schemas__v2__Shards___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(const ::ton_http::schemas::v2::Transaction& lhs, const ::ton_http::schemas::v2::Transaction& rhs) {
  return lhs._type == rhs._type && lhs.address == rhs.address && lhs.account == rhs.account && lhs.utime == rhs.utime &&
    lhs.data == rhs.data && lhs.transaction_id == rhs.transaction_id && lhs.fee == rhs.fee &&
    lhs.storage_fee == rhs.storage_fee && lhs.other_fee == rhs.other_fee && lhs.in_msg == rhs.in_msg &&
    lhs.out_msgs == rhs.out_msgs && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Transaction::_Type& value
) {
  return lh << ToString(value);
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::Transaction& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


Transaction::_Type Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


Transaction Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


::ton_http::schemas::v2::Transaction::_Type FromString(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type>
) {
  const auto result = k__ton_http__schemas__v2__Transaction___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  throw std::runtime_error(
    fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::Transaction::_Type", value)
  );
}

::ton_http::schemas::v2::Transaction::_Type Parse(
  std::string_view value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::Transaction::_Type> to
) {
  return FromString(value, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  const ::ton_http::schemas::v2::Transaction::_Type& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  return USERVER_NAMESPACE::formats::json::ValueBuilder(ToString(value)).ExtractValue();
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::Transaction& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["@type"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Transaction::_Type>{value._type};

  vb["address"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>{value.address};

  vb["account"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.account
    };

  vb["utime"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.utime};

  vb["data"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{
      value.data
    };

  vb["transaction_id"] =
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>{value.transaction_id};

  vb["fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.fee
    };

  vb["storage_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.storage_fee
    };

  vb["other_fee"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::int256>{
      value.other_fee
    };

  vb["in_msg"] = USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>{value.in_msg};

  vb["out_msgs"] = USERVER_NAMESPACE::chaotic::Array<
    USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>,
    std::vector<::ton_http::schemas::v2::Message>>{value.out_msgs};


  return vb.ExtractValue();
}


std::string ToString(::ton_http::schemas::v2::Transaction::_Type value) {
  const auto result = k__ton_http__schemas__v2__Transaction___Type_Mapping.TryFindByFirst(value);
  if (result.has_value()) {
    return std::string{*result};
  }
  throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<int>(value)));
}


bool operator==(
  const ::ton_http::schemas::v2::TransactionsRequest& lhs, const ::ton_http::schemas::v2::TransactionsRequest& rhs
) {
  return lhs.address == rhs.address && lhs.lt == rhs.lt && lhs.hash == rhs.hash && lhs.to_lt == rhs.to_lt &&
    lhs.archival == rhs.archival && lhs.limit == rhs.limit && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TransactionsRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TransactionsRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TransactionsRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TransactionsRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.address
    };

  if (value.lt) {
    vb["lt"] = USERVER_NAMESPACE::chaotic::WithType<
      USERVER_NAMESPACE::chaotic::Variant<
        USERVER_NAMESPACE::chaotic::Primitive<std::string>,
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
      std::int64_t>{*value.lt};
  }

  if (value.hash) {
    vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{*value.hash};
  }

  if (value.to_lt) {
    vb["to_lt"] = USERVER_NAMESPACE::chaotic::WithType<
      USERVER_NAMESPACE::chaotic::Variant<
        USERVER_NAMESPACE::chaotic::Primitive<std::string>,
        USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
      std::int64_t>{*value.to_lt};
  }

  vb["archival"] = USERVER_NAMESPACE::chaotic::Primitive<bool>{value.archival};

  vb["limit"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.limit};


  return vb.ExtractValue();
}


bool operator==(
  const ::ton_http::schemas::v2::TryLocateTxRequest& lhs, const ::ton_http::schemas::v2::TryLocateTxRequest& rhs
) {
  return lhs.source == rhs.source && lhs.destination == rhs.destination && lhs.created_lt == rhs.created_lt && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
  USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::TryLocateTxRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


TryLocateTxRequest Parse(
  USERVER_NAMESPACE::formats::json::Value json,
  USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TryLocateTxRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
  [[maybe_unused]] const ::ton_http::schemas::v2::TryLocateTxRequest& value,
  USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["source"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.source
    };

  vb["destination"] =
    USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{
      value.destination
    };

  vb["created_lt"] = USERVER_NAMESPACE::chaotic::WithType<
    USERVER_NAMESPACE::chaotic::Variant<
      USERVER_NAMESPACE::chaotic::Primitive<std::string>,
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::int64_t>, std::int64_t>>,
    std::int64_t>{value.created_lt};


  return vb.ExtractValue();
}


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountAddress::_Type>::format(
  const ::ton_http::schemas::v2::AccountAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateRaw::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateRaw::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateWalletV3::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateWalletV3::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateWalletV4::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateWalletV4::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV1::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateWalletHighloadV2::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateDns::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateDns::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::RWalletLimit::_Type>::format(
  const ::ton_http::schemas::v2::RWalletLimit::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::RWalletConfig::_Type>::format(
  const ::ton_http::schemas::v2::RWalletConfig::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateRWallet::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateRWallet::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::PChanConfig::_Type>::format(
  const ::ton_http::schemas::v2::PChanConfig::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::PChanStateInit::_Type>::format(
  const ::ton_http::schemas::v2::PChanStateInit::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::PChanStateClose::_Type>::format(
  const ::ton_http::schemas::v2::PChanStateClose::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::PChanStatePayout::_Type>::format(
  const ::ton_http::schemas::v2::PChanStatePayout::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStatePChan::_Type>::format(
  const ::ton_http::schemas::v2::AccountStatePChan::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateUninited::_Type>::format(
  const ::ton_http::schemas::v2::AccountStateUninited::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateEnum>::format(
  const ::ton_http::schemas::v2::AccountStateEnum& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type>::format(
  const ::ton_http::schemas::v2::ExtraCurrencyBalance::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::InternalTransactionId::_Type>::format(
  const ::ton_http::schemas::v2::InternalTransactionId::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::TonBlockIdExt::_Type>::format(
  const ::ton_http::schemas::v2::TonBlockIdExt::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AddressInformation::_Type>::format(
  const ::ton_http::schemas::v2::AddressInformation::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::BlockHeader::_Type>::format(
  const ::ton_http::schemas::v2::BlockHeader::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::BlockLinkBack::_Type>::format(
  const ::ton_http::schemas::v2::BlockLinkBack::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::BlockSignature::_Type>::format(
  const ::ton_http::schemas::v2::BlockSignature::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ShortTxId::_Type>::format(
  const ::ton_http::schemas::v2::ShortTxId::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::BlockTransactions::_Type>::format(
  const ::ton_http::schemas::v2::BlockTransactions::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::TvmCell::_Type>::format(
  const ::ton_http::schemas::v2::TvmCell::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ConfigInfo::_Type>::format(
  const ::ton_http::schemas::v2::ConfigInfo::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ConsensusBlock::_Type>::format(
  const ::ton_http::schemas::v2::ConsensusBlock::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DetectAddressBase64Variant::_Type>::format(
  const ::ton_http::schemas::v2::DetectAddressBase64Variant::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DetectAddress::_Type>::format(
  const ::ton_http::schemas::v2::DetectAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DetectAddress::Given_Type>::format(
  const ::ton_http::schemas::v2::DetectAddress::Given_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DetectHash::_Type>::format(
  const ::ton_http::schemas::v2::DetectHash::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DnsRecordStorageAddress::_Type>::format(
  const ::ton_http::schemas::v2::DnsRecordStorageAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::SmcAddr::_Type>::format(
  const ::ton_http::schemas::v2::SmcAddr::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DnsRecordSmcAddress::_Type>::format(
  const ::ton_http::schemas::v2::DnsRecordSmcAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type>::format(
  const ::ton_http::schemas::v2::DnsRecordAdnlAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::DnsRecordNextResolver::_Type>::format(
  const ::ton_http::schemas::v2::DnsRecordNextResolver::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MsgDataRaw::_Type>::format(
  const ::ton_http::schemas::v2::MsgDataRaw::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MsgDataText::_Type>::format(
  const ::ton_http::schemas::v2::MsgDataText::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MsgDataDecryptedText::_Type>::format(
  const ::ton_http::schemas::v2::MsgDataDecryptedText::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MsgDataEncryptedText::_Type>::format(
  const ::ton_http::schemas::v2::MsgDataEncryptedText::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ExtMessage::_Type>::format(
  const ::ton_http::schemas::v2::ExtMessage::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ExtTransaction::_Type>::format(
  const ::ton_http::schemas::v2::ExtTransaction::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>::format(
  const ::ton_http::schemas::v2::ExtendedAddressInformation::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::TokenContent::Type>::format(
  const ::ton_http::schemas::v2::TokenContent::Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::JettonMasterData::_Type>::format(
  const ::ton_http::schemas::v2::JettonMasterData::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::JettonMasterData::Contract_Type>::format(
  const ::ton_http::schemas::v2::JettonMasterData::Contract_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::JettonWalletData::_Type>::format(
  const ::ton_http::schemas::v2::JettonWalletData::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::JettonWalletData::Contract_Type>::format(
  const ::ton_http::schemas::v2::JettonWalletData::Contract_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::WalletInformation::_Type>::format(
  const ::ton_http::schemas::v2::WalletInformation::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::WalletInformation::Wallet_Type>::format(
  const ::ton_http::schemas::v2::WalletInformation::Wallet_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::NftCollectionData::_Type>::format(
  const ::ton_http::schemas::v2::NftCollectionData::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::NftCollectionData::Contract_Type>::format(
  const ::ton_http::schemas::v2::NftCollectionData::Contract_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::NftItemData::_Type>::format(
  const ::ton_http::schemas::v2::NftItemData::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::NftItemData::Contract_Type>::format(
  const ::ton_http::schemas::v2::NftItemData::Contract_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MasterchainInfo::_Type>::format(
  const ::ton_http::schemas::v2::MasterchainInfo::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>::format(
  const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ShardBlockLink::_Type>::format(
  const ::ton_http::schemas::v2::ShardBlockLink::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::ShardBlockProof::_Type>::format(
  const ::ton_http::schemas::v2::ShardBlockProof::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::LibraryEntry::_Type>::format(
  const ::ton_http::schemas::v2::LibraryEntry::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::LibraryResult::_Type>::format(
  const ::ton_http::schemas::v2::LibraryResult::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::Message::_Type>::format(
  const ::ton_http::schemas::v2::Message::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::OutMsgQueueSize::_Type>::format(
  const ::ton_http::schemas::v2::OutMsgQueueSize::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>::format(
  const ::ton_http::schemas::v2::OutMsgQueueSizes::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::Shards::_Type>::format(
  const ::ton_http::schemas::v2::Shards::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::Transaction::_Type>::format(
  const ::ton_http::schemas::v2::Transaction::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}

