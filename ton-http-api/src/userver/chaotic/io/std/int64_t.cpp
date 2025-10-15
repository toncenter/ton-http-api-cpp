#include "int64_t.hpp"

std::int64_t userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<std::int64_t>) {
  return std::int64_t{std::stoll(value)};
}
std::string userver::chaotic::convert::Convert(const std::int64_t& value, chaotic::convert::To<std::string>) {
  return std::to_string(value);
}
std::int64_t userver::chaotic::convert::Convert(const std::string_view& value, chaotic::convert::To<std::int64_t>) {
  return Convert(std::string{value}, chaotic::convert::To<std::int64_t>{});
}
