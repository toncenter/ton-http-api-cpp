#pragma once
#include "userver/http/predefined_header.hpp"
#include "userver/server/middlewares/http_middleware_base.hpp"
#include "userver/server/handlers/http_handler_base.hpp"

namespace ton_http::middleware {
class VersionHeaderMiddleware final : public userver::server::middlewares::HttpMiddlewareBase {
public:
  static constexpr std::string_view kName{"version-header-middleware"};
  explicit VersionHeaderMiddleware(const userver::server::handlers::HttpHandlerBase&) {}
private:
  void HandleRequest(
    userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context
  ) const override;
  static constexpr userver::http::headers::PredefinedHeader kApiVersionHeader{"X-API-Version"};
};

using VersionHeaderMiddlewareFactory = userver::server::middlewares::SimpleHttpMiddlewareFactory<VersionHeaderMiddleware>;
}
