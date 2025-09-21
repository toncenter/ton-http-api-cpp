#include "userver/components/minimal_server_component_list.hpp"
#include "userver/server/handlers/server_monitor.hpp"
#include "userver/server/handlers/ping.hpp"
#include "userver/utils/daemon_run.hpp"
#include "userver/clients/http/component.hpp"
#include "userver/clients/dns/component.hpp"
#include "userver/components/fs_cache.hpp"
#include "userver/server/handlers/http_handler_static.hpp"

#include "td/utils/port/signals.h"
#include "tonlib/Logging.h"

#include "components/tonlib_component.h"
#include "handlers/HandlerDetectAddress.h"
#include "handlers/HandlerGetMasterchainInfo.h"


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
  // api handlers
  component_list.Append<ton_http::handlers::HandlerGetMasterchainInfo>();
  component_list.Append<ton_http::handlers::HandlerDetectAddress>();

  return userver::utils::DaemonMain(argc, argv, component_list);
}
