#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetAddressBalanceHandler
    : public TonlibRequestHandler<schemas::v2::AddressBalanceRequest, schemas::v2::AddressBalance> {
public:
  static constexpr std::string_view kName = "handler-GetAddressBalance";

  GetAddressBalanceHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::AddressBalanceRequest& request) const override;
  schemas::v2::AddressBalanceRequest ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;

  td::Result<schemas::v2::AddressBalance> HandleRequestTonlibThrow(
    schemas::v2::AddressBalanceRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
