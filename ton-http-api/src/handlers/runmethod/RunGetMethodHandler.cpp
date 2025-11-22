#include "RunGetMethodHandler.h"

#include <boost/lexical_cast.hpp>

#include "converters/convert.hpp"

ton_http::handlers::RunGetMethodHandler::RunGetMethodHandler(
  const userver::components::ComponentConfig& config, const userver::components::ComponentContext& context
) :
    TonlibRequestHandler(config, context),
    max_stack_entry_depth_(config["max_stack_entry_depth"].As<std::int32_t>(100)) {
}

ton_http::schemas::v2::RunGetMethodRequest
ton_http::handlers::RunGetMethodHandler::ParseTonlibGetRequest(const HttpRequest&, RequestContext&) const {
  throw std::logic_error("unreachable");
}
td::Status ton_http::handlers::RunGetMethodHandler::ValidateRequest(const schemas::v2::RunGetMethodRequest&) const {
  return td::Status::OK();
}
td::Result<ton_http::schemas::v2::RunGetMethodResult> ton_http::handlers::RunGetMethodHandler::HandleRequestTonlibThrow(
  schemas::v2::RunGetMethodRequest& request, multiclient::SessionPtr& session
) const {
  auto method = std::holds_alternative<std::string>(request.method) ?
    std::get<std::string>(request.method) :
    std::to_string(std::get<std::int32_t>(request.method));

  try {
    converters::LegacyTvmStackParse(request.stack);
  } catch (const utils::TonlibException& e) {
    return td::Status::Error(e.code(), e.message());
  } catch (const std::exception& e) {
    return td::Status::Error(400, std::string{e.what()});
  }
  core::TonlibWorker::StackBuilder stack_builder = [&] {
    return converters::LegacyTvmStackParse(request.stack);
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
  auto result_object = converters::Convert(result);
  if (!checkStackDepth(result_object.stack)) {
    return td::Status::Error(533, "Result stack depth >= " + std::to_string(max_stack_entry_depth_));
  }
  return result_object;
}

userver::yaml_config::Schema ton_http::handlers::RunGetMethodHandler::GetStaticConfigSchema() {
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

bool ton_http::handlers::RunGetMethodHandler::checkStackDepth(
  const std::vector<schemas::v2::LegacyStackEntry>& stack
) const {
  std::queue<std::pair<std::int32_t, const schemas::v2::RunGetMethodStdResult::StackA&>> queue;
  for (auto& entry : stack) {
    if (auto entry_type = std::get<std::string>(entry[0]); entry_type == "tuple") {
      for (auto& tuple = std::get<userver::utils::Box<schemas::v2::TvmTuple>>(entry[1]);
           auto& item : tuple->elements) {
        queue.push({1, item});
      }
    } else if (entry_type == "list") {
      for (auto& list = std::get<userver::utils::Box<schemas::v2::TvmList>>(entry[1]);
           auto& item : list->elements) {
        queue.push({1, item});
      }
    }
  }

  while (!queue.empty()) {
    auto [depth, entry] = queue.front();
    queue.pop();
    if (depth >= max_stack_entry_depth_) {
      return false;
    }
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmStackEntryTuple>>(entry)) {
      for (auto& tuple = std::get<userver::utils::Box<schemas::v2::TvmStackEntryTuple>>(entry);
           auto& item : tuple->tuple.elements) {
        queue.push({depth + 1, item});
      }
    }
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmStackEntryList>>(entry)) {
      for (auto& list = std::get<userver::utils::Box<schemas::v2::TvmStackEntryList>>(entry);
           auto& item : list->list.elements) {
        queue.push({depth + 1, item});
      }
    }
  }
  return true;
}
