#include "GetShardsHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetShardsHandler::GetShardsHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ShardsRequest ton_http::handlers::GetShardsHandler::ParseTonlibGetRequest(
  const HttpRequest& request, const Value&, RequestContext&
) const {
  schemas::v2::ShardsRequest req;

  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetShardsHandler::ValidateRequest(const schemas::v2::ShardsRequest& request) const {
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::Shards> ton_http::handlers::GetShardsHandler::HandleRequestTonlibThrow(
  schemas::v2::ShardsRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(&core::TonlibWorker::getShards, request.seqno, std::nullopt, std::nullopt, session)
  );
  return converters::Convert(result);
}
