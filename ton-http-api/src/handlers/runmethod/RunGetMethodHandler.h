#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class RunGetMethodHandler : public TonlibRequestHandler<schemas::v2::RunGetMethodRequest, schemas::v2::RunGetMethodResult> {
public:
  static constexpr std::string_view kName = "handler-RunGetMethod";

  RunGetMethodHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::RunGetMethodRequest& request) const override;
  schemas::v2::RunGetMethodRequest ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const override;

  td::Result<schemas::v2::RunGetMethodResult> HandleRequestTonlibThrow(
      schemas::v2::RunGetMethodRequest& request, multiclient::SessionPtr& session
  ) const override;

  static userver::yaml_config::Schema GetStaticConfigSchema();
private:
  std::int32_t max_stack_entry_depth_;
  bool checkStackDepth(const std::vector<schemas::v2::LegacyStackEntry>& stack) const;
};

} // namespace ton_http::handlers
