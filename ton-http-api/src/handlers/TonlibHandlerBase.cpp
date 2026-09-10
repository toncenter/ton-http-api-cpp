#include "TonlibHandlerBase.h"

#include "SerializedResult.h"
#include "components/TonlibComponent.h"
#include "schemas/v2.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/logging/component.hpp"
#include "userver/logging/json_string.hpp"
#include "userver/logging/log.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

namespace ton_http::handlers {

TonlibHandlerBase::TonlibHandlerBase(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    HttpHandlerBase(config, context),
    tonlib_component_(context.FindComponent<core::TonlibComponent>()),
    logger_(context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2"))),
    use_custom_serializer_(config["use_custom_serializer"].As<bool>(false)) {
}

multiclient::SessionPtr TonlibHandlerBase::CreateSession(RequestContext& context) const {
  auto session = tonlib_component_.GetNewSession();
  context.SetData(std::string{kSession}, session);
  return session;
}

userver::formats::json::Value TonlibHandlerBase::MakeErrorResponse(
  const HttpRequest& request, RequestContext& context, const utils::TonlibException& exc
) const {
  auto code = exc.code();
  if (code == 0) {
    code = 500;
  } else if (code == -3) {
    code = 542;
  } else if (code < 0) {
    code = 500;
  }
  const auto& session = context.GetData<multiclient::SessionPtr>(kSession);

  schemas::v2::TonlibErrorResponse response;
  response.ok = false;
  response.error = exc.message();
  response.code = code;
  response._extra = session->to_string();

  auto& http_response = request.GetHttpResponse();
  http_response.SetContentType(userver::http::content_type::kApplicationJson);
  http_response.SetStatus(static_cast<userver::server::http::HttpStatus>(code));
  return userver::formats::json::ValueBuilder{response}.ExtractValue();
}

std::string TonlibHandlerBase::MakeSuccessResponse(
  const HttpRequest& request, RequestContext& context, const SerializedResult& result, bool is_cached
) const {
  const auto& session = context.GetData<multiclient::SessionPtr>(kSession);
  const auto extra = session->to_string() + (is_cached ? ":c" : "");

  auto& http_response = request.GetHttpResponse();
  http_response.SetContentType(userver::http::content_type::kApplicationJson);
  http_response.SetStatus(userver::server::http::HttpStatus::kOk);
  return result.MakeSuccessBody(extra);
}

void TonlibHandlerBase::LogJsonResponse(
  const HttpRequest& request,
  userver::utils::function_ref<userver::formats::json::Value()> make_parsed_request,
  std::string_view response,
  userver::logging::Level level
) const {
  LOG_TO(*logger_, level) << [&](auto& log) {
    userver::logging::LogExtra log_extra;
    log_extra.Extend("http_method", request.GetMethodStr());
    log_extra.Extend("api_method", request.GetRequestPath());
    log_extra.Extend("request", make_parsed_request());
    log_extra.Extend("response", userver::logging::JsonString{std::string{response}});
    log << log_extra;
  };
}

void TonlibHandlerBase::LogMalformedRequest(const HttpRequest& request, RequestContext&) const {
  LOG_WARNING_TO(*logger_) << [&](auto& log) {
    userver::logging::LogExtra log_extra;
    log_extra.Extend("http_method", request.GetMethodStr());
    log_extra.Extend("api_method", request.GetRequestPath());
    log_extra.Extend("request", request.RequestBody());
    log_extra.Extend("response", "malformed request");
    log << log_extra;
  };
}

userver::yaml_config::Schema TonlibHandlerBase::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<HttpHandlerBase>(R"(
type: object
description: TonlibRequest base config
additionalProperties: false
properties:
  logger:
    type: string
    description: 'logger name (default: api-v2)'
  use_custom_serializer:
    type: boolean
    description: use custom JSON serializer
  cache_enabled:
    type: boolean
    description: enable cache
    defaultDescription: false
  cache_size:
    type: integer
    description: max amount of items to store in cache
    defaultDescription: 10000
  cache_ways:
    type: integer
    description: number of ways for associative cache
    defaultDescription: 16
  cache_ttl:
    type: string
    description: TTL for cache entries (0 is unlimited)
    defaultDescription: 0
)");
}

}  // namespace ton_http::handlers
