#include "tonlib_worker.h"

namespace ton_http::core {
td::Result<tonlib_api::dns_resolve::ReturnType> TonlibWorker::dnsResolve(
  const std::string& address,
  const std::string& name,
  std::optional<std::string> category,
  std::optional<std::int32_t> ttl,
  std::optional<std::int32_t> seqno,
  std::optional<bool> archival,
  multiclient::SessionPtr session
) const {
  tonlib_api::object_ptr<tonlib_api::ton_blockIdExt> with_block;
  if (seqno.has_value()) {
    TRY_RESULT_ASSIGN(
      with_block, lookupBlock(ton::masterchainId, ton::shardIdAll, seqno.value(), std::nullopt, std::nullopt, session)
    );
  }
  if (!with_block) {
    auto request = multiclient::RequestFunction<tonlib_api::dns_resolve>{
      .parameters = {.mode = multiclient::RequestMode::Single},
      .request_creator =
        [address_ = address, name_ = name, category_ = category, ttl_ = ttl] {
          return tonlib_api::make_object<tonlib_api::dns_resolve>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_),
            name_,
            td::Bits256::zero(),
            ttl_.value_or(0)
          );
      },
    .session = session
  };
    return send_request_function(std::move(request), true);
  }
  auto request = multiclient::RequestFunction<tonlib_api::withBlock>{
    .parameters = {.mode = multiclient::RequestMode::Single},
    .request_creator =
      [address_ = address, name_ = name, category_ = category, ttl_ = ttl,
       workchain_ = with_block->workchain_,
       shard_ = with_block->shard_,
       seqno_ = with_block->seqno_,
       root_hash_ = with_block->root_hash_,
       file_hash_ = with_block->file_hash_] {
        return tonlib_api::make_object<tonlib_api::withBlock>(
          tonlib_api::make_object<tonlib_api::ton_blockIdExt>(workchain_, shard_, seqno_, root_hash_, file_hash_),
          tonlib_api::make_object<tonlib_api::dns_resolve>(
            tonlib_api::make_object<tonlib_api::accountAddress>(address_),
            name_,
            td::Bits256::zero(),
            ttl_.value_or(0)
          )
        );
    },
  .session = session
};
  TRY_RESULT(result, send_request_function(std::move(request), true));
  return ton::move_tl_object_as<tonlib_api::dns_resolved>(result);
}
}  // namespace ton_http::core
