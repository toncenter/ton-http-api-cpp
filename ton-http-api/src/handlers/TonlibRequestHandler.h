#pragma once
#include "userver/server/handlers/http_handler_json_base.hpp"
#include "components/tonlib_component.h"
#include "schemas/v2.hpp"

namespace ton_http {
namespace handlers {

class TonlibRequestHandler : public userver::server::handlers::HttpHandlerJsonBase {
public:
  using HttpHandlerJsonBase::HttpHandlerJsonBase;
  virtual td::Result<schemas::v2::TonObject> HandleRequestTonlibThrow(const HttpRequest& request, const Value& request_json, RequestContext& context, multiclient::SessionPtr& session) const = 0;
  userver::formats::json::Value HandleRequestJsonThrow(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;
  TonlibRequestHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);
protected:
  core::TonlibComponent& tonlib_component_;
  userver::logging::LoggerPtr logger_;
};

}  // namespace handlers
}  // namespace ton_http
