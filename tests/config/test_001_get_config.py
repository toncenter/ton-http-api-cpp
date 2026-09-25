import pytest
from tests.helpers import boc, error, success


@pytest.mark.live
@pytest.mark.parametrize("identifier", ["param", "config_id"])
def test_config_param(api_method_call, mc_block, identifier):
    result = success(api_method_call("getConfigParam", **{identifier: 4}, seqno=mc_block["seqno"]))
    assert result["@type"] == "configInfo"
    assert result["config"]["@type"] == "tvm.cell"
    boc(result["config"]["bytes"])
    assert result == success(api_method_call("getConfigParam", param=4, seqno=mc_block["seqno"]))


@pytest.mark.live
def test_config_all(api_method_call, mc_block):
    result = success(api_method_call("getConfigAll", seqno=mc_block["seqno"]))
    assert result["@type"] == "configInfo"
    assert result["config"]["@type"] == "tvm.cell"
    boc(result["config"]["bytes"])


@pytest.mark.validation
@pytest.mark.parametrize("params", [{}, {"param": -1}, {"config_id": -1},
    {"param": "bad"}, {"param": 2**31}, {"param": 4, "seqno": 0}, {"param": 4, "seqno": -1}])
def test_invalid_config_param(api_method_call, params):
    error(api_method_call("getConfigParam", **params))


@pytest.mark.validation
@pytest.mark.regression
def test_config_identifiers_are_mutually_exclusive(api_method_call):
    error(api_method_call("getConfigParam", param=4, config_id=0))


@pytest.mark.validation
@pytest.mark.parametrize("seqno", [0, -1, "bad", 2**31])
def test_invalid_config_all(api_method_call, seqno):
    error(api_method_call("getConfigAll", seqno=seqno))
