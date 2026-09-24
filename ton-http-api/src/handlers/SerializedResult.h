#pragma once

#include <memory>
#include <string>
#include <string_view>

#include <userver/formats/json.hpp>
#include <userver/formats/json/string_builder.hpp>
#include <userver/formats/serialize/common_containers.hpp>
#include <userver/formats/serialize/variant.hpp>

namespace ton_http::handlers {

// Only internally serialized JSON can enter the cache; request metadata stays outside it.
class SerializedResult final {
public:
  template <typename Response>
  explicit SerializedResult(const Response& response) :
      json_(ToString(userver::formats::json::ValueBuilder{response}.ExtractValue())) {
  }

  std::string MakeSuccessBody(std::string_view extra) const {
    userver::formats::json::StringBuilder builder;
    {
      const userver::formats::json::StringBuilder::ObjectGuard object{builder};
      builder.Key("ok");
      builder.WriteBool(true);
      builder.Key("result");
      builder.WriteRawString(json_);
      builder.Key("@extra");
      builder.WriteString(extra);
    }
    return builder.GetString();
  }

private:
  std::string json_;
};

using SerializedResultPtr = std::shared_ptr<const SerializedResult>;

}  // namespace ton_http::handlers
