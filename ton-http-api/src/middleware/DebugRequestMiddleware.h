#pragma once

#include <string>
#include <string_view>

#include "userver/http/predefined_header.hpp"
#include "userver/logging/fwd.hpp"
#include "userver/logging/level.hpp"
#include "userver/logging/log_extra.hpp"
#include "userver/server/middlewares/configuration.hpp"
#include "userver/server/middlewares/http_middleware_base.hpp"
#include "userver/utils/function_ref.hpp"

USERVER_NAMESPACE_BEGIN
namespace components {
class Logging;
}
USERVER_NAMESPACE_END

namespace ton_http::middleware {

// Returns true when the request uses debug logging. The writer is only evaluated
// for the first record of a marked request, independently of logger/span cutoffs.
bool LogDebugRequest(
  userver::server::request::RequestContext& context,
  userver::logging::LoggerRef logger,
  userver::utils::function_ref<userver::logging::LogExtra()> make_log_extra
);

class DebugRequestMiddleware final : public userver::server::middlewares::HttpMiddlewareBase {
public:
  static constexpr std::string_view kName{"debug-request-middleware"};
  static constexpr userver::http::headers::PredefinedHeader kDebugRequestHeader{"X-Debug-Request"};

  DebugRequestMiddleware(userver::logging::Level log_level, userver::logging::LoggerPtr logger);
  static bool IsDebugRequest(const userver::server::http::HttpRequest& request);

private:
  void HandleRequest(
    userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context
  ) const override;

  const userver::logging::Level log_level_;
  const userver::logging::LoggerPtr logger_;
};

class DebugRequestMiddlewareFactory final : public userver::server::middlewares::HttpMiddlewareFactoryBase {
public:
  static constexpr std::string_view kName = DebugRequestMiddleware::kName;

  DebugRequestMiddlewareFactory(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );
  static userver::yaml_config::Schema GetStaticConfigSchema();

private:
  userver::yaml_config::Schema GetMiddlewareConfigSchema() const override;
  std::unique_ptr<userver::server::middlewares::HttpMiddlewareBase> Create(
    const userver::server::handlers::HttpHandlerBase& handler, userver::yaml_config::YamlConfig config
  ) const override;

  const userver::logging::Level log_level_;
  const std::string logger_name_;
  userver::components::Logging& logging_;
};

class DebugRequestPipelineBuilder final : public userver::server::middlewares::PipelineBuilder {
public:
  static constexpr std::string_view kName{"debug-request-server-middleware-pipeline-builder"};
  using PipelineBuilder::PipelineBuilder;

  userver::server::middlewares::MiddlewaresList BuildPipeline(
    userver::server::middlewares::MiddlewaresList pipeline
  ) const override;
};

}  // namespace ton_http::middleware

USERVER_NAMESPACE_BEGIN
template <>
inline constexpr bool components::kHasValidate<ton_http::middleware::DebugRequestMiddlewareFactory> = true;
template <>
inline constexpr bool components::kHasValidate<ton_http::middleware::DebugRequestPipelineBuilder> = true;
USERVER_NAMESPACE_END
