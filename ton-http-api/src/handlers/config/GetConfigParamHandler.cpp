#include "GetConfigParamHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetConfigParamHandler::GetConfigParamHandler(
    const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) : TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::ConfigParamRequest ton_http::handlers::GetConfigParamHandler::ParseTonlibGetRequest(
    const HttpRequest& request, RequestContext&
) const {
  schemas::v2::ConfigParamRequest req;
  if (request.HasArg("param")) {
    try {
      req.param = boost::lexical_cast<std::int32_t>(request.GetArg("param"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse param", 422);
    }
  }
  if (request.HasArg("config_id")) { // backward compatibility
    try {
      req.param = boost::lexical_cast<std::int32_t>(request.GetArg("config_id"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse config_id", 422);
    }
  }
  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }

  return req;
}
td::Status ton_http::handlers::GetConfigParamHandler::ValidateRequest(
    const schemas::v2::ConfigParamRequest& request
) const {
  std::int32_t param = -1;
  if (!(request.config_id.has_value() ^ request.param.has_value())) {
    return td::Status::Error(422, "only one of config_id or param should be specified");
  }
  if (request.config_id.has_value()) {
    param = request.config_id.value();
  }
  if (request.param.has_value()) {
    param = request.param.value();
  }
  if (param < 0) {
    return td::Status::Error(422, "param should be non-negative");
  }
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::ConfigInfo> ton_http::handlers::GetConfigParamHandler::HandleRequestTonlibThrow(
    schemas::v2::ConfigParamRequest& request, multiclient::SessionPtr& session
) const {
  auto param = (request.config_id.has_value() ? request.config_id.value() : request.param.has_value() ? request.param.value() : -1);
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::getConfigParam, param, request.seqno, session));
  return converters::Convert(result);
}
