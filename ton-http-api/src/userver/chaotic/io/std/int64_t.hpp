#pragma once
#include <cstdint>
#include <string>

#include "userver/chaotic/convert/to.hpp"

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {
std::int64_t Convert(const std::string& value, chaotic::convert::To<std::int64_t>);
std::int64_t Convert(const std::string_view& value, chaotic::convert::To<std::int64_t>);
std::string Convert(const std::int64_t& value, chaotic::convert::To<std::string>);
}
USERVER_NAMESPACE_END
