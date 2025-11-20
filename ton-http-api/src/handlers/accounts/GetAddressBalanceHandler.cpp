#include "GetAddressBalanceHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetAddressBalanceHandler::GetAddressBalanceHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::AddressBalanceRequest ton_http::handlers::GetAddressBalanceHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::AddressBalanceRequest req;

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
td::Status ton_http::handlers::GetAddressBalanceHandler::ValidateRequest(
  const schemas::v2::AddressBalanceRequest& request
) const {
  if (request.address.empty()) {
    return td::Status::Error(422, "empty address");
  }
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::AddressBalance>
ton_http::handlers::GetAddressBalanceHandler::HandleRequestTonlibThrow(
  schemas::v2::AddressBalanceRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
    &core::TonlibWorker::getAddressInformation, request.address.GetUnderlying(), request.seqno, session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return std::to_string(result_ok->balance_ < 0 ? 0 : result_ok->balance_);
}
