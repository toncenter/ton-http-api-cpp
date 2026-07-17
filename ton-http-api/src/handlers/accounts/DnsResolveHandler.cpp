#include "DnsResolveHandler.h"
#include <boost/lexical_cast.hpp>
#include "converters/accounts.hpp"

ton_http::handlers::DnsResolveHandler::DnsResolveHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::DnsResolveRequest ton_http::handlers::DnsResolveHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::DnsResolveRequest req;

  req.address = userver::chaotic::convert::Convert(
    request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
  );
  if (request.HasArg("name")) {
    req.name = request.GetArg("name");
  }
  if (request.HasArg("category")) {
    req.category = request.GetArg("category");
  }
  if (request.HasArg("ttl")) {
    try {
      req.ttl = boost::lexical_cast<std::int32_t>(request.GetArg("ttl"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse ttl", 422);
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
td::Status ton_http::handlers::DnsResolveHandler::ValidateRequest(
  const schemas::v2::DnsResolveRequest& request
) const {
  if (request.address.empty()) {
    return td::Status::Error(422, "empty address");
  }
  if (request.ttl.has_value() && request.ttl.value() < 0) {
    return td::Status::Error(422, "ttl should be non-negative");
  }
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::DnsResolved>
ton_http::handlers::DnsResolveHandler::HandleRequestTonlibThrow(
  schemas::v2::DnsResolveRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
    &core::TonlibWorker::dnsResolve,
    request.address.GetUnderlying(),
    request.name.value_or(""),
    request.category,
    request.ttl,
    request.seqno,
        std::nullopt,
    session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
