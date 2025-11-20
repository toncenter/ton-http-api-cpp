#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetConfigParamHandler : public TonlibRequestHandler<schemas::v2::ConfigParamRequest, schemas::v2::ConfigInfo> {
public:
  static constexpr std::string_view kName = "handler-GetConfigParam";

  GetConfigParamHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::ConfigParamRequest& request) const override;
  schemas::v2::ConfigParamRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::ConfigInfo> HandleRequestTonlibThrow(
      schemas::v2::ConfigParamRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
