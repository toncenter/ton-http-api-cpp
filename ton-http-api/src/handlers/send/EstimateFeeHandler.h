#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class EstimateFeeHandler : public TonlibRequestHandler<schemas::v2::EstimateFeeRequest, schemas::v2::QueryFees> {
public:
  static constexpr std::string_view kName = "handler-EstimateFee";

  EstimateFeeHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::EstimateFeeRequest& request) const override;
  schemas::v2::EstimateFeeRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::QueryFees> HandleRequestTonlibThrow(
      schemas::v2::EstimateFeeRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
