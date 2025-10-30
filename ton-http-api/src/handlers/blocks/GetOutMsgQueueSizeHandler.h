#pragma once
#include "handlers/TonlibRequestHandler.h"
#include "schemas/v2.hpp"


namespace ton_http::handlers {

class GetOutMsgQueueSizeHandler : public TonlibRequestHandler<schemas::v2::OutMsgQueueSizeRequest, schemas::v2::OutMsgQueueSizes> {
public:
  static constexpr std::string_view kName = "handler-GetOutMsgQueueSize";

  GetOutMsgQueueSizeHandler(const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context);

  td::Status ValidateRequest(const schemas::v2::OutMsgQueueSizeRequest& request) const override;
  schemas::v2::OutMsgQueueSizeRequest ParseTonlibGetRequest(const HttpRequest& request, const Value& request_json, RequestContext& context) const override;

  td::Result<schemas::v2::OutMsgQueueSizes> HandleRequestTonlibThrow(
      schemas::v2::OutMsgQueueSizeRequest& request, multiclient::SessionPtr& session
  ) const override;
};

} // namespace ton_http::handlers
