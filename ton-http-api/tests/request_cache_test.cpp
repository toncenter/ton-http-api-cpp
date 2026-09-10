#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <userver/components/component_base.hpp>
#include <userver/components/minimal_component_list.hpp>
#include <userver/components/run.hpp>
#include <userver/engine/sleep.hpp>
#include <userver/formats/json.hpp>
#include <userver/yaml_config/merge_schemas.hpp>

#include "handlers/RequestCache.h"
#include "schemas/v2.hpp"

namespace cache_key_test {
namespace json = userver::formats::json;
namespace schemas = ton_http::schemas::v2;
using namespace std::chrono_literals;

void Check(bool condition, const char* message) {
  if (!condition) {
    throw std::runtime_error(message);
  }
}

struct CountedRequest {
  std::string value;
  static inline int serializations = 0;

  bool operator==(const CountedRequest&) const = default;
};

[[maybe_unused]] json::Value Serialize(const CountedRequest&, userver::formats::serialize::To<json::Value>) {
  ++CountedRequest::serializations;
  throw std::runtime_error("Cache keys must not invoke JSON serializers");
}
}  // namespace cache_key_test

namespace ton_http::handlers::detail {
template <>
inline constexpr bool kIsRequestAggregate<cache_key_test::CountedRequest> = true;
}  // namespace ton_http::handlers::detail

