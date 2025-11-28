#!/bin/bash
set -e

# config path
THACPP_STATIC_CONFIG_PATH=${THACPP_STATIC_CONFIG_PATH:-/app/static_config.yaml}
if [[ ! -f "$THACPP_STATIC_CONFIG_PATH" ]]; then
  echo "Static config file '$THACPP_STATIC_CONFIG_PATH' not found}"
  exit 1
fi
PARAMS="--config $THACPP_STATIC_CONFIG_PATH"

# config vars
USE_ENV_VARS=${USE_ENV_VARS:-0}
THACPP_CONFIG_VARS=${THACPP_CONFIG_VARS:-/app/config_vars.yaml}
if [[ ! -f "$THACPP_CONFIG_VARS" ]]; then
  echo "Config vars file path not found. Config will be rendered from env vars"
  USE_ENV_VARS=1
fi
PARAMS="$PARAMS --config_vars $THACPP_CONFIG_VARS"

if [[ "$USE_ENV_VARS" -eq 1 ]]; then
  echo "Rendering config from env vars"
  if [[ "$THACPP_TONLIB_CONFIG_PATH" == "http://"* || "$THACPP_TONLIB_CONFIG_PATH" == "https://"* ]]; then
    echo "Downloading TON network config from $THACPP_TONLIB_CONFIG_PATH"
    curl -L --fail -o "/app/ton-config" "$THACPP_TONLIB_CONFIG_PATH"
    THACPP_TONLIB_CONFIG_PATH=/app/ton-config
  fi
  cat <<EOF > /app/config_vars.yaml
tonlib_config_path: ${THACPP_TONLIB_CONFIG_PATH:-/run/secrets/ton-global-config}
tonlib_keystore_path: ${THACPP_TONLIB_KEYSTORE_PATH:-/tmp/keystore/}
tonlib_boc_endpoints: ${THACPP_TONLIB_BOC_ENDPOINTS:-[]}
tonlib_threads: ${THACPP_TONLIB_THREADS:-4}

server_port: 8081
monitor_port: 8082

main_worker_threads: ${THACPP_MAIN_WORKER_THREADS:-4}
fs_worker_threads: ${THACPP_FS_WORKER_THREADS:-1}
http_worker_threads: ${THACPP_HTTP_WORKER_THREADS:-2}

log_level: ${THACPP_LOG_LEVEL:-warning}
log_path: "${THACPP_LOG_PATH:-@stdout}"

system_log_level: ${THACPP_SYSTEM_LOG_LEVEL:-warning}
system_log_path: "${THACPP_SYSTEM_LOG_PATH:-@stdout}"

jsonrpc_log_level: ${THACPP_JSONRPC_LOG_LEVEL:-warning}
jsonrpc_log_path: "${THACPP_JSONRPC_LOG_PATH:-@stdout}"

log_format: ${THACPP_LOG_FORMAT:-json}

http_worker_user_agent: ${THACPP_HTTP_WORKER_USER_AGENT:-empty}

static_content_dir: ${THACPP_STATIC_CONTENT_DIR:-/static/}

max_stack_entry_depth: ${THACPP_MAX_STACK_ENTRY_DEPTH:-256}
EOF
  echo "Config:"
  cat "$THACPP_CONFIG_VARS"
fi

# params ready
echo "params: $PARAMS"

# check global config
TONLIB_CONFIG_PATH=$(grep '^tonlib_config_path:' "$THACPP_CONFIG_VARS" | awk '{print $2}')

if [[ ! -f "$TONLIB_CONFIG_PATH" ]]; then
  echo "TON global config '$TONLIB_CONFIG_PATH' not found"
  exit 1
fi

# create keystore path
TONLIB_KEYSTORE_PATH=$(grep '^tonlib_keystore_path:' "$THACPP_CONFIG_VARS" | awk '{print $2}')
mkdir -p "$TONLIB_KEYSTORE_PATH"

# check static file dir exists
STATIC_FILES_PATH=$(grep '^static_content_dir:' "$THACPP_CONFIG_VARS" | awk '{print $2}')
if [[ ! -d "$STATIC_FILES_PATH" ]]; then
  echo "Config with WWW content not found: '$STATIC_FILES_PATH'"
  exit 1
fi

exec ton-http-api-cpp $PARAMS "$@"
