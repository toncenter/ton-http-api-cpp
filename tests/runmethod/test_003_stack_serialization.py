import pytest
from tests.data import ELECTOR, EMPTY_BODY_BOC
from tests.helpers import boc, error, success


def number(value):
    return {"@type": "tvm.stackEntryNumber", "number": {"@type": "tvm.numberDecimal", "number": str(value)}}


@pytest.mark.live
@pytest.mark.parametrize("value", [0, -1, 2**200 + 1, -(2**200) + 1])
def test_integer_precision_and_stack_cache_isolation(api_method_call_no_get, mc_block, value):
    params = {"address": ELECTOR, "method": "active_election_id", "seqno": mc_block["seqno"]}
    legacy = success(api_method_call_no_get("runGetMethod", stack=[["num", str(value)]], **params))
    standard = success(api_method_call_no_get("runGetMethodStd", stack=[number(value)], **params))
    assert legacy["exit_code"] == standard["exit_code"] == 0
    assert len(legacy["stack"]) == len(standard["stack"]) == 2
    assert int(legacy["stack"][0][1], 16) == value
    assert standard["stack"][0] == number(value)


@pytest.mark.live
@pytest.mark.parametrize("kind", ["Tuple", "List"])
def test_nested_stack_container_roundtrip(api_method_call_no_get, kind):
    lower = kind.lower()
    entry = {"@type": "tvm.stackEntry" + kind,
             lower: {"@type": "tvm." + lower, "elements": [number(2**100)]}}
    result = success(api_method_call_no_get("runGetMethodStd", address=ELECTOR,
                                            method="active_election_id", stack=[entry]))
    assert result["exit_code"] == 0
    assert result["stack"][0] == entry


@pytest.mark.live
@pytest.mark.parametrize("kind", ["Cell", "Slice"])
def test_cell_and_slice_roundtrip(api_method_call_no_get, kind):
    lower = kind.lower()
    entry = {"@type": "tvm.stackEntry" + kind,
             lower: {"@type": "tvm." + lower, "bytes": EMPTY_BODY_BOC}}
    result = success(api_method_call_no_get("runGetMethodStd", address=ELECTOR,
                                            method="active_election_id", stack=[entry]))
    assert result["exit_code"] == 0
    returned = result["stack"][0]
    assert returned["@type"] == entry["@type"]
    boc(returned[lower]["bytes"])


@pytest.mark.validation
@pytest.mark.parametrize("stack", [[[]], [["num"]],
    pytest.param([["unknown", "0"]], marks=pytest.mark.regression, id="unsupported-type-client-error"),
    [["cell", "bad"]]])
def test_malformed_legacy_stack(api_method_call_no_get, stack):
    error(api_method_call_no_get("runGetMethod", address=ELECTOR,
                                method="active_election_id", stack=stack))


@pytest.mark.validation
@pytest.mark.parametrize("stack", [[{}], [{"@type": "not.a.stackEntry"}],
    [{"@type": "tvm.stackEntryNumber", "number": {}}]])
def test_malformed_typed_stack(api_method_call_no_get, stack):
    error(api_method_call_no_get("runGetMethodStd", address=ELECTOR,
                                method="active_election_id", stack=stack))
