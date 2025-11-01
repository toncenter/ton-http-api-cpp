#include "GetBlockTransactionsExtHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetBlockTransactionsExtHandler::GetBlockTransactionsExtHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::BlockTransactionsExtRequest ton_http::handlers::GetBlockTransactionsExtHandler::
  ParseTonlibGetRequest(const HttpRequest& request, RequestContext&) const {
  schemas::v2::BlockTransactionsExtRequest req;
  try {
    req.workchain = boost::lexical_cast<std::int32_t>(request.GetArg("workchain"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }
  try {
    req.shard = boost::lexical_cast<std::int64_t>(request.GetArg("shard"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }
  try {
    req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse seqno", 422);
  }
  if (request.HasArg("root_hash")) {
    try {
      req.root_hash = userver::chaotic::convert::Convert(
        request.GetArg("root_hash"), userver::chaotic::convert::To<ton_http::types::ton_hash>{}
      );
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse root_hash", 422);
    }
  }
  if (request.HasArg("file_hash")) {
    try {
      req.file_hash = userver::chaotic::convert::Convert(
        request.GetArg("file_hash"), userver::chaotic::convert::To<ton_http::types::ton_hash>{}
      );
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse file_hash", 422);
    }
  }
  if (request.HasArg("after_lt")) {
    try {
      req.after_lt = boost::lexical_cast<std::int64_t>(request.GetArg("after_lt"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse after_lt", 422);
    }
  }
  if (request.HasArg("after_hash")) {
    try {
      req.after_hash = userver::chaotic::convert::Convert(
        request.GetArg("after_hash"), userver::chaotic::convert::To<ton_http::types::ton_addr_without_workchain>{}
      );
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse after_hash", 422);
    }
  }
  if (request.HasArg("count")) {
    try {
      req.count = boost::lexical_cast<std::int32_t>(request.GetArg("count"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse count", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetBlockTransactionsExtHandler::ValidateRequest(
  const schemas::v2::BlockTransactionsExtRequest& request
) const {
  if (request.count <= 0) {
    return td::Status::Error(422, "count should be positive");
  }
  if (request.count > 2000) {
    return td::Status::Error(422, "count should be less or equal 100");
  }
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  bool has_after_lt = false;
  if (request.after_lt) {
    has_after_lt = true;
    if (*request.after_lt <= 0) {
      return td::Status::Error(422, "after_lt should be positive");
    }
  }
  bool has_after_hash = false;
  if (request.after_hash.has_value() && !request.after_hash.value().empty()) {
    has_after_hash = true;
  }
  if (has_after_hash != has_after_lt) {
    return td::Status::Error(422, "after_lt and after_hash should be used together");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::BlockTransactionsExt>
ton_http::handlers::GetBlockTransactionsExtHandler::HandleRequestTonlibThrow(
  schemas::v2::BlockTransactionsExtRequest& request, multiclient::SessionPtr& session
) const {
  auto root_hash = request.root_hash.has_value() ? request.root_hash.value().GetUnderlying() : "";
  auto file_hash = request.file_hash.has_value() ? request.file_hash.value().GetUnderlying() : "";
  auto after_hash = request.after_hash.has_value() ? request.after_hash.value().GetUnderlying() : "";

  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::getBlockTransactionsExt,
      request.workchain,
      request.shard,
      request.seqno,
      request.count,
      root_hash,
      file_hash,
      request.after_lt,
      after_hash,
      std::nullopt,
      session
    )
  );
  return converters::Convert(result);
}
