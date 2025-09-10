cmake_minimum_required(VERSION 3.16)
project(ton-http-api-cpp CXX)


userver_setup_environment()

set(TON_HTTP_API_CPP_SOURCE
        src/main.cpp
        src/userver/chaotic/io/ton_http/types/ton_hash.cpp
        src/userver/chaotic/io/ton_http/types/shard_id.cpp
        src/handlers/HandlerGetMasterchainInfo.cpp
        src/handlers/TonlibRequestHandler.cpp
        src/components/tonlib_component.cpp
        src/schemas/v2.cpp
        src/converters/convert.hpp
        src/core/types.hpp
        src/core/tonlib_worker.cpp
        src/core/tlb/tokens-tlb.cpp
        src/utils/common.cpp
)
set(TLB_TOKENS
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/tlb/tokens-tlb.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/core/tlb/tokens-tlb.h
)

add_custom_command(
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/core/tlb/
        COMMAND tlbc -o tokens-tlb -n tokens::gen -z ${CMAKE_CURRENT_SOURCE_DIR}/tlb/tokens.tlb
        COMMENT "Generate tokes tlb source files"
        OUTPUT ${TLB_TOKENS}
        DEPENDS tlbc ${CMAKE_CURRENT_SOURCE_DIR}/tlb/tokens.tlb
)
add_custom_target(${PROJECT_NAME}-tlbgen DEPENDS ${TLB_TOKENS})

file(GLOB_RECURSE API_SCHEMAS ${CMAKE_CURRENT_SOURCE_DIR}/schemas/v2.json)
userver_target_generate_chaotic(
        ${PROJECT_NAME}-chgen
        GENERATE_SERIALIZERS
        LAYOUT "/components/schemas/([^/]*)/=ton_http::schemas::{stem}::{0}"
        OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/
        SCHEMAS ${API_SCHEMAS}
        INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src
        RELATIVE_TO ${CMAKE_CURRENT_SOURCE_DIR}/
)

add_executable(${PROJECT_NAME} ${TON_HTTP_API_CPP_SOURCE})
target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/userver
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
)

add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}-tlbgen ${PROJECT_NAME}-chgen)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} userver::core tonlib::multiclient)
target_link_options(${PROJECT_NAME} PUBLIC -rdynamic)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
