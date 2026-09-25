import pytest
from tests.helpers import error, payload, success


@pytest.mark.validation
@pytest.mark.regression
@pytest.mark.parametrize("body", ["{", "{}", "[]", '{"method":123}', '{"method":null}'])
def test_malformed_rpc_has_client_error_envelope(raw_api_request, body):
    # Match REST validation: malformed client input must not escape as an empty 500.
    error(raw_api_request("POST", "jsonRPC", data=body,
                          headers={"Content-Type": "application/json"}), 422)


@pytest.mark.validation
@pytest.mark.parametrize("method", ["unknownMethod", "../healthcheck", "getMasterchainInfo?x=1"])
def test_unknown_rpc_method(raw_api_request, method):
    error(raw_api_request("POST", "jsonRPC", json={"method": method}), 404)


@pytest.mark.validation
def test_nonempty_positional_params_rejected(raw_api_request):
    error(raw_api_request("POST", "jsonRPC", json={"method": "detectHash", "params": ["0" * 64]}))


@pytest.mark.validation
@pytest.mark.parametrize("params", [None, [], 123])
def test_legacy_non_object_params_become_empty_object(raw_api_request, params):
    # Existing compatibility behavior, not a claim of strict JSON-RPC 2.0 compliance.
    response = raw_api_request("POST", "jsonRPC", json={"method": "detectHash", "params": params})
    error(response)
    assert "hash" in payload(response)["error"].lower()


@pytest.mark.validation
def test_rpc_uses_ton_response_envelope(raw_api_request):
    response = raw_api_request("POST", "jsonRPC", json={"jsonrpc": "2.0", "id": "test-id",
                               "method": "detectHash", "params": {"hash": "0" * 64}})
    success(response)
    body = payload(response)
    assert "@extra" in body
    assert "jsonrpc" not in body and "id" not in body


@pytest.mark.validation
def test_rpc_get_is_disallowed(raw_api_request):
    error(raw_api_request("GET", "jsonRPC"), 405)


@pytest.mark.validation
@pytest.mark.parametrize("method", ["getConfigParam", "dnsResolve", "runGetMethod", "estimateFee"])
def test_malformed_rest_json(raw_api_request, method):
    error(raw_api_request("POST", method, data="{", headers={"Content-Type": "application/json"}))
