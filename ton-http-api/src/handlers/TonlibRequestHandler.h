#pragma once

#include <memory>
#include <optional>
#include <string>

#include "RequestCache.h"
#include "SerializedResult.h"
#include "TonlibHandlerBase.h"
#include "components/TonlibComponent.h"
#include "schemas/v2.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

namespace ton_http::handlers {
template <typename Request, typename Response>
class TonlibRequestHandler : public TonlibHandlerBase {
public:
  using CacheKey = typename RequestCache<Request, SerializedResultPtr>::Key;
  using Hash = typename RequestCache<Request, SerializedResultPtr>::Hash;
  using Equal = typename RequestCache<Request, SerializedResultPtr>::Equal;
  using Cache = typename RequestCache<Request, SerializedResultPtr>::Cache;

  explicit TonlibRequestHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      TonlibHandlerBase(config, context), cache_(config, context) {
  }

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
        context.SetData(std::string{kRequest}, ParseTonlibGetRequest(request, context));
      } catch (std::exception& exc) {
        throw utils::TonlibException(std::string("failed to parse get request: ") + exc.what(), 422);
      }
    } else if (request.GetMethod() == userver::server::http::HttpMethod::kPost) {
      try {
        context.SetData(std::string{kRequest}, ParseTonlibPostRequest(request, context));
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
    auto response_body = ToString(MakeErrorResponse(request, context, exc));

    if (!is_malformed) {
      LogResponse<userver::logging::Level::kWarning>(request, context, response_body);
    }
    return response_body;
  }

  std::string ReturnTonlibResponse(
    const HttpRequest& request, RequestContext& context, const SerializedResult& result, bool is_cached
  ) const {
    auto response_body = MakeSuccessResponse(request, context, result, is_cached);

    LogResponse(request, context, response_body);
    return response_body;
  }

  std::optional<SerializedResultPtr> TryGetCachedResponse(const std::optional<CacheKey>& key) const {
    return cache_.Get(key);
  }

  void CacheResponse(const std::optional<CacheKey>& key, const SerializedResultPtr& response) const {
    cache_.Put(key, response);
  }

  std::string HandleRequestThrow(const HttpRequest& request, RequestContext& context) const override {
    auto session = CreateSession(context);

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
    // Keep the same request snapshot for lookup and insertion across the Tonlib wait.
    const auto cache_key = cache_.PrepareKey(tonlib_request);
    if (auto tonlib_cached_response = TryGetCachedResponse(cache_key); tonlib_cached_response.has_value()) {
      return ReturnTonlibResponse(request, context, *tonlib_cached_response.value(), true);
    }

    auto tonlib_response = HandleRequestTonlibThrow(tonlib_request, session);
    if (tonlib_response.is_error()) {
      auto tonlib_error = tonlib_response.move_as_error();
      return ReturnErrorResponse(
        request, context, utils::TonlibException{tonlib_error.message().str(), tonlib_error.code()}, false
      );
    }

    auto tonlib_result = tonlib_response.move_as_ok();

    if (!cache_key) {
      return ReturnTonlibResponse(request, context, SerializedResult{tonlib_result}, false);
    }

    const auto serialized_result = std::make_shared<const SerializedResult>(tonlib_result);
    CacheResponse(cache_key, serialized_result);
    return ReturnTonlibResponse(request, context, *serialized_result, false);
  }

  template <userver::logging::Level level = userver::logging::Level::kInfo>
  void LogResponse(
    const HttpRequest& request, RequestContext& context, std::string_view response
  ) const {
    LogJsonResponse(
      request,
      [&context] {
        const auto& tonlib_request = context.GetData<Request>(kRequest);
        return userver::formats::json::ValueBuilder{tonlib_request}.ExtractValue();
      },
      response,
      level
    );
  }

private:
  RequestCache<Request, SerializedResultPtr> cache_;
};

}  // namespace ton_http::handlers
