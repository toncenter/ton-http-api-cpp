import binascii
import pytest
from tests.data import ELECTOR
from tests.helpers import error, success

METHODS = ["runGetMethod", "runGetMethodStd"]


@pytest.mark.live
@pytest.mark.parametrize("endpoint_method", METHODS)
def test_named_and_numeric_method(api_method_call_no_get, mc_block, endpoint_method):
    method_name = "active_election_id"
    method_id = (binascii.crc_hqx(method_name.encode(), 0) & 0xffff) | 0x10000
    params = {"address": ELECTOR, "stack": [], "seqno": mc_block["seqno"]}
    named = success(api_method_call_no_get(endpoint_method, method=method_name, **params))
    numbered = success(api_method_call_no_get(endpoint_method, method=method_id, **params))
    assert named["exit_code"] in (0, 1)
    assert int(named["gas_used"]) >= 0
    assert named["stack"]
    assert named["stack"] == numbered["stack"]
    assert named["exit_code"] == numbered["exit_code"]


@pytest.mark.live
@pytest.mark.parametrize("endpoint_method", METHODS)
def test_vm_failure_is_execution_result(api_method_call_no_get, endpoint_method):
    result = success(api_method_call_no_get(endpoint_method, address=ELECTOR,
                                            method="test_method_that_does_not_exist_82f134", stack=[]))
    assert result["exit_code"] not in (0, 1)
    assert isinstance(result["stack"], list)


@pytest.mark.validation
@pytest.mark.parametrize("endpoint_method", METHODS)
@pytest.mark.parametrize("params", [{}, {"address": ELECTOR},
    {"address": ELECTOR, "method": "active_election_id"},
    {"address": "bad", "method": "active_election_id", "stack": []},
    {"address": ELECTOR, "method": {}, "stack": []},
    {"address": ELECTOR, "method": "active_election_id", "stack": "invalid"}])
def test_invalid_get_method(api_method_call_no_get, endpoint_method, params):
    error(api_method_call_no_get(endpoint_method, **params))
