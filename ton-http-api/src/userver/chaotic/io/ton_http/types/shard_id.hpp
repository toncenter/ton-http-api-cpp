#pragma once

#include <userver/chaotic/convert.hpp>
#include <userver/chaotic/io/userver/utils/strong_typedef.hpp>

namespace ton_http::types {
class shard_id : public USERVER_NAMESPACE::utils::StrongTypedef<shard_id, std::int64_t> {
  using StrongTypedef::StrongTypedef;
};
}

USERVER_NAMESPACE_BEGIN

namespace chaotic::convert {

ton_http::types::shard_id Convert(const std::string& value, chaotic::convert::To<ton_http::types::shard_id>);
std::string Convert(const ton_http::types::shard_id& value, chaotic::convert::To<std::string>);

}

USERVER_NAMESPACE_END
