#pragma once
#include <string>

#include "userver/chaotic/convert/to.hpp"

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {
std::int32_t Convert(const std::string& value, chaotic::convert::To<std::int32_t>);
std::int32_t Convert(const std::string_view& value, chaotic::convert::To<std::int32_t>);
std::int32_t Convert(const std::variant<std::string, std::int32_t>& value, chaotic::convert::To<std::int32_t>);
std::string Convert(const std::int32_t& value, chaotic::convert::To<std::string>);
}  // namespace chaotic::convert
USERVER_NAMESPACE_END
