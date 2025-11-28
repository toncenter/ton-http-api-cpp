cmake_minimum_required(VERSION 3.16)
project(ton-http-api-cpp CXX)

userver_setup_environment()

# userver custom types
set(USERVER_TYPES_SOURCE
        src/userver/chaotic/io/ton_http/types/ton_hash_hex.cpp
        src/userver/chaotic/io/ton_http/types/ton_hash.cpp
        src/userver/chaotic/io/ton_http/types/ton_addr.cpp
        src/userver/chaotic/io/ton_http/types/ton_addr_without_workchain.cpp
        src/userver/chaotic/io/ton_http/types/int256.cpp
        src/userver/chaotic/io/ton_http/types/bytes.cpp
        src/userver/chaotic/io/std/int64_t.cpp
        src/userver/chaotic/io/std/uint64_t.cpp
        src/userver/chaotic/io/std/int32_t.cpp
        src/userver/chaotic/io/std/uint32_t.cpp
        src/userver/chaotic/io/bool.cpp)
add_library(${PROJECT_NAME}-userver-types STATIC ${USERVER_TYPES_SOURCE})
target_link_libraries(${PROJECT_NAME}-userver-types
        tdutils ton_crypto ton_block userver::core userver::chaotic)
target_include_directories(${PROJECT_NAME}-userver-types PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
        ${CMAKE_CURRENT_SOURCE_DIR}/../external/userver)

# tokens tlb schemas
set(TLB_TOKENS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/tlb/tokens-tlb.cpp
)
add_custom_command(
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/core/tlb/
        COMMAND tlbc -o tokens-tlb -n tokens::gen -z ${CMAKE_CURRENT_SOURCE_DIR}/tlb/tokens.tlb
        COMMENT "Generate tokes tlb source files"
        OUTPUT ${TLB_TOKENS}
        DEPENDS tlbc ${CMAKE_CURRENT_SOURCE_DIR}/tlb/tokens.tlb
)
add_custom_target(${PROJECT_NAME}-tlbgen DEPENDS ${TLB_TOKENS})

# openapi schemas
set(OPENAPI_YAML
        ${CMAKE_CURRENT_SOURCE_DIR}/schemas/v2.yaml
)
set(OPENAPI_JSON
        ${CMAKE_CURRENT_SOURCE_DIR}/static/openapi.json
)
add_custom_command(
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND yq -Poj ${OPENAPI_YAML} > ${OPENAPI_JSON}
        COMMENT "Generate OpenAPI json file"
        OUTPUT ${OPENAPI_JSON}
        DEPENDS ${OPENAPI_YAML}
)
add_custom_target(${PROJECT_NAME}-openapi-gen DEPENDS ${OPENAPI_JSON})

# chaotic codegen
file(GLOB_RECURSE
        API_SCHEMAS
        ${CMAKE_CURRENT_SOURCE_DIR}/schemas/v2.yaml
)
userver_target_generate_chaotic(
        ${PROJECT_NAME}-chgen
        GENERATE_SERIALIZERS
        LAYOUT "/components/schemas/([^/]*)/=ton_http::schemas::v2::{0}"
        OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/
        SCHEMAS ${API_SCHEMAS}
        LINK_TARGETS ${PROJECT_NAME}-userver-types
        INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
        RELATIVE_TO ${CMAKE_CURRENT_SOURCE_DIR}/
)


# ton-http-api
set(TON_HTTP_API_CPP_SOURCE
        src/main.cpp
        src/components/TonlibComponent.cpp
        src/schemas/v2.cpp
        src/utils/common.cpp
        src/handlers/JsonRpcHandler.cpp
        src/handlers/blocks/GetMasterchainInfoHandler.cpp
        src/handlers/utils/DetectAddressHandler.cpp
        src/handlers/utils/DetectHashHandler.cpp
        src/handlers/utils/PackAddressHandler.cpp
        src/handlers/utils/UnpackAddressHandler.cpp
        src/handlers/accounts/GetAddressInformationHandler.cpp
        src/handlers/accounts/GetExtendedAddressInformationHandler.cpp
        src/handlers/accounts/GetWalletInformationHandler.cpp
        src/handlers/accounts/GetAddressBalanceHandler.cpp
        src/handlers/accounts/GetAddressStateHandler.cpp
        src/handlers/blocks/GetMasterchainBlockSignaturesHandler.cpp
        src/handlers/accounts/GetTokenDataHandler.cpp
        src/core/tonlib_worker.cpp
        src/core/tlb/tokens-tlb.cpp
        src/core/tonlib_worker_utils.cpp
        src/core/tonlib_worker_accounts.cpp
        src/core/tonlib_worker_blocks.cpp
        src/core/tonlib_worker_config.cpp
        src/core/tonlib_worker_transactions.cpp
        src/core/tonlib_worker_send.cpp
        src/core/tonlib_worker_tokens.cpp
        src/handlers/blocks/GetShardBlockProofHandler.cpp
        src/handlers/blocks/GetConsensusBlockHandler.cpp
        src/handlers/blocks/LookupBlockHandler.cpp
        src/handlers/blocks/GetShardsHandler.cpp
        src/handlers/blocks/GetBlockHeaderHandler.cpp
        src/handlers/blocks/GetOutMsgQueueSizeHandler.cpp
        src/handlers/transactions/GetBlockTransactionsHandler.cpp
        src/handlers/transactions/GetBlockTransactionsExtHandler.cpp
        src/handlers/transactions/GetTransactionsStdHandler.cpp
        src/handlers/transactions/GetTransactionsHandler.cpp
        src/handlers/transactions/TryLocateResultTxHandler.cpp
        src/handlers/transactions/TryLocateSourceTxHandler.cpp
        src/handlers/config/GetConfigParamHandler.cpp
        src/handlers/config/GetConfigAllHandler.cpp
        src/handlers/config/GetLibrariesHandler.cpp
        src/handlers/send/SendBocHandler.cpp
        src/handlers/runmethod/RunGetMethodStdHandler.cpp
        src/handlers/send/EstimateFeeHandler.cpp
        src/handlers/runmethod/RunGetMethodHandler.cpp
)
add_executable(${PROJECT_NAME} ${TON_HTTP_API_CPP_SOURCE})
target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/userver
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
)

add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-tlbgen ${PROJECT_NAME}-chgen ${PROJECT_NAME}-openapi-gen)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} userver::core userver::chaotic tonlib::multiclient-static ${PROJECT_NAME}-userver-types)
target_link_options(${PROJECT_NAME} PUBLIC -rdynamic)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
