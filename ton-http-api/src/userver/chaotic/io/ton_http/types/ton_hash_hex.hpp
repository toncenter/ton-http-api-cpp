#pragma once

#include <userver/chaotic/convert.hpp>
#include <userver/chaotic/io/userver/utils/strong_typedef.hpp>

#include <string>

namespace ton_http::types {
class ton_hash_hex : public USERVER_NAMESPACE::utils::StrongTypedef<ton_hash_hex, std::string> {
  using StrongTypedef::StrongTypedef;
};
}  // namespace ton_http::types

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {

ton_http::types::ton_hash_hex Convert(const std::string& str, chaotic::convert::To<ton_http::types::ton_hash_hex>);
std::string Convert(const ton_http::types::ton_hash_hex& hash, chaotic::convert::To<std::string>);

}  // namespace chaotic::convert

USERVER_NAMESPACE_END
