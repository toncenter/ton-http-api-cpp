#include "ton_hash.hpp"

#include "td/utils/base64.h"
#include "td/utils/misc.h"
#include "utils/exceptions.hpp"


ton_http::types::ton_hash
userver::chaotic::convert::Convert(const std::string& str, chaotic::convert::To<ton_http::types::ton_hash>) {
  if (str.empty()) {
    return ton_http::types::ton_hash{str};
  }

  if (str.length() == 44) {
    if (auto res = td::base64_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash{res.move_as_ok()};
    }
    if (auto res = td::base64url_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash{res.move_as_ok()};
    }
  } else if (str.length() == 43) {
    if (auto res = td::base64url_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash{res.move_as_ok()};
    }
  } else if (str.length() == 64) {
    if (auto res = td::hex_decode(str); res.is_ok()) {
      return ton_http::types::ton_hash{res.move_as_ok()};
    }
  }
  throw ton_http::utils::ParsingException("invalid hash: '" + str + "'");
}
std::string
userver::chaotic::convert::Convert(const ton_http::types::ton_hash& hash, chaotic::convert::To<std::string>) {
  return td::base64_encode(hash.GetUnderlying());
}
