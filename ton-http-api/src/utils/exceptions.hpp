#pragma once

#include <userver/utils/traceful_exception.hpp>
#include <utility>

#include "userver/formats/json/value.hpp"
#include "userver/formats/json/value_builder.hpp"
#include "userver/server/http/http_status.hpp"

namespace ton_http::utils {
class TonlibException : public userver::utils::TracefulException {
public:
  using TracefulException::TracefulException;

  explicit TonlibException(const std::string& message, std::int32_t code = 500)
    : message_(std::string{message}), code_(code) {}

  [[nodiscard]] const std::string& message() const {
    return message_;
  }
  [[nodiscard]] std::int32_t code() const {
    return code_;
  }
  [[nodiscard]] const char* what() const noexcept override {
    return message_.c_str();
  }
private:
  std::string message_;
  std::int32_t code_;
};
}
