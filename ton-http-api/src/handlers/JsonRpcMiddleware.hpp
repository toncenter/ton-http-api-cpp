#pragma once
#include <string>
#include "userver/server/middlewares/http_middleware_base.hpp"
#include "userver/logging/log.hpp"

namespace ton_http::middlewares {
class JsonRpcMiddleware final : public userver::server::middlewares::HttpMiddlewareBase {
public:
  // This will be used as a kName for the SimpleHttpMiddlewareFactory
  static constexpr std::string_view kName{"jsonrpc-middleware"};

  explicit JsonRpcMiddleware(const userver::server::handlers::HttpHandlerBase&) {}

private:
  void HandleRequest(userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context) const override {
    Next(request, context);
  }

  static constexpr userver::http::headers::PredefinedHeader kCustomServerHeader{"X-Some-Server-Header"};
};

using JsonRpcMiddlewareFactory = userver::server::middlewares::SimpleHttpMiddlewareFactory<JsonRpcMiddleware>;
}