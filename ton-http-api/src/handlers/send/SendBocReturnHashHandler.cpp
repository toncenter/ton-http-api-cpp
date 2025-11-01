#include "SendBocReturnHashHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::SendBocReturnHashHandler::SendBocReturnHashHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::SendBocRequest ton_http::handlers::SendBocReturnHashHandler::ParseTonlibGetRequest(
    const HttpRequest&, RequestContext&
) const {
  throw std::logic_error("unreachable");
}
td::Status ton_http::handlers::SendBocReturnHashHandler::ValidateRequest(
    const schemas::v2::SendBocRequest& request
) const {
  if (request.boc.empty()) {
    return td::Status::Error(422, "empty boc");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::ExtMessageInfo> ton_http::handlers::SendBocReturnHashHandler::HandleRequestTonlibThrow(
    schemas::v2::SendBocRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::raw_sendMessageReturnHash, request.boc.GetUnderlying(), session));
  return converters::Convert(result);
}
