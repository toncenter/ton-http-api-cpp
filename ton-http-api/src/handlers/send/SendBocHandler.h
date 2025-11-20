#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {
class SendBocHandler : public TonlibRequestHandler<schemas::v2::SendBocRequest, schemas::v2::SendBocResult> {
public:
  static constexpr std::string_view kName = "handler-SendBocReturnHash";

  SendBocHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::SendBocRequest& request) const override;
  schemas::v2::SendBocRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::SendBocResult> HandleRequestTonlibThrow(
      schemas::v2::SendBocRequest& request, multiclient::SessionPtr& session
  ) const override;

  static userver::yaml_config::Schema GetStaticConfigSchema();
private:
  userver::clients::http::Client& http_client_;
  std::vector<std::string> external_message_endpoints_;
  bool return_hash_{true};
  bool ignore_errors_{false};

  bool SendBocToExternalEndpoints(const schemas::v2::SendBocRequest& request) const;
};

} // namespace ton_http::handlers
