#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "schemas/v2_fwd.hpp"
#include "userver/formats/json/value.hpp"
#include "userver/logging/fwd.hpp"
#include "userver/logging/level.hpp"
#include "userver/server/handlers/http_handler_base.hpp"

namespace multiclient {
class Session;
}

namespace ton_http::core {
class TonlibComponent;
}

namespace ton_http::utils {
class TonlibException;
}

namespace ton_http::handlers {

class TonlibHandlerBase : public userver::server::handlers::HttpHandlerBase {
public:
  using HttpRequest = userver::server::http::HttpRequest;
  using RequestContext = userver::server::request::RequestContext;

  static constexpr std::string_view kSession{"session"};
  static constexpr std::string_view kRequest{"request"};

  explicit TonlibHandlerBase(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  void LogMalformedRequest(const HttpRequest& request, RequestContext&) const;
  static userver::yaml_config::Schema GetStaticConfigSchema();

protected:
  std::shared_ptr<multiclient::Session> CreateSession(RequestContext& context) const;

  userver::formats::json::Value MakeErrorResponse(
    const HttpRequest& request, RequestContext& context, const utils::TonlibException& exc
  ) const;
  userver::formats::json::Value MakeSuccessResponse(
    const HttpRequest& request, RequestContext& context, schemas::v2::TonlibResponse& response, bool is_cached
  ) const;
  void LogJsonResponse(
    const HttpRequest& request,
    const userver::formats::json::Value& parsed_request,
    const userver::formats::json::Value& response,
    userver::logging::Level level
  ) const;

  core::TonlibComponent& tonlib_component_;
  userver::logging::LoggerPtr logger_;

private:
  bool use_custom_serializer_;
};

}  // namespace ton_http::handlers
