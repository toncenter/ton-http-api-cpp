#pragma once
#include <string>
#include <variant>
#include <cstdint>
#include "userver/chaotic/convert/to.hpp"

USERVER_NAMESPACE_BEGIN
namespace chaotic::convert {
bool Convert(const std::variant<std::string, std::int32_t, bool>& value, chaotic::convert::To<bool>);
}  // namespace chaotic::convert
USERVER_NAMESPACE_END
