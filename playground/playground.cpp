#include "smc-envelope/SmartContractCode.h"
#include "td/utils/base64.h"


int main() {
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
