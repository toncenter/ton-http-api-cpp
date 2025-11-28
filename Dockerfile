FROM ubuntu:24.04 AS builder
RUN DEBIAN_FRONTEND=noninteractive apt update -y \
    && apt install -y wget curl build-essential cmake clang openssl  \
    libssl-dev zlib1g-dev gperf wget git ninja-build libsodium-dev libmicrohttpd-dev liblz4-dev  \
    pkg-config autoconf automake libtool libjemalloc-dev lsb-release software-properties-common gnupg \
    libabsl-dev libbenchmark-dev libboost-context1.83-dev libboost-coroutine1.83-dev libboost-filesystem1.83-dev  \
    libboost-iostreams1.83-dev libboost-locale1.83-dev libboost-program-options1.83-dev libboost-regex1.83-dev  \
    libboost-stacktrace1.83-dev libboost1.83-dev libbson-dev libbz2-dev libc-ares-dev libcctz-dev libcrypto++-dev  \
    libcurl4-openssl-dev libdouble-conversion-dev libev-dev libfmt-dev libgflags-dev libgmock-dev libgtest-dev \
    libhiredis-dev libidn11-dev libjemalloc2 libjemalloc-dev libkrb5-dev libldap2-dev liblz4-dev \
     libnghttp2-dev libpugixml-dev libsnappy-dev libsasl2-dev libssl-dev libxxhash-dev libyaml-cpp0.8  libyaml-cpp-dev \
    libzstd-dev libssh2-1-dev netbase python3-dev python3-jinja2 python3-venv python3-yaml \
    ragel yasm zlib1g-dev liblzma-dev libre2-dev clang-format gcc g++ yq gdb \
    && rm -rf /var/lib/apt/lists/*

ENV CC=/usr/bin/clang
ENV CXX=/usr/bin/clang++
ENV CCACHE_DISABLE=1
ENV BUILD_TON_PLAYGROUND=1
ENV USERVER_FEATURE_STACK_USAGE_MONITOR=1

COPY examples/ /app/examples/
COPY py/ /app/py/
COPY tonlib-multiclient/ /app/tonlib-multiclient/
COPY ton-http-api/ /app/ton-http-api/
COPY playground/ /app/playground/
COPY CMakeLists.txt /app/CMakeLists.txt
COPY external/ /app/external/

ARG BUILD_WITH_TON_REPO
ARG BUILD_WITH_TON_REPO
RUN if [ -n "${BUILD_WITH_TON_REPO}" ]; then \
        echo "Using ton from ${BUILD_WITH_TON_REPO}:${BUILD_WITH_TON_REPO:-master}"; \
        rm -rf /app/external/ton/ && \
        git clone --recursive --branch ${BUILD_WITH_TON_REPO:-master} ${BUILD_WITH_TON_REPO} /app/external/ton; \
    else \
        echo "Using ton submodule"; \
    fi

WORKDIR /app/build
RUN cmake -DCMAKE_BUILD_TYPE=Release -DPORTABLE=1 .. && make -j$(nproc) && make install
RUN mkdir -p /root/.config/gdb && echo "set auto-load safe-path /" > /root/.config/gdb/gdbinit
COPY ton-http-api/static/ /static/
COPY config/static_config.yaml /app/static_config.yaml
ENTRYPOINT [ "ton-http-api-cpp" ]
# end builder


FROM ubuntu:24.04 AS http-api-cpp
RUN DEBIAN_FRONTEND=noninteractive apt update -y \
    && apt install -y curl dnsutils libcurl4 libfmt9 libsodium23 libcctz2 libatomic1 libicu74 \
    && rm -rf /var/lib/apt/lists/*
COPY --from=builder /app/build/ton-http-api/ton-http-api-cpp /usr/bin/
COPY ton-http-api/static/ /static/
COPY config/static_config.yaml /app/static_config.yaml
COPY scripts/entrypoint.sh /app/entrypoint.sh
ENTRYPOINT [ "/app/entrypoint.sh" ]
