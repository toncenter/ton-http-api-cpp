#include "GetConsensusBlockHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetConsensusBlockHandler::GetConsensusBlockHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ConsensusBlockRequest ton_http::handlers::GetConsensusBlockHandler::ParseTonlibGetRequest(
    const HttpRequest&, const Value&, RequestContext&
) const {
  return {};
}
td::Status ton_http::handlers::GetConsensusBlockHandler::ValidateRequest(
    const schemas::v2::ConsensusBlockRequest&
) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::ConsensusBlock> ton_http::handlers::GetConsensusBlockHandler::HandleRequestTonlibThrow(
    schemas::v2::ConsensusBlockRequest&, multiclient::SessionPtr& session
) const {
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::getConsensusBlock, session));
  return converters::Convert(result);
}
