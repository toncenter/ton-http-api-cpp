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
        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{*value.account_address};
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

  vb["frozen_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.frozen_hash};


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
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtraCurrencyBalance::_Type> to
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

  vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.hash};


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

  vb["shard"] = USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::int64_t>{
      value.shard
  };

  vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.seqno};

  vb["root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.root_hash};

  vb["file_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.file_hash};


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

  vb["frozen_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.frozen_hash};

  vb["sync_utime"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.sync_utime};

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


bool operator==(const ::ton_http::schemas::v2::BlockHeader& lhs, const ::ton_http::schemas::v2::BlockHeader& rhs) {
  return lhs._type == rhs._type && lhs.id == rhs.id && lhs.global_id == rhs.global_id && lhs.version == rhs.version &&
      lhs.after_merge == rhs.after_merge && lhs.after_split == rhs.after_split &&
      lhs.before_split == rhs.before_split && lhs.want_merge == rhs.want_merge && lhs.want_split == rhs.want_split &&
      lhs.validator_list_hash_short == rhs.validator_list_hash_short && lhs.catchain_seqno == rhs.catchain_seqno &&
      lhs.min_ref_mc_seqno == rhs.min_ref_mc_seqno && lhs.is_key_block == rhs.is_key_block &&
      lhs.prev_key_block_seqno == rhs.prev_key_block_seqno && lhs.start_lt == rhs.start_lt &&
      lhs.end_lt == rhs.end_lt && lhs.gen_utime == rhs.gen_utime && lhs.prev_blocks == rhs.prev_blocks &&
      lhs.extra == rhs.extra &&

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

  vb["node_id_short"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.node_id_short};

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

  vb["account"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{value.account};

  vb["lt"] =
      USERVER_NAMESPACE::chaotic::WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>{value.lt};

  vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.hash};


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


bool operator==(
    const ::ton_http::schemas::v2::DetectAddressRequest& lhs, const ::ton_http::schemas::v2::DetectAddressRequest& rhs
) {
  return lhs.address == rhs.address && true;
}


USERVER_NAMESPACE::logging::LogHelper& operator<<(
    USERVER_NAMESPACE::logging::LogHelper& lh, const ::ton_http::schemas::v2::DetectAddressRequest& value
) {
  return lh << ToString(USERVER_NAMESPACE::formats::json::ValueBuilder(value).ExtractValue());
}


DetectAddressRequest Parse(
    USERVER_NAMESPACE::formats::json::Value json,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressRequest> to
) {
  return Parse<USERVER_NAMESPACE::formats::json::Value>(json, to);
}


USERVER_NAMESPACE::formats::json::Value Serialize(
    [[maybe_unused]] const ::ton_http::schemas::v2::DetectAddressRequest& value,
    USERVER_NAMESPACE::formats::serialize::To<USERVER_NAMESPACE::formats::json::Value>
) {
  USERVER_NAMESPACE::formats::json::ValueBuilder vb = USERVER_NAMESPACE::formats::common::Type::kObject;


  vb["address"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{value.address};


  return vb.ExtractValue();
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
    vb["body"] = USERVER_NAMESPACE::chaotic::
        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{*value.body};
  }

  if (value.init_state) {
    vb["init_state"] = USERVER_NAMESPACE::chaotic::
        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>{*value.init_state};
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
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataDecryptedText::_Type> to
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
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::MsgDataEncryptedText::_Type> to
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

  vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.hash};

  vb["source"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{value.source};

  vb["destination"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{value.destination};

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

  vb["body_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.body_hash};

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

  vb["sync_utime"] = USERVER_NAMESPACE::chaotic::Primitive<int>{value.sync_utime};

  vb["account_state"] =
      USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw>{value.account_state};

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

  vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.hash};

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

  vb["state_root_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.state_root_hash};

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

  vb["hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.hash};

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

  vb["body_hash"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>{value.body_hash};

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


bool operator==(
    const ::ton_http::schemas::v2::TonlibErrorResponse& lhs, const ::ton_http::schemas::v2::TonlibErrorResponse& rhs
) {
  return lhs.ok == rhs.ok && lhs.error == rhs.error && lhs.code == rhs.code && lhs._extra == rhs._extra && true;
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

  if (value.error) {
    vb["error"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value.error};
  }

  if (value.code) {
    vb["code"] = USERVER_NAMESPACE::chaotic::Primitive<
        int,
        USERVER_NAMESPACE::chaotic::Minimum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMinimum>,
        USERVER_NAMESPACE::chaotic::Maximum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMaximum>>{*value.code};
  }

  if (value._extra) {
    vb["@extra"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{*value._extra};
  }


  return vb.ExtractValue();
}


bool operator==(
    const ::ton_http::schemas::v2::TonlibResponse& lhs, const ::ton_http::schemas::v2::TonlibResponse& rhs
) {
  return lhs.ok == rhs.ok && lhs.result == rhs.result && lhs._extra == rhs._extra && true;
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
      USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
          &::ton_http::schemas::v2::kTonlibObject_Settings,
          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress>,
          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo>,
          USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash>>>{value.result};

  vb["@extra"] = USERVER_NAMESPACE::chaotic::Primitive<std::string>{value._extra};


  return vb.ExtractValue();
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

  vb["account"] = USERVER_NAMESPACE::chaotic::
      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>{value.account};

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
    std::string_view value,
    USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation::Wallet_Type>
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
    vb["seqno"] = USERVER_NAMESPACE::chaotic::Primitive<int>{*value.seqno};
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


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountAddress::_Type>::format(
    const ::ton_http::schemas::v2::AccountAddress::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateEnum>::format(
    const ::ton_http::schemas::v2::AccountStateEnum& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::AccountStateRaw::_Type>::format(
    const ::ton_http::schemas::v2::AccountStateRaw::_Type& value, fmt::format_context& ctx
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


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>::format(
    const ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type& value, fmt::format_context& ctx
) const {
  return fmt::format_to(ctx.out(), "{}", ToString(value));
}


fmt::format_context::iterator fmt::formatter<::ton_http::schemas::v2::MasterchainInfo::_Type>::format(
    const ::ton_http::schemas::v2::MasterchainInfo::_Type& value, fmt::format_context& ctx
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

