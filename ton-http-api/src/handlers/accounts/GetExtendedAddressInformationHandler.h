#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetExtendedAddressInformationHandler : public TonlibRequestHandler<
                                               schemas::v2::ExtendedAddressInformationRequest,
                                               schemas::v2::ExtendedAddressInformation> {
public:
  static constexpr std::string_view kName = "handler-GetExtendedAddressInformation";

  GetExtendedAddressInformationHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  schemas::v2::ExtendedAddressInformationRequest ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;

  td::Result<schemas::v2::ExtendedAddressInformation> HandleRequestTonlibThrow(
    schemas::v2::ExtendedAddressInformationRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
