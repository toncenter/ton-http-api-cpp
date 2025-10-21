#pragma once
#include <cstdint>
#include <string>

#include "userver/chaotic/convert/to.hpp"

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {
std::uint64_t Convert(const std::string& value, chaotic::convert::To<std::uint64_t>);
std::uint64_t Convert(const std::string_view& value, chaotic::convert::To<std::uint64_t>);
std::string Convert(const std::uint64_t& value, chaotic::convert::To<std::string>);
}  // namespace chaotic::convert
USERVER_NAMESPACE_END
