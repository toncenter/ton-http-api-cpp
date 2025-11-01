#include "TryLocateSourceTxHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::TryLocateSourceTxHandler::TryLocateSourceTxHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::TryLocateSourceTxRequest ton_http::handlers::TryLocateSourceTxHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext&
) const {
  schemas::v2::TryLocateSourceTxRequest req;

  req.source = userver::chaotic::convert::Convert(
    request.GetArg("source"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
  );
  req.destination = userver::chaotic::convert::Convert(
    request.GetArg("destination"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
  );
  try {
    req.created_lt = boost::lexical_cast<std::int64_t>(request.GetArg("created_lt"));
  } catch (std::exception&) {
    throw utils::TonlibException("failed to parse created_lt", 422);
  }
  return req;
}
td::Status ton_http::handlers::TryLocateSourceTxHandler::ValidateRequest(
  const schemas::v2::TryLocateSourceTxRequest& request
  ) const {
  if (request.source.empty()) {
    return td::Status::Error(422, "empty source address");
  }
  if (request.destination.empty()) {
    return td::Status::Error(422, "empty destination address");
  }
  if (request.created_lt <= 0) {
    return td::Status::Error(422, "created_lt should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::Transaction> ton_http::handlers::TryLocateSourceTxHandler::HandleRequestTonlibThrow(
  schemas::v2::TryLocateSourceTxRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::tryLocateTransactionByOutgoingMessage,
      request.source.GetUnderlying(),
      request.destination.GetUnderlying(),
      request.created_lt,
      session
    )
  );
  if (result->transactions_.empty()) {
    throw utils::TonlibException("transaction not found", 404);
  }
  return converters::Convert<schemas::v2::Transaction>(result->transactions_.front());
}
