#include "tonlib_worker.h"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<tonlib_api::raw_sendMessage::ReturnType> TonlibWorker::raw_sendMessage(
  const std::string& boc, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::raw_sendMessage>{
    .parameters = {.mode = multiclient::RequestMode::Multiple, .clients_number = 5},
    .request_creator = [boc]() { return tonlib_api::make_object<tonlib_api::raw_sendMessage>(boc); },
    .session = session
  };
  return send_request_function(std::move(request), false);
}

td::Result<tonlib_api::raw_sendMessageReturnHash::ReturnType> TonlibWorker::raw_sendMessageReturnHash(
  const std::string& boc, multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::raw_sendMessageReturnHash>{
    .parameters = {.mode = multiclient::RequestMode::Multiple, .clients_number = 5},
    .request_creator =
      [boc]() { return tonlib_api::make_object<tonlib_api::raw_sendMessageReturnHash>(boc); },
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
  if (session == nullptr) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, nullptr), "failed to get session: ");
  } else if (!session->is_valid()) {
    auto options = multiclient::RequestParameters{.mode = multiclient::RequestMode::Single, .archival = std::nullopt};
    TRY_RESULT_PREFIX_ASSIGN(session, tonlib_.get_session(options, std::move(session)), "failed to get session: ");
  }


  auto request = multiclient::RequestFunction<tonlib_api::raw_createQuery>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = std::nullopt},
    .request_creator =
      [addr_ = account_address, init_code_ = init_code, init_data_ = init_data, body_ = body] {
        return tonlib_api::make_object<tonlib_api::raw_createQuery>(
          tonlib_api::make_object<tonlib_api::accountAddress>(addr_), init_code_, init_data_, body_
        );
      },
    .session = session
  };
  TRY_RESULT(query_info, send_request_function(std::move(request), false));

  auto request_2 = multiclient::RequestFunction<tonlib_api::query_estimateFees>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = std::nullopt},
    .request_creator =
      [id = query_info->id_, ignore_chksig_ = ignore_chksig] {
        return tonlib_api::make_object<tonlib_api::query_estimateFees>(id, ignore_chksig_);
      },
    .session = session
  };

  TRY_RESULT(result, send_request_function(std::move(request_2), false))
  return result;
}
}  // namespace ton_http::core
