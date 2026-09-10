#pragma once

#include <optional>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

#include "RequestCache.h"
#include "TonlibHandlerBase.h"
#include "components/TonlibComponent.h"
#include "schemas/v2.hpp"
#include "userver/yaml_config/merge_schemas.hpp"
#include "utils/exceptions.hpp"

namespace ton_http::handlers {
namespace detail {

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

}  // namespace detail

template <typename Request, typename Response>
class TonlibRequestHandler : public TonlibHandlerBase {
public:
  using Hash = typename RequestCache<Request, Response>::Hash;
  using Equal = typename RequestCache<Request, Response>::Equal;
  using Cache = typename RequestCache<Request, Response>::Cache;

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
    auto response_body = MakeErrorResponse(request, context, exc);

    if (!is_malformed) {
      LogResponse<userver::logging::Level::kWarning>(request, context, response_body);
    }
    return ToString(response_body);
  }

  std::string ReturnTonlibResponse(
    const HttpRequest& request, RequestContext& context, Response& tonlib_response, bool is_cached
  ) const {
    schemas::v2::TonlibResponse response;
    if constexpr (detail::VariantLike<Response>) {
      std::visit([&]<typename T0>(T0&& val) { response.result = std::forward<T0>(val); }, tonlib_response);
    } else if constexpr (detail::VectorLike<Response>) {
      std::vector<schemas::v2::TonlibObject> result_vector;
      for (const auto& item : tonlib_response) {
        result_vector.emplace_back(item);
      }
      response.result = result_vector;
    } else {
      response.result = tonlib_response;
    }

    auto response_body = MakeSuccessResponse(request, context, response, is_cached);

    LogResponse(request, context, response_body);
    return ToString(response_body);
  }

  std::optional<Response> TryGetCachedResponse(const Request& request) const {
    return cache_.Get(request);
  }

  void CacheResponse(const Request& request, const Response& response) const {
    cache_.Put(request, response);
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

  template <userver::logging::Level level = userver::logging::Level::kInfo>
  void LogResponse(
    const HttpRequest& request, RequestContext& context, const userver::formats::json::Value& response
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
  RequestCache<Request, Response> cache_;
};

}  // namespace ton_http::handlers
