#include "VersionHeaderMiddleware.h"
#include "version.h"

void ton_http::middleware::VersionHeaderMiddleware::HandleRequest(
  userver::server::http::HttpRequest& request, userver::server::request::RequestContext& context
) const {
  Next(request, context);
  request.GetHttpResponse().SetHeader(kApiVersionHeader, std::string{Version});
}