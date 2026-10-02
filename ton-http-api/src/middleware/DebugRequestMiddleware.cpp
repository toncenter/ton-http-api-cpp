#include "DebugRequestMiddleware.h"

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <utility>

#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/formats/json.hpp"
#include "userver/formats/yaml.hpp"
#include "userver/logging/component.hpp"
#include "userver/logging/log.hpp"
#include "userver/logging/log_helper.hpp"
#include "userver/server/middlewares/builtin.hpp"
#include "userver/server/request/request_context.hpp"
#include "userver/tracing/span.hpp"
#include "userver/yaml_config/merge_schemas.hpp"

namespace ton_http::middleware {
namespace {

constexpr std::string_view kDebugRequestLogSettings{"debug-request-log-settings"};

struct DebugRequestLogSettings {
  userver::logging::Level level;
  bool record_written{false};
};

void ExtendJsonOrString(userver::logging::LogExtra& extra, const std::string& key, const std::string& data) {
  try {
    extra.Extend(key, userver::formats::json::FromString(data));
  } catch (const userver::formats::json::Exception&) {
    extra.Extend(key, data);
  }
}

void LogFallback(
  const userver::server::http::HttpRequest& request,
  userver::server::request::RequestContext& context,
  userver::logging::LoggerRef logger,
  bool completed
) {
  LogDebugRequest(context, logger, [&] {
    userver::logging::LogExtra extra;
    extra.Extend("http_method", request.GetMethodStr());
    extra.Extend("api_method", request.GetRequestPath());
    if (request.RequestBody().empty()) {
      extra.Extend("request", request.GetUrl());
    } else {
      ExtendJsonOrString(extra, "request", request.RequestBody());
    }
    if (completed) {
      const auto& response = request.GetHttpResponse();
      extra.Extend("http_status", static_cast<int>(response.GetStatus()));
      ExtendJsonOrString(extra, "response", response.GetData());
    } else {
      // An outer exception middleware still has to produce the HTTP response.
      extra.Extend("response", "request processing threw an exception");
    }
    return extra;
  });
}

}  // namespace

bool LogDebugRequest(
  userver::server::request::RequestContext& context,
  userver::logging::LoggerRef logger,
  userver::utils::function_ref<userver::logging::LogExtra()> make_log_extra
) {
  auto* settings = context.GetDataOptional<DebugRequestLogSettings>(kDebugRequestLogSettings);
  if (!settings) {
    return false;
  }
  if (settings->record_written) {
    return true;
  }

  try {
    auto extra = make_log_extra();
    extra.Extend("debug_request", true);
    // userver only supplies correlation IDs automatically when there is a
    // loggable span. Keep them on forced records even if all spans are hidden.
    if (const auto* span = userver::tracing::Span::CurrentSpanUnchecked(); span && !span->GetSpanIdForChildLogs()) {
      extra.Extend("trace_id", std::string{span->GetTraceId()});
      extra.Extend("span_id", std::string{span->GetSpanId()});
      extra.Extend("link", std::string{span->GetLink()});
    }
    {
      // LOG_TO checks both the logger and current span thresholds. Constructing
      // the public log builder directly bypasses those checks for this record.
      userver::logging::LogHelper log{logger, settings->level};
      log << extra;
    }
    settings->record_written = true;
  } catch (const std::exception& exc) {
    LOG_ERROR() << "Failed to log debug request: " << exc;
  } catch (...) {
    LOG_ERROR() << "Failed to log debug request";
  }
  return true;
}

DebugRequestMiddleware::DebugRequestMiddleware(userver::logging::Level log_level, userver::logging::LoggerPtr logger) :
    log_level_(log_level), logger_(std::move(logger)) {
}

bool DebugRequestMiddleware::IsDebugRequest(const userver::server::http::HttpRequest& request) {
  std::string_view value = request.GetHeader(kDebugRequestHeader);
  const auto first = value.find_first_not_of(" \t");
  if (first == std::string_view::npos) {
    return false;
  }
  value = value.substr(first, value.find_last_not_of(" \t") - first + 1);
  return value.size() == 4 && (value[0] == 't' || value[0] == 'T') && (value[1] == 'r' || value[1] == 'R') &&
    (value[2] == 'u' || value[2] == 'U') && (value[3] == 'e' || value[3] == 'E');
}

void DebugRequestMiddleware::HandleRequest(
  userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context
) const {
  if (!IsDebugRequest(request)) {
    Next(request, context);
    return;
  }

  context.SetData(std::string{kDebugRequestLogSettings}, DebugRequestLogSettings{log_level_});
  try {
    Next(request, context);
  } catch (...) {
    LogFallback(request, context, *logger_, false);
    throw;
  }
  LogFallback(request, context, *logger_, true);
}

DebugRequestMiddlewareFactory::DebugRequestMiddlewareFactory(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    HttpMiddlewareFactoryBase(config, context),
    log_level_(userver::logging::LevelFromString(config["log-level"].As<std::string>("info"))),
    logger_name_(config["logger"].As<std::string>("api-v2")),
    logging_(context.FindComponent<userver::components::Logging>()) {
  if (log_level_ == userver::logging::Level::kNone) {
    throw std::runtime_error("debug-request-middleware log-level must not be none");
  }
}

std::unique_ptr<userver::server::middlewares::HttpMiddlewareBase> DebugRequestMiddlewareFactory::Create(
  const userver::server::handlers::HttpHandlerBase&, userver::yaml_config::YamlConfig config
) const {
  const auto logger_name = config.IsMissing() ? logger_name_ : config["logger"].As<std::string>(logger_name_);
  return std::make_unique<DebugRequestMiddleware>(log_level_, logging_.GetLogger(logger_name));
}

userver::yaml_config::Schema DebugRequestMiddlewareFactory::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<HttpMiddlewareFactoryBase>(R"(
type: object
description: Forced logging for requests marked with X-Debug-Request
additionalProperties: false
properties:
  log-level:
    type: string
    description: Severity of forced request records
    defaultDescription: info
    enum: [trace, debug, info, warning, error, critical]
  logger:
    type: string
    description: Logger for requests without a handler-produced record
    defaultDescription: api-v2
)");
}

userver::yaml_config::Schema DebugRequestMiddlewareFactory::GetMiddlewareConfigSchema() const {
  return userver::formats::yaml::FromString(R"(
type: object
description: Handler-specific fallback logger for debug requests
additionalProperties: false
properties:
  logger:
    type: string
    description: Overrides the fallback logger for this handler
)")
    .As<userver::yaml_config::Schema>();
}

userver::server::middlewares::MiddlewaresList DebugRequestPipelineBuilder::BuildPipeline(
  userver::server::middlewares::MiddlewaresList pipeline
) const {
  pipeline = PipelineBuilder::BuildPipeline(std::move(pipeline));
  const auto tracing = std::find(pipeline.begin(), pipeline.end(), userver::server::middlewares::builtin::kTracing);
  if (tracing == pipeline.end()) {
    throw std::runtime_error("debug-request-middleware requires the tracing middleware");
  }
  pipeline.insert(std::next(tracing), std::string{DebugRequestMiddleware::kName});
  return pipeline;
}

}  // namespace ton_http::middleware
