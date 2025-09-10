#include "HandlerGetMasterchainInfo.h"
#include "converters/convert.hpp"
#include "userver/chaotic/io/userver/utils/datetime/time_point_tz_fraction.hpp"

ton_http::handlers::HandlerGetMasterchainInfo::HandlerGetMasterchainInfo(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

td::Result<ton_http::schemas::v2::TonObject>
ton_http::handlers::HandlerGetMasterchainInfo::HandleRequestTonlibThrow(
    const HttpRequest& request, const Value& request_json, RequestContext& context, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(&core::TonlibWorker::getMasterchainInfo, session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
