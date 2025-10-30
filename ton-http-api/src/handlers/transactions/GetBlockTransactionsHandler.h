#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetBlockTransactionsHandler : public TonlibRequestHandler<schemas::v2::BlockTransactionsRequest, schemas::v2::BlockTransactions> {
public:
  static constexpr std::string_view kName = "handler-GetBlockTransactions";

  GetBlockTransactionsHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::BlockTransactionsRequest& request) const override;
  schemas::v2::BlockTransactionsRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::BlockTransactions> HandleRequestTonlibThrow(
      schemas::v2::BlockTransactionsRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
