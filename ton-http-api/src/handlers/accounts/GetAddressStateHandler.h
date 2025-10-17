#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetAddressStateHandler : public TonlibRequestHandler<schemas::v2::AddressStateRequest, schemas::v2::AddressState> {
public:
  static constexpr std::string_view kName = "handler-GetAddressState";

  GetAddressStateHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::AddressStateRequest& request) const override;
  schemas::v2::AddressStateRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::AddressState> HandleRequestTonlibThrow(
      schemas::v2::AddressStateRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
