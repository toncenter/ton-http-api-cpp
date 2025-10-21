#pragma once
#include "../TonlibRequestHandler.h"

namespace ton_http::handlers {

class GetMasterchainInfoHandler
    : public TonlibRequestHandler<schemas::v2::MasterchainInfoRequest, schemas::v2::MasterchainInfo> {
public:
  static constexpr std::string_view kName = "handler-GetMasterchainInfo";

  GetMasterchainInfoHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
  );

  schemas::v2::EmptyRequest ParseTonlibGetRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;
  schemas::v2::EmptyRequest ParseTonlibPostRequest(
    const HttpRequest& request, const Value& request_json, RequestContext& context
  ) const override;

  td::Result<schemas::v2::MasterchainInfo> HandleRequestTonlibThrow(
    schemas::v2::EmptyRequest& request, multiclient::SessionPtr& session
  ) const override;
};

}  // namespace ton_http::handlers
