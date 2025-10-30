#pragma once
#include <auto/tl/tonlib_api.h>
#include <string>
#include <userver/formats/json.hpp>

#include "block.h"
#include "core/types.hpp"
#include "td/utils/Status.h"
#include "vm/cells/Cell.h"
#include "vm/cells/CellSlice.h"

namespace ton_http::utils {
using namespace ton;

inline std::optional<bool> stringToBool(std::string str) {
  std::cout << "Archival: " << str << std::endl;
  if (str.empty()) {
    return std::nullopt;
  }
  std::ranges::transform(str, str.begin(), ::tolower);
  std::cout << "Archival: " << str << std::endl;
  if (str == "y" || str == "yes" || str == "t" || str == "true" || str == "on" || str == "1") {
    std::cout << "ARCHIVAL" << std::endl;
    return true;
  }
  if (str == "n" || str == "no" || str == "f" || str == "false" || str == "off" || str == "0") {
    std::cout << "NOT ARCHIVAL" << std::endl;
    return false;
  }
  throw std::invalid_argument("failed to parse bool");
}

// run get method tools
td::Result<userver::formats::json::Value> render_tvm_stack(const std::string& stack_str);
td::Result<userver::formats::json::Value> render_tvm_element(
  const std::string& element_type, const userver::formats::json::Value& element
);

userver::formats::json::Value serialize_tvm_stack(
  const std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>& tvm_stack
);
userver::formats::json::Value serialize_tvm_entry(const tonlib_api::tvm_stackEntryCell& entry);
userver::formats::json::Value serialize_tvm_entry(const tonlib_api::tvm_stackEntrySlice& entry);

td::Result<std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>> parse_stack(
  const std::vector<std::string>& stack_vector
);

userver::formats::json::Value serialize_cell(const td::Ref<vm::Cell>& cell);

td::Result<std::string> address_from_cell(const std::string& data);

td::Result<std::string> address_from_tvm_stack_entry(const tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>& entry);
td::Result<std::string> number_from_tvm_stack_entry(const tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>& entry);

// tokens
td::Result<std::string> parse_snake_data(td::Ref<vm::CellSlice> data);
td::Result<std::string> parse_chunks_data(const td::Ref<vm::CellSlice>& data);
td::Result<std::string> parse_content_data(const td::Ref<vm::CellSlice>& cs);
td::Result<std::tuple<bool, std::map<std::string, std::string>>> parse_token_data(td::Ref<vm::Cell> cell);
td::Result<std::map<std::string, core::DnsRecord>> parse_dns_content(td::Ref<vm::Cell> cell);
}  // namespace ton_http::utils
