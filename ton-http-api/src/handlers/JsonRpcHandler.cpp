#include "JsonRpcHandler.h"
#include "userver/clients/http/component.hpp"

namespace ton_http::handlers {

JsonRpcHandler::JsonRpcHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
  HttpHandlerJsonBase(config, context),
  logger_(context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2-jsonrpc"))),
  http_client_(context.FindComponent<userver::components::HttpClient>("http-client").GetHttpClient()),
  base_url_("http://localhost:" + std::to_string(config["port"].As<std::int32_t>()) + "/api/v2/")
{
}
userver::server::handlers::HttpHandlerJsonBase::Value JsonRpcHandler::HandleRequestJsonThrow(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  auto method = request_json["method"].As<std::string>();
  auto params = request_json["params"];

  auto url = base_url_ + method;
  auto req = http_client_.CreateRequest();
  auto resp = req.post(url, ToString(params)) \
    .headers({{"Content-Type", "application/json"}}) \
    .timeout(std::chrono::seconds(10)).perform();
  auto code = resp->status_code();
  request.GetHttpResponse().SetStatus(code);
  return userver::formats::json::FromString(resp->body());;
}
userver::yaml_config::Schema JsonRpcHandler::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<HttpHandlerJsonBase>(R"(
type: object
description: jsonRPC handler config
additionalProperties: false
properties:
  logger:
    type: string
    description: logger name
  port:
    type: integer
    description: server port, same as components.server.listener.port
)");
}

}  // namespace ton_http::handlers
