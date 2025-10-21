#include "bytes.hpp"

#include "td/utils/base64.h"
#include "utils/exceptions.hpp"


ton_http::types::bytes
userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<ton_http::types::bytes>) {
  if (value.empty()) {
    return ton_http::types::bytes{};
  }
  auto res = td::base64_decode(value);
  if (res.is_error()) {
    throw ton_http::utils::TonlibException("invalid base64 encoded bytes: " + res.move_as_error().message().str(), 422);
  }
  return ton_http::types::bytes{res.move_as_ok()};
}
ton_http::types::bytes
userver::chaotic::convert::Convert(const std::string_view& value, chaotic::convert::To<ton_http::types::bytes>) {
  return Convert(std::string{value}, chaotic::convert::To<ton_http::types::bytes>{});
}
std::string userver::chaotic::convert::Convert(const ton_http::types::bytes& value, chaotic::convert::To<std::string>) {
  if (value.GetUnderlying().empty()) {
    return "";
  }
  return td::base64_encode(value.GetUnderlying());
}
