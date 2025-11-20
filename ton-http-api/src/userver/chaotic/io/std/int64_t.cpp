#include "int64_t.hpp"
#include <boost/lexical_cast.hpp>

std::int64_t userver::chaotic::convert::Convert(const std::string& value, userver::chaotic::convert::To<std::int64_t>) {
  return boost::lexical_cast<std::int64_t>(value);
}
std::string userver::chaotic::convert::Convert(const std::int64_t& value, userver::chaotic::convert::To<std::string>) {
  return std::to_string(value);
}
std::int64_t userver::chaotic::convert::Convert(const std::string_view& value, userver::chaotic::convert::To<std::int64_t>) {
  return Convert(std::string{value}, userver::chaotic::convert::To<std::int64_t>{});
}
std::int64_t userver::chaotic::convert::
  Convert(const std::variant<std::string, std::int64_t>& value, userver::chaotic::convert::To<std::int64_t>) {
  if (std::holds_alternative<std::string>(value)) {
      auto val = std::get<std::string>(value);
      return Convert(val, userver::chaotic::convert::To<std::int64_t>{});
  }
  if (std::holds_alternative<std::int64_t>(value)) {
      return std::get<std::int64_t>(value);
  }
  throw std::runtime_error("invalid variant type");
}
