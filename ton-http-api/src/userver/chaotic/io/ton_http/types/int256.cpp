#include "int256.hpp"

#include "common/refint.h"
#include "utils/exceptions.hpp"


ton_http::types::int256
chaotic::convert::Convert(const std::string& value, userver::chaotic::convert::To<ton_http::types::int256>) {
  auto integer = td::string_to_int256(value);
  if (integer.is_null()) {
    throw ton_http::utils::TonlibException{"Failed to parse int256: '" + value + "'", 422};
  }
  return ton_http::types::int256{integer->to_dec_string()};
}

std::string
chaotic::convert::Convert(const ton_http::types::int256& value, userver::chaotic::convert::To<std::string>) {
  return value.GetUnderlying();
}
