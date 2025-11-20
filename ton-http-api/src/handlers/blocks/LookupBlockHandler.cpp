#include "LookupBlockHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::LookupBlockHandler::LookupBlockHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::LookupBlockRequest ton_http::handlers::LookupBlockHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::LookupBlockRequest req;
  try {
    req.workchain = boost::lexical_cast<std::int32_t>(request.GetArg("workchain"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }
  try {
    req.workchain = boost::lexical_cast<std::int32_t>(request.GetArg("workchain"));
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse workchain", 422);
  }
  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }
  if (request.HasArg("lt")) {
    try {
      req.lt = boost::lexical_cast<std::int64_t>(request.GetArg("lt"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse lt", 422);
    }
  }
  if (request.HasArg("unixtime")) {
    try {
      req.unixtime = boost::lexical_cast<std::int32_t>(request.GetArg("unixtime"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse unixtime", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::LookupBlockHandler::ValidateRequest(
  const schemas::v2::LookupBlockRequest& request
) const {
  int has_arg = 0;
  if (request.seqno.has_value()) {
    ++has_arg;
    if (request.seqno.value() <= 0) {
      return td::Status::Error(422, "seqno should be positive");
    }
  }
  if (request.lt.has_value()) {
    ++has_arg;
    if (request.lt.value() < 0) {
      return td::Status::Error(422, "lt should be non-negative");
    }
  }
  if (request.unixtime.has_value()) {
    ++has_arg;
    if (request.unixtime.value() < 0) {
      return td::Status::Error(422, "unixtime should be non-negative");
    }
  }
  if (has_arg != 1) {
    return td::Status::Error(422, "exactly one of seqno, lt, unixtime should be specified");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::LookupBlock> ton_http::handlers::LookupBlockHandler::HandleRequestTonlibThrow(
  schemas::v2::LookupBlockRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::lookupBlock,
      request.workchain,
      request.shard,
      request.seqno,
      request.lt,
      request.unixtime,
      session
    )
  );
  return converters::Convert(result);
}
