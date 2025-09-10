#include "TonlibRequestHandler.h"

#include "userver/components/component_context.hpp"
#include "userver/logging/component.hpp"
#include "schemas/v2.hpp"


userver::formats::json::Value ton_http::handlers::TonlibRequestHandler::HandleRequestJsonThrow(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  auto session = tonlib_component_.GetNewSession();

  auto result = HandleRequestTonlibThrow(request, request_json, context, session);

  schemas::v2::TonResponse response;
  if (result.is_error()) {
    auto tonlib_error = result.move_as_error();
    response.ok = false;
    response.error = tonlib_error.message().str();
    response.code = tonlib_error.code();
  } else {
    response.ok = true;
    response.result = result.move_as_ok();
  }
  response._extra = session->to_string();
  return userver::formats::json::ValueBuilder{response}.ExtractValue();
}
ton_http::handlers::TonlibRequestHandler::TonlibRequestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    HttpHandlerJsonBase(config, context),
    tonlib_component_(context.FindComponent<core::TonlibComponent>()),
    logger_(context.FindComponent<userver::components::Logging>().GetLogger("api-v2")) {
}
