#include "HandlerDetectAddress.h"

#include "converters/convert.hpp"

ton_http::handlers::HandlerDetectAddress::HandlerDetectAddress(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}
ton_http::schemas::v2::DetectAddressRequest ton_http::handlers::HandlerDetectAddress::ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::DetectAddressRequest req;

  req.address = userver::chaotic::convert::Convert(request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{});
  return req;
}
ton_http::schemas::v2::DetectAddressRequest ton_http::handlers::HandlerDetectAddress::ParseTonlibPostRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  return request_json.As<ton_http::schemas::v2::DetectAddressRequest>();
}
td::Result<ton_http::schemas::v2::DetectAddress> ton_http::handlers::HandlerDetectAddress::HandleRequestTonlibThrow(
    schemas::v2::DetectAddressRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(&core::TonlibWorker::detectAddress, request.address.GetUnderlying(), session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
