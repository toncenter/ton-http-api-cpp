#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetBlockTransactionsExtHandler : public TonlibRequestHandler<schemas::v2::BlockTransactionsExtRequest, schemas::v2::BlockTransactionsExt> {
public:
  static constexpr std::string_view kName = "handler-GetBlockTransactionsExt";

  GetBlockTransactionsExtHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::BlockTransactionsExtRequest& request) const override;
  schemas::v2::BlockTransactionsExtRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::BlockTransactionsExt> HandleRequestTonlibThrow(
      schemas::v2::BlockTransactionsExtRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
