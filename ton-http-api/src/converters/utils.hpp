#include "auto/tl/tonlib_api.h"
#include "core/types.hpp"
#include "schemas/v2.hpp"
#include "td/utils/base64.h"

namespace ton_http::converters {

using namespace ton;

inline schemas::v2::DetectAddress Convert(core::DetectAddressResult& value) {
  schemas::v2::DetectAddress result;
  result.raw_form = value.to_raw_form(true);

  block::StdAddress b_addr(value.address);
  b_addr.bounceable = false;
  result.bounceable =  schemas::v2::DetectAddressBase64Variant{b_addr.rserialize(false), b_addr.rserialize(true)};

  b_addr.bounceable = true;
  result.non_bounceable = schemas::v2::DetectAddressBase64Variant{b_addr.rserialize(false), b_addr.rserialize(true)};
  if (value.given_type == "raw_form") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kRawForm;
  } else if (value.given_type == "friendly_bounceable") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kFriendlyBounceable;
  } else if (value.given_type == "friendly_non_bounceable") {
    result.given_type = schemas::v2::DetectAddress::Given_Type::kFriendlyNonBounceable;
  } else {
    throw std::runtime_error("Unknown given type, this should not happen");
  }
  result.test_only = value.address.testnet;
  return result;
}

inline schemas::v2::DetectHash Convert(core::DetectHashResult& value) {
  schemas::v2::DetectHash result;
  result.b64 = td::base64_encode(value.hash);
  result.b64url = td::base64url_encode(value.hash);
  result.hex = td::hex_encode(value.hash);
  return result;
}

}
