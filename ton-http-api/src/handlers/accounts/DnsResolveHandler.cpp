#include "DnsResolveHandler.h"
#include <boost/lexical_cast.hpp>
#include "converters/accounts.hpp"
#include "core/dns.h"

namespace {
ton_http::schemas::v2::DnsResolveRequest NormalizeRequest(ton_http::schemas::v2::DnsResolveRequest req) {
  auto prepared = ton_http::core::dns::prepare_domain(req.domain, req.resolver_address.has_value());
  if (prepared.is_error()) {
    throw ton_http::utils::TonlibException(prepared.error().message().str(), 422);
  }
  req.domain = prepared.move_as_ok().domain;
  return req;
}
}  // namespace

ton_http::handlers::DnsResolveHandler::DnsResolveHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::DnsResolveRequest ton_http::handlers::DnsResolveHandler::ParseTonlibGetRequest(
  const HttpRequest& request, RequestContext& context
) const {
  schemas::v2::DnsResolveRequest req;

  for (const auto* removed : {"address", "name", "category", "ttl"}) {
    if (request.HasArg(removed)) {
      throw utils::TonlibException(std::string("unsupported parameter: ") + removed, 422);
    }
  }
  req.domain = request.GetArg("domain");
  if (request.HasArg("resolver_address")) {
    req.resolver_address = userver::chaotic::convert::Convert(
      request.GetArg("resolver_address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
    );
  }
  if (request.HasArg("seqno")) {
    try {
      req.seqno = boost::lexical_cast<std::int32_t>(request.GetArg("seqno"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse seqno", 422);
    }
  }
  return NormalizeRequest(std::move(req));
}
ton_http::schemas::v2::DnsResolveRequest ton_http::handlers::DnsResolveHandler::ParseTonlibPostRequest(
  const HttpRequest& request, RequestContext& context
) const {
  return NormalizeRequest(TonlibRequestHandler::ParseTonlibPostRequest(request, context));
}
td::Status ton_http::handlers::DnsResolveHandler::ValidateRequest(const schemas::v2::DnsResolveRequest& request) const {
  if (request.seqno.has_value() && request.seqno.value() <= 0) {
    return td::Status::Error(422, "seqno should be positive");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::DnsResolved> ton_http::handlers::DnsResolveHandler::HandleRequestTonlibThrow(
  schemas::v2::DnsResolveRequest& request, multiclient::SessionPtr& session
) const {
  auto result = tonlib_component_.DoRequest(
    &core::TonlibWorker::dnsResolve,
    request.domain,
    request.resolver_address ? std::make_optional(request.resolver_address->GetUnderlying()) : std::nullopt,
    request.seqno,
    session
  );
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto result_ok = result.move_as_ok();
  return converters::Convert(result_ok);
}