namespace cache_key_test {
using TestCache = ton_http::handlers::RequestCache<CountedRequest, int>;

struct ConstantHash {
  std::size_t operator()(const TestCache::Key&) const noexcept {
    return 0;
  }
};

void CheckCollisions() {
  auto& serializations = CountedRequest::serializations;
  serializations = 0;
  const TestCache::Key first{CountedRequest{"first"}};
  const TestCache::Key second{CountedRequest{"second"}};
  userver::cache::ExpirableLruCache<TestCache::Key, int, ConstantHash, TestCache::Equal> cache{1, 4};
  cache.Put(first, 11);
  cache.Put(second, 22);
  Check(cache.GetOptionalNoUpdate(first) == 11, "collision overwrote first entry");
  Check(cache.GetOptionalNoUpdate(second) == 22, "collision overwrote second entry");
  Check(serializations == 0, "hash/equality serialized a request");
  // Also exercise a collision of the stored structural hashes, not just cache buckets.
  const userver::utils::CachedHash<CountedRequest> collided_first{0, {"first"}};
  const userver::utils::CachedHash<CountedRequest> collided_second{0, {"second"}};
  Check(!(collided_first == collided_second), "equal hashes bypassed value equality");
}

template <typename Request>
void CheckEquivalence(const std::vector<std::string>& inputs) {
  using Cache = ton_http::handlers::RequestCache<Request, int>;
  std::vector<std::string> old_keys;
  std::vector<typename Cache::Key> new_keys;
  for (const auto& input : inputs) {
    const auto request = json::FromString(input).As<Request>();
    old_keys.push_back(ToString(json::ValueBuilder{request}.ExtractValue()));
    new_keys.emplace_back(request);
  }
  for (std::size_t i = 0; i < inputs.size(); ++i) {
    for (std::size_t j = 0; j < inputs.size(); ++j) {
      Check(
        typename Cache::Equal{}(new_keys[i], new_keys[j]) == (old_keys[i] == old_keys[j]), "key equivalence changed"
      );
      if (old_keys[i] == old_keys[j]) {
        Check(
          typename Cache::Hash{}(new_keys[i]) == typename Cache::Hash{}(new_keys[j]), "equal keys have different hashes"
        );
      }
    }
  }
}

void CheckSchemaKeys() {
  CheckEquivalence<schemas::EmptyRequest>({"{}", "{}"});
  CheckEquivalence<schemas::DetectHashRequest>(
    {R"({"hash":"0000000000000000000000000000000000000000000000000000000000000000"})",
     R"({"hash":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA="})",
     R"({"hash":"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"})",
     R"({"hash":"1111111111111111111111111111111111111111111111111111111111111111"})"}
  );
  const std::string address = "0:" + std::string(64, '0');
  const auto prefix = "{\"address\":\"" + address + "\"";
  CheckEquivalence<schemas::AddressWithSeqnoRequest>(
    {prefix + "}",
     prefix + ",\"seqno\":0}",
     prefix + ",\"seqno\":123}",
     R"({"address":"EQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAM9c"})"}
  );
  CheckEquivalence<schemas::TransactionsRequest>(
    {prefix + "}",
     prefix + R"(,"lt":123,"limit":10,"archival":false})",
     prefix + R"(,"lt":"123","limit":"10","archival":"false"})",
     prefix + R"(,"lt":123,"limit":11,"archival":false})",
     prefix + R"(,"lt":123,"limit":10,"archival":true})"}
  );
  CheckEquivalence<schemas::EstimateFeeRequest>(
    {prefix + R"(,"body":"AA=="})",
     prefix + R"(,"body":"AA==","ignore_chksig":true})",
     prefix + R"(,"body":"AA==","ignore_chksig":false})",
     prefix + R"(,"body":"AA==","init_code":""})",
     prefix + R"(,"body":"AQ=="})"}
  );
  CheckEquivalence<schemas::RunGetMethodRequest>(
    {prefix + R"(,"method":"seqno","stack":[]})",
     prefix + R"(,"stack":[],"method":"seqno"})",
     prefix + R"(,"method":123,"stack":[]})",
     prefix + R"(,"method":"123","stack":[]})",
     prefix + R"(,"method":"seqno","stack":[["num","1"]]})",
     prefix + R"(,"method":"seqno","stack":[["num","1"]],"seqno":123})"}
  );
  const std::string number = R"({"@type":"tvm.stackEntryNumber","number":{"@type":"tvm.numberDecimal","number":"1"}})";
  const auto tuple = R"({"@type":"tvm.stackEntryTuple","tuple":{"@type":"tvm.tuple","elements":[)" + number + "]}}";
  const auto list = R"({"@type":"tvm.stackEntryList","list":{"@type":"tvm.list","elements":[)" + tuple + "]}}";
  CheckEquivalence<schemas::RunGetMethodStdRequest>(
    {prefix + R"(,"method":"seqno","stack":[]})",
     prefix + R"(,"method":"seqno","stack":[)" + number + "]}",
     prefix + R"(,"method":"seqno","stack":[)" + tuple + "]}",
     prefix + R"(,"method":"seqno","stack":[)" + list + "]}",
     prefix + R"(,"method":"seqno","stack":[)" + list + R"(],"seqno":123})"}
  );

  using StackCache = ton_http::handlers::RequestCache<schemas::RunGetMethodStdRequest, int>;
  auto request =
    json::FromString(prefix + R"(,"method":"seqno","stack":[)" + list + "]}").As<schemas::RunGetMethodStdRequest>();
  const auto original = request;
  const StackCache::Key key{request};
  std::get<userver::utils::Box<schemas::TvmStackEntryList>>(request.stack[0])->list.elements.clear();
  Check(StackCache::Equal{}(key, StackCache::Key{original}), "nested request mutation changed a prepared key");
  Check(!StackCache::Equal{}(key, StackCache::Key{request}), "nested stack change was ignored");
}

void CheckStructuralHash() {
  using ton_http::handlers::detail::StructuralHash;
  Check(StructuralHash(std::optional<int>{}) != StructuralHash(std::optional<int>{0}), "optional presence ignored");
  Check(StructuralHash(std::vector<int>{1, 2}) != StructuralHash(std::vector<int>{2, 1}), "vector order ignored");
  Check(StructuralHash(std::vector<int>{1}) != StructuralHash(std::vector<int>{1, 0}), "vector length ignored");
  Check(
    StructuralHash(std::variant<int, long>{std::in_place_index<0>, 1}) !=
      StructuralHash(std::variant<int, long>{std::in_place_index<1>, 1}),
    "variant alternative ignored"
  );
  Check(StructuralHash(std::string{"a\0b", 3}) != StructuralHash(std::string{"a\0c", 3}), "binary string truncated");
  const userver::utils::Box<schemas::TvmNumberDecimal> first{schemas::TvmNumberDecimal{}};
  const auto second = first;
  Check(StructuralHash(first) == StructuralHash(second), "box hashed by address");
}

