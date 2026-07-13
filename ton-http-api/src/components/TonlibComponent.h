#pragma once
#include <atomic>
#include <chrono>
#include <compare>
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "core/tonlib_worker.h"
#include "tonlib-multiclient/multi_client.h"
#include "userver/clients/http/client.hpp"
#include "userver/components/component_base.hpp"
#include "userver/dynamic_config/source.hpp"
#include "userver/logging/fwd.hpp"
#include "userver/utils/async.hpp"
#include "userver/utils/periodic_task.hpp"

namespace ton_http::core {
class TonlibComponent final : public userver::components::ComponentBase {
public:
  static constexpr std::string_view kName = "tonlib";

  TonlibComponent(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );
  ~TonlibComponent() override;

  [[nodiscard]] multiclient::SessionPtr GetNewSession() const;
  [[nodiscard]] bool ShouldBlockExternalMessages() const;

  template <typename Func, typename... Args>
  auto DoRequest(Func&& func, Args&&... args) -> decltype(auto) {
    auto task =
      userver::utils::Async(task_processor_, "tonlib_request", [this, func, ... args = std::forward<Args>(args)] {
        return (this->worker_.get()->*func)(args...);
      });
    return task.Get();
  }

  template <typename Func>
  auto DoRequest(Func&& func) -> decltype(auto) {
    auto task =
      userver::utils::Async(task_processor_, "tonlib_request", [this, func] { return (this->worker_.get()->*func)(); });
    return task.Get();
  }

  template <typename Func, typename... Args>
  auto DoStaticRequest(Func&& func, Args&&... args) -> decltype(auto) {
    auto task = userver::utils::Async(
      task_processor_, "tonlib_static_request", [this, func, ... args = std::forward<Args>(args)] {
        return (*func)(args...);
      }
    );
    return task.Get();
  }

  template <typename Func>
  auto DoStaticRequest(Func&& func) -> decltype(auto) {
    auto task = userver::utils::Async(task_processor_, "tonlib_static_request", [this, func] { return (*func)(); });
    return task.Get();
  }
  static userver::yaml_config::Schema GetStaticConfigSchema();

private:
  struct BlockId {
    std::int32_t workchain{};
    std::int64_t shard{};
    std::int32_t seqno{};
    std::string root_hash;
    std::string file_hash;

    auto operator<=>(const BlockId&) const = default;
  };

  struct BlockData {
    std::int64_t gen_utime{};
    std::vector<BlockId> prev_blocks;
    std::optional<std::uint64_t> transaction_count;
  };

  struct TpsSnapshot {
    std::uint64_t transaction_count{};
    std::size_t block_count{};
    std::int32_t masterchain_seqno{};
    std::int64_t masterchain_gen_utime{};
  };

  static BlockId MakeBlockId(const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& value);
  td::Result<BlockData> LoadBlockData(const BlockId& block, const multiclient::SessionPtr& session);
  td::Result<TpsSnapshot> CalculateNetworkTps();
  void CheckNetworkTps();

  userver::dynamic_config::Source config_;
  std::unique_ptr<TonlibWorker> worker_;
  userver::engine::TaskProcessor& task_processor_;
  userver::logging::LoggerPtr logger_;

  bool sendboc_tps_guard_enabled_{true};
  std::uint64_t sendboc_tps_limit_{300};
  std::chrono::seconds sendboc_tps_window_{60};
  std::chrono::milliseconds sendboc_tps_check_interval_{5000};
  std::chrono::milliseconds sendboc_tps_check_timeout_{60000};
  std::map<BlockId, BlockData> block_cache_;
  std::atomic_bool sendboc_blocked_by_tps_{false};
  std::atomic<std::uint64_t> last_transaction_count_{0};

  // Must be destroyed before the state used by its callback.
  userver::utils::PeriodicTask sendboc_tps_check_task_;
};
}  // namespace ton_http::core
