import pytest
import os, requests
from typing import Optional


API_CALL_MODES = ["get", "post", "jsonrpc"]

def pytest_addoption(parser):
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


@pytest.fixture(scope='module')
def endpoint(request) -> str:
    base = request.config.getoption("--endpoint").rstrip("/") + "/"
    return base


@pytest.fixture(scope='module')
def api_key(request) -> Optional[str]:
    return request.config.getoption("--apikey")

def _selected_modes(config) -> list[str]:
    opts = config.getoption("--method") or []
    return API_CALL_MODES if (not opts or "all" in opts) else [m for m in opts if m in API_CALL_MODES]

def pytest_generate_tests(metafunc):
    if "api_mode" in metafunc.fixturenames:
        modes = _selected_modes(metafunc.config)
        metafunc.parametrize("api_mode", modes, ids=modes, scope='module')

@pytest.fixture(scope='module')
def headers(api_key):
    h = {}
    if api_key:
        h["X-API-Key"] = api_key
    return h


@pytest.fixture(scope='module')
def api_method_call(endpoint, headers, api_mode):
    """
    Call the REST or JSON-RPC endpoint according to the selected api_mode.
    Usage: resp = api_method_call("getMasterchainInfo", foo=1)
    """
    def _call(method: str, **kwargs):
        url = endpoint  # already has trailing slash
        with requests.Session() as session:
            if api_mode == "get":
                return session.get(url + method, params=kwargs, headers=headers)
            if api_mode == "post":
                return session.post(url + method, json=kwargs, headers=headers)
            # jsonrpc
            return session.post(url + "jsonRPC",
                                json={"jsonrpc": "2.0", "method": method, "params": kwargs, "id": 1},
                                headers=headers)
    return _call


@pytest.fixture(scope='module')
def api_method_call_get(endpoint, headers):
    def _call(method, **kwargs):
        with requests.Session() as session:
            return session.get(os.path.join(endpoint, method),
                               params=kwargs,
                               headers=headers)
    return _call


@pytest.fixture(scope='module')
def last_mc_seqno(api_method_call_get):
    resp = api_method_call_get("getMasterchainInfo")
    resp.raise_for_status()
    return resp.json()['result']['last']['seqno']


# Nice-to-have: show selected modes in the test header
def pytest_report_header(config):
    return f"Selected API modes: {', '.join(_selected_modes(config))}"
