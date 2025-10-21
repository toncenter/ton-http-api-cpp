#include "GetWalletInformationHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetWalletInformationHandler::GetWalletInformationHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::WalletInformationRequest ton_http::handlers::GetWalletInformationHandler::ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
) const {
  schemas::v2::WalletInformationRequest req;

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
td::Status ton_http::handlers::GetWalletInformationHandler::ValidateRequest(
    const schemas::v2::WalletInformationRequest& request
) const {
  if (request.address.empty()) {
    return td::Status::Error(422, "empty address");
  }
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::WalletInformation>
ton_http::handlers::GetWalletInformationHandler::HandleRequestTonlibThrow(
    schemas::v2::WalletInformationRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
      &core::TonlibWorker::getAddressInformation,
      request.address.GetUnderlying(),
      request.seqno,
      session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert<schemas::v2::WalletInformation>(result_ok);
}
