#include "JsonRpcHandler.h"

#include "schemas/v2.hpp"
#include "userver/clients/http/component.hpp"
#include <userver/server/component.hpp>
#include "utils/exceptions.hpp"

namespace ton_http::handlers {

JsonRpcHandler::JsonRpcHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    HttpHandlerBase(config, context),
    logger_(context.FindComponent<userver::components::Logging>().GetLogger(
      config["logger"].As<std::string>("api-v2-jsonrpc")
    )),
    http_client_(context.FindComponent<userver::components::HttpClient>("jsonrpc-http-client").GetHttpClient()),
    base_url_("http://localhost:" + std::to_string(config["port"].As<std::int32_t>()) + "/api/v2/") {
}
std::string JsonRpcHandler::HandleRequestThrow(
  const HttpRequest& request, RequestContext&
) const {
  try {
    if (request.GetMethod() == userver::server::http::HttpMethod::kGet) {
      throw utils::TonlibException("method GET is not supported", 405);
    }
    auto request_json = userver::formats::json::FromString(request.RequestBody());
    auto method = request_json["method"].As<std::string>();
    userver::formats::json::Value params = userver::formats::json::MakeObject();
    if (request_json.HasMember("params")) {
      if (request_json["params"].IsArray() && !request_json["params"].IsEmpty()) {
        throw utils::TonlibException("params must contain an object", 422);
      }
      if (request_json["params"].IsObject()) {
        params = request_json["params"];
      }
    }

    auto url = base_url_ + method;
    auto req = http_client_.CreateRequest();
    auto resp = req.post(url, ToString(params))
                  .headers({{"Content-Type", "application/json"}})
                  .timeout(std::chrono::seconds(10))
                  .perform();
    auto code = resp->status_code();

    auto& http_response = request.GetHttpResponse();
    http_response.SetStatus(code);
    http_response.SetContentType(userver::http::content_type::kApplicationJson);
    return resp->body();
  } catch (const utils::TonlibException& exc) {
    schemas::v2::TonlibErrorResponse response;
    response.ok = false;
    response.error = exc.message();
    response.code = exc.code();
    response._extra = "_";

    auto& http_response = request.GetHttpResponse();
    http_response.SetStatus(static_cast<userver::server::http::HttpStatus>(exc.code()));
    http_response.SetContentType(userver::http::content_type::kApplicationJson);
    return ToString(userver::formats::json::ValueBuilder{response}.ExtractValue());
  }
}
userver::yaml_config::Schema JsonRpcHandler::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<HttpHandlerBase>(R"(
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
