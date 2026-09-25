import json
import pytest
import requests
from typing import Optional
from tests.helpers import success


API_CALL_MODES = ["get", "post", "jsonrpc"]

def pytest_addoption(parser):
    parser.addoption("--request-timeout", type=float, default=20,
                     help="HTTP read timeout in seconds; connect timeout is at most 3 seconds")
    parser.addoption("--mc-seqno", type=int, default=None,
                     help="Pin new historical tests to a masterchain block")
    parser.addoption(
        "--endpoint",
        action="store",
        default="http://localhost:8080/api/v2/",
        help="REST API endpoint URL"
    )
    parser.addoption(
        "--apikey",
        action="store",
        default=None,
        help="API key to pass in X-API-Key header"
    )
    parser.addoption(
        "--method",
        action="append",
        choices=API_CALL_MODES + ["all"],
        default=[],
        help="Which API modes to run (may be repeated). Examples: "
             "--method get  |  --method get --method post  |  --method all",
    )


@pytest.fixture(scope='session')
def endpoint(request, record_testsuite_property) -> str:
    base = request.config.getoption("--endpoint").rstrip("/") + "/"
    record_testsuite_property("api_endpoint", base)
    return base


@pytest.fixture(scope='session')
def api_key(request) -> Optional[str]:
    return request.config.getoption("--apikey")

def _selected_modes(config) -> list[str]:
    opts = config.getoption("--method") or []
    return API_CALL_MODES if (not opts or "all" in opts) else list(dict.fromkeys(opts))

def pytest_generate_tests(metafunc):
    if "api_mode" in metafunc.fixturenames:
        modes = _selected_modes(metafunc.config)
        metafunc.parametrize("api_mode", modes, ids=modes, scope='module')
    if "api_mode_no_get" in metafunc.fixturenames:
        modes = [x for x in _selected_modes(metafunc.config) if x != 'get']
        metafunc.parametrize("api_mode_no_get", modes, ids=modes, scope='module')

@pytest.fixture(scope='session')
def headers(api_key):
    h = {}
    if api_key:
        h["X-API-Key"] = api_key
    return h


@pytest.fixture(scope='module')
def api_method_call(api_client, api_mode):
    """
    Call the REST or JSON-RPC endpoint according to the selected api_mode.
    Usage: resp = api_method_call("getMasterchainInfo", foo=1)
    """
    def _call(__method: str, **kwargs):
        return api_client(__method, api_mode, **kwargs)
    return _call


@pytest.fixture(scope='module')
def api_method_call_no_get(api_client, api_mode_no_get):
    """
    Call the REST or JSON-RPC endpoint according to the selected api_mode.
    Use this fixture for POST-methods.
    Usage: resp = api_method_call_no_get("getMasterchainInfo", foo=1)
    """
    def _call(__method: str, **kwargs):
        return api_client(__method, api_mode_no_get, **kwargs)
    return _call


@pytest.fixture(scope='session')
def api_method_call_get(api_client):
    def _call(__method, **kwargs):
        return api_client(__method, "get", **kwargs)
    return _call


@pytest.fixture(scope='module')
def last_mc_seqno(api_method_call_get):
    resp = api_method_call_get("getMasterchainInfo")
    resp.raise_for_status()
    return resp.json()['result']['last']['seqno']


# Nice-to-have: show selected modes in the test header
def pytest_report_header(config):
    return f"Selected API modes: {', '.join(_selected_modes(config))}"


def pytest_configure(config):
    if config.getoption("--request-timeout") <= 0:
        raise pytest.UsageError("--request-timeout must be positive")
    if config.getoption("--mc-seqno") is not None and config.getoption("--mc-seqno") <= 0:
        raise pytest.UsageError("--mc-seqno must be positive")
    for marker, description in {
        "live": "Requires chain access, with mainnet fixtures unless noted",
        "validation": "Input validation, without successful chain queries",
        "regression": "Desired behavior for a reproduced bug; intentionally not xfailed",
        "local": "Repository checks without a running API",
    }.items():
        config.addinivalue_line("markers", f"{marker}: {description}")


def pytest_collection_modifyitems(items):
    # Existing tests predate markers; conservatively treat them as live tests.
    for item in items:
        if not any(item.get_closest_marker(marker) for marker in ("local", "validation", "live")):
            item.add_marker(pytest.mark.live)


SEND_METHODS = {"sendBoc", "sendBocReturnHash", "sendBocReturnHashNoError"}


@pytest.fixture(scope="session")
def http_session(headers):
    with requests.Session() as session:
        session.headers.update(headers)
        yield session


@pytest.fixture(scope="session")
def raw_api_request(endpoint, http_session, request):
    timeout = request.config.getoption("--request-timeout")

    def call(verb, method, **kwargs):
        if method in SEND_METHODS:
            raise AssertionError("Use api_client for safe sender validation")
        if method == "jsonRPC":
            body = kwargs.get("json")
            if body is None:
                try:
                    body = json.loads(kwargs.get("data", ""))
                except (ValueError, TypeError):
                    body = None
            envelopes = body if isinstance(body, list) else [body]
            if any(isinstance(value, dict) and isinstance(value.get("method"), str)
                   and value["method"] in SEND_METHODS for value in envelopes):
                raise AssertionError("Use api_client for safe sender validation")
        return http_session.request(verb, endpoint + method,
                                    timeout=(min(3, timeout), timeout), **kwargs)
    return call


@pytest.fixture(scope="session")
def api_client(endpoint, http_session, request):
    timeout = request.config.getoption("--request-timeout")

    def call(endpoint_method, mode="get", **params):
        # Only absent/empty BOCs are allowed: no message can be broadcast.
        if endpoint_method in SEND_METHODS and params.get("boc") not in (None, ""):
            raise AssertionError("Broadcasts are prohibited in this test suite")
        kwargs = {"timeout": (min(3, timeout), timeout)}
        if mode == "get":
            return http_session.get(endpoint + endpoint_method, params=params, **kwargs)
        if mode == "post":
            return http_session.post(endpoint + endpoint_method, json=params, **kwargs)
        if mode == "jsonrpc":
            return http_session.post(endpoint + "jsonRPC", json={
                "jsonrpc": "2.0", "method": endpoint_method, "params": params, "id": 1,
            }, **kwargs)
        raise AssertionError(f"Unknown transport: {mode}")
    return call


@pytest.fixture(scope="session")
def mc_block(api_method_call_get, request, record_testsuite_property):
    seqno = request.config.getoption("--mc-seqno")
    if seqno is None:
        seqno = success(api_method_call_get("getMasterchainInfo"))["last"]["seqno"] - 5
    record_testsuite_property("mc_seqno", seqno)
    return {"workchain": -1, "shard": "-9223372036854775808", "seqno": seqno}
