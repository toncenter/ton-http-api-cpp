#include "DetectHashHandler.h"
#include "converters/convert.hpp"
#include "utils/exceptions.hpp"

ton_http::handlers::DetectHashHandler::DetectHashHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::DetectHashRequest ton_http::handlers::DetectHashHandler::ParseTonlibGetRequest(
  const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::DetectHashRequest req;

  req.hash = userver::chaotic::convert::Convert(
    request.GetArg("hash"), userver::chaotic::convert::To<ton_http::types::ton_hash>{}
  );
  return req;
}
td::Result<ton_http::schemas::v2::DetectHash> ton_http::handlers::DetectHashHandler::HandleRequestTonlibThrow(
  schemas::v2::DetectHashRequest& request, multiclient::SessionPtr& session
) const {
  auto result =
    tonlib_component_.DoStaticRequest(&core::TonlibWorker::detectHash, request.hash.GetUnderlying(), session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
