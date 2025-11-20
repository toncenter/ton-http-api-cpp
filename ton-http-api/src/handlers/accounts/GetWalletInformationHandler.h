#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetWalletInformationHandler
    : public TonlibRequestHandler<schemas::v2::WalletInformationRequest, schemas::v2::WalletInformation> {
public:
  static constexpr std::string_view kName = "handler-GetWalletInformation";

  GetWalletInformationHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::WalletInformationRequest& request) const override;
  schemas::v2::WalletInformationRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::WalletInformation> HandleRequestTonlibThrow(
    schemas::v2::WalletInformationRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
