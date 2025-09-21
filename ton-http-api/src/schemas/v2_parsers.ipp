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
  res.account_address = value["account_address"]
                            .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
                                USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                                ton_http::types::bytes>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__AccountAddress_PropertiesNames
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

  res._type = value["@type"]
                  .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw::_Type>>(
                      ::ton_http::schemas::v2::AccountStateRaw::_Type::kRawAccountstate
                  );
  res.code =
      value["code"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.data =
      value["data"]
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
  res.lt = value["lt"]
               .template As<USERVER_NAMESPACE::chaotic::
                                WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
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

  res._type =
      value["@type"]
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
  res.code =
      value["code"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.data =
      value["data"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.frozen_hash =
      value["frozen_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.sync_utime = value["sync_utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.state =
      value["state"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateEnum>>();
  res.suspended = value["suspended"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__AddressInformation_PropertiesNames
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
  res.start_lt = value["start_lt"]
                     .template As<USERVER_NAMESPACE::chaotic::
                                      WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
  res.end_lt = value["end_lt"]
                   .template As<USERVER_NAMESPACE::chaotic::
                                    WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
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
  res.proof =
      value["proof"]
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
  res.lt = value["lt"]
               .template As<USERVER_NAMESPACE::chaotic::
                                WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
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

  res._type =
      value["@type"]
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
  res.bytes =
      value["bytes"]
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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ConsensusBlock___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::ConsensusBlock::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::ConsensusBlock::_Type::kExtConsensusblock, "ext.consensusBlock"
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
          ::ton_http::schemas::v2::ConsensusBlock::_Type::kExtConsensusblock
      );
  res.consensus_block = value["consensus_block"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();
  res.timestamp = value["timestamp"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::int32_t>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__ConsensusBlock_PropertiesNames
  );

  return res;
}


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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DetectAddress___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::DetectAddress::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::DetectAddress::_Type::kUtilsDetectedaddress, "utils.detectedAddress"
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
          ::ton_http::schemas::v2::DetectAddress::_Type::kUtilsDetectedaddress
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


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__DetectAddressRequest_PropertiesNames =
    [](auto selector) {
      return selector().template Type<std::string_view>().Case("address");
    };


template <typename Value>
::ton_http::schemas::v2::DetectAddressRequest Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::DetectAddressRequest>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::DetectAddressRequest res;

  res.address =
      value["address"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__DetectAddressRequest_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__DetectHash___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::DetectHash::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::DetectHash::_Type::kUtilsDetectedhash, "utils.detectedHash"
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
          ::ton_http::schemas::v2::DetectHash::_Type::kUtilsDetectedhash
      );
  res.b64 = value["b64"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.b64url = value["b64url"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();
  res.hex = value["hex"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__DetectHash_PropertiesNames
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
  res.body = value["body"]
                 .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
                     USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                     ton_http::types::bytes>>>();
  res.init_state = value["init_state"]
                       .template As<std::optional<USERVER_NAMESPACE::chaotic::WithType<
                           USERVER_NAMESPACE::chaotic::Primitive<std::string>,
                           ton_http::types::bytes>>>();


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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ExtMessage___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::ExtMessage::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::ExtMessage::_Type::kExtMessage, "ext.message"
      );
    };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ExtMessage_PropertiesNames =
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
::ton_http::schemas::v2::ExtMessage::_Type Parse(
    Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ExtMessage___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
      fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtMessage::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ExtMessage Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtMessage>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ExtMessage res;

  res._type =
      value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage::_Type>>(
          ::ton_http::schemas::v2::ExtMessage::_Type::kExtMessage
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
  res.value =
      value["value"]
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
  res.created_lt = value["created_lt"]
                       .template As<USERVER_NAMESPACE::chaotic::
                                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
  res.body_hash =
      value["body_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.msg_data = value["msg_data"]
                     .template As<USERVER_NAMESPACE::chaotic::Variant<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>>();
  res.message = value["message"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.message_decode_error =
      value["message_decode_error"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__ExtMessage_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__ExtTransaction___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::ExtTransaction::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::ExtTransaction::_Type::kExtTransaction, "ext.transaction"
      );
    };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__ExtTransaction_PropertiesNames =
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
::ton_http::schemas::v2::ExtTransaction::_Type Parse(
    Value val, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction::_Type>
) {
  const auto value = val.template As<std::string>();
  const auto result = k__ton_http__schemas__v2__ExtTransaction___Type_Mapping.TryFindBySecond(value);
  if (result.has_value()) {
    return *result;
  }
  USERVER_NAMESPACE::chaotic::ThrowForValue(
      fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::ExtTransaction::_Type", value), val
  );
}


template <typename Value>
::ton_http::schemas::v2::ExtTransaction Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::ExtTransaction>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::ExtTransaction res;

  res._type =
      value["@type"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtTransaction::_Type>>(
          ::ton_http::schemas::v2::ExtTransaction::_Type::kExtTransaction
      );
  res.address =
      value["address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.utime = value["utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.data =
      value["data"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.transaction_id =
      value["transaction_id"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.fee =
      value["fee"]
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
      value["in_msg"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage>>();
  res.out_msgs = value["out_msgs"]
                     .template As<USERVER_NAMESPACE::chaotic::Array<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtMessage>,
                         std::vector<::ton_http::schemas::v2::ExtMessage>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__ExtTransaction_PropertiesNames
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
          .template As<
              USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ExtendedAddressInformation::_Type>>(
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
  res.sync_utime = value["sync_utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.account_state =
      value["account_state"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountStateRaw>>();
  res.revision = value["revision"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__ExtendedAddressInformation_PropertiesNames
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
  res.data =
      value["data"]
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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap
    k__ton_http__schemas__v2__MasterchainBlockSignatures___Type_Mapping = [](auto selector) {
      return selector()
          .template Type<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type, std::string_view>()
          .Case(
              ::ton_http::schemas::v2::MasterchainBlockSignatures::_Type::kBlocksBlocksignatures,
              "blocks.blockSignatures"
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
          .template As<
              USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainBlockSignatures::_Type>>(
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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__MasterchainInfo___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::MasterchainInfo::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::MasterchainInfo::_Type::kBlocksMasterchaininfo, "blocks.masterchainInfo"
      );
    };


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__MasterchainInfo_PropertiesNames =
    [](auto selector) {
      return selector()
          .template Type<std::string_view>()
          .Case("@type")
          .Case("last")
          .Case("state_root_hash")
          .Case("init");
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

  res._type = value["@type"]
                  .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo::_Type>>(
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


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__Message___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::Message::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::Message::_Type::kRawMessage, "raw.message"
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
          .Case("msg_data");
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
          ::ton_http::schemas::v2::Message::_Type::kRawMessage
      );
  res.hash =
      value["hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.source =
      value["source"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.destination = value["destination"]
                        .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.value =
      value["value"]
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
  res.created_lt = value["created_lt"]
                       .template As<USERVER_NAMESPACE::chaotic::
                                        WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, std::uint64_t>>();
  res.body_hash =
      value["body_hash"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_hash>>();
  res.msg_data = value["msg_data"]
                     .template As<USERVER_NAMESPACE::chaotic::Variant<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataRaw>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataText>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataDecryptedText>,
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MsgDataEncryptedText>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(value, k__ton_http__schemas__v2__Message_PropertiesNames);

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

  res._type = value["@type"]
                  .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSize::_Type>>(
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

  res._type = value["@type"]
                  .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::OutMsgQueueSizes::_Type>>(
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
  res.proof =
      value["proof"]
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

  res._type = value["@type"]
                  .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::ShardBlockProof::_Type>>(
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


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonlibErrorResponse_PropertiesNames =
    [](auto selector) {
      return selector().template Type<std::string_view>().Case("ok").Case("error").Case("code").Case("@extra");
    };


template <typename Value>
::ton_http::schemas::v2::TonlibErrorResponse Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::TonlibErrorResponse>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::TonlibErrorResponse res;

  res.ok = value["ok"].template As<USERVER_NAMESPACE::chaotic::Primitive<bool>>(false);
  res.error = value["error"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();
  res.code =
      value["code"]
          .template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<
              int,
              USERVER_NAMESPACE::chaotic::Minimum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMinimum>,
              USERVER_NAMESPACE::chaotic::Maximum<::ton_http::schemas::v2::TonlibErrorResponse::kCodeMaximum>>>>();
  res._extra = value["@extra"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<std::string>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__TonlibErrorResponse_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialSet k__ton_http__schemas__v2__TonlibResponse_PropertiesNames =
    [](auto selector) {
      return selector().template Type<std::string_view>().Case("ok").Case("result").Case("@extra");
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
                       USERVER_NAMESPACE::chaotic::OneOfWithDiscriminator<
                           &::ton_http::schemas::v2::kTonlibObject_Settings,
                           USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectAddress>,
                           USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::MasterchainInfo>,
                           USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::DetectHash>>>>();
  res._extra = value["@extra"].template As<USERVER_NAMESPACE::chaotic::Primitive<std::string>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__TonlibResponse_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__Transaction___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::Transaction::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::Transaction::_Type::kRawTransaction, "raw.transaction"
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
          ::ton_http::schemas::v2::Transaction::_Type::kRawTransaction
      );
  res.address =
      value["address"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::AccountAddress>>();
  res.account =
      value["account"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::ton_addr>>();
  res.utime = value["utime"].template As<USERVER_NAMESPACE::chaotic::Primitive<int>>();
  res.data =
      value["data"]
          .template As<USERVER_NAMESPACE::chaotic::
                           WithType<USERVER_NAMESPACE::chaotic::Primitive<std::string>, ton_http::types::bytes>>();
  res.transaction_id =
      value["transaction_id"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::InternalTransactionId>>();
  res.fee =
      value["fee"]
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
  res.in_msg = value["in_msg"].template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>>();
  res.out_msgs = value["out_msgs"]
                     .template As<USERVER_NAMESPACE::chaotic::Array<
                         USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::Message>,
                         std::vector<::ton_http::schemas::v2::Message>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__Transaction_PropertiesNames
  );

  return res;
}


static constexpr USERVER_NAMESPACE::utils::TrivialBiMap k__ton_http__schemas__v2__WalletInformation___Type_Mapping =
    [](auto selector) {
      return selector().template Type<::ton_http::schemas::v2::WalletInformation::_Type, std::string_view>().Case(
          ::ton_http::schemas::v2::WalletInformation::_Type::kWalletinformation, "walletInformation"
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
      fmt::format("Invalid enum value ({}) for type ::ton_http::schemas::v2::WalletInformation::Wallet_Type", value),
      val
  );
}


template <typename Value>
::ton_http::schemas::v2::WalletInformation Parse(
    Value value, USERVER_NAMESPACE::formats::parse::To<::ton_http::schemas::v2::WalletInformation>
) {
  value.CheckNotMissing();
  value.CheckObjectOrNull();

  ::ton_http::schemas::v2::WalletInformation res;

  res._type =
      value["@type"]
          .template As<USERVER_NAMESPACE::chaotic::Primitive<::ton_http::schemas::v2::WalletInformation::_Type>>(
              ::ton_http::schemas::v2::WalletInformation::_Type::kWalletinformation
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
  res.seqno = value["seqno"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<int>>>();
  res.wallet_id = value["wallet_id"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<int>>>();
  res.is_signature_allowed =
      value["is_signature_allowed"].template As<std::optional<USERVER_NAMESPACE::chaotic::Primitive<bool>>>();


  USERVER_NAMESPACE::chaotic::ValidateNoAdditionalProperties(
      value, k__ton_http__schemas__v2__WalletInformation_PropertiesNames
  );

  return res;
}


}  // namespace v2
}  // namespace schemas
}  // namespace ton_http

