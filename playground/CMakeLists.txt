cmake_minimum_required(VERSION 3.16)
project(ton-playground CXX)

set(PLAYGROUND_SOURCE
        playground.cpp
)
add_executable(ton-playground ${PLAYGROUND_SOURCE})
target_include_directories(ton-playground
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../external/ton
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_compile_features(ton-playground PRIVATE cxx_std_20)
add_dependencies(ton-playground tl_generate_common)
target_link_libraries(ton-playground tonlib tdutils ton_crypto)
target_link_options(ton-playground PUBLIC -rdynamic)
