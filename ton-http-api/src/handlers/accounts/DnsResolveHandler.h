#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class DnsResolveHandler
    : public TonlibRequestHandler<schemas::v2::DnsResolveRequest, schemas::v2::DnsResolved> {
public:
  static constexpr std::string_view kName = "handler-DnsResolve";

  DnsResolveHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  td::Status ValidateRequest(const schemas::v2::DnsResolveRequest& request) const override;
  schemas::v2::DnsResolveRequest ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext& context
  ) const override;

  td::Result<schemas::v2::DnsResolved> HandleRequestTonlibThrow(
    schemas::v2::DnsResolveRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
