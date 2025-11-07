#pragma once
#include "components/tonlib_component.h"
#include "http/http.h"
#include "schemas/v2.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/logging/component.hpp"
#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

#include <type_traits>
#include <variant>

// check std::variant
template <class>
struct is_variant : std::false_type {};
template <class... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <class T>
inline constexpr bool is_variant_v = is_variant<std::remove_cvref_t<T>>::value;
template <class T>
concept VariantLike = is_variant_v<T>;

// check std::vector
template <class>
struct is_vector : std::false_type {};
template <class T>
struct is_vector<std::vector<T>> : std::true_type {};
template <class T>
inline constexpr bool is_vector_v = is_vector<std::remove_cvref_t<T>>::value;
template <class T>
concept VectorLike = is_vector_v<T>;

namespace ton_http::handlers {

template <typename Request, typename Response>
class TonlibRequestHandler : public userver::server::handlers::HttpHandlerBase {
public:
  using HttpHandlerBase::HttpHandlerBase;
  using HttpRequest = userver::server::http::HttpRequest;
  using RequestContext = userver::server::request::RequestContext;

  virtual Request ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const = 0;
  virtual Request ParseTonlibPostRequest(const HttpRequest& request, RequestContext&) const {
    const auto request_json = userver::formats::json::FromString(request.RequestBody());
    return request_json.As<Request>();
  }
  virtual td::Status ValidateRequest(const Request&) const {
    return td::Status::OK();
  }
  virtual td::Result<Response> HandleRequestTonlibThrow(Request& request, multiclient::SessionPtr& session) const = 0;

  Request ParseTonlibRequestThrow(const HttpRequest& request, RequestContext& context) const {
    Request tonlib_request;
    if (request.GetMethod() == userver::server::http::HttpMethod::kGet) {
      try {
        tonlib_request = ParseTonlibGetRequest(request, context);
      } catch (std::exception& exc) {
        throw utils::TonlibException(std::string("failed to parse get request: ") + exc.what(), 422);
      }
    } else if (request.GetMethod() == userver::server::http::HttpMethod::kPost) {
      try {
        tonlib_request = ParseTonlibPostRequest(request, context);
      } catch (std::exception& exc) {
        throw utils::TonlibException(std::string("failed to parse post request: ") + exc.what(), 422);
      }
    } else {
      throw utils::TonlibException(std::string("unsupported http method: ") + request.GetMethodStr(), 405);
    }
    return tonlib_request;
  }

  schemas::v2::TonlibResponse PrepareResponse(const Response& tonlib_result) const {
    schemas::v2::TonlibResponse response;
    response.ok = true;
    if constexpr (VariantLike<Response>) {
      std::visit([&]<typename T0>(T0&& val) { response.result = std::forward<T0>(val); }, tonlib_result);
    } else if constexpr (VectorLike<Response>) {
      std::vector<schemas::v2::TonlibObject> result_vector;
      for (auto& item : tonlib_result) {
        result_vector.emplace_back(item);
      }
      response.result = result_vector;
    } else {
      response.result = std::move(tonlib_result);
    }
    return response;
  }

  static schemas::v2::TonlibErrorResponse PrepareErrorResponse(const utils::TonlibException& exc) {
    auto code = exc.code();
    if (code == 0) {
      code = 500;
    } else if (code == -3) {
      code = 542;
    } else if (code < 0) {
      code = 500;
    }

    schemas::v2::TonlibErrorResponse response;
    response.ok = false;
    response.error = exc.message();
    response.code = code;
    return response;
  }

  std::string HandleRequestThrow(const HttpRequest& request, RequestContext& context) const override {
    auto session = tonlib_component_.GetNewSession();
    schemas::v2::TonlibErrorResponse error_response;
    Request tonlib_request;
    try {
      tonlib_request = ParseTonlibRequestThrow(request, context);
      if (auto validate_result = ValidateRequest(tonlib_request); validate_result.is_error()) {
        auto error = validate_result.move_as_error();
        throw utils::TonlibException(std::string("failed to validate request: ") + error.message().str(), error.code());
      }

      auto tonlib_response = HandleRequestTonlibThrow(tonlib_request, session);
      if (tonlib_response.is_error()) {
        auto tonlib_error = tonlib_response.move_as_error();
        throw utils::TonlibException(tonlib_error.message().str(), tonlib_error.code());
      }
      auto tonlib_result = tonlib_response.move_as_ok();
      auto response = PrepareResponse(tonlib_result);
      response._extra = session->to_string();

      auto& http_response = request.GetHttpResponse();
      http_response.SetContentType(userver::http::content_type::kApplicationJson);
      http_response.SetStatus(userver::server::http::HttpStatus::kOk);
      if (use_custom_serializer_) {
        throw std::runtime_error("not implemented");
      }

      auto response_body = userver::formats::json::ValueBuilder{response}.ExtractValue();
      LogTonlibRequest(request, context, tonlib_request, response_body, std::nullopt, userver::logging::Level::kInfo);
      return ToString(response_body);
    } catch (const utils::TonlibException& error) {
      error_response = PrepareErrorResponse(error);
    } catch (const std::exception& exc) {
      LOG_ERROR_TO(*logger_) << "Unknown exception: " << exc.what();
      error_response =
        PrepareErrorResponse(utils::TonlibException(std::string("unknown exception: ") + exc.what(), 500));
    }
    error_response._extra = session->to_string();

    auto& http_response = request.GetHttpResponse();
    http_response.SetContentType(userver::http::content_type::kApplicationJson);
    http_response.SetStatus(static_cast<userver::server::http::HttpStatus>(error_response.code));

    auto response_body = userver::formats::json::ValueBuilder{error_response}.ExtractValue();
    LogTonlibRequest(request, context, tonlib_request, std::nullopt, response_body, userver::logging::Level::kWarning);
    return ToString(response_body);
  }
  TonlibRequestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      HttpHandlerBase(config, context),
      tonlib_component_(context.FindComponent<core::TonlibComponent>()),
      logger_(
        context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2"))
      ),
      use_custom_serializer_(config["use_custom_serializer"].As<bool>(false)) {
  }

  void LogTonlibRequest(
    const HttpRequest& request,
    RequestContext&,
    const Request& req,
    std::optional<userver::formats::json::Value> response = std::nullopt,
    std::optional<userver::formats::json::Value> error = std::nullopt,
    const userver::logging::Level log_level = userver::logging::Level::kInfo
  ) const {
    userver::logging::LogExtra log_extra;
    log_extra.Extend("http_method", request.GetMethodStr());
    log_extra.Extend("api_method", request.GetRequestPath());
    auto request_body = userver::formats::json::ValueBuilder{req}.ExtractValue();
    log_extra.Extend("request", request_body);
    if (response.has_value()) {
      log_extra.Extend("response", response.value());
    }
    if (error.has_value()) {
      log_extra.Extend("response", error.value());
    }
    LOG_TO(*logger_, log_level) << log_extra;
  }

  static userver::yaml_config::Schema GetStaticConfigSchema() {
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
)");
  }

protected:
  core::TonlibComponent& tonlib_component_;
  userver::logging::LoggerPtr logger_;

private:
  bool use_custom_serializer_;
};

}  // namespace ton_http::handlers
