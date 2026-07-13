#include "TonlibComponent.h"

#include <limits>
#include <set>
#include <stdexcept>
#include <utility>

#include "userver/components/component.hpp"
#include "userver/components/component_context.hpp"
#include "userver/dynamic_config/storage/component.hpp"
#include "userver/engine/deadline.hpp"
#include "userver/engine/future_status.hpp"
#include "userver/engine/task/cancel.hpp"
#include "userver/logging/component.hpp"
#include "userver/logging/log.hpp"
#include "userver/yaml_config/merge_schemas.hpp"

namespace ton_http::core {
namespace {
std::atomic<const char*> sendboc_tps_check_stage{"not_started"};
std::atomic<std::int32_t> sendboc_tps_check_workchain{0};
std::atomic<std::int64_t> sendboc_tps_check_shard{0};
std::atomic<std::int32_t> sendboc_tps_check_seqno{0};
std::atomic<std::size_t> sendboc_tps_headers_loaded{0};
std::atomic<std::size_t> sendboc_tps_transaction_counts_loaded{0};

multiclient::SessionPtr CloneSession(const multiclient::SessionPtr& session) {
  return std::make_shared<multiclient::Session>(
    std::vector<std::size_t>(session->active_workers().begin(), session->active_workers().end())
  );
}
}  // namespace

TonlibComponent::TonlibComponent(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    userver::components::ComponentBase(config, context),
    config_(context.FindComponent<userver::components::DynamicConfig>().GetSource()),
    worker_(
      std::make_unique<TonlibWorker>(multiclient::MultiClientConfig{
        .global_config_path = config["global_config"].As<std::string>(),
        .key_store_root = config["keystore"].As<std::string>(),
        .blockchain_name = "",
        .reset_key_store = false,
        .scheduler_threads = config["threads"].As<std::size_t>(),
      })
    ),
    task_processor_(context.GetTaskProcessor(config["task_processor"].As<std::string>())),
    logger_(context.FindComponent<userver::components::Logging>().GetLogger("api-v2")),
    sendboc_tps_guard_enabled_(config["sendboc_tps_guard_enabled"].As<bool>(true)),
    sendboc_tps_limit_(config["sendboc_tps_limit"].As<std::uint64_t>(300)),
    sendboc_tps_window_(
      std::chrono::duration_cast<std::chrono::seconds>(
        config["sendboc_tps_window"].As<std::chrono::milliseconds>(std::chrono::seconds{60})
      )
    ),
    sendboc_tps_check_interval_(
      config["sendboc_tps_check_interval"].As<std::chrono::milliseconds>(std::chrono::seconds{5})
    ),
    sendboc_tps_check_timeout_(
      config["sendboc_tps_check_timeout"].As<std::chrono::milliseconds>(std::chrono::seconds{60})
    ) {
  if (sendboc_tps_limit_ == 0) {
    throw std::invalid_argument("sendboc_tps_limit must be positive");
  }
  if (sendboc_tps_window_.count() <= 0) {
    throw std::invalid_argument("sendboc_tps_window must be at least one second");
  }
  if (sendboc_tps_check_interval_.count() <= 0) {
    throw std::invalid_argument("sendboc_tps_check_interval must be positive");
  }
  if (sendboc_tps_check_timeout_.count() <= 0) {
    throw std::invalid_argument("sendboc_tps_check_timeout must be positive");
  }
  if (sendboc_tps_limit_ > std::numeric_limits<std::uint64_t>::max() / sendboc_tps_window_.count()) {
    throw std::invalid_argument("sendboc TPS threshold does not fit into uint64");
  }

  if (sendboc_tps_guard_enabled_) {
    userver::utils::PeriodicTask::Settings settings{
      sendboc_tps_check_interval_,
      userver::utils::Flags<userver::utils::PeriodicTask::Flags>{userver::utils::PeriodicTask::Flags::kNow}
    };
    settings.task_processor = &task_processor_;
    sendboc_tps_check_task_.Start("sendboc-tps-check", settings, [this] { CheckNetworkTps(); });
  }
}
TonlibComponent::~TonlibComponent() {
  sendboc_tps_check_task_.Stop();
}
multiclient::SessionPtr TonlibComponent::GetNewSession() const {
  return std::make_shared<multiclient::Session>();
}
bool TonlibComponent::ShouldBlockExternalMessages() const {
  return sendboc_tps_guard_enabled_ && sendboc_blocked_by_tps_.load(std::memory_order_relaxed);
}

TonlibComponent::BlockId TonlibComponent::MakeBlockId(const tonlib_api::object_ptr<tonlib_api::ton_blockIdExt>& value) {
  return BlockId{
    .workchain = value->workchain_,
    .shard = value->shard_,
    .seqno = value->seqno_,
    .root_hash = value->root_hash_,
    .file_hash = value->file_hash_
  };
}

td::Result<TonlibComponent::BlockData> TonlibComponent::LoadBlockData(
  const BlockId& block, const multiclient::SessionPtr& session
) {
  sendboc_tps_check_stage.store("block_header", std::memory_order_relaxed);
  sendboc_tps_check_workchain.store(block.workchain, std::memory_order_relaxed);
  sendboc_tps_check_shard.store(block.shard, std::memory_order_relaxed);
  sendboc_tps_check_seqno.store(block.seqno, std::memory_order_relaxed);
  TRY_RESULT(
    header,
    worker_->getBlockHeader(block.workchain, block.shard, block.seqno, block.root_hash, block.file_hash, session)
  );

  BlockData result;
  result.gen_utime = header->gen_utime_;
  result.prev_blocks.reserve(header->prev_blocks_.size());
  for (const auto& prev_block : header->prev_blocks_) {
    result.prev_blocks.emplace_back(MakeBlockId(prev_block));
  }
  sendboc_tps_headers_loaded.fetch_add(1, std::memory_order_relaxed);
  return result;
}

td::Result<TonlibComponent::TpsSnapshot> TonlibComponent::CalculateNetworkTps() {
  auto session = GetNewSession();
  sendboc_tps_check_stage.store("masterchain_info", std::memory_order_relaxed);
  TRY_RESULT(masterchain_info, worker_->getMasterchainInfo(session));
  if (!masterchain_info->last_) {
    return td::Status::Error("masterchain info contains no last block");
  }

  const auto masterchain_block = MakeBlockId(masterchain_info->last_);
  auto masterchain_data_it = block_cache_.find(masterchain_block);
  if (masterchain_data_it == block_cache_.end()) {
    TRY_RESULT(masterchain_data, LoadBlockData(masterchain_block, session));
    masterchain_data_it = block_cache_.emplace(masterchain_block, std::move(masterchain_data)).first;
  }

  const auto masterchain_gen_utime = masterchain_data_it->second.gen_utime;
  const auto cutoff = masterchain_gen_utime - sendboc_tps_window_.count();
  const auto cache_cutoff = cutoff - sendboc_tps_window_.count();
  for (auto it = block_cache_.begin(); it != block_cache_.end();) {
    if (it->second.gen_utime < cache_cutoff) {
      it = block_cache_.erase(it);
    } else {
      ++it;
    }
  }

  sendboc_tps_check_stage.store("shards", std::memory_order_relaxed);
  TRY_RESULT(shards, worker_->getShardsByBlockId(*masterchain_info->last_, session));

  std::vector<BlockId> pending_blocks;
  pending_blocks.reserve(shards->shards_.size() + 1);
  pending_blocks.emplace_back(masterchain_block);
  for (const auto& shard : shards->shards_) {
    pending_blocks.emplace_back(MakeBlockId(shard));
  }

  std::set<BlockId> visited_blocks;
  std::uint64_t transaction_count = 0;
  std::size_t block_count = 0;

  while (!pending_blocks.empty()) {
    userver::engine::current_task::CancellationPoint();

    std::vector<BlockId> current_blocks;
    current_blocks.reserve(pending_blocks.size());
    for (auto& block : pending_blocks) {
      if (visited_blocks.emplace(block).second) {
        current_blocks.emplace_back(std::move(block));
      }
    }
    pending_blocks.clear();

    struct HeaderTask {
      BlockId block;
      userver::engine::TaskWithResult<td::Result<BlockData>> task;
    };
    struct TransactionCountTask {
      BlockId block;
      userver::engine::TaskWithResult<td::Result<std::uint64_t>> task;
    };
    std::vector<HeaderTask> header_tasks;
    std::vector<TransactionCountTask> transaction_count_tasks;
    header_tasks.reserve(current_blocks.size());
    transaction_count_tasks.reserve(current_blocks.size());

    for (const auto& block : current_blocks) {
      const auto block_data_it = block_cache_.find(block);
      const auto needs_header = block_data_it == block_cache_.end();
      if (needs_header) {
        auto request_session = CloneSession(session);
        header_tasks.emplace_back(
          HeaderTask{
            block,
            userver::utils::Async(
              task_processor_, "sendboc-tps-block-header", [this, block, session = std::move(request_session)] {
                return LoadBlockData(block, session);
              }
            )
          }
        );
      }

      const auto needs_transaction_count =
        needs_header || (block_data_it->second.gen_utime > cutoff && !block_data_it->second.transaction_count);
      if (needs_transaction_count) {
        auto request_session = CloneSession(session);
        transaction_count_tasks.emplace_back(
          TransactionCountTask{
            block,
            userver::utils::Async(
              task_processor_, "sendboc-tps-block-transactions", [this, block, session = std::move(request_session)] {
                sendboc_tps_check_stage.store("block_transactions", std::memory_order_relaxed);
                sendboc_tps_check_workchain.store(block.workchain, std::memory_order_relaxed);
                sendboc_tps_check_shard.store(block.shard, std::memory_order_relaxed);
                sendboc_tps_check_seqno.store(block.seqno, std::memory_order_relaxed);
                return worker_->getBlockTransactionCount(
                  block.workchain, block.shard, block.seqno, block.root_hash, block.file_hash, std::nullopt, session
                );
              }
            )
          }
        );
      }
    }

    for (auto& request : header_tasks) {
      auto result = request.task.Get();
      if (result.is_error()) {
        return result.move_as_error();
      }
      block_cache_.emplace(std::move(request.block), result.move_as_ok());
    }
    for (auto& request : transaction_count_tasks) {
      auto result = request.task.Get();
      if (result.is_error()) {
        return result.move_as_error();
      }
      block_cache_.at(request.block).transaction_count = result.move_as_ok();
      sendboc_tps_transaction_counts_loaded.fetch_add(1, std::memory_order_relaxed);
    }

    for (const auto& block : current_blocks) {
      const auto& block_data = block_cache_.at(block);
      if (block_data.gen_utime <= cutoff) {
        continue;
      }
      if (!block_data.transaction_count) {
        return td::Status::Error("transaction count is missing after a TPS calculation batch");
      }

      transaction_count += block_data.transaction_count.value();
      ++block_count;
      pending_blocks.insert(pending_blocks.end(), block_data.prev_blocks.begin(), block_data.prev_blocks.end());
    }
  }

  return TpsSnapshot{
    .transaction_count = transaction_count,
    .block_count = block_count,
    .masterchain_seqno = masterchain_block.seqno,
    .masterchain_gen_utime = masterchain_gen_utime
  };
}

void TonlibComponent::CheckNetworkTps() {
  try {
    sendboc_tps_check_stage.store("starting", std::memory_order_relaxed);
    sendboc_tps_headers_loaded.store(0, std::memory_order_relaxed);
    sendboc_tps_transaction_counts_loaded.store(0, std::memory_order_relaxed);
    auto calculation_task =
      userver::utils::Async(task_processor_, "sendboc-tps-calculate", [this] { return CalculateNetworkTps(); });
    const auto wait_status =
      calculation_task.WaitNothrowUntil(userver::engine::Deadline::FromDuration(sendboc_tps_check_timeout_));
    if (wait_status != userver::engine::FutureStatus::kReady) {
      calculation_task.SyncCancel();
      const auto transaction_count = last_transaction_count_.load(std::memory_order_relaxed);
      const auto tps = static_cast<double>(transaction_count) / sendboc_tps_window_.count();
      LOG_WARNING_TO(*logger_)
        << "Network TPS check failed; keeping previous state: tps=" << tps
        << " blocked=" << sendboc_blocked_by_tps_.load(std::memory_order_relaxed)
        << " stage=" << sendboc_tps_check_stage.load(std::memory_order_relaxed)
        << " block=" << sendboc_tps_check_workchain.load(std::memory_order_relaxed) << ":"
        << sendboc_tps_check_shard.load(std::memory_order_relaxed) << ":"
        << sendboc_tps_check_seqno.load(std::memory_order_relaxed)
        << " headers_loaded=" << sendboc_tps_headers_loaded.load(std::memory_order_relaxed)
        << " transaction_counts_loaded=" << sendboc_tps_transaction_counts_loaded.load(std::memory_order_relaxed)
        << " error="
        << (wait_status == userver::engine::FutureStatus::kTimeout ? "calculation timed out" : "calculation cancelled");
      return;
    }

    auto snapshot_result = calculation_task.Get();
    if (snapshot_result.is_error()) {
      const auto error = snapshot_result.move_as_error();
      const auto transaction_count = last_transaction_count_.load(std::memory_order_relaxed);
      const auto tps = static_cast<double>(transaction_count) / sendboc_tps_window_.count();
      LOG_WARNING_TO(*logger_)
        << "Network TPS check failed; keeping previous state: tps=" << tps
        << " blocked=" << sendboc_blocked_by_tps_.load(std::memory_order_relaxed)
        << " stage=" << sendboc_tps_check_stage.load(std::memory_order_relaxed) << " error=" << error.message().str();
      return;
    }

    const auto snapshot = snapshot_result.move_as_ok();
    const auto threshold = sendboc_tps_limit_ * sendboc_tps_window_.count();
    const auto blocked = snapshot.transaction_count > threshold;
    const auto tps = static_cast<double>(snapshot.transaction_count) / sendboc_tps_window_.count();

    last_transaction_count_.store(snapshot.transaction_count, std::memory_order_relaxed);
    sendboc_blocked_by_tps_.store(blocked, std::memory_order_relaxed);
    sendboc_tps_check_stage.store("completed", std::memory_order_relaxed);

    // The api-v2 logger defaults to warning, so use warning to make every requested TPS check visible.
    LOG_WARNING_TO(*logger_) << "Network TPS check: tps=" << tps << " transactions=" << snapshot.transaction_count
                             << " blocks=" << snapshot.block_count << " window_seconds=" << sendboc_tps_window_.count()
                             << " limit=" << sendboc_tps_limit_ << " blocked=" << blocked
                             << " masterchain_seqno=" << snapshot.masterchain_seqno
                             << " masterchain_gen_utime=" << snapshot.masterchain_gen_utime;
  } catch (const std::exception& exc) {
    const auto transaction_count = last_transaction_count_.load(std::memory_order_relaxed);
    const auto tps = static_cast<double>(transaction_count) / sendboc_tps_window_.count();
    LOG_WARNING_TO(*logger_)
      << "Network TPS check failed with an exception; keeping previous state: tps=" << tps
      << " blocked=" << sendboc_blocked_by_tps_.load(std::memory_order_relaxed)
      << " stage=" << sendboc_tps_check_stage.load(std::memory_order_relaxed) << " error=" << exc.what();
  } catch (...) {
    const auto transaction_count = last_transaction_count_.load(std::memory_order_relaxed);
    const auto tps = static_cast<double>(transaction_count) / sendboc_tps_window_.count();
    LOG_WARNING_TO(*logger_)
      << "Network TPS check failed with an unknown exception; keeping previous state: tps=" << tps
      << " blocked=" << sendboc_blocked_by_tps_.load(std::memory_order_relaxed)
      << " stage=" << sendboc_tps_check_stage.load(std::memory_order_relaxed);
  }
}

userver::yaml_config::Schema TonlibComponent::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<ComponentBase>(R"(
type: object
description: tonlib component config
additionalProperties: false
properties:
    global_config:
        type: string
        description: path to TON network config
    keystore:
        type: string
        description: path to Tonlib keystore
    threads:
        type: integer
        description: number of Tonlib threads
    task_processor:
        type: string
        description: task processor name
    sendboc_tps_guard_enabled:
        type: boolean
        description: enable automatic sendBoc blocking based on network TPS
    sendboc_tps_limit:
        type: integer
        description: average TPS above which sendBoc is silently disabled
    sendboc_tps_window:
        type: string
        description: rolling window used to calculate network TPS
    sendboc_tps_check_interval:
        type: string
        description: interval between network TPS checks
    sendboc_tps_check_timeout:
        type: string
        description: maximum duration of one network TPS check
)");
}
}  // namespace ton_http::core
