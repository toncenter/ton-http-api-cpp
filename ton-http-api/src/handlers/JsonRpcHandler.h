#pragma once
#include "userver/logging/component.hpp"
#include "userver/clients/http/client.hpp"
#include "userver/components/component_context.hpp"
#include "userver/components/component_config.hpp"
#include "userver/server/handlers/http_handler_json_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"

namespace ton_http::handlers {

class JsonRpcHandler : public userver::server::handlers::HttpHandlerJsonBase {
public:
  using HttpHandlerJsonBase::HttpHandlerJsonBase;

  static constexpr std::string_view kName = "handler-JsonRpc";

  JsonRpcHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);
  ~JsonRpcHandler() final = default;

  Value HandleRequestJsonThrow(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  static userver::yaml_config::Schema GetStaticConfigSchema();
private:
  userver::logging::LoggerPtr logger_;
  userver::clients::http::Client& http_client_;
  std::string base_url_;
};

}
