#include "PackAddressHandler.h"

#include "converters/convert.hpp"

ton_http::handlers::PackAddressHandler::PackAddressHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::PackAddressRequest ton_http::handlers::PackAddressHandler::ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::PackAddressRequest req;

  req.address = userver::chaotic::convert::Convert(request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{});
  return req;
}
td::Result<ton_http::schemas::v2::PackAddress> ton_http::handlers::PackAddressHandler::HandleRequestTonlibThrow(
    schemas::v2::PackAddressRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(&core::TonlibWorker::packAddress, request.address.GetUnderlying(), session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return result_ok;
}
