#include "GetOutMsgQueueSizeHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetOutMsgQueueSizeHandler::GetOutMsgQueueSizeHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::OutMsgQueueSizeRequest ton_http::handlers::GetOutMsgQueueSizeHandler::ParseTonlibGetRequest(
    const HttpRequest&, const Value&, RequestContext&
) const {
  return {};
}
td::Status ton_http::handlers::GetOutMsgQueueSizeHandler::ValidateRequest(
    const schemas::v2::OutMsgQueueSizeRequest&
) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::OutMsgQueueSizes> ton_http::handlers::GetOutMsgQueueSizeHandler::HandleRequestTonlibThrow(
    schemas::v2::OutMsgQueueSizeRequest&, multiclient::SessionPtr& session
) const {
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::getOutMsgQueueSizes, session));
  return converters::Convert(result);
}
