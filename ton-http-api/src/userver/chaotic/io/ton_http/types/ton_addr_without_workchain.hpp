#pragma once

#include <userver/chaotic/convert.hpp>
#include <userver/chaotic/io/userver/utils/strong_typedef.hpp>

#include <string>

namespace ton_http::types {
class ton_addr_without_workchain : public USERVER_NAMESPACE::utils::StrongTypedef<ton_addr_without_workchain, std::string> {
  using StrongTypedef::StrongTypedef;
};
}  // namespace ton_http::types

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {

ton_http::types::ton_addr_without_workchain Convert(const std::string& str, chaotic::convert::To<ton_http::types::ton_addr_without_workchain>);
std::string Convert(const ton_http::types::ton_addr_without_workchain& hash, chaotic::convert::To<std::string>);

}  // namespace chaotic::convert

USERVER_NAMESPACE_END
