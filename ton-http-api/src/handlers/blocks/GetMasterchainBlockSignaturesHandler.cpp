#include "GetMasterchainBlockSignaturesHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetMasterchainBlockSignaturesHandler::GetMasterchainBlockSignaturesHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::MasterchainBlockSignaturesRequest
ton_http::handlers::GetMasterchainBlockSignaturesHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::MasterchainBlockSignaturesRequest req;

  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetMasterchainBlockSignaturesHandler::ValidateRequest(
  const schemas::v2::MasterchainBlockSignaturesRequest& request
) const {
  if (request.seqno <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::MasterchainBlockSignatures>
ton_http::handlers::GetMasterchainBlockSignaturesHandler::HandleRequestTonlibThrow(
  schemas::v2::MasterchainBlockSignaturesRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(&core::TonlibWorker::getMasterchainBlockSignatures, request.seqno, session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
