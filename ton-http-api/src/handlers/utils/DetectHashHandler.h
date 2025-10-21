#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class DetectHashHandler : public TonlibRequestHandler<schemas::v2::DetectHashRequest, schemas::v2::DetectHash> {
public:
  static constexpr std::string_view kName = "handler-DetectHash";

  DetectHashHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  schemas::v2::DetectHashRequest ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;

  td::Result<schemas::v2::DetectHash> HandleRequestTonlibThrow(
    schemas::v2::DetectHashRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
