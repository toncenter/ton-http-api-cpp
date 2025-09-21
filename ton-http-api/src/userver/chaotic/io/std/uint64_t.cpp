#include "uint64_t.hpp"

std::uint64_t userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<std::uint64_t>) {
  return std::uint64_t{std::stoull(value)};
}
std::string userver::v2_13_rc::Convert(const std::uint64_t& value, chaotic::convert::To<std::string>) {
  return std::to_string(value);
}
