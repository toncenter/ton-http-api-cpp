#include "GetShardAccountCellHandler.h"

#include <boost/lexical_cast.hpp>
#include "converters/convert.hpp"
#include "utils/wallets.hpp"

ton_http::handlers::GetShardAccountCellHandler::GetShardAccountCellHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::AddressInformationRequest ton_http::handlers::GetShardAccountCellHandler::
  ParseTonlibGetRequest(const HttpRequest& request, RequestContext&) const {
  schemas::v2::AddressInformationRequest req;

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
td::Status ton_http::handlers::GetShardAccountCellHandler::ValidateRequest(
  const schemas::v2::ShardAccountCellRequest& request
) const {
  if (request.address.empty()) {
    return td::Status::Error(422, "empty address");
  }
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::TvmCell>
ton_http::handlers::GetShardAccountCellHandler::HandleRequestTonlibThrow(
  schemas::v2::ShardAccountCellRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
    &core::TonlibWorker::getShardAccountCell, request.address.GetUnderlying(), request.seqno, session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();

  // prepare response
  auto response = converters::Convert(result_ok);
  return response;
}
