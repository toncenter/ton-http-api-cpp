#include "UnpackAddressHandler.h"

#include "converters/convert.hpp"

ton_http::handlers::UnpackAddressHandler::UnpackAddressHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::UnpackAddressRequest ton_http::handlers::UnpackAddressHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::UnpackAddressRequest req;

  req.address = userver::chaotic::convert::Convert(
    request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
  );
  return req;
}
td::Result<ton_http::schemas::v2::UnpackAddress> ton_http::handlers::UnpackAddressHandler::HandleRequestTonlibThrow(
  schemas::v2::UnpackAddressRequest& request, multiclient::SessionPtr& session
) const {
  auto result =
    tonlib_component_.DoStaticRequest(&core::TonlibWorker::unpackAddress, request.address.GetUnderlying(), session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return result_ok;
}
