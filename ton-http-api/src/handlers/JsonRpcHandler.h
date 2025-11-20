#pragma once
#include "userver/clients/http/client.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/logging/component.hpp"
#include "userver/server/handlers/http_handler_json_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"

namespace ton_http::handlers {

class JsonRpcHandler : public userver::server::handlers::HttpHandlerBase {
public:
  using HttpHandlerBase::HttpHandlerBase;
  using HttpRequest = userver::server::http::HttpRequest;
  using RequestContext = userver::server::request::RequestContext;

  static constexpr std::string_view kName = "handler-JsonRpc";

  JsonRpcHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );
  ~JsonRpcHandler() override = default;

  std::string HandleRequestThrow(
    const HttpRequest& request, RequestContext& context
  ) const override;

  static userver::yaml_config::Schema GetStaticConfigSchema();

private:
  userver::logging::LoggerPtr logger_;
  userver::clients::http::Client& http_client_;
  std::string base_url_;
};

}  // namespace ton_http::handlers
