#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetAddressInformationHandler : public TonlibRequestHandler<schemas::v2::AddressInformationRequest, schemas::v2::AddressInformation> {
public:
  static constexpr std::string_view kName = "handler-GetAddressInformation";

  GetAddressInformationHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::AddressInformationRequest& request) const override;
  schemas::v2::AddressInformationRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::AddressInformation> HandleRequestTonlibThrow(
      schemas::v2::AddressInformationRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
