#pragma once
#include "auto/tl/tonlib_api.h"
#include "schemas/v2.hpp"
#include "userver/utils/box.hpp"


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
}  // namespace ton_http::converters
