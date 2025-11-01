#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetTransactionsStdHandler : public TonlibRequestHandler<schemas::v2::TransactionsRequest, schemas::v2::TransactionsStd> {
public:
  static constexpr std::string_view kName = "handler-GetTransactionsStd";

  GetTransactionsStdHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::TransactionsRequest& request) const override;
  schemas::v2::TransactionsRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::TransactionsStd> HandleRequestTonlibThrow(
      schemas::v2::TransactionsRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
