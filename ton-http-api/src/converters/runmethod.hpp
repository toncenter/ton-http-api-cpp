#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"
#include "userver/utils/box.hpp"
#include <string>
#include <queue>

namespace ton_http::converters {

using namespace ton;

template <typename To>
To Convert(const tonlib_api::object_ptr<tonlib_api::smc_runResult>&) {
  throw std::logic_error("Not implemented");
}

template <typename To>
To Convert(const tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>&) {
  throw std::logic_error("Not implemented");
}

template <>
inline schemas::v2::RunGetMethodStdResult::StackA Convert<schemas::v2::RunGetMethodStdResult::StackA>(
  const tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>& value
) {
  schemas::v2::RunGetMethodStdResult::StackA result;
  ton::tonlib_api::downcast_call(
    *value.get(),
    td::overloaded(
      [&](const tonlib_api::tvm_stackEntryNumber& val) {
        schemas::v2::TvmStackEntryNumber res;
        res.number.number = types::int256{val.number_->number_};
        result = res;
      },
      [&](const tonlib_api::tvm_stackEntrySlice& val) {
        schemas::v2::TvmStackEntrySlice res;
        res.slice.bytes = types::bytes{val.slice_->bytes_};
        result = res;
      },
      [&](const tonlib_api::tvm_stackEntryCell& val) {
        schemas::v2::TvmStackEntryCell res;
        res.cell.bytes = types::bytes{val.cell_->bytes_};
        result = res;
      },
      [&](const tonlib_api::tvm_stackEntryTuple& val) {
        schemas::v2::TvmStackEntryTuple res;
        res.tuple.elements.reserve(val.tuple_->elements_.size());
        for (const auto& entry : val.tuple_->elements_) {
          auto entry_res = Convert<schemas::v2::RunGetMethodStdResult::StackA>(entry);
          std::visit([&](const auto& v) { res.tuple.elements.emplace_back(std::move(v)); }, entry_res);
        }
        result = res;
      },
      [&](const tonlib_api::tvm_stackEntryList& val) {
        schemas::v2::TvmStackEntryList res;
        res.list.elements.reserve(val.list_->elements_.size());
        for (const auto& entry : val.list_->elements_) {
          auto entry_res = Convert<schemas::v2::RunGetMethodStdResult::StackA>(entry);
          std::visit([&](const auto& v) { res.list.elements.emplace_back(std::move(v)); }, entry_res);
        }
        result = res;
      },
      [&](const auto&) {
        LOG_ERROR() << "Unsupported stack entry type: " << value->get_id();
        result = schemas::v2::TvmStackEntryUnsupported{};
      }
    )
  );
  return result;
}

template <>
inline schemas::v2::RunGetMethodStdResult Convert<schemas::v2::RunGetMethodStdResult>(
  const tonlib_api::object_ptr<tonlib_api::smc_runResult>& value
) {
  schemas::v2::RunGetMethodStdResult result;
  result.gas_used = value->gas_used_;
  for (const auto& entry : value->stack_) {
    auto entry_res = Convert<schemas::v2::RunGetMethodStdResult::StackA>(entry);
    std::visit([&](const auto& v) { result.stack.push_back(v); }, entry_res);
  }
  result.exit_code = value->exit_code_;
  return result;
}


template <class... Ts>
struct overloads : Ts... {
  using Ts::operator()...;
};

inline tonlib_api::object_ptr<tonlib_api::tvm_StackEntry> TvmStackEntryParse(
  const schemas::v2::RunGetMethodStdRequest::StackA& value
) {
  tonlib_api::object_ptr<tonlib_api::tvm_StackEntry> result;
  std::visit(
    overloads{
      [&](const userver::utils::Box<schemas::v2::TvmStackEntrySlice>& entry) {
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(
          tonlib_api::make_object<tonlib_api::tvm_slice>(entry->slice.bytes.GetUnderlying())

        );
      },
      [&](const userver::utils::Box<schemas::v2::TvmStackEntryCell>& entry) {
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntryCell>(
          tonlib_api::make_object<tonlib_api::tvm_cell>(entry->cell.bytes.GetUnderlying())

        );
      },
      [&](const userver::utils::Box<schemas::v2::TvmStackEntryNumber>& entry) {
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(
          tonlib_api::make_object<tonlib_api::tvm_numberDecimal>(entry->number.number.GetUnderlying())

        );
      },
      [&](const userver::utils::Box<schemas::v2::TvmStackEntryTuple>& entry) {
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
        stack.reserve(entry->tuple.elements.size());
        for (const auto& item : entry->tuple.elements) {
          stack.emplace_back(TvmStackEntryParse(item));
        }
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntryTuple>(
          tonlib_api::make_object<tonlib_api::tvm_tuple>(std::move(stack))
        );
      },
      [&](const userver::utils::Box<schemas::v2::TvmStackEntryList>& entry) {
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
        stack.reserve(entry->list.elements.size());
        for (const auto& it : entry->list.elements) {
          stack.emplace_back(TvmStackEntryParse(it));
        }
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntryList>(
          tonlib_api::make_object<tonlib_api::tvm_list>(std::move(stack))
        );
      },
      [&](const auto&) {
        result = tonlib_api::make_object<tonlib_api::tvm_stackEntryUnsupported>();
      }
    },
    value
  );
  return result;
}

inline std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> TvmStackParse(
  const std::vector<schemas::v2::RunGetMethodStdRequest::StackA>& value
) {
  std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> result;
  result.reserve(value.size());
  for (const auto& item : value) {
    result.emplace_back(TvmStackEntryParse(item));
  }
  return result;
}

inline tonlib_api::object_ptr<tonlib_api::tvm_StackEntry> LegacyTvmStackEntryParse(
  const schemas::v2::LegacyStackEntry& value
) {
  tonlib_api::object_ptr<tonlib_api::tvm_StackEntry> result;
  if (value.size() != 2) {
      throw utils::TonlibException{std::string{"Expected 2 elements in stack entry, got: "} + std::to_string(value.size()), 422};
  }
  if (!std::holds_alternative<std::string>(value[0])) {
    throw utils::TonlibException{"Expected string as first element in stack entry", 422};
  }
  const auto& type = std::get<std::string>(value[0]);
  const auto& entry_variant = value[1];
  if (type == "num" || type == "int" || type == "number" || type == "integer") {
    if (std::holds_alternative<std::int32_t>(entry_variant)) {
      auto entry = std::get<std::int32_t>(entry_variant);
      return tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(
        tonlib_api::make_object<tonlib_api::tvm_numberDecimal>(std::to_string(entry))
      );
    }
    if (std::holds_alternative<std::string>(entry_variant)) {
      auto r_number = td::string_to_int256(std::get<std::string>(entry_variant));
      if (r_number.is_null()) {
        throw utils::TonlibException{"Invalid number: " + std::get<std::string>(entry_variant), 422};
      }
      return tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(
        tonlib_api::make_object<tonlib_api::tvm_numberDecimal>(r_number->to_dec_string())
      );
    }
    throw utils::TonlibException{"Wrong type of number in stack entry", 422};
  }
  if (type == "tvm.Cell") {
    if (std::holds_alternative<std::string>(entry_variant)) {
      auto entry = std::get<std::string>(entry_variant);
      if (entry.empty()) {
        throw utils::TonlibException{"Empty tvm.Cell", 422};
      }
      auto r_cell = td::base64_decode(entry);
      if (r_cell.is_error()) {
        throw utils::TonlibException{r_cell.move_as_error().message().str(), 422};
      }
      return tonlib_api::make_object<tonlib_api::tvm_stackEntryCell>(
        tonlib_api::make_object<tonlib_api::tvm_cell>(r_cell.move_as_ok())
      );
    }
    throw utils::TonlibException{"Invalid tvm.Cell, base64 string expected", 422};
  }
  if (type == "cell") {
    if (std::holds_alternative<schemas::v2::LegacyStackEntryCell>(entry_variant)) {
      auto entry = std::get<schemas::v2::LegacyStackEntryCell>(entry_variant);
      if (entry.bytes.empty()) {
        throw utils::TonlibException{"Empty cell", 422};
      }
      return tonlib_api::make_object<tonlib_api::tvm_stackEntryCell>(
        tonlib_api::make_object<tonlib_api::tvm_cell>(entry.bytes.GetUnderlying())
      );
    }
    throw utils::TonlibException{"Invalid cell, object with field bytes expected", 422};
  }
  if (type == "tvm.Slice") {
    if (std::holds_alternative<std::string>(entry_variant)) {
      auto entry = std::get<std::string>(entry_variant);
      if (entry.empty()) {
        throw utils::TonlibException{"Empty tvm.Slice", 422};
      }

      auto r_cell = td::base64_decode(entry);
      if (r_cell.is_error()) {
        throw utils::TonlibException{r_cell.move_as_error().message().str(), 422};
      }
      return tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(
        tonlib_api::make_object<tonlib_api::tvm_slice>(r_cell.move_as_ok())
      );
    }
    throw utils::TonlibException{"Invalid tvm.Slice, base64 string expected", 422};
  }
  if (type == "slice") {
    if (std::holds_alternative<schemas::v2::LegacyStackEntryCell>(entry_variant)) {
      auto entry = std::get<schemas::v2::LegacyStackEntryCell>(entry_variant);
      if (entry.bytes.empty()) {
        throw utils::TonlibException{"Empty slice", 422};
      }
      return tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(
        tonlib_api::make_object<tonlib_api::tvm_slice>(entry.bytes.GetUnderlying())
      );
    }
    throw utils::TonlibException{"Invalid slice, object with field bytes expected", 422};
  }
  if (type == "tuple" || type == "tvm.Tuple") {
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmTuple>>(entry_variant)) {
      userver::utils::Box<schemas::v2::TvmStackEntryTuple> entry_tuple;
      entry_tuple->tuple = *std::get<userver::utils::Box<schemas::v2::TvmTuple>>(entry_variant);
      return TvmStackEntryParse(entry_tuple);
    }
    throw utils::TonlibException{"Invalid tvm.Tuple, valid tvm_stackEntryTuple expected", 422};
  }
  if (type == "list" || type == "tvm.List") {
    if (std::holds_alternative<userver::utils::Box<schemas::v2::TvmList>>(entry_variant)) {
      userver::utils::Box<schemas::v2::TvmStackEntryList> entry_list;
      entry_list->list = *std::get<userver::utils::Box<schemas::v2::TvmList>>(entry_variant);
      return TvmStackEntryParse(entry_list);
    }
    throw utils::TonlibException{"Invalid tvm.List, valid tvm_stackEntryList expected", 422};
  }

