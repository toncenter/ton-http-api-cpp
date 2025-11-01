#include "RunGetMethodStdHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::RunGetMethodStdHandler::RunGetMethodStdHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context), max_stack_entry_depth_(config["max_stack_entry_depth"].As<std::int32_t>(100)) {
}

ton_http::schemas::v2::RunGetMethodStdRequest ton_http::handlers::RunGetMethodStdHandler::
  ParseTonlibGetRequest(const HttpRequest&, RequestContext&) const {
  throw std::logic_error("unreachable");
}
td::Status
ton_http::handlers::RunGetMethodStdHandler::ValidateRequest(const schemas::v2::RunGetMethodStdRequest&) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::RunGetMethodStdResult>
ton_http::handlers::RunGetMethodStdHandler::HandleRequestTonlibThrow(
  schemas::v2::RunGetMethodStdRequest& request, multiclient::SessionPtr& session
) const {
  auto method = std::holds_alternative<std::string>(request.method) ?
    std::get<std::string>(request.method) :
    std::to_string(std::get<std::int32_t>(request.method));
  core::TonlibWorker::StackBuilder stack_builder = [&] {
    return converters::TvmStackParse(request.stack);
  };
  TRY_RESULT(
    result,
    tonlib_component_.DoRequest(
      &core::TonlibWorker::runGetMethod,
      request.address.GetUnderlying(),
      method,
      stack_builder,
      request.seqno,
      std::nullopt,
      session
    )
  );
  auto result_object = converters::Convert<schemas::v2::RunGetMethodStdResult>(result.result);
  if (!checkStackDepth(result_object.stack)) {
    throw utils::TonlibException{"No no no, mr. Fish! Result stack depth >= " + std::to_string(max_stack_entry_depth_), 533};
  }
  return result_object;
}

userver::yaml_config::Schema ton_http::handlers::RunGetMethodStdHandler::GetStaticConfigSchema() {
  return userver::yaml_config::MergeSchemas<TonlibRequestHandler>(R"(
type: object
description: RunGetMethod config
additionalProperties: false
properties:
  max_stack_entry_depth:
    type: integer
    description: 'Maximal stack entry depth (default: 100)'
)");
}

bool ton_http::handlers::RunGetMethodStdHandler::checkStackDepth(
  const std::vector<schemas::v2::RunGetMethodStdResult::StackA>& stack
) const {
  std::queue<std::pair<std::int32_t, const schemas::v2::RunGetMethodStdResult::StackA&>> queue;
  for (auto& entry : stack) {
    queue.push({1, entry});
  }

  while (!queue.empty()) {
    auto [depth, entry] = queue.front();
    queue.pop();
    if (depth >= max_stack_entry_depth_) {
      return false;
    }
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmStackEntryTuple>>(entry)) {
      auto& tuple = std::get<userver::utils::Box<schemas::v2::TvmStackEntryTuple>>(entry);
      for (auto& item : tuple->tuple.elements) {
        queue.push({depth + 1, item});
      }
    }
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmStackEntryList>>(entry)) {
      auto& list = std::get<userver::utils::Box<schemas::v2::TvmStackEntryList>>(entry);
      for (auto& item : list->list.elements) {
        queue.push({depth + 1, item});
      }
    }
  }
  return true;
}
