#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetShardAccountCellHandler
    : public TonlibRequestHandler<schemas::v2::ShardAccountCellRequest, schemas::v2::TvmCell> {
public:
  static constexpr std::string_view kName = "handler-GetShardAccountCellHandler";

  GetShardAccountCellHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::AddressInformationRequest& request) const override;
  schemas::v2::ShardAccountCellRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::TvmCell> HandleRequestTonlibThrow(
    schemas::v2::ShardAccountCellRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
