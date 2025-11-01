#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class LookupBlockHandler : public TonlibRequestHandler<schemas::v2::LookupBlockRequest, schemas::v2::LookupBlock> {
public:
  static constexpr std::string_view kName = "handler-LookupBlock";

  LookupBlockHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::LookupBlockRequest& request) const override;
  schemas::v2::LookupBlockRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::LookupBlock> HandleRequestTonlibThrow(
      schemas::v2::LookupBlockRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
