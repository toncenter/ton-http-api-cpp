#include "userver/clients/dns/component.hpp"
#include "userver/clients/http/component.hpp"
#include "userver/components/fs_cache.hpp"
#include "userver/components/minimal_server_component_list.hpp"
#include "userver/server/handlers/http_handler_static.hpp"
#include "userver/server/handlers/ping.hpp"
#include "userver/server/handlers/server_monitor.hpp"
#include "userver/utils/daemon_run.hpp"

#include "td/utils/port/signals.h"
#include "tonlib/Logging.h"

#include "components/tonlib_component.h"
#include "handlers/JsonRpcHandler.h"
#include "handlers/accounts/GetAddressBalanceHandler.h"
#include "handlers/accounts/GetAddressInformationHandler.h"
#include "handlers/accounts/GetAddressStateHandler.h"
#include "handlers/accounts/GetExtendedAddressInformationHandler.h"
#include "handlers/accounts/GetTokenDataHandler.h"
#include "handlers/accounts/GetWalletInformationHandler.h"
#include "handlers/blocks/GetBlockHeaderHandler.h"
#include "handlers/blocks/GetConsensusBlockHandler.h"
#include "handlers/blocks/GetMasterchainBlockSignaturesHandler.h"
#include "handlers/blocks/GetMasterchainInfoHandler.h"
#include "handlers/blocks/GetOutMsgQueueSizeHandler.h"
#include "handlers/blocks/GetShardBlockProofHandler.h"
#include "handlers/blocks/GetShardsHandler.h"
#include "handlers/blocks/LookupBlockHandler.h"
#include "handlers/transactions/GetBlockTransactionsExtHandler.h"
#include "handlers/transactions/GetBlockTransactionsHandler.h"
#include "handlers/transactions/GetTransactionsHandler.h"
#include "handlers/transactions/GetTransactionsStdHandler.h"
#include "handlers/utils/DetectAddressHandler.h"
#include "handlers/utils/DetectHashHandler.h"
#include "handlers/utils/PackAddressHandler.h"
#include "handlers/utils/UnpackAddressHandler.h"


int main(int argc, char* argv[]) {
  tonlib::Logging::set_verbosity_level(1);
  td::set_default_failure_signal_handler().ensure();

  auto component_list = userver::components::MinimalServerComponentList();
  // components
  component_list.Append<userver::clients::dns::Component>();
  component_list.Append<userver::components::HttpClient>();
  component_list.Append<userver::components::FsCache>("fs-cache-main");
  component_list.Append<ton_http::core::TonlibComponent>();
  // common handlers
  component_list.Append<userver::server::handlers::ServerMonitor>();
  component_list.Append<userver::server::handlers::Ping>();
  component_list.Append<userver::server::handlers::HttpHandlerStatic>();
  //
  // api handlers
  //
  // utils
  component_list.Append<ton_http::handlers::DetectAddressHandler>();
  component_list.Append<ton_http::handlers::DetectHashHandler>();
  component_list.Append<ton_http::handlers::PackAddressHandler>();
  component_list.Append<ton_http::handlers::UnpackAddressHandler>();

  // accounts
  component_list.Append<ton_http::handlers::GetAddressInformationHandler>();
  component_list.Append<ton_http::handlers::GetExtendedAddressInformationHandler>();
  component_list.Append<ton_http::handlers::GetWalletInformationHandler>();
  component_list.Append<ton_http::handlers::GetAddressBalanceHandler>();
  component_list.Append<ton_http::handlers::GetAddressStateHandler>();
  component_list.Append<ton_http::handlers::GetTokenDataHandler>();

  // blocks
  component_list.Append<ton_http::handlers::GetMasterchainInfoHandler>();
  component_list.Append<ton_http::handlers::GetMasterchainBlockSignaturesHandler>();
  component_list.Append<ton_http::handlers::GetShardBlockProofHandler>();
  component_list.Append<ton_http::handlers::GetConsensusBlockHandler>();
  component_list.Append<ton_http::handlers::LookupBlockHandler>();
  component_list.Append<ton_http::handlers::GetShardsHandler>();
  component_list.Append<ton_http::handlers::GetShardsHandler>("handler-Shards");
  component_list.Append<ton_http::handlers::GetBlockHeaderHandler>();
  component_list.Append<ton_http::handlers::GetOutMsgQueueSizeHandler>();

  // transactions
  component_list.Append<ton_http::handlers::GetBlockTransactionsHandler>();
  component_list.Append<ton_http::handlers::GetBlockTransactionsExtHandler>();
  component_list.Append<ton_http::handlers::GetTransactionsHandler>();
  component_list.Append<ton_http::handlers::GetTransactionsStdHandler>();

  // config

  // run methods

  // send

  // jsonRpc handler
  component_list.Append<ton_http::handlers::JsonRpcHandler>();

  return userver::utils::DaemonMain(argc, argv, component_list);
}
