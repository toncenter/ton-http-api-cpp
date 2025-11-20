#include "ton_addr_without_workchain.hpp"

#include "block.h"
#include "ton_hash.hpp"


ton_http::types::ton_addr_without_workchain
userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<ton_http::types::ton_addr_without_workchain>) {
  auto r_addr = block::StdAddress::parse(value);
  if (r_addr.is_ok()) {
    auto addr = r_addr.move_as_ok();
    return ton_http::types::ton_addr_without_workchain{addr.addr.as_slice().str()};
  }
  auto hash = Convert(value, convert::To<ton_http::types::ton_hash>{});
  return ton_http::types::ton_addr_without_workchain{hash.GetUnderlying()};
}
std::string
userver::chaotic::convert::Convert(const ton_http::types::ton_addr_without_workchain& addr, chaotic::convert::To<std::string>) {
  return addr.GetUnderlying();
}
