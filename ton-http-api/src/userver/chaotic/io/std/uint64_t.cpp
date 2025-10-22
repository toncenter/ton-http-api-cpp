#include "uint64_t.hpp"

std::uint64_t userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<std::uint64_t>) {
  return std::uint64_t{std::stoull(value)};
}
std::uint64_t userver::chaotic::convert::Convert(const std::string_view& value, chaotic::convert::To<std::uint64_t>) {
  return Convert(std::string{value}, chaotic::convert::To<std::uint64_t>{});
}
std::string userver::chaotic::convert::Convert(const std::uint64_t& value, chaotic::convert::To<std::string>) {
  return std::to_string(value);
}
std::uint64_t userver::chaotic::convert::
  Convert(const std::variant<std::string, std::int64_t>& value, chaotic::convert::To<std::uint64_t>) {
  if (std::holds_alternative<std::string>(value)) {
    auto val = std::get<std::string>(value);
    return Convert(val, chaotic::convert::To<std::uint64_t>{});
  }
  if (std::holds_alternative<std::int64_t>(value)) {
    return std::get<std::int64_t>(value);
  }
  throw std::runtime_error("invalid variant type");
}

