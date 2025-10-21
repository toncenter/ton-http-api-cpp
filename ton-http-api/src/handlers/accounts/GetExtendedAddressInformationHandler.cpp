#include "GetExtendedAddressInformationHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetExtendedAddressInformationHandler::GetExtendedAddressInformationHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ExtendedAddressInformationRequest
ton_http::handlers::GetExtendedAddressInformationHandler::ParseTonlibGetRequest(
  const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::ExtendedAddressInformationRequest req;

  req.address = userver::chaotic::convert::Convert(
    request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
  );
  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }
  return req;
}
td::Result<ton_http::schemas::v2::ExtendedAddressInformation>
ton_http::handlers::GetExtendedAddressInformationHandler::HandleRequestTonlibThrow(
  schemas::v2::ExtendedAddressInformationRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
    &core::TonlibWorker::getExtendedAddressInformation, request.address.GetUnderlying(), request.seqno, session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
