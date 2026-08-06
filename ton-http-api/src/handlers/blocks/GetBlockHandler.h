#pragma once

#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"

namespace ton_http::handlers {

class GetBlockHandler : public TonlibRequestHandler<schemas::v2::BlockDataRequest, schemas::v2::BlockData> {
public:
  static constexpr std::string_view kName = "handler-GetBlock";

  GetBlockHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::BlockDataRequest& request) const override;
  schemas::v2::BlockDataRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;
  td::Result<schemas::v2::BlockData> HandleRequestTonlibThrow(
    schemas::v2::BlockDataRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
