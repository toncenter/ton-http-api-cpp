#include "GetBlockHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"
#include "utils/common.hpp"

ton_http::handlers::GetBlockHandler::GetBlockHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::BlockDataRequest ton_http::handlers::GetBlockHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext&
) const {
  schemas::v2::BlockDataRequest req;
  try {
    req.workchain = boost::lexical_cast<std::int32_t>(request.GetArg("workchain"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }
  try {
    req.shard = boost::lexical_cast<std::int64_t>(request.GetArg("shard"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse shard", 422);
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
  if (request.HasArg("archival")) {
    try {
      req.archival = utils::stringToBool(request.GetArg("archival"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse archival", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetBlockHandler::ValidateRequest(
  const schemas::v2::BlockDataRequest& request
) const {
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::BlockData> ton_http::handlers::GetBlockHandler::HandleRequestTonlibThrow(
  schemas::v2::BlockDataRequest& request, multiclient::SessionPtr& session
) const {
  auto root_hash = request.root_hash.has_value() ? request.root_hash.value().GetUnderlying() : "";
  auto file_hash = request.file_hash.has_value() ? request.file_hash.value().GetUnderlying() : "";
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::getBlock,
      request.workchain,
      request.shard,
      request.seqno,
      root_hash,
      file_hash,
      request.archival,
      session
    )
  );
  return converters::Convert(result);
}