class CacheTestComponent final : public userver::components::ComponentBase {
public:
  static userver::yaml_config::Schema GetStaticConfigSchema() {
    return userver::yaml_config::MergeSchemas<ComponentBase>(R"(
type: object
description: Cache regression test
additionalProperties: false
properties:
  cache_enabled:
    type: boolean
    description: Enable cache
  cache_size:
    type: integer
    description: Cache capacity
  cache_ways:
    type: integer
    description: Cache partitions
  cache_ttl:
    type: string
    description: Entry lifetime
)");
  }

  CacheTestComponent(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  ) :
      ComponentBase(config, context) {
    TestCache cache{config, context};
    auto& serializations = CountedRequest::serializations;
    serializations = 0;
    CountedRequest request{"original"};
    if (!config["cache_enabled"].As<bool>()) {
      const auto key = cache.PrepareKey(request);
      Check(!key, "disabled cache prepared a key");
      Check(!cache.Get(key), "disabled cache returned a response");
      cache.Put(key, 11);
      Check(serializations == 0, "disabled cache serialized a request");
      return;
    }

    const auto key = cache.PrepareKey(request);
    Check(key.has_value(), "enabled cache did not prepare a key");
    Check(!cache.Get(key), "empty cache returned a response");
    cache.Put(key, 11);
    for (int i = 0; i < 10; ++i) {
      Check(cache.Get(key) == 11, "cache hit failed");
    }
    Check(serializations == 0, "lookup/insertion serialized the prepared request again");

    // Mutating or destroying request data must not change a prepared key.
    request.value = "changed";
    const auto changed = cache.PrepareKey(request);
    Check(!cache.Get(changed), "distinct request hit an old entry");
    cache.Put(key, 22);
    Check(cache.Get(key) == 22, "request mutation changed the prepared key");
    Check(serializations == 0, "cache operations serialized a request");

    Check(!cache.Get(std::nullopt), "absent key returned a response");
    cache.Put(std::nullopt, 33);
    Check(cache.PrepareKey(request).has_value(), "request with a throwing serializer was rejected");
    Check(serializations == 0, "key preparation called a JSON serializer");

    userver::engine::SleepFor(200ms);
    Check(!cache.Get(key), "expired entry was returned");
    cache.Put(key, 44);
    Check(cache.Get(key) == 44, "expired key could not be reinserted");
    CheckCollisions();
    CheckSchemaKeys();
    CheckStructuralHash();
  }
};

void RunTests(bool enabled) {
  const std::string config = R"(
components_manager:
  coro_pool:
    initial_size: 5
    max_size: 50
  default_task_processor: main-task-processor
  fs_task_processor: main-task-processor
  event_thread_pool:
    threads: 1
  task_processors:
    main-task-processor:
      worker_threads: 1
  components:
    logging:
      loggers:
        default:
          file_path: '@null'
    cache-test:
      cache_size: 8
      cache_ways: 1
      cache_ttl: 100ms
      cache_enabled: )" +
    std::string{enabled ? "true" : "false"} + "\n";
  userver::components::RunOnce(
    userver::components::InMemoryConfig{config},
    userver::components::MinimalComponentList().Append<CacheTestComponent>("cache-test")
  );
}
}  // namespace cache_key_test

int main() {
  try {
    cache_key_test::RunTests(false);
    cache_key_test::RunTests(true);
    std::cout << "Cache key regression tests passed\n";
  } catch (const std::exception& exception) {
    std::cerr << exception.what() << '\n';
    return 1;
  }
}
