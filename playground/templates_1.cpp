#include "header.h"

#include <type_traits>
#include <variant>
#include <string>
#include "td/utils/logging.h"


template <class>
struct is_variant : std::false_type {};
template <class... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <class T>
inline constexpr bool is_variant_v = is_variant<std::remove_cvref_t<T>>::value;

template <class T>
concept VariantLike = is_variant_v<T>;

template <typename Response>
class Base {
public:
  virtual ~Base() = default;
  virtual Response func2() = 0;

  void test() {
    auto resp = func2();
    if constexpr (VariantLike<Response>) {
      std::visit([](auto&& val) { LOG(INFO) << "std::variant " << val; }, resp);
    } else {
      LOG(INFO) << "plain " << resp;
    }
  }
};

class A : public Base<int> {
  int func2() override {
    return 2;
  }
};

class B : public Base<std::variant<int, std::string>> {
  std::variant<int, std::string> func2() override {
    return "123";
  }
};

void test_templates_1() {
  A a;
  a.test();

  B b;
  b.test();
}
