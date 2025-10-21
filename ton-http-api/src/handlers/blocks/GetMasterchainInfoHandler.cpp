#include "GetMasterchainInfoHandler.h"
#include "converters/blocks.hpp"

ton_http::handlers::GetMasterchainInfoHandler::GetMasterchainInfoHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::MasterchainInfoRequest ton_http::handlers::GetMasterchainInfoHandler::
  ParseTonlibGetRequest(const HttpRequest&, const Value&, RequestContext&) const {
  return schemas::v2::MasterchainInfoRequest{};
}

ton_http::schemas::v2::MasterchainInfoRequest ton_http::handlers::GetMasterchainInfoHandler::
  ParseTonlibPostRequest(const HttpRequest&, const Value&, RequestContext&) const {
  return schemas::v2::MasterchainInfoRequest{};
}

td::Result<ton_http::schemas::v2::MasterchainInfo>
ton_http::handlers::GetMasterchainInfoHandler::HandleRequestTonlibThrow(
  schemas::v2::EmptyRequest&, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(&core::TonlibWorker::getMasterchainInfo, session);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
