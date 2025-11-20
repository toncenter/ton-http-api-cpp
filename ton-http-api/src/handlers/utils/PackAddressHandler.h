#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class PackAddressHandler : public TonlibRequestHandler<schemas::v2::PackAddressRequest, schemas::v2::PackAddress> {
public:
  static constexpr std::string_view kName = "handler-PackAddress";

  PackAddressHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  schemas::v2::PackAddressRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::PackAddress> HandleRequestTonlibThrow(
    schemas::v2::PackAddressRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
