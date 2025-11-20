#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetShardsHandler : public TonlibRequestHandler<schemas::v2::ShardsRequest, schemas::v2::Shards> {
public:
  static constexpr std::string_view kName = "handler-GetShards";

  GetShardsHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::ShardsRequest& request) const override;
  schemas::v2::ShardsRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::Shards> HandleRequestTonlibThrow(
      schemas::v2::ShardsRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
