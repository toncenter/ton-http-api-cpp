#pragma once

#include <userver/chaotic/convert.hpp>
#include <userver/chaotic/io/userver/utils/strong_typedef.hpp>

namespace ton_http::types {
class bytes : public USERVER_NAMESPACE::utils::StrongTypedef<bytes, std::string> {
  using StrongTypedef::StrongTypedef;
};
}

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {
ton_http::types::bytes Convert(const std::string& value, chaotic::convert::To<ton_http::types::bytes>);
std::string Convert(const ton_http::types::bytes& value, chaotic::convert::To<std::string>);

}

USERVER_NAMESPACE_END
