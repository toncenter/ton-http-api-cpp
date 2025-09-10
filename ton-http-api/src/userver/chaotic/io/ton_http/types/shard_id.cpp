#include "shard_id.hpp"
#include "utils/exceptions.hpp"

ton_http::types::shard_id
userver::chaotic::convert::Convert(const std::string& value, chaotic::convert::To<ton_http::types::shard_id>) {
  try {
    return ton_http::types::shard_id{std::stoll(value)};
  } catch (...) {
    throw ton_http::utils::ParsingException{"Failed to parse shard_id: '" + value + "'"};
  }
}
std::string
userver::chaotic::convert::Convert(const ton_http::types::shard_id& value, chaotic::convert::To<std::string>) {
  return std::to_string(value.GetUnderlying());
}
