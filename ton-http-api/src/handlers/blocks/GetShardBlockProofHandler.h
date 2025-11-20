#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetShardBlockProofHandler
    : public TonlibRequestHandler<schemas::v2::ShardBlockProofRequest, schemas::v2::ShardBlockProof> {
public:
  static constexpr std::string_view kName = "handler-GetShardBlockProof";

  GetShardBlockProofHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::ShardBlockProofRequest& request) const override;
  schemas::v2::ShardBlockProofRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::ShardBlockProof> HandleRequestTonlibThrow(
    schemas::v2::ShardBlockProofRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
