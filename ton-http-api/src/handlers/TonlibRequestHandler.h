#pragma once
#include "components/tonlib_component.h"
#include "schemas/v2.hpp"
#include "userver/logging/component.hpp"
#include "userver/components/component_context.hpp"
#include "userver/components/component_config.hpp"
#include "userver/server/handlers/http_handler_json_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"

namespace ton_http::handlers {

template <typename Request, typename Response>
class TonlibRequestHandler : public userver::server::handlers::HttpHandlerJsonBase {
public:
  using HttpHandlerJsonBase::HttpHandlerJsonBase;

  virtual Request ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const = 0;
  virtual Request ParseTonlibPostRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const = 0;
  virtual td::Result<Response> HandleRequestTonlibThrow(Request& request, multiclient::SessionPtr& session) const = 0;

  userver::formats::json::Value HandleRequestJsonThrow(const HttpRequest& request, const Value& request_json, RequestContext& context) const override {
    auto session = tonlib_component_.GetNewSession();

    Request tonlib_request;
    if (request.GetMethod() == userver::server::http::HttpMethod::kGet) {
      tonlib_request = ParseTonlibGetRequest(request, request_json, context);
    } else if (request.GetMethod() == userver::server::http::HttpMethod::kPost) {
      tonlib_request = ParseTonlibPostRequest(request, request_json, context);
    }

    auto result = HandleRequestTonlibThrow(tonlib_request, session);

    if (result.is_error()) {
      schemas::v2::TonlibErrorResponse response;
      auto tonlib_error = result.move_as_error();
      response.ok = false;
      response.error = tonlib_error.message().str();
      response.code = tonlib_error.code();
      response._extra = session->to_string();
      return userver::formats::json::ValueBuilder{response}.ExtractValue();
    }
    schemas::v2::TonlibResponse response;
    response.ok = true;
    response.result = result.move_as_ok();
    response._extra = session->to_string();
    response._extra = session->to_string();
    return userver::formats::json::ValueBuilder{response}.ExtractValue();
  }
  TonlibRequestHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context) :
    HttpHandlerJsonBase(config, context),
    tonlib_component_(context.FindComponent<core::TonlibComponent>()),
    logger_(context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2"))) {
  }

  static userver::yaml_config::Schema GetStaticConfigSchema()  {
    return userver::yaml_config::MergeSchemas<HttpHandlerJsonBase>(R"(
type: object
description: TonlibRequest base config
additionalProperties: false
properties:
  logger:
    type: string
    description: logger name
)");
  }
protected:
  core::TonlibComponent& tonlib_component_;
  userver::logging::LoggerPtr logger_;
};

}  // namespace ton_http::handlers
