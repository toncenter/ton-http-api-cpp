#include "ton_hash_hex.hpp"

#include "td/utils/base64.h"
#include "td/utils/misc.h"
#include "utils/exceptions.hpp"


ton_http::types::ton_hash_hex
userver::chaotic::convert::Convert(const std::string& str, chaotic::convert::To<ton_http::types::ton_hash_hex>) {
  if (str.empty()) {
    return ton_http::types::ton_hash_hex{""};
  }

  if (str.length() == 44) {
    if (auto res = td::base64_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash_hex{res.move_as_ok()};
    }
    if (auto res = td::base64url_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash_hex{res.move_as_ok()};
    }
  } else if (str.length() == 43) {
    if (auto res = td::base64url_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash_hex{res.move_as_ok()};
    }
  } else if (str.length() == 64) {
    if (auto res = td::hex_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash_hex{res.move_as_ok()};
    }
  }
  throw ton_http::utils::TonlibException("invalid hash: '" + str + "'", 422);
}
std::string
userver::chaotic::convert::Convert(const ton_http::types::ton_hash_hex& hash, chaotic::convert::To<std::string>) {
  return td::hex_encode(hash.GetUnderlying());
}
