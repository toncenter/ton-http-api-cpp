#include "tonlib_worker.h"
#include "userver/formats/json.hpp"
#include "utils/common.hpp"


namespace ton_http::core {
td::Result<TokenDataResultPtr> TonlibWorker::getTokenData(
    const std::string& address,
    bool skip_verification,
    std::optional<std::uint32_t> seqno,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  TRY_RESULT(smc_info, loadContract(address, seqno, archival, session));
  auto r_jetton_master = checkJettonMaster(smc_info->id_, address, skip_verification, seqno, archival, session);
  auto r_jetton_wallet = checkJettonWallet(smc_info->id_, address, skip_verification, seqno, archival, session);
  auto r_nft_collection = checkNFTCollection(smc_info->id_, address, skip_verification, seqno, archival, session);
  auto r_nft_item = checkNFTItem(smc_info->id_, address, skip_verification, seqno, archival, session);
  TRY_STATUS(forgetContract(smc_info->id_, archival, session));

  if (r_jetton_master.is_ok()) {
    if (auto data = r_jetton_master.move_as_ok()) {
      return std::move(data);
    }
  } else {
    LOG(DEBUG) << "Jetton master: " << r_jetton_master.move_as_error();
  }
  if (r_jetton_wallet.is_ok()) {
    if (auto data = r_jetton_wallet.move_as_ok()) {
      return std::move(data);
    }
  } else {
    LOG(DEBUG) << "Jetton wallet: " << r_jetton_wallet.move_as_error();
  }

  if (r_nft_collection.is_ok()) {
    if (auto data = r_nft_collection.move_as_ok()) {
      return std::move(data);
    }
  } else {
    LOG(DEBUG) << "NFT collection: " << r_nft_collection.move_as_error();
  }

  if (r_nft_item.is_ok()) {
    if (auto data = r_nft_item.move_as_ok()) {
      return std::move(data);
    }
  } else {
    LOG(DEBUG) << "NFT item: " << r_nft_item.move_as_error();
  }

  return td::Status::Error(409, PSLICE() << "Smart contract " << address << " is not Jetton or NFT");
}

td::Result<std::unique_ptr<TokenDataResult>> TonlibWorker::checkJettonMaster(
    std::int64_t smc_id,
    const std::string& address,
    bool,
    std::optional<std::uint32_t>,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] {
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_jetton_data"),
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>{});
    },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), false));
  if (result->exit_code_ != 0) {
    return td::Status::Error(500, "Exit code " + std::to_string(result->exit_code_) + " != 0");
  }
  if (result->stack_.size() < 5) {
    return td::Status::Error(500, "Stack size " + std::to_string(result->stack_.size()) + " < 5");
  }
  auto data = std::make_unique<JettonMasterDataResult>(address);

  // data
  TRY_RESULT_ASSIGN(data->total_supply_, utils::number_from_tvm_stack_entry(result->stack_[0]));
  TRY_RESULT(mintable, utils::number_from_tvm_stack_entry(result->stack_[1]));
  data->mintable_ = std::stoi(mintable);
  TRY_RESULT_ASSIGN(data->admin_address_, utils::address_from_tvm_stack_entry(result->stack_[2]));

  // jetton_content_
  if (result->stack_[3]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 3 position");
  }
  TRY_RESULT(jetton_content_cell,
    vm::std_boc_deserialize(static_cast<tonlib_api::tvm_stackEntryCell&>(*result->stack_[3]).cell_->bytes_,
      true, true)
  );
  TRY_RESULT_PREFIX(jetton_content,
    utils::parse_token_data(std::move(jetton_content_cell)),
    "Failed to parse jetton content from the cell: ");
  data->jetton_content_onchain_ = std::get<0>(jetton_content);
  data->jetton_content_ = std::move(std::get<1>(jetton_content));

  // jetton_wallet_code_
  if (result->stack_[4]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 3 position");
  }
  data->jetton_wallet_code_ = static_cast<const tonlib_api::tvm_stackEntryCell&>(*result->stack_[4]).cell_->bytes_;
  return std::move(data);
}
td::Result<std::unique_ptr<TokenDataResult>> TonlibWorker::checkJettonWallet(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification,
    std::optional<std::uint32_t> seqno,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] {
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_wallet_data"),
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>{});
    },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), false));
  if (result->exit_code_ != 0) {
    return td::Status::Error(500, "Exit code " + std::to_string(result->exit_code_) + " != 0");
  }
  if (result->stack_.size() < 4) {
    return td::Status::Error(500, "Stack size " + std::to_string(result->stack_.size()) + " < 4");
  }
  auto data = std::make_unique<JettonWalletDataResult>(address);

  // data
  TRY_RESULT_ASSIGN(data->balance_, utils::number_from_tvm_stack_entry(result->stack_[0]));
  TRY_RESULT_ASSIGN(data->owner_address_, utils::address_from_tvm_stack_entry(result->stack_[1]));
  TRY_RESULT_ASSIGN(data->jetton_master_address_, utils::address_from_tvm_stack_entry(result->stack_[2]));

  // jetton_wallet_code_
  if (result->stack_[3]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 3 position");
  }
  data->jetton_wallet_code_ = static_cast<const tonlib_api::tvm_stackEntryCell&>(*result->stack_[3]).cell_->bytes_;

  if (skip_verification) {
    return std::move(data);
  }

  // verification
  TRY_RESULT(parent_smc_info, loadContract(data->jetton_master_address_, seqno, archival, session));

  // construct owner_address cell
  TRY_RESULT(owner_address_std, block::StdAddress::parse(data->owner_address_));

  vm::CellBuilder anycast_cb;
  anycast_cb.store_bool_bool(false);
  auto anycast_cell = anycast_cb.finalize();
  td::Ref<vm::CellSlice> anycast_cs = vm::load_cell_slice_ref(anycast_cell);

  vm::CellBuilder cb;
  block::gen::t_MsgAddressInt.pack_addr_std(cb, anycast_cs, owner_address_std.workchain, owner_address_std.addr);
  TRY_RESULT(owner_address_cell, vm::std_boc_serialize(cb.finalize()));

  // call get_wallet_address on master
  auto request_2 = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode=multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = parent_smc_info->id_, owner_address_cell_ = owner_address_cell.as_slice().str()] {
      std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
      auto tonlib_slice = tonlib_api::make_object<tonlib_api::tvm_slice>(owner_address_cell_);
      stack.emplace_back(tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(std::move(tonlib_slice)));
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
        id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_wallet_address"),
        std::move(stack));
    },
    .session = session
  };
  TRY_RESULT(result_2, send_request_function(std::move(request_2)));
  if (result_2->exit_code_ != 0) {
    LOG(ERROR) << "Exit code " << result_2->exit_code_ << " != 0";
    return td::Status::Error(409, "Verification exit code " + std::to_string(result_2->exit_code_) + " != 0");
  }
  TRY_RESULT(wallet_address_from_master, utils::address_from_tvm_stack_entry(result_2->stack_[0]));

  // check addresses
  TRY_RESULT(address_std, block::StdAddress::parse(address));
  TRY_RESULT(address_from_master_std, block::StdAddress::parse(wallet_address_from_master));

  LOG(DEBUG) << "address: " << address_std << " expected: " << address_from_master_std;
  if (address_from_master_std != address_std) {
    return td::Status::Error(409, "Verification on master failed");
  }
  data->is_validated_ = true;

  TRY_STATUS(forgetContract(parent_smc_info->id_, archival, session));
  return std::move(data);
}
td::Result<std::unique_ptr<TokenDataResult>> TonlibWorker::checkNFTCollection(
    std::int64_t smc_id,
    const std::string& address,
    bool,
    std::optional<std::uint32_t>,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] {
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_collection_data"),
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>{});
    },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), false));
  if (result->exit_code_ != 0) {
    return td::Status::Error(500, "Exit code " + std::to_string(result->exit_code_) + " != 0");
  }
  if (result->stack_.size() < 3) {
    return td::Status::Error(500, "Stack size " + std::to_string(result->stack_.size()) + " < 3");
  }
  auto data = std::make_unique<NFTCollectionDataResult>(address);

  // total_supply_
  if (result->stack_[0]->get_id() != tonlib_api::tvm_stackEntryNumber::ID) {
    return td::Status::Error(500, "stackEntryNumber expected at 0 position");
  }
  TRY_RESULT_ASSIGN(data->next_item_index_, utils::number_from_tvm_stack_entry(result->stack_[0]));

  // collection_content_
  if (result->stack_[1]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 1 position");
  }
  TRY_RESULT(collection_content_cell,
    vm::std_boc_deserialize(static_cast<tonlib_api::tvm_stackEntryCell&>(*result->stack_[1]).cell_->bytes_,
      true, true));
  TRY_RESULT_PREFIX(collection_content,
    utils::parse_token_data(std::move(collection_content_cell)),
    "Failed to parse jetton content from the cell: ");

  data->collection_content_onchain_ = std::get<0>(collection_content);
  data->collection_content_ = std::move(std::get<1>(collection_content));

  // owner_address_
  TRY_RESULT_ASSIGN(data->owner_address_, utils::address_from_tvm_stack_entry(result->stack_[2]));
  return std::move(data);
}
td::Result<std::unique_ptr<TokenDataResult>> TonlibWorker::checkNFTItem(
    std::int64_t smc_id,
    const std::string& address,
    bool skip_verification,
    std::optional<std::uint32_t> seqno,
    std::optional<bool> archival,
    multiclient::SessionPtr session
) const {
  auto request = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode = multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] {
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_nft_data"),
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>>{});
    },
    .session = session
  };
  TRY_RESULT(result, send_request_function(std::move(request), false));
  if (result->exit_code_ != 0) {
    return td::Status::Error(500, "Exit code " + std::to_string(result->exit_code_) + " != 0");
  }
  if (result->stack_.size() < 5) {
    return td::Status::Error(500, "Stack size " + std::to_string(result->stack_.size()) + " < 5");
  }
  auto data = std::make_unique<NFTItemDataResult>(address);

  // data
  TRY_RESULT(init, utils::number_from_tvm_stack_entry(result->stack_[0]));
  data->init_ = std::stoi(init);
  TRY_RESULT_ASSIGN(data->index_, utils::number_from_tvm_stack_entry(result->stack_[1]));
  TRY_RESULT_ASSIGN(data->collection_address_, utils::address_from_tvm_stack_entry(result->stack_[2]));
  TRY_RESULT_ASSIGN(data->owner_address_, utils::address_from_tvm_stack_entry(result->stack_[3]));

  // content_
  if (result->stack_[4]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 4 position");
  }
  auto ind_content_cell_data = static_cast<tonlib_api::tvm_stackEntryCell&>(*result->stack_[4]).cell_->bytes_;

  if (data->collection_address_.empty()) {
    TRY_RESULT(content_cell, vm::std_boc_deserialize(ind_content_cell_data, true, true));
    TRY_RESULT_PREFIX(content, utils::parse_token_data(std::move(content_cell)),
      "Failed to parse jetton content from the cell: ");
    data->content_onchain_ = std::get<0>(content);
    data->content_ = std::move(std::get<1>(content));
  }

  if (skip_verification) {
    return std::move(data);
  }

  // verification
  if (data->collection_address_.empty()) {
    data->is_validated_ = true;
    return std::move(data);
  }
  TRY_RESULT(parent_smc_info, loadContract(data->collection_address_, seqno, archival, session));

  // verify with master
  auto request_2 = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode=multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = parent_smc_info->id_, index_ = data->index_] {
      std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
      auto tonlib_slice = tonlib_api::make_object<tonlib_api::tvm_numberDecimal>(index_);
      auto entry = tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(std::move(tonlib_slice));
      stack.push_back(std::move(entry));
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
        id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_nft_address_by_index"),
        std::move(stack));
    },
    .session = session
  };
  TRY_RESULT(result_2, send_request_function(std::move(request_2)));
  if (result_2->exit_code_ != 0) {
    return td::Status::Error(409, "Verification exit code " + std::to_string(result_2->exit_code_) + " != 0");
  }
  TRY_RESULT(address_from_collection, utils::address_from_tvm_stack_entry(result_2->stack_[0]));

  // check addresses
  TRY_RESULT(address_std, block::StdAddress::parse(address));
  TRY_RESULT(address_from_collection_std, block::StdAddress::parse(address_from_collection));
  if (address_from_collection_std != address_std) {
    return td::Status::Error(409, "Verification on collection failed");
  }
  data->is_validated_ = true;

  // content_
  auto request_3 = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode=multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = parent_smc_info->id_, index_ = data->index_, ind_content = std::move(ind_content_cell_data)] {
      std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
      auto tonlib_slice = tonlib_api::make_object<tonlib_api::tvm_numberDecimal>(index_);
      auto entry = tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(std::move(tonlib_slice));
      stack.push_back(std::move(entry));

      auto tonlib_slice_2 = tonlib_api::make_object<tonlib_api::tvm_cell>(std::move(ind_content));
      auto entry_2 = tonlib_api::make_object<tonlib_api::tvm_stackEntryCell>(std::move(tonlib_slice_2));
      stack.push_back(std::move(entry_2));
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
        id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_nft_content"),
        std::move(stack));
    },
    .session = session
  };
  TRY_RESULT(result_3, send_request_function(std::move(request_3)));
  if (result_3->exit_code_ != 0) {
    LOG(DEBUG) << "Exit code " << result_3->exit_code_ << " != 0";
    return td::Status::Error(500, "Exit code " + std::to_string(result_3->exit_code_) + " != 0");
  }
  if (result_3->stack_.size() < 1) {
    return td::Status::Error(500, "Stack size " + std::to_string(result_3->stack_.size()) + " < 1");
  }
  if (result_3->stack_[0]->get_id() != tonlib_api::tvm_stackEntryCell::ID) {
    return td::Status::Error(500, "stackEntryCell expected at 0 position");
  }
  TRY_RESULT(content_cell,
    vm::std_boc_deserialize(static_cast<tonlib_api::tvm_stackEntryCell&>(*(result_3->stack_[0])).cell_->bytes_,
      true, true));
  TRY_RESULT_PREFIX(content, utils::parse_token_data(std::move(content_cell)),
    "Failed to parse nft content from the cell: ");

  data->content_onchain_ = std::get<0>(content);
  data->content_ = std::move(std::get<1>(content));

  // dns resolve
  auto request_dns = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
    .parameters = {.mode=multiclient::RequestMode::Single, .archival = archival},
    .request_creator = [id_ = smc_id] {
      std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
      auto zero_byte_cell = vm::CellBuilder().store_bytes("\0").finalize();
      auto zero_byte_cell_str = vm::std_boc_serialize(zero_byte_cell).move_as_ok();

      auto tonlib_slice = tonlib_api::make_object<tonlib_api::tvm_slice>(zero_byte_cell_str.as_slice().str());
      stack.emplace_back(tonlib_api::make_object<tonlib_api::tvm_stackEntrySlice>(std::move(tonlib_slice)));

      auto tonlib_slice_2 = tonlib_api::make_object<tonlib_api::tvm_numberDecimal>("0");
      stack.push_back(tonlib_api::make_object<tonlib_api::tvm_stackEntryNumber>(std::move(tonlib_slice_2)));
      return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
        id_,
        tonlib_api::make_object<tonlib_api::smc_methodIdName>("dnsresolve"),
        std::move(stack));
    },
    .session = session
  };
  TRY_RESULT(result_dns, send_request_function(std::move(request_dns)));
  if (result_dns->exit_code_ == 0 && result_dns->stack_.size() == 2) {
    auto request_domain = multiclient::RequestFunction<tonlib_api::smc_runGetMethod>{
      .parameters = {.mode=multiclient::RequestMode::Single, .archival = archival},
      .request_creator = [id_ = smc_id] {
        std::vector<tonlib_api::object_ptr<tonlib_api::tvm_StackEntry>> stack;
        return tonlib_api::make_object<tonlib_api::smc_runGetMethod>(
          id_,
          tonlib_api::make_object<tonlib_api::smc_methodIdName>("get_domain"),
          std::move(stack));
      },
      .session = session
    };
    TRY_RESULT(result_domain, send_request_function(std::move(request_domain)));
    if (result_domain->exit_code_ == 0) {
      auto domain_cell_str = static_cast<tonlib_api::tvm_stackEntryCell&>(*result_domain->stack_[0]).cell_->bytes_;
      auto r_domain_cell = vm::std_boc_deserialize(domain_cell_str, true, true);
      if (r_domain_cell.is_ok()) {
        auto domain_cell = r_domain_cell.move_as_ok();
        auto domain_cs = vm::load_cell_slice_ref(domain_cell);
        auto r_domain = td::hex_decode(domain_cs->as_bitslice().to_hex());
        if (r_domain.is_ok()) {
          auto domain = r_domain.move_as_ok();
          data->domain_ = domain;

          std::stringstream ss;
          domain_cs->print_rec(ss, 0);
          LOG(DEBUG) << "domain cs: " << ss.str() << " domain: " << domain;
        }
      } else {
        LOG(DEBUG) << "Failed to parse domain cell: " << r_domain_cell.error();
      }
    } else {
      LOG(DEBUG) << "Failed to get domain with exit_code: " << result_domain->exit_code_;
    }
    LOG(INFO) << "parsing dns content";
    if (result_dns->stack_[1]->get_id() == tonlib_api::tvm_stackEntryCell::ID) {
      auto dns_content_data_str = static_cast<tonlib_api::tvm_stackEntryCell&>(*(result_dns->stack_[1])).cell_->bytes_;
      if (auto r_dns_content_cell = vm::std_boc_deserialize(dns_content_data_str, true, true);
          r_dns_content_cell.is_error()) {
        LOG(ERROR) << r_dns_content_cell.move_as_error_prefix("Failed to unpack dns content cell: ");
      } else {
        auto dns_content_cell = r_dns_content_cell.move_as_ok();
        if (auto r_dns_content = utils::parse_dns_content(std::move(dns_content_cell));
          r_dns_content.is_error()) {
          LOG(ERROR) << r_dns_content.move_as_error_prefix("Failed to parse dns content from the cell: ");
        } else {
          data->dns_content_ = r_dns_content.move_as_ok();
          data->is_dns_ = true;
        }
      }
    }
  }
  TRY_STATUS(forgetContract(parent_smc_info->id_, archival, session));
  return std::move(data);
}
}
