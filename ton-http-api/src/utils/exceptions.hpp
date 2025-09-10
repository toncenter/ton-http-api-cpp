#pragma once

#include <userver/utils/traceful_exception.hpp>

namespace ton_http::utils {
class ParsingException : public userver::utils::TracefulException {
public:
  using userver::utils::TracefulException::TracefulException;
};
}
