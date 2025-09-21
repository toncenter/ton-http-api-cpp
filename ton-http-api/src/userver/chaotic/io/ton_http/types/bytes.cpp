#include "bytes.hpp"

#include "td/utils/base64.h"
#include "utils/exceptions.hpp"


ton_http::types::bytes userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<ton_http::types::bytes>) {
  if (value.empty()) {
    return ton_http::types::bytes{};
  }
  auto res = td::base64_decode(value);
  if (res.is_error()) {
    throw ton_http::utils::ParsingException("invalid base64 encoded bytes: " + res.move_as_error().message().str());
  }
  return ton_http::types::bytes{res.move_as_ok()};
}
std::string userver::chaotic::convert::Convert(const ton_http::types::bytes& value, chaotic::convert::To<std::string>) {
  if (value.GetUnderlying().empty()) {
    return "";
  }
  return td::base64_encode(value.GetUnderlying());
}
