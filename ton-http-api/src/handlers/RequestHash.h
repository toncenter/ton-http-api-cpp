#pragma once

#include <cstddef>
#include <functional>
#include <optional>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

#include <boost/container_hash/hash.hpp>
#include <boost/pfr/core.hpp>
#include <userver/utils/box.hpp>
#include <userver/utils/strong_typedef.hpp>

#include "schemas/v2.hpp"

namespace ton_http::handlers::detail {

template <typename T, typename... Types>
inline constexpr bool kIsOneOf = (std::is_same_v<T, Types> || ...);

// Opt in schema aggregates, not arbitrary objects with potentially non-value fields.
// PFR visits every field, so adding a field cannot silently omit it from the hash.
template <typename T>
inline constexpr bool kIsRequestAggregate = kIsOneOf<
  T,
  schemas::v2::AddressWithSeqnoRequest,
  schemas::v2::AddressRequest,
  schemas::v2::BlockDataRequest,
  schemas::v2::BlockHeaderRequest,
  schemas::v2::BlockTransactionsRequest,
  schemas::v2::ConfigAllRequest,
  schemas::v2::ConfigParamRequest,
  schemas::v2::EmptyRequest,
  schemas::v2::DetectHashRequest,
  schemas::v2::DnsResolveRequest,
  schemas::v2::EstimateFeeRequest,
  schemas::v2::LibrariesRequest,
  schemas::v2::LookupBlockRequest,
  schemas::v2::SeqnoRequest,
  schemas::v2::RunGetMethodRequest,
  schemas::v2::RunGetMethodStdRequest,
  schemas::v2::SendBocRequest,
  schemas::v2::ShardBlockProofRequest,
  schemas::v2::TransactionsRequest,
  schemas::v2::TryLocateTxRequest,
  schemas::v2::LegacyTvmCell,
  schemas::v2::LegacyTvmCell::Data,
  schemas::v2::LegacyStackEntryCell,
  schemas::v2::TvmCell,
  schemas::v2::TvmSlice,
  schemas::v2::TvmNumberDecimal,
  schemas::v2::TvmTuple,
  schemas::v2::TvmList,
  schemas::v2::TvmStackEntryCell,
  schemas::v2::TvmStackEntrySlice,
  schemas::v2::TvmStackEntryNumber,
  schemas::v2::TvmStackEntryTuple,
  schemas::v2::TvmStackEntryList,
  schemas::v2::TvmStackEntryUnsupported>;

template <typename T, template <typename...> typename Template>
inline constexpr bool kIsInstantiation = false;

template <template <typename...> typename Template, typename... Args>
inline constexpr bool kIsInstantiation<Template<Args...>, Template> = true;

template <typename T>
void AppendRequestHash(std::size_t& seed, const T& value) {
  if constexpr (std::is_integral_v<T> || std::is_enum_v<T> || std::is_same_v<T, std::string>) {
    boost::hash_combine(seed, value);
  } else if constexpr (userver::utils::IsStrongTypedef<T>::value) {
    AppendRequestHash(seed, value.GetUnderlying());
  } else if constexpr (kIsInstantiation<T, std::optional>) {
    AppendRequestHash(seed, value.has_value());
    if (value)
      AppendRequestHash(seed, *value);
  } else if constexpr (kIsInstantiation<T, std::variant>) {
    AppendRequestHash(seed, value.index());
    std::visit([&seed](const auto& item) { AppendRequestHash(seed, item); }, value);
  } else if constexpr (kIsInstantiation<T, std::vector>) {
    AppendRequestHash(seed, value.size());
    for (const auto& item : value)
      AppendRequestHash(seed, item);
  } else if constexpr (kIsInstantiation<T, userver::utils::Box>) {
    AppendRequestHash(seed, *value);
  } else if constexpr (kIsRequestAggregate<T>) {
    static_assert(std::is_aggregate_v<T>, "Cache key schema must remain an aggregate");
    AppendRequestHash(seed, boost::pfr::tuple_size_v<T>);
    boost::pfr::for_each_field(value, [&seed](const auto& field) { AppendRequestHash(seed, field); });
  } else {
    static_assert(kIsOneOf<T>, "Unsupported cache key field: add explicit value hashing support");
  }
}

template <typename T>
std::size_t StructuralHash(const T& value) {
  std::size_t seed = 0;
  AppendRequestHash(seed, value);
  return seed;
}

}  // namespace ton_http::handlers::detail
