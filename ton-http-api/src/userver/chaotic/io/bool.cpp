#include "bool.hpp"

bool userver::chaotic::convert::
  Convert(const std::variant<std::string, std::int32_t, bool>& value, userver::chaotic::convert::To<bool>) {
  if (std::holds_alternative<bool>(value)) {
    return std::get<bool>(value);
  }
  if (std::holds_alternative<std::int32_t>(value)) {
    return std::get<std::int32_t>(value) != 0;
  }
  if (std::holds_alternative<std::string>(value)) {
    auto str = std::get<std::string>(value);
    std::ranges::transform(str, str.begin(), ::tolower);
    if (str == "y" || str == "yes" || str == "t" || str == "true" || str == "on" || str == "1") {
      return true;
    }
    if (str == "n" || str == "no" || str == "f" || str == "false" || str == "off" || str == "0") {
      return false;
    }
  }
  throw std::runtime_error("invalid variant type");
}