  throw utils::TonlibException{"Unsupported stack entry type: " + type, 542};
}

inline std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> LegacyTvmStackParse(
  const std::vector<schemas::v2::LegacyStackEntry>& value
) {
  std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> result;
  result.reserve(value.size());
  for (const auto& item : value) {
    result.emplace_back(LegacyTvmStackEntryParse(item));
  }
  return result;
}

inline schemas::v2::LegacyTvmCell SerializeCell(td::Ref<vm::Cell> cell) {
  schemas::v2::LegacyTvmCell result;
  bool is_special = false;
  auto cs = vm::load_cell_slice_special(cell, is_special);
  auto r_ls = cell->load_cell();
  if (r_ls.is_error()) {
    throw utils::TonlibException{r_ls.move_as_error().message().str(), 500};
  }
  auto ls = r_ls.move_as_ok();
  auto size = (ls.data_cell->get_bits() + 7) / 8;
  std::string cell_data;
  cell_data.resize(size);
  std::memcpy(cell_data.data(), ls.data_cell->get_data(), size);

  result.data.b64 = types::bytes{cell_data};
  result.data.len = ls.data_cell->get_bits();
  result.special = ls.data_cell->is_special();
  while (cs.have_refs(1)) {
    cs.advance(1);
    if (auto child_ref = cs.fetch_ref(); child_ref.not_null()) {
      result.refs.emplace_back(SerializeCell(child_ref));
    }
  }
  return result;
}

