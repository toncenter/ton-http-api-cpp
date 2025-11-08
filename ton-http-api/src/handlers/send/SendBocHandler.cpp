#include "SendBocHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"
#include "userver/clients/http/component.hpp"

ton_http::handlers::SendBocHandler::SendBocHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context),

    http_client_(context.FindComponent<userver::components::HttpClient>().GetHttpClient()),
    external_message_endpoints_(
      config["external_message_endpoints"].As<std::vector<std::string>>(std::vector<std::string>{})
    ),
    return_hash_(config["return_hash"].As<bool>(true)),
    ignore_errors_(config["ignore_error"].As<bool>(false)) {
}
ton_http::schemas::v2::SendBocRequest
ton_http::handlers::SendBocHandler::ParseTonlibGetRequest(const HttpRequest&, RequestContext&) const {
  throw std::logic_error("unreachable");
}
td::Status ton_http::handlers::SendBocHandler::ValidateRequest(const schemas::v2::SendBocRequest& request) const {
  if (request.boc.empty()) {
    return td::Status::Error(422, "empty boc");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::SendBocResult> ton_http::handlers::SendBocHandler::HandleRequestTonlibThrow(
  schemas::v2::SendBocRequest& request, multiclient::SessionPtr& session
) const {
  auto result =
    tonlib_component_.DoRequest(&core::TonlibWorker::raw_sendMessageReturnHash, request.boc.GetUnderlying(), session);
  if (result.is_error()) {
    if (ignore_errors_) {
      return td::Status::Error(400, result.move_as_error().message());
    }
    return result.move_as_error();
  }
  if (auto external_send_success = SendBocToExternalEndpoints(request); !external_send_success) {
    LOG_WARNING_TO(*logger_) << "Failed to send BOC to some of external endpoints";
  }
  if (!return_hash_) {
    return schemas::v2::ResultOk{};
  }
  return converters::Convert(result.move_as_ok());
}
userver::yaml_config::Schema ton_http::handlers::SendBocHandler::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<TonlibRequestHandler>(R"(
type: object
description: SendBoc config
additionalProperties: false
properties:
  external_message_endpoints:
    type: array
    description: list of external endpoints for sendBoc method
    defaultDescription: '<empty>'
    items:
      type: string
      description: external endpoint url
  return_hash:
    type: boolean
    description: 'Return hashes of message (default: true)'
  ignore_errors:
    type: boolean
    description: 'Ignore errors (default: false)'
)");
}
bool ton_http::handlers::SendBocHandler::SendBocToExternalEndpoints(const schemas::v2::SendBocRequest& request) const {
  if (external_message_endpoints_.empty()) {
    return true;
  }

  const auto body = ToString(userver::formats::json::ValueBuilder{request}.ExtractValue());
  auto success = true;
  for (const auto& endpoint : external_message_endpoints_) {
    auto post_request = http_client_.CreateRequest()
                          .post(endpoint, body)
                          .headers({{"Content-Type", "application/json"}})
                          .timeout(std::chrono::seconds(1))
                          .perform();
    if (!post_request->IsOk()) {
      LOG_WARNING_TO(*logger_)
        << "Failed to send BOC to external endpoint: " << endpoint << " Error: " << post_request->body_view();
      success = false;
    }
  }
  return success;
}
