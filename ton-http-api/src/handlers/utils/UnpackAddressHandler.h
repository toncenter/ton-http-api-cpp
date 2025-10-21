#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class UnpackAddressHandler
    : public TonlibRequestHandler<schemas::v2::UnpackAddressRequest, schemas::v2::UnpackAddress> {
public:
  static constexpr std::string_view kName = "handler-UnpackAddress";

  UnpackAddressHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  schemas::v2::UnpackAddressRequest ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;

  td::Result<schemas::v2::UnpackAddress> HandleRequestTonlibThrow(
    schemas::v2::UnpackAddressRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
