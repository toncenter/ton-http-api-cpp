#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class SendBocReturnHashHandler : public TonlibRequestHandler<schemas::v2::SendBocRequest, schemas::v2::ExtMessageInfo> {
public:
  static constexpr std::string_view kName = "handler-SendBocReturnHash";

  SendBocReturnHashHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::SendBocRequest& request) const override;
  schemas::v2::SendBocRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::ExtMessageInfo> HandleRequestTonlibThrow(
      schemas::v2::SendBocRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
