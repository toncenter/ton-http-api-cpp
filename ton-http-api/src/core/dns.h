#pragma once

#include <functional>
#include <string>

#include "auto/tl/tonlib_api.h"
#include "td/utils/Status.h"

namespace ton_http::core::dns {

struct PreparedDomain {
  std::string domain;
  std::string encoded;
};

// The optional initial zero byte means "self" for an explicitly selected resolver.
td::Result<PreparedDomain> prepare_domain(std::string domain, bool custom_resolver);
td::Result<std::string> root_from_config(const ton::tonlib_api::configInfo& config);

using Query = std::function<td::Result<ton::tonlib_api::smc_runGetMethod::ReturnType>(
  const std::string& resolver, const std::string& encoded_domain
)>;

// Query must execute every step against the same masterchain block.
td::Result<ton::tonlib_api::dns_resolve::ReturnType> resolve(
  const PreparedDomain& domain, std::string resolver, const Query& query
);

}  // namespace ton_http::core::dns
