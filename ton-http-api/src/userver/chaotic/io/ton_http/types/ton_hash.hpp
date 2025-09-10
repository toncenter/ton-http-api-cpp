#pragma once

#include <userver/chaotic/convert.hpp>
#include <userver/chaotic/io/userver/utils/strong_typedef.hpp>

#include <string>

namespace ton_http::types {
class ton_hash : public USERVER_NAMESPACE::utils::StrongTypedef<ton_hash, std::string> {
  using StrongTypedef::StrongTypedef;
};
}

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {

ton_http::types::ton_hash Convert(const std::string& str, chaotic::convert::To<ton_http::types::ton_hash>);
std::string Convert(const ton_http::types::ton_hash& hash, chaotic::convert::To<std::string>);

}

USERVER_NAMESPACE_END
