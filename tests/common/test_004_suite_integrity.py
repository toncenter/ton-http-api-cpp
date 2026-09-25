import ast
from pathlib import Path
import re
import pytest
from tests.coverage_matrix import ENDPOINT_TESTS

TESTS = Path(__file__).resolve().parents[1]
REPO = TESTS.parent
pytestmark = pytest.mark.local


def test_endpoint_inventory_matches_routes_and_rpc_allowlist():
    config = (REPO / "config/static_config.yaml").read_text()
    routes = set(re.findall(r"path:\s*/api/v2/(\w+)\s*$", config, re.MULTILINE)) - {"jsonRPC", "healthcheck"}
    assert routes == set(ENDPOINT_TESTS)
    rpc = (REPO / "ton-http-api/src/handlers/JsonRpcHandler.cpp").read_text()
    allowlist = rpc.split("kAllowedMethods = {", 1)[1].split("};", 1)[0]
    assert set(re.findall(r'"(\w+)"', allowlist)) == routes


@pytest.mark.parametrize("method,path", ENDPOINT_TESTS.items(), ids=ENDPOINT_TESTS)
def test_inventory_points_to_real_tests(method, path):
    tree = ast.parse((TESTS / path).read_text())
    assert any(isinstance(node, ast.FunctionDef) and node.name.startswith("test_") for node in tree.body)
    assert method in {node.value for node in ast.walk(tree) if isinstance(node, ast.Constant) and isinstance(node.value, str)}


def test_no_silently_overwritten_test_functions():
    def check_scope(nodes, path):
        seen = set()
        for node in nodes:
            if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)) and node.name.startswith("test_"):
                assert node.name not in seen, f"{path}:{node.lineno}: duplicate {node.name}"
                seen.add(node.name)
            if isinstance(node, ast.ClassDef):
                check_scope(node.body, path)
    for path in TESTS.rglob("test_*.py"):
        check_scope(ast.parse(path.read_text()).body, path)


@pytest.mark.parametrize("method", ["sendBoc", "sendBocReturnHash", "sendBocReturnHashNoError"])
@pytest.mark.parametrize("mode", ["get", "post", "jsonrpc"])
def test_nonempty_send_payload_is_blocked_before_http(api_client, method, mode):
    with pytest.raises(AssertionError, match="Broadcasts are prohibited"):
        api_client(method, mode, boc="not-even-a-message")


@pytest.mark.parametrize("method", ["sendBoc", "sendBocReturnHash", "sendBocReturnHashNoError"])
def test_raw_sender_calls_are_blocked_before_http(raw_api_request, method):
    with pytest.raises(AssertionError, match="safe sender validation"):
        raw_api_request("POST", method, json={})
    with pytest.raises(AssertionError, match="safe sender validation"):
        raw_api_request("POST", "jsonRPC", json={"method": method, "params": {}})
    with pytest.raises(AssertionError, match="safe sender validation"):
        raw_api_request("POST", "jsonRPC", json=[{"method": method, "params": {}}])
