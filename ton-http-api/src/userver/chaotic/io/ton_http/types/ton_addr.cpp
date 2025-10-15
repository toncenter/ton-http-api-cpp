#include "ton_addr.hpp"

#include "block.h"
#include "utils/exceptions.hpp"


ton_http::types::ton_addr
userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<ton_http::types::ton_addr>) {
  auto r_addr = block::StdAddress::parse(value);
  if (r_addr.is_error()) {
    throw ton_http::utils::TonlibException{"Failed to parse ton_addr: '" + value + "'", 422};
  }
  auto addr = r_addr.move_as_ok();
  if (value.find(':') != std::string::npos) {
    auto raw_addr = fmt::format("{}:{}", addr.workchain, td::hex_encode(addr.addr.as_slice()));
    return ton_http::types::ton_addr{raw_addr};
  }

  return ton_http::types::ton_addr{addr.rserialize()};
}
std::string
userver::chaotic::convert::Convert(const ton_http::types::ton_addr& hash, chaotic::convert::To<std::string>) {
  return hash.GetUnderlying();
}
