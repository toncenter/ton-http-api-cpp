#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetConsensusBlockHandler : public TonlibRequestHandler<schemas::v2::ConsensusBlockRequest, schemas::v2::ConsensusBlock> {
public:
  static constexpr std::string_view kName = "handler-GetConsensusBlock";

  GetConsensusBlockHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::ConsensusBlockRequest& request) const override;
  schemas::v2::ConsensusBlockRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::ConsensusBlock> HandleRequestTonlibThrow(
      schemas::v2::ConsensusBlockRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
