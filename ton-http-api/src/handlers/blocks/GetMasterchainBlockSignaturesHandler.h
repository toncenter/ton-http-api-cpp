#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetMasterchainBlockSignaturesHandler : public TonlibRequestHandler<schemas::v2::MasterchainBlockSignaturesRequest, schemas::v2::MasterchainBlockSignatures> {
public:
  static constexpr std::string_view kName = "handler-GetMasterchainBlockSignatures";

  GetMasterchainBlockSignaturesHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::MasterchainBlockSignaturesRequest& request) const override;
  schemas::v2::MasterchainBlockSignaturesRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::MasterchainBlockSignatures> HandleRequestTonlibThrow(
      schemas::v2::MasterchainBlockSignaturesRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
