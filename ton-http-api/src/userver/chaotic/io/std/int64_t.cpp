#include "int64_t.hpp"

std::int64_t userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<std::int64_t>) {
  return std::int64_t{std::stoll(value)};
}
std::string userver::v2_13_rc::Convert(const std::int64_t& value, chaotic::convert::To<std::string>) {
  return std::to_string(value);
}