template<>
inline schemas::v2::LegacyStackEntry Convert<schemas::v2::LegacyStackEntry>(const tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>& value) {
  schemas::v2::LegacyStackEntry result;
  ton::tonlib_api::downcast_call(
    *value.get(),
    td::overloaded(
      [&](const tonlib_api::tvm_stackEntryNumber& val) {
        result.push_back("num");
        auto number = td::string_to_int256(val.number_->number_)->to_hex_string();
        if (number[0] == '-') {
          number = "-0x" + number.substr(1, number.size() - 1);
        } else {
          number = "0x" + number;
        }
        result.push_back(number);
      },
      [&](const tonlib_api::tvm_stackEntrySlice& val) {
        schemas::v2::LegacyStackEntryCell res;
        res.bytes = types::bytes{val.slice_->bytes_};
        auto r_cell = vm::std_boc_deserialize(val.slice_->bytes_);
        if (r_cell.is_error()) {
          throw utils::TonlibException{r_cell.move_as_error().message().str(), 500};
        }
        res.object = SerializeCell(r_cell.move_as_ok());
        result.push_back("cell");
        result.push_back(res);
      },
      [&](const tonlib_api::tvm_stackEntryCell& val) {
        schemas::v2::LegacyStackEntryCell res;
        res.bytes = types::bytes{val.cell_->bytes_};
        auto r_cell = vm::std_boc_deserialize(val.cell_->bytes_);
        if (r_cell.is_error()) {
          throw utils::TonlibException{r_cell.move_as_error().message().str(), 500};
        }
        res.object = SerializeCell(r_cell.move_as_ok());
        result.push_back("cell");
        result.push_back(res);
      },
      [&](const tonlib_api::tvm_stackEntryTuple& val) {
        schemas::v2::TvmStackEntryTuple res;
        res.tuple.elements.reserve(val.tuple_->elements_.size());
        for (const auto& entry : val.tuple_->elements_) {
          auto entry_res = Convert<schemas::v2::RunGetMethodStdResult::StackA>(entry);
          std::visit([&](const auto& v) { res.tuple.elements.emplace_back(std::move(v)); }, entry_res);
        }
        result.push_back("tuple");
        result.push_back(res.tuple);
      },
      [&](const tonlib_api::tvm_stackEntryList& val) {
        schemas::v2::TvmStackEntryList res;
        res.list.elements.reserve(val.list_->elements_.size());
        for (const auto& entry : val.list_->elements_) {
          auto entry_res = Convert<schemas::v2::RunGetMethodStdResult::StackA>(entry);
          std::visit([&](const auto& v) { res.list.elements.emplace_back(std::move(v)); }, entry_res);
        }
        result.push_back("list");
        result.push_back(res.list);
      },
      [&](const auto&) {
        LOG_ERROR() << "Unsupported stack entry type: " << value->get_id();
        result.push_back("unsupported");
        result.push_back("");
      }
    )
  );
  return result;
}

inline schemas::v2::RunGetMethodResult Convert(
  const core::RunGetMethodResult& value
) {
  schemas::v2::RunGetMethodResult result;
  result.gas_used = value.result->gas_used_;
  for (const auto& entry : value.result->stack_) {
    result.stack.emplace_back(Convert<schemas::v2::LegacyStackEntry>(entry));
  }
  result.exit_code = value.result->exit_code_;
  result.block_id = Convert(value.state->block_id_);
  result.last_transaction_id = Convert(value.state->last_transaction_id_);
  return result;
}
}  // namespace ton_http::converters
