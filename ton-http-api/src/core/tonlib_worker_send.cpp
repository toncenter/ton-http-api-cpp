#include "tonlib_worker.h"
#include "userver/formats/json.hpp"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<tonlib_api::raw_sendMessage::ReturnType> TonlibWorker::raw_sendMessage(
  const std::string& boc,
  multiclient::SessionPtr session
) const {
  auto r_boc = td::base64_decode(boc);
  if (r_boc.is_error()) {
    return r_boc.move_as_error();
  }
  auto boc_bytes = r_boc.move_as_ok();
  auto request = multiclient::RequestFunction<tonlib_api::raw_sendMessage>{
    .parameters = {.mode=multiclient::RequestMode::Multiple, .clients_number = 5},
    .request_creator = [boc_bytes]() {
      return tonlib_api::make_object<tonlib_api::raw_sendMessage>(boc_bytes);
    },
    .session = session
  };
  return send_request_function(std::move(request), false);
}

td::Result<tonlib_api::raw_sendMessageReturnHash::ReturnType> TonlibWorker::raw_sendMessageReturnHash(
    const std::string& boc, multiclient::SessionPtr session
) const {
  auto r_boc = td::base64_decode(boc);
  if (r_boc.is_error()) {
    return r_boc.move_as_error();
  }
  auto boc_bytes = r_boc.move_as_ok();
  auto request = multiclient::RequestFunction<tonlib_api::raw_sendMessageReturnHash>{
    .parameters = {.mode = multiclient::RequestMode::Multiple, .clients_number = 5},
    .request_creator =
        [boc_bytes]() { return tonlib_api::make_object<tonlib_api::raw_sendMessageReturnHash>(boc_bytes); },
    .session = session
};
  return send_request_function(std::move(request), false);
}
td::Result<std::unique_ptr<tonlib_api::query_fees>> TonlibWorker::queryEstimateFees(
    const std::string& account_address,
    const std::string& body,
    const std::string& init_code,
    const std::string& init_data,
    bool ignore_chksig,
    multiclient::SessionPtr session
) const {
  auto r_body = td::base64_decode(body);
  if (r_body.is_error()) {
    return r_body.move_as_error();
  }
  auto body_bin = r_body.move_as_ok();

  auto r_init_code = td::base64_decode(init_code);
  if (init_code.length() > 0 && r_init_code.is_error()) {
    return r_init_code.move_as_error();
  }
  auto init_code_bin = r_init_code.move_as_ok();

  auto r_init_data = td::base64_decode(init_data);
  if (init_data.length() > 0 && r_init_data.is_error()) {
    return r_init_data.move_as_error();
  }
  auto init_data_bin = r_init_data.move_as_ok();

  auto request = multiclient::RequestFunction<tonlib_api::raw_createQuery>{
      .parameters = {.mode = multiclient::RequestMode::Single, .archival = std::nullopt},
      .request_creator =
          [addr_ = account_address, init_code_ = init_code_bin, init_data_ = init_data_bin, body_ = body_bin] {
            return tonlib_api::make_object<tonlib_api::raw_createQuery>(
                tonlib_api::make_object<tonlib_api::accountAddress>(addr_), init_code_, init_data_, body_
            );
          },
      .session = session
  };
  auto result = send_request_function(std::move(request), false);
  if (result.is_error()) {
    return result.move_as_error();
  }
  auto query_info = result.move_as_ok();

  auto request_2 = multiclient::RequestFunction<tonlib_api::query_estimateFees>{
      .parameters = {.mode = multiclient::RequestMode::Single, .archival = std::nullopt},
      .request_creator =
          [id = query_info->id_, ignore_chksig_ = ignore_chksig] {
            return tonlib_api::make_object<tonlib_api::query_estimateFees>(id, ignore_chksig_);
          },
      .session = session
  };
  auto result_2 = send_request_function(std::move(request_2), false);
  if (result_2.is_error()) {
    return result_2.move_as_error();
  }
  return result_2.move_as_ok();
}
}
