#pragma once
#include "TonlibRequestHandler.h"

namespace ton_http {
namespace handlers {

class HandlerGetMasterchainInfo : public TonlibRequestHandler {
public:
  static constexpr std::string_view kName = "handler-get-masterchain-info";

  HandlerGetMasterchainInfo(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);
  td::Result<schemas::v2::TonObject> HandleRequestTonlibThrow(const HttpRequest& request, const Value& request_json, RequestContext& context, multiclient::SessionPtr& session) const override;
};

}  // namespace handlers
}  // namespace ton_http
