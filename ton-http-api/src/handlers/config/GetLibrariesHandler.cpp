#include "GetLibrariesHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::GetLibrariesHandler::GetLibrariesHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context) {
}

ton_http::schemas::v2::LibrariesRequest ton_http::handlers::GetLibrariesHandler::
  ParseTonlibGetRequest(const HttpRequest& request, RequestContext&) const {
  schemas::v2::LibrariesRequest req;
  if (request.HasArg("libraries")) {
    try {
      if (auto libraries = request.GetArgVector("libraries"); !libraries.empty()) {
        std::vector<types::ton_hash> libs;
        for (const auto& lib : libraries) {
          libs.emplace_back(
            userver::chaotic::convert::Convert(lib, userver::chaotic::convert::To<ton_http::types::ton_hash>{})
          );
        }
        req.libraries = std::move(libs);
      }
    } catch (std::exception& exc) {
      throw utils::TonlibException("failed to parse libraries", 422);
    }
  }

  return req;
}
td::Status ton_http::handlers::GetLibrariesHandler::ValidateRequest(const schemas::v2::LibrariesRequest&) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::LibraryResult> ton_http::handlers::GetLibrariesHandler::HandleRequestTonlibThrow(
  schemas::v2::LibrariesRequest& request, multiclient::SessionPtr& session
) const {
  std::vector<std::string> libraries;
  if (request.libraries.has_value()) {
    for (const auto& lib : request.libraries.value()) {
      libraries.emplace_back(lib.GetUnderlying());
    }
  }
  TRY_RESULT(result, tonlib_component_.DoRequest(&core::TonlibWorker::getLibraries, libraries, session));
  return converters::Convert(result);
}
