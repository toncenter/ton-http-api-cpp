#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class TryLocateResultTxHandler : public TonlibRequestHandler<schemas::v2::TryLocateResultTxRequest, schemas::v2::Transaction> {
public:
  static constexpr std::string_view kName = "handler-TryLocateResultTx";

  TryLocateResultTxHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::TryLocateResultTxRequest& request) const override;
  schemas::v2::TryLocateResultTxRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::Transaction> HandleRequestTonlibThrow(
      schemas::v2::TryLocateResultTxRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
