#include "tonlib_worker.h"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<DetectAddressResult> TonlibWorker::detectAddress(const std::string& address, multiclient::SessionPtr) {
  auto r_std_address = block::StdAddress::parse(address);
  if (r_std_address.is_error()) {
    return r_std_address.move_as_error();
  }
  const auto std_address = r_std_address.move_as_ok();
  std::string given_type = "raw_form";
  if (address.length() == 48) {
    given_type = std::string("friendly_") + (std_address.bounceable ? "bounceable" : "non_bounceable");
  }
  DetectAddressResult result{std_address, given_type};
  return std::move(result);
}
td::Result<std::string> TonlibWorker::packAddress(const std::string& address, multiclient::SessionPtr) {
  auto r_std_address = block::StdAddress::parse(address);
  if (r_std_address.is_error()) {
    return r_std_address.move_as_error();
  }
  const auto std_address = r_std_address.move_as_ok();
  return std_address.rserialize(true);
}

td::Result<std::string> TonlibWorker::unpackAddress(const std::string& address, multiclient::SessionPtr) {
  auto r_std_address = block::StdAddress::parse(address);
  if (r_std_address.is_error()) {
    return r_std_address.move_as_error();
  }
  const auto std_address = r_std_address.move_as_ok();
  std::stringstream ss;
  ss << std_address.workchain << ":" << std_address.addr.to_hex();
  return ss.str();
}
td::Result<DetectHashResult> TonlibWorker::detectHash(const std::string& hash, multiclient::SessionPtr) {
  if (hash.empty()) {
    return td::Status::Error(422, "empty hash");
  }
  DetectHashResult result{hash};
  return std::move(result);
}
}  // namespace ton_http::core
