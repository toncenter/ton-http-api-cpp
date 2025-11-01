#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetBlockHeaderHandler : public TonlibRequestHandler<schemas::v2::BlockHeaderRequest, schemas::v2::BlockHeader> {
public:
  static constexpr std::string_view kName = "handler-GetBlockHeader";

  GetBlockHeaderHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::BlockHeaderRequest& request) const override;
  schemas::v2::BlockHeaderRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::BlockHeader> HandleRequestTonlibThrow(
      schemas::v2::BlockHeaderRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
