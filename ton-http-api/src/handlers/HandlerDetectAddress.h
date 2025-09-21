#pragma once
#include "TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class HandlerDetectAddress : public TonlibRequestHandler<schemas::v2::DetectAddressRequest, schemas::v2::DetectAddress> {
public:
  static constexpr std::string_view kName = "handler-detectAddress";

  HandlerDetectAddress(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  schemas::v2::DetectAddressRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;
  schemas::v2::DetectAddressRequest ParseTonlibPostRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::DetectAddress> HandleRequestTonlibThrow(
      schemas::v2::DetectAddressRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers


