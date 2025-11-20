#pragma once
#include "components/TonlibComponent.h"
#include "schemas/v2.hpp"
#include "userver/cache/expirable_lru_cache.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/components/statistics_storage.hpp"
#include "userver/logging/component.hpp"
#include "userver/server/handlers/http_handler_base.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

#include <type_traits>
#include <variant>

// check std::variant
template <class>
struct is_variant : std::false_type {};
template <class... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <class T>
inline constexpr bool is_variant_v = is_variant<std::remove_cvref_t<T>>::value;
template <class T>
concept VariantLike = is_variant_v<T>;

// check std::vector
template <class>
struct is_vector : std::false_type {};
template <class T>
struct is_vector<std::vector<T>> : std::true_type {};
template <class T>
inline constexpr bool is_vector_v = is_vector<std::remove_cvref_t<T>>::value;
template <class T>
concept VectorLike = is_vector_v<T>;

namespace ton_http::handlers {

template <typename Request, typename Response>
class TonlibRequestHandler : public userver::server::handlers::HttpHandlerBase {
public:
  using HttpHandlerBase::HttpHandlerBase;
  using HttpRequest = userver::server::http::HttpRequest;
  using RequestContext = userver::server::request::RequestContext;

  static constexpr std::string kSession = "session";
  static constexpr std::string kRequest = "request";

  struct Hash {
    std::size_t operator()(const Request& request) const noexcept {
      return std::hash<std::string>{}(ToString(userver::formats::json::ValueBuilder{request}.ExtractValue()));
    }
  };
  struct Equal {
    bool operator()(const Request& lhs, const Request& rhs) const noexcept {
      return ToString(userver::formats::json::ValueBuilder{lhs}.ExtractValue()) ==
        ToString(userver::formats::json::ValueBuilder{rhs}.ExtractValue());
    }
  };
  using Cache = userver::cache::ExpirableLruCache<Request, Response, Hash, Equal>;

  virtual Request ParseTonlibGetRequest(const HttpRequest& request, RequestContext& context) const = 0;
  virtual Request ParseTonlibPostRequest(const HttpRequest& request, RequestContext&) const {
    return userver::formats::json::FromString(request.RequestBody()).As<Request>();
  }
  virtual td::Status ValidateRequest(const Request&) const {
    return td::Status::OK();
  }
  virtual td::Result<Response> HandleRequestTonlibThrow(Request& request, multiclient::SessionPtr& session) const = 0;

  void ParseTonlibRequestThrow(const HttpRequest& request, RequestContext& context) const {
    if (request.GetMethod() == userver::server::http::HttpMethod::kGet) {
      try {
        context.SetData(kRequest, ParseTonlibGetRequest(request, context));
      } catch (std::exception& exc) {
        throw utils::TonlibException(std::string("failed to parse get request: ") + exc.what(), 422);
      }
    } else if (request.GetMethod() == userver::server::http::HttpMethod::kPost) {
      try {
        context.SetData(kRequest, ParseTonlibPostRequest(request, context));
      } catch (std::exception& exc) {
        throw utils::TonlibException(std::string("failed to parse post request: ") + exc.what(), 422);
      }
    } else {
      throw utils::TonlibException(std::string("unsupported http method: ") + request.GetMethodStr(), 405);
    }
  }

  std::string ReturnErrorResponse(
    const HttpRequest& request, RequestContext& context, const utils::TonlibException& exc, bool is_malformed
  ) const {
    auto code = exc.code();
    if (code == 0) {
      code = 500;
    } else if (code == -3) {
      code = 542;
    } else if (code < 0) {
      code = 500;
    }
    const auto& session = context.GetData<multiclient::SessionPtr>(kSession);

    schemas::v2::TonlibErrorResponse response;
    response.ok = false;
    response.error = exc.message();
    response.code = code;
    response._extra = session->to_string();

    auto& http_response = request.GetHttpResponse();
    http_response.SetContentType(userver::http::content_type::kApplicationJson);
    http_response.SetStatus(static_cast<userver::server::http::HttpStatus>(code));
    auto response_body = userver::formats::json::ValueBuilder{response}.ExtractValue();

    if (!is_malformed) {
      LogResponse<userver::logging::Level::kWarning>(request, context, response_body);
    }
    return ToString(response_body);
  }

  std::string ReturnTonlibResponse(
    const HttpRequest& request, RequestContext& context, Response& tonlib_response, bool is_cached
  ) const {
    schemas::v2::TonlibResponse response;
    response.ok = true;
    if constexpr (VariantLike<Response>) {
      std::visit([&]<typename T0>(T0&& val) { response.result = std::forward<T0>(val); }, tonlib_response);
    } else if constexpr (VectorLike<Response>) {
      std::vector<schemas::v2::TonlibObject> result_vector;
      for (const auto& item : tonlib_response) {
        result_vector.emplace_back(item);
      }
      response.result = result_vector;
    } else {
      response.result = tonlib_response;
    }

    const auto& session = context.GetData<multiclient::SessionPtr>(kSession);
    response._extra = session->to_string() + (is_cached ? ":c" : "");

    auto& http_response = request.GetHttpResponse();
    http_response.SetContentType(userver::http::content_type::kApplicationJson);
    http_response.SetStatus(userver::server::http::HttpStatus::kOk);
    auto response_body = userver::formats::json::ValueBuilder{response}.ExtractValue();

    LogResponse(request, context, response_body);
    return ToString(response_body);
  }

  std::optional<Response> TryGetCachedResponse(const Request& request) const {
    if (!cache_) {
      return std::nullopt;
    }
    return cache_->GetOptionalNoUpdate(request);
  }

  void CacheResponse(const Request& request, const Response& response) const {
    if (!cache_) {
      return;
    }
    cache_->Put(request, response);
  }

  std::string HandleRequestThrow(const HttpRequest& request, RequestContext& context) const override {
    auto session = tonlib_component_.GetNewSession();
    context.SetData(kSession, session);

    // parse request
    try {
      ParseTonlibRequestThrow(request, context);
    } catch (const utils::TonlibException& exc) {
      LogMalformedRequest(request, context);
      return ReturnErrorResponse(request, context, exc, true);
    } catch (const std::exception& exc) {
      LogMalformedRequest(request, context);
      return ReturnErrorResponse(
        request, context, utils::TonlibException{std::string("unknown exception: ") + exc.what(), 500}, true
      );
    }

    // validate request
    auto tonlib_request = context.GetData<Request>(kRequest);
    if (auto validate_result = ValidateRequest(tonlib_request); validate_result.is_error()) {
      auto error = validate_result.move_as_error();
      return ReturnErrorResponse(
        request,
        context,
        utils::TonlibException{std::string("failed to validate request: ") + error.message().str(), error.code()},
        false
      );
    }

    // check cache
    if (auto tonlib_cached_response = TryGetCachedResponse(tonlib_request); tonlib_cached_response.has_value()) {
      return ReturnTonlibResponse(request, context, tonlib_cached_response.value(), true);
    }

    auto tonlib_response = HandleRequestTonlibThrow(tonlib_request, session);
    if (tonlib_response.is_error()) {
      auto tonlib_error = tonlib_response.move_as_error();
      return ReturnErrorResponse(
        request, context, utils::TonlibException{tonlib_error.message().str(), tonlib_error.code()}, false
      );
    }

    auto tonlib_result = tonlib_response.move_as_ok();

    CacheResponse(tonlib_request, tonlib_result);
    return ReturnTonlibResponse(request, context, tonlib_result, false);
  }
  explicit TonlibRequestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      HttpHandlerBase(config, context),
      tonlib_component_(context.FindComponent<core::TonlibComponent>()),
      logger_(
        context.FindComponent<userver::components::Logging>().GetLogger(config["logger"].As<std::string>("api-v2"))
      ),
      cache_(nullptr),
      use_custom_serializer_(config["use_custom_serializer"].As<bool>(false)) {
    const auto cache_ways = config["cache_ways"].As<std::size_t>(16);
    const auto cache_size = config["cache_size"].As<std::size_t>(10000);
    const auto cache_ttl = config["cache_ttl"].As<std::chrono::milliseconds>(0);
    if (config["cache_enabled"].As<bool>(false)) {
      if (cache_size <= 0) {
        throw std::runtime_error("cache_size must be positive when cache is enabled");
      }
      if (cache_ways <= 0) {
        throw std::runtime_error("cache_ways must be positive when cache is enabled");
      }
      if (cache_ttl.count() < 0) {
        throw std::runtime_error("cache_ttl must be non-negative when cache is enabled");
      }
      auto way_size = std::max(cache_size / cache_ways, 1ul);
      cache_ = std::make_shared<Cache>(cache_size, way_size);
      cache_->SetMaxLifetime(cache_ttl);
      cache_->SetBackgroundUpdate(userver::cache::BackgroundUpdateMode::kEnabled);
      cache_stats_holder_ = context.FindComponent<userver::components::StatisticsStorage>().GetStorage().RegisterWriter(
        "cache",
        [this](userver::utils::statistics::Writer& writer) { writer = *cache_; },
        {{"cache_name", std::string{userver::components::GetCurrentComponentName(context)}}}
      );
    }
  }

  template <userver::logging::Level level = userver::logging::Level::kInfo>
  void LogResponse(
    const HttpRequest& request, RequestContext& context, const userver::formats::json::Value& response
  ) const {
    const auto& tonlib_request = context.GetData<Request>(kRequest);

    userver::logging::LogExtra log_extra;
    log_extra.Extend("http_method", request.GetMethodStr());
    log_extra.Extend("api_method", request.GetRequestPath());
    log_extra.Extend("request", userver::formats::json::ValueBuilder{tonlib_request}.ExtractValue());
    log_extra.Extend("response", response);
    LOG_TO(*logger_, level) << log_extra;
  }

  void LogMalformedRequest(const HttpRequest& request, RequestContext&) const {
    userver::logging::LogExtra log_extra;
    log_extra.Extend("http_method", request.GetMethodStr());
    log_extra.Extend("api_method", request.GetRequestPath());
    log_extra.Extend("request", request.RequestBody());
    log_extra.Extend("response", "malformed request");
    LOG_WARNING_TO(*logger_) << log_extra;
  }

  static userver::yaml_config::Schema GetStaticConfigSchema() {
    return userver::yaml_config::MergeSchemas<HttpHandlerBase>(R"(
type: object
description: TonlibRequest base config
additionalProperties: false
properties:
  logger:
    type: string
    description: 'logger name (default: api-v2)'
  use_custom_serializer:
    type: boolean
    description: use custom JSON serializer
  cache_enabled:
    type: boolean
    description: enable cache
    defaultDescription: false
  cache_size:
    type: integer
    description: max amount of items to store in cache
    defaultDescription: 10000
  cache_ways:
    type: integer
    description: number of ways for associative cache
    defaultDescription: 16
  cache_ttl:
    type: string
    description: TTL for cache entries (0 is unlimited)
    defaultDescription: 0
)");
  }

protected:
  core::TonlibComponent& tonlib_component_;
  userver::logging::LoggerPtr logger_;

private:
  std::shared_ptr<Cache> cache_;
  userver::utils::statistics::Entry cache_stats_holder_;
  bool use_custom_serializer_;
};

}  // namespace ton_http::handlers
