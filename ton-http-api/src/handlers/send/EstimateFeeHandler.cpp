#include "EstimateFeeHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::EstimateFeeHandler::EstimateFeeHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::EstimateFeeRequest
ton_http::handlers::EstimateFeeHandler::ParseTonlibGetRequest(const HttpRequest&, RequestContext&) const {
  throw std::logic_error("unreachable");
}
td::Status ton_http::handlers::EstimateFeeHandler::ValidateRequest(const schemas::v2::EstimateFeeRequest&) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::QueryFees>
ton_http::handlers::EstimateFeeHandler::HandleRequestTonlibThrow(
  schemas::v2::EstimateFeeRequest& request, multiclient::SessionPtr& session
) const {
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::queryEstimateFees,
      request.address.GetUnderlying(),
      request.body.GetUnderlying(),
      request.init_code.GetUnderlying(),
      request.init_data.GetUnderlying(),
      request.ignore_chksig,
      session
    )
  );
  return converters::Convert(result);
}
