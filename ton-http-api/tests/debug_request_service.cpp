#include <atomic>
#include <stdexcept>
#include <string>

#include "handlers/JsonRpcHandler.h"
#include "middleware/DebugRequestMiddleware.h"
#include "userver/cache/expirable_lru_cache.hpp"
#include "userver/clients/dns/component.hpp"
#include "userver/clients/http/component.hpp"
#include "userver/clients/http/middlewares/pipeline_component.hpp"
#include "userver/components/minimal_server_component_list.hpp"
#include "userver/formats/json.hpp"
#include "userver/logging/component.hpp"
#include "userver/logging/json_string.hpp"
#include "userver/logging/log.hpp"
#include "userver/server/handlers/exceptions.hpp"
#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/utils/daemon_run.hpp"

namespace {

// Exercises the real middleware and JSON-RPC handler without a TON node. This
// handler supplies a structured logging path, a cache, and exceptional responses.
class DebugRequestTestHandler final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName{"handler-debug-request-test"};

  DebugRequestTestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      HttpHandlerBase(config, context),
      logger_(context.FindComponent<userver::components::Logging>().GetLogger("api-v2")),
      rpc_logger_(context.FindComponent<userver::components::Logging>().GetLogger("api-v2-jsonrpc")) {
  }

private:
  std::string HandleRequestThrow(
    const userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context
  ) const override {
    const auto& mode = request.GetArg("mode");
    if (mode == "flush") {
      userver::logging::LogFlush(*logger_);
      userver::logging::LogFlush(*rpc_logger_);
      return "{}";
    }
    if (mode == "throw") {
      throw std::runtime_error("debug request test exception");
    }
    if (mode == "nonstd-throw") {
      throw 1;
    }
    if (mode == "custom-error") {
      throw ClientError{ExternalBody{"test rejection"}};
    }

    bool cache_hit = false;
    auto response = std::string{"{\"ok\":true}"};
    if (mode == "cached") {
      const auto& key = request.GetArg("cache_key");
      if (const auto cached = cache_.GetOptionalUnexpirable(key)) {
        response = *cached;
        cache_hit = true;
      } else {
        response = "{\"ok\":true,\"generation\":" + std::to_string(++generation_) + "}";
        cache_.Put(key, response);
      }
    }
    if (mode == "malformed") {
      request.GetHttpResponse().SetStatus(userver::server::http::HttpStatus::kUnprocessableEntity);
      response = "{\"ok\":false}";
    }
    if (mode == "fallback" || mode == "plain") {
      return mode == "plain" ? "plain text response" : response;
    }

    const auto make_log_extra = [&] {
      userver::logging::LogExtra extra;
      extra.Extend("http_method", request.GetMethodStr());
      extra.Extend("api_method", request.GetRequestPath());
      extra.Extend(
        "request",
        request.RequestBody().empty() ? userver::formats::json::MakeObject("id", request.GetArg("id")) :
                                        userver::formats::json::FromString(request.RequestBody())
      );
      extra.Extend("response", userver::logging::JsonString{response});
      extra.Extend("cache_hit", cache_hit);
      return extra;
    };
    if (!ton_http::middleware::LogDebugRequest(context, *logger_, make_log_extra)) {
      LOG_INFO_TO(*logger_) << make_log_extra();
    }
    return response;
  }

  userver::logging::LoggerPtr logger_;
  userver::logging::LoggerPtr rpc_logger_;
  mutable userver::cache::ExpirableLruCache<std::string, std::string> cache_{1, 16};
  mutable std::atomic<unsigned> generation_{0};
};

}  // namespace

int main(int argc, char* argv[]) {
  auto components = userver::components::MinimalServerComponentList();
  components.Append<ton_http::middleware::DebugRequestMiddlewareFactory>();
  components.Append<ton_http::middleware::DebugRequestPipelineBuilder>();
  components.Append<DebugRequestTestHandler>();
  components.Append<DebugRequestTestHandler>("handler-debug-request-throttled");
  components.Append<DebugRequestTestHandler>("handler-DetectHash");
  components.Append<userver::clients::dns::Component>();
  components.Append<userver::clients::http::MiddlewarePipelineComponent>();
  components.Append<userver::components::HttpClientCore>("jsonrpc-http-client-core");
  components.Append<userver::components::HttpClient>("jsonrpc-http-client");
  components.Append<ton_http::handlers::JsonRpcHandler>();
  return userver::utils::DaemonMain(argc, argv, components);
}
