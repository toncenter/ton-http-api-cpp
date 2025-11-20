#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetConfigAllHandler : public TonlibRequestHandler<schemas::v2::ConfigAllRequest, schemas::v2::ConfigInfo> {
public:
  static constexpr std::string_view kName = "handler-GetConfigAll";

  GetConfigAllHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::ConfigAllRequest& request) const override;
  schemas::v2::ConfigAllRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::ConfigInfo> HandleRequestTonlibThrow(
      schemas::v2::ConfigAllRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
