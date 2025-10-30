#include "GetBlockHeaderHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetBlockHeaderHandler::GetBlockHeaderHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::BlockHeaderRequest ton_http::handlers::GetBlockHeaderHandler::ParseTonlibGetRequest(
  const HttpRequest& request, const Value&, RequestContext&
) const {
  schemas::v2::BlockHeaderRequest req;
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
  return req;
}
td::Status ton_http::handlers::GetBlockHeaderHandler::ValidateRequest(
  const schemas::v2::BlockHeaderRequest& request
) const {
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::BlockHeader> ton_http::handlers::GetBlockHeaderHandler::HandleRequestTonlibThrow(
  schemas::v2::BlockHeaderRequest& request, multiclient::SessionPtr& session
) const {
  auto root_hash = request.root_hash.has_value() ? request.root_hash.value().GetUnderlying() : "";
  auto file_hash = request.file_hash.has_value() ? request.file_hash.value().GetUnderlying() : "";
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::getBlockHeader,
      request.workchain,
      request.shard,
      request.seqno,
      root_hash,
      file_hash,
      session
    )
  );
  return converters::Convert(result);
}
