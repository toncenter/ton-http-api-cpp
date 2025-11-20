#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetLibrariesHandler : public TonlibRequestHandler<schemas::v2::LibrariesRequest, schemas::v2::LibraryResult> {
public:
  static constexpr std::string_view kName = "handler-GetLibraries";

  GetLibrariesHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::LibrariesRequest& request) const override;
  schemas::v2::LibrariesRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::LibraryResult> HandleRequestTonlibThrow(
      schemas::v2::LibrariesRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
