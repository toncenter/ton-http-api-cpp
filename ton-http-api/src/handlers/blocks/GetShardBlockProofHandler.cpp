#include "GetShardBlockProofHandler.h"
#include <boost/lexical_cast.hpp>
#include "converters/convert.hpp"

ton_http::handlers::GetShardBlockProofHandler::GetShardBlockProofHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ShardBlockProofRequest ton_http::handlers::GetShardBlockProofHandler::ParseTonlibGetRequest(
  const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::ShardBlockProofRequest req;
  if (!request.HasArg("workchain")) {
    throw utils::TonlibException("workchain required", 422);
  }
  try {
    req.workchain = boost::lexical_cast<std::int32_t>(request.GetArg("workchain"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }

  if (!request.HasArg("shard")) {
    throw utils::TonlibException("shard required", 422);
  }
  try {
    req.shard = boost::lexical_cast<std::int64_t>(request.GetArg("shard"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse shard", 422);
  }
  if (!request.HasArg("seqno")) {
    throw utils::TonlibException("seqno required", 422);
  }
  try {
    req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse seqno", 422);
  }
  if (request.HasArg("from_seqno")) {
    try {
      req.from_seqno = boost::lexical_cast<std::int32_t>(request.GetArg("from_seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse from_seqno", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetShardBlockProofHandler::ValidateRequest(
  const schemas::v2::ShardBlockProofRequest& request
) const {
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  if (request.from_seqno.has_value() && request.from_seqno.value() <= 0) {
    return td::Status::Error(422, "from_seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::ShardBlockProof>
ton_http::handlers::GetShardBlockProofHandler::HandleRequestTonlibThrow(
  schemas::v2::ShardBlockProofRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::getShardBlockProof,
      request.workchain,
      request.shard,
      request.seqno,
      request.from_seqno,
      session
    )
  );
  return converters::Convert(result);
}
