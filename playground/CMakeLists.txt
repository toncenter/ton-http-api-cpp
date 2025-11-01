cmake_minimum_required(VERSION 3.16)
project(ton-playground CXX)

userver_setup_environment()
set(PLAYGROUND_SOURCE
        playground.cpp
        templates_1.cpp
        wallets_1.cpp
        schemas_1.cpp
        schemas/test_schemas_1.cpp
)
add_executable(ton-playground ${PLAYGROUND_SOURCE})
target_include_directories(ton-playground
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
)

userver_target_generate_chaotic(
        ton-playground-schema
        GENERATE_SERIALIZERS
        LAYOUT "/([^/]*)/=schema::{0}"
        OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/schemas/
        SCHEMAS ${CMAKE_CURRENT_SOURCE_DIR}/test_schemas_1.yaml
        RELATIVE_TO ${CMAKE_CURRENT_SOURCE_DIR}/
)

target_compile_features(ton-playground PRIVATE cxx_std_20)
add_dependencies(ton-playground tl_generate_common ton-playground-schema)
target_link_libraries(ton-playground tonlib tdutils ton_crypto userver::chaotic userver::core)
target_link_options(ton-playground PUBLIC -rdynamic)
