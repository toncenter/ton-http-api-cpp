#pragma once

#include <utility>

#include "auto/tl/tonlib_api.h"
#include "block.h"

namespace ton_http {
namespace core {
using namespace ton;

struct DetectAddressResult {
  block::StdAddress address;
  std::string given_type;
  [[nodiscard]] std::string to_raw_form(const bool lower=false) const {
    td::StringBuilder sb;
    sb << address.workchain << ":" << address.addr.to_hex();
    auto raw_form = sb.as_cslice().str();
    if (lower) {
      std::ranges::transform(raw_form, raw_form.begin(), ::tolower);
    }
    return raw_form;
  }
};

struct DetectHashResult {
  std::string hash;
};

struct ConsensusBlockResult {
  std::int32_t seqno;
  std::time_t timestamp;
};

struct RunGetMethodResult {
  tonlib_api::smc_runGetMethod::ReturnType result;
  tonlib_api::smc_getRawFullAccountState::ReturnType state;
};

struct TokenDataResult {
  explicit TokenDataResult(std::string  address) : address_(std::move(address)) {}
  virtual ~TokenDataResult() = default;
  std::string address_;
};
using TokenDataResultPtr = std::unique_ptr<TokenDataResult>;

struct JettonMasterDataResult final : public TokenDataResult {
  std::string total_supply_;
  bool mintable_{false};
  std::string admin_address_;
  bool jetton_content_onchain_{false};
  std::map<std::string, std::string> jetton_content_;
  std::string jetton_wallet_code_;
  explicit JettonMasterDataResult(const std::string& address) : TokenDataResult(address) {}
};

struct JettonWalletDataResult final : public TokenDataResult {
  std::string balance_;
  std::string owner_address_;
  std::string jetton_master_address_;
  std::optional<bool> mintless_is_claimed_;
  std::string jetton_wallet_code_;
  bool is_validated_{false};

  explicit JettonWalletDataResult(const std::string& address) : TokenDataResult(address) {}
};

struct NFTCollectionDataResult final : public TokenDataResult {
  std::string next_item_index_;
  std::string owner_address_;
  bool collection_content_onchain_{false};
  std::map<std::string, std::string> collection_content_;

  explicit NFTCollectionDataResult(const std::string& address) : TokenDataResult(address) {}
};


const std::map<std::string, std::string> TonDnsRoots {
      {"EQC3dNlesgVD8YbAazcauIrXBPfiVhMMr5YYk2in0Mtsz0Bz", ".ton"}
};;

struct DnsRecordStorageAddress {
  constexpr static std::string_view kType = "dns_storage_address";
  std::string bag_id;
};

struct DnsRecordSmcAddress {
  constexpr static std::string_view kType = "dns_smc_address";
  block::StdAddress smc_addr;
};

struct DnsRecordAdnlAddress {
  constexpr static std::string_view kType = "dns_adnl_address";
  std::string adnl_addr;
};

struct DnsRecordNextResolver {
  constexpr static std::string_view kType = "dns_next_resolver";
  block::StdAddress resolver;
};

using DnsRecord = std::variant<DnsRecordStorageAddress, DnsRecordSmcAddress, DnsRecordAdnlAddress, DnsRecordNextResolver>;


struct NFTItemDataResult final : public TokenDataResult {
  bool init_{false};
  std::string index_;
  std::string collection_address_;
  std::string owner_address_;
  bool content_onchain_{false};
  std::map<std::string, std::string> content_;
  bool is_validated_{false};

  std::map<std::string, DnsRecord> dns_content_;
  std::string domain_;
  bool is_dns_{false};
  // TODO: implement dns entry parsing
  explicit NFTItemDataResult(const std::string& address) : TokenDataResult(address) {}
};
}
}
