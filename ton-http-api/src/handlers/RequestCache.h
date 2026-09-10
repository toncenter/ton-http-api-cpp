#pragma once

#include <algorithm>
#include <chrono>
#include <functional>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

#include "userver/cache/expirable_lru_cache.hpp"
#include "userver/components/component_config.hpp"
#include "userver/components/component_context.hpp"
#include "userver/components/statistics_storage.hpp"
#include "userver/utils/cached_hash.hpp"

#include "RequestHash.h"
#include "userver/utils/statistics/entry.hpp"

namespace ton_http::handlers {

template <typename Request, typename Response>
class RequestCache {
public:
  class Key {
  public:
    explicit Key(const Request& request) : value_{0, request} {
      value_.hash = detail::StructuralHash(value_.key);
    }

    std::size_t GetHash() const noexcept {
      return value_.hash;
    }

    bool operator==(const Key& other) const {
      return value_ == other.value_;
    }

  private:
    userver::utils::CachedHash<Request> value_;
  };

  struct Hash {
    std::size_t operator()(const Key& key) const noexcept {
      return key.GetHash();
    }
  };
  struct Equal {
    bool operator()(const Key& lhs, const Key& rhs) const {
      return lhs == rhs;
    }
  };
  using Cache = userver::cache::ExpirableLruCache<Key, Response, Hash, Equal>;

  RequestCache(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) {
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
      const auto way_size = std::max(cache_size / cache_ways, 1ul);
      cache_ = std::make_unique<Cache>(cache_ways, way_size);
      cache_->SetMaxLifetime(cache_ttl);
      cache_->SetBackgroundUpdate(userver::cache::BackgroundUpdateMode::kEnabled);
      cache_stats_holder_ = context.FindComponent<userver::components::StatisticsStorage>().GetStorage().RegisterWriter(
        "cache",
        [cache = cache_.get()](userver::utils::statistics::Writer& writer) { writer = *cache; },
        {{"cache_name", std::string{userver::components::GetCurrentComponentName(context)}}}
      );
    }
  }

  RequestCache(const RequestCache&) = delete;
  RequestCache& operator=(const RequestCache&) = delete;
  RequestCache(RequestCache&&) = delete;
  RequestCache& operator=(RequestCache&&) = delete;

  ~RequestCache() {
    // Wait for statistics readers before destroying the cache they access.
    cache_stats_holder_.Unregister();
  }

  std::optional<Key> PrepareKey(const Request& request) const {
    if (!cache_) {
      return std::nullopt;
    }
    return Key{request};
  }

  std::optional<Response> Get(const std::optional<Key>& key) const {
    if (!cache_ || !key) {
      return std::nullopt;
    }
    return cache_->GetOptionalNoUpdate(*key);
  }

  void Put(const std::optional<Key>& key, const Response& response) const {
    if (cache_ && key) {
      cache_->Put(*key, response);
    }
  }

private:
  std::unique_ptr<Cache> cache_;
  userver::utils::statistics::Entry cache_stats_holder_;
};

}  // namespace ton_http::handlers
