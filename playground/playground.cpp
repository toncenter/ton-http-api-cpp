#include "smc-envelope/SmartContractCode.h"
#include "td/utils/base64.h"

#include <variant>
#include <type_traits>


template<class> struct is_variant : std::false_type {};
template<class... Ts> struct is_variant<std::variant<Ts...>> : std::true_type {};
template<class T>
inline constexpr bool is_variant_v = is_variant<std::remove_cvref_t<T>>::value;

template<class T>
concept VariantLike = is_variant_v<T>;

template <typename Response>
class Base {
public:
  virtual ~Base() = default;
  virtual Response func2() = 0;

  void test() {
    auto resp = func2();
    if constexpr(VariantLike<Response>) {
      std::visit([](auto&& val) { std::cout << "std::variant " << val << '\n'; }, resp);
    } else {
      std::cout << "plain " << resp << '\n';
    }
  }
};

class A : public Base<int> {
  int func2() override { return 2; }
};

class B : public Base<std::variant<int, std::string>> {
  std::variant<int, std::string> func2() override {
    return "123";
  }
};


int main() {
  A a;
  a.test();

  B b;
  b.test();


  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::RestrictedWallet, 1);
    LOG(INFO) << "rwallet: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::ManualDns, -1);
    LOG(INFO) << "manual dns: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::ManualDns, 1);
    LOG(INFO) << "manual dns rev 1: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::PaymentChannel, -1);
    LOG(INFO) << "payment channel: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV1, -1);
    LOG(INFO) << "highload v1 rev -1: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV1, 1);
    LOG(INFO) << "highload v1 rev 1: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV1, 2);
    LOG(INFO) << "highload v1 rev 2: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV2, -1);
    LOG(INFO) << "highload v2 rev -1: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV2, 1);
    LOG(INFO) << "highload v2 rev 1: " << td::base64_encode(code->get_hash().as_slice());
  }
  {
    auto code = ton::SmartContractCode::get_code(ton::SmartContractCode::HighloadWalletV2, 2);
    LOG(INFO) << "highload v2 rev 2: " << td::base64_encode(code->get_hash().as_slice());
  }
  return 0;
}
