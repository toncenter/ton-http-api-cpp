#include "GetTransactionsHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"
#include "utils/common.hpp"

ton_http::handlers::GetTransactionsHandler::GetTransactionsHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::TransactionsRequest ton_http::handlers::GetTransactionsHandler::
  ParseTonlibGetRequest(const HttpRequest& request, RequestContext&) const {
  schemas::v2::TransactionsRequest req;
  try {
    req.address = userver::chaotic::convert::Convert(
      request.GetArg("address"), userver::chaotic::convert::To<ton_http::types::ton_addr>{}
    );
  } catch (std::exception& exc) {
    throw utils::TonlibException("failed to parse address", 422);
  }
  if (request.HasArg("lt")) {
    try {
      req.lt = boost::lexical_cast<std::int64_t>(request.GetArg("lt"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse lt", 422);
    }
  }
  if (request.HasArg("hash")) {
    try {
      req.hash = userver::chaotic::convert::Convert(
        request.GetArg("hash"), userver::chaotic::convert::To<ton_http::types::ton_hash>{}
      );
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse hash", 422);
    }
  }
  if (request.HasArg("to_lt")) {
    try {
      req.to_lt = boost::lexical_cast<std::int64_t>(request.GetArg("to_lt"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse to_lt", 422);
    }
  }

  if (request.HasArg("limit")) {
    try {
      req.limit = boost::lexical_cast<std::int32_t>(request.GetArg("limit"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse limit", 422);
    }
  }
  if (request.HasArg("archival")) {
    try {
      req.archival = utils::stringToBool(request.GetArg("archival"));
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse archival", 422);
    }
  }
  return req;
}
td::Status ton_http::handlers::GetTransactionsHandler::ValidateRequest(
  const schemas::v2::TransactionsRequest& request
) const {
  if (request.limit <= 0) {
    return td::Status::Error(422, "limit should be positive");
  }
  if (request.limit > 100) {
    return td::Status::Error(422, "limit should be less or equal 100");
  }
  bool has_lt = false;
  if (request.lt) {
    has_lt = true;
    if (*request.lt <= 0) {
      return td::Status::Error(422, "lt should be positive");
    }
  }
  bool has_hash = false;
  if (request.hash.has_value() && !request.hash.value().empty()) {
    has_hash = true;
  }
  if (has_hash != has_lt) {
    return td::Status::Error(422, "lt and hash should be used together");
  }
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::Transactions>
ton_http::handlers::GetTransactionsHandler::HandleRequestTonlibThrow(
  schemas::v2::TransactionsRequest& request, multiclient::SessionPtr& session
) const {
  auto hash = request.hash.has_value() ? request.hash.value().GetUnderlying() : "";
  auto to_lt = request.to_lt.has_value() ? request.to_lt.value() : 0;
  constexpr size_t CHUNK_SIZE = 10;
  constexpr bool TRY_DECODE_MESSAGES = true;
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::getTransactions,
      request.address.GetUnderlying(),
      request.lt,
      hash,
      to_lt,
      request.limit,
      CHUNK_SIZE,
      TRY_DECODE_MESSAGES,
      request.archival,
      session
    )
  );
  return converters::Convert<schemas::v2::Transactions>(result);
}
