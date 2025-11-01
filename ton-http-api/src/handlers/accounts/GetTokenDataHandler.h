#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetTokenDataHandler : public TonlibRequestHandler<schemas::v2::TokenDataRequest, schemas::v2::TokenData> {
public:
  static constexpr std::string_view kName = "handler-GetTokenData";

  GetTokenDataHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::TokenDataRequest& request) const override;
  schemas::v2::TokenDataRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::TokenData> HandleRequestTonlibThrow(
    schemas::v2::TokenDataRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
