#pragma once
#include <userver/chaotic/convert.hpp>
#include "userver/chaotic/io/userver/utils/strong_typedef.hpp"

namespace ton_http::types {

class int256 : public USERVER_NAMESPACE::utils::StrongTypedef<int256, std::string> {
  using StrongTypedef::StrongTypedef;
};
}  // namespace ton_http::types

namespace chaotic::convert {

ton_http::types::int256
Convert(const std::string& value, USERVER_NAMESPACE::chaotic::convert::To<ton_http::types::int256>);
std::string Convert(const ton_http::types::int256& value, USERVER_NAMESPACE::chaotic::convert::To<std::string>);

}  // namespace chaotic::convert
