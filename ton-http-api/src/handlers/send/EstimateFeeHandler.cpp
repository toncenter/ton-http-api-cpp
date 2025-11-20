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
  auto init_code = request.init_code.has_value() ? request.init_code.value().GetUnderlying() : "";
  auto init_data = request.init_data.has_value() ? request.init_data.value().GetUnderlying() : "";
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::queryEstimateFees,
      request.address.GetUnderlying(),
      request.body.GetUnderlying(),
      init_code,
      init_data,
      request.ignore_chksig,
      session
    )
  );
  return converters::Convert(result);
}
