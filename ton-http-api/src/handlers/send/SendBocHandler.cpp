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
    ignore_errors_(config["ignore_errors"].As<bool>(false)),
    debug_log_measurements_(config["debug_log_measurements"].As<bool>(false)) {
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

struct Measurement {
  std::string ext_msg_hash_;
  std::string ext_msg_hash_norm_;

  std::map<std::string, double> timings_{};

  Measurement& measure_step(const std::string& step_name, std::optional<double> time = std::nullopt) {
    const double ts =
      time.value_or(std::chrono::duration<double>(std::chrono::system_clock::now().time_since_epoch()).count());
    timings_[step_name] = ts;
    return *this;
  }
  std::vector<std::string> render_measurement() {
    std::vector<std::string> result;
    for (const auto& [step_name, ts] : timings_) {
      std::stringstream ss;
      ss << "MEASURE[id=-1;msg_hash_norm=" << td::base64_encode(ext_msg_hash_norm_) << ";msg_hash=" << td::base64_encode(ext_msg_hash_) << ";trace_id=-]";
      result.emplace_back(ss.str() + "(step=" + step_name + ";time=" + std::to_string(ts) + ")");
    }
    return result;
  }
};

td::Result<ton_http::schemas::v2::SendBocResult> ton_http::handlers::SendBocHandler::HandleRequestTonlibThrow(
  schemas::v2::SendBocRequest& request, multiclient::SessionPtr& session
) const {
  Measurement measurement;
  measurement.measure_step("boc_received");
  auto result =
    tonlib_component_.DoRequest(&core::TonlibWorker::raw_sendMessageReturnHash, request.boc.GetUnderlying(), session);
  if (result.is_error()) {
    if (ignore_errors_) {
      return td::Status::Error(400, result.move_as_error().message());
    }
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();

  measurement.measure_step("boc_sent_to_liteservers");
  measurement.ext_msg_hash_ = result_ok->hash_;
  measurement.ext_msg_hash_norm_ = result_ok->hash_norm_;
  if (auto external_send_success = SendBocToExternalEndpoints(request); !external_send_success) {
    LOG_WARNING_TO(*logger_) << "Failed to send BOC to some of external endpoints";
  }
  measurement.measure_step("boc_sent_to_smart_broadcast");
  if (debug_log_measurements_) {
    for (auto& line : measurement.render_measurement()) {
      LOG_CRITICAL_TO(*logger_) << line;
    }
  }
  if (!return_hash_) {
    return schemas::v2::ResultOk{};
  }
  return converters::Convert(result_ok);
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
  debug_log_measurements:
    type: boolean
    description: 'Log timings to debug (default: false)'
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
