#include "GetConfigAllHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetConfigAllHandler::GetConfigAllHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ConfigAllRequest ton_http::handlers::GetConfigAllHandler::ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext&
) const {
  schemas::v2::ConfigAllRequest req;
  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }

  return req;
}
td::Status ton_http::handlers::GetConfigAllHandler::ValidateRequest(
    const schemas::v2::ConfigAllRequest& request
) const {
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::ConfigInfo> ton_http::handlers::GetConfigAllHandler::HandleRequestTonlibThrow(
    schemas::v2::ConfigAllRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::getConfigAll, request.seqno, session));
  return converters::Convert(result);
}
