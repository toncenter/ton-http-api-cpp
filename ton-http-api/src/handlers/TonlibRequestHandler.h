#pragma once
#include "components/tonlib_component.h"
#include "http/http.h"
#include "schemas/v2.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/logging/component.hpp"
#include "userver/server/handlers/http_handler_json_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

#include <type_traits>
#include <variant>

template <class>
struct is_variant : std::false_type {};
template <class... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <class T>
inline constexpr bool is_variant_v = is_variant<std::remove_cvref_t<T>>::value;
template <class T>
concept VariantLike = is_variant_v<T>;

namespace ton_http::handlers {

template <typename Request, typename Response>
class TonlibRequestHandler : public userver::server::handlers::HttpHandlerJsonBase {
public:
  using HttpHandlerJsonBase::HttpHandlerJsonBase;

  virtual Request ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const = 0;
  virtual Request ParseTonlibPostRequest(const HttpRequest&, const Value& request_json, RequestContext&) const {
    try {
      return request_json.As<Request>();
    } catch (std::exception& exc) {
      throw utils::TonlibException(exc.what(), 422);
    }
  }
  virtual td::Status ValidateRequest(const Request&) const {
    return td::Status::OK();
  }
  virtual td::Result<Response> HandleRequestTonlibThrow(Request& request, multiclient::SessionPtr& session) const = 0;

  userver::formats::json::Value HandleRequestJsonThrow(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override {
    auto session = tonlib_component_.GetNewSession();
    try {
      Request tonlib_request;
      if (request.GetMethod() == userver::server::http::HttpMethod::kGet) {
        tonlib_request = ParseTonlibGetRequest(request, request_json, context);
      } else if (request.GetMethod() == userver::server::http::HttpMethod::kPost) {
        tonlib_request = ParseTonlibPostRequest(request, request_json, context);
      }
      if (auto validate_result = ValidateRequest(tonlib_request); validate_result.is_error()) {
        auto error = validate_result.move_as_error();
        throw utils::TonlibException(error.message().str(), error.code());
      }

      auto result = HandleRequestTonlibThrow(tonlib_request, session);

      if (result.is_error()) {
        auto tonlib_error = result.move_as_error();
        throw utils::TonlibException(tonlib_error.message().str(), tonlib_error.code());
      }
      schemas::v2::TonlibResponse response;
      response.ok = true;
      if constexpr (VariantLike<Response>) {
        auto result_ok = result.move_as_ok();
        std::visit([&]<typename T0>(T0&& val) { response.result = std::forward<T0>(val); }, result_ok);
      } else {
        response.result = result.move_as_ok();
      }
      response._extra = session->to_string();
      return userver::formats::json::ValueBuilder{response}.ExtractValue();

    } catch (const utils::TonlibException& exc) {
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
      response._extra = session->to_string();

      request.GetHttpResponse().SetStatus(static_cast<userver::server::http::HttpStatus>(code));
      return userver::formats::json::ValueBuilder{response}.ExtractValue();
    } catch (const std::exception& exc) {
      LOG_ERROR_TO(*logger_) << "Unknown exception: " << exc.what();
      std::stringstream ss;
      ss << "unknown exception: " << exc.what();
      throw utils::TonlibException(ss.str(), 500);
    }
  }
  TonlibRequestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      HttpHandlerJsonBase(config, context),
      tonlib_component_(context.FindComponent<core::TonlibComponent>()),
      logger_(
        context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2"))
      ) {
  }

  static userver::yaml_config::Schema GetStaticConfigSchema() {
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
