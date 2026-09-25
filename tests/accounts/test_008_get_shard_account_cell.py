import pytest
from tests.data import WALLET
from tests.helpers import boc, error, success


@pytest.mark.live
def test_shard_account_cell(api_method_call, mc_block):
    result = success(api_method_call("getShardAccountCell", address=WALLET, seqno=mc_block["seqno"]))
    assert result["@type"] == "tvm.cell"
    boc(result["bytes"])
    assert success(api_method_call("getShardAccountCell", address=WALLET, seqno=mc_block["seqno"])) == result


@pytest.mark.validation
@pytest.mark.parametrize("params", [{}, {"address": ""}, {"address": "invalid"},
    {"address": WALLET, "seqno": 0}, {"address": WALLET, "seqno": -1},
    {"address": WALLET, "seqno": "invalid"}])
def test_invalid_shard_account_cell(api_method_call, params):
    error(api_method_call("getShardAccountCell", **params))
