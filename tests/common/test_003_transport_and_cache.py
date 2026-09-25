import pytest
from tests.data import ELECTOR, WALLET
from tests.helpers import error, success


@pytest.mark.live
@pytest.mark.parametrize("method,params", [
    ("lookupBlock", {}), ("getBlock", {}), ("getBlockHeader", {}),
    ("getBlockTransactions", {"count": 2}), ("getBlockTransactionsExt", {"count": 2}),
    ("getConfigParam", {"param": 4}), ("getConfigAll", {}),
    ("getShards", {}), ("shards", {}),
    ("getShardAccountCell", {"address": WALLET}),
    ("getAddressBalance", {"address": WALLET}),
])
def test_fixed_block_result_matches_get_and_repeated_requests(api_method_call, api_method_call_get,
                                                             mc_block, method, params):
    block_methods = {"lookupBlock", "getBlock", "getBlockHeader", "getBlockTransactions", "getBlockTransactionsExt"}
    params = {**(mc_block if method in block_methods else {"seqno": mc_block["seqno"]}), **params}
    expected = success(api_method_call_get(method, **params))
    # Compare business data only; @extra is per-request timing/cache metadata.
    assert success(api_method_call(method, **params)) == expected
    assert success(api_method_call(method, **params)) == expected


@pytest.mark.live
def test_config_cache_key_includes_param(api_method_call, mc_block):
    first = success(api_method_call("getConfigParam", param=0, seqno=mc_block["seqno"]))
    second = success(api_method_call("getConfigParam", param=4, seqno=mc_block["seqno"]))
    assert first != second
    assert success(api_method_call("getConfigParam", param=0, seqno=mc_block["seqno"])) == first


@pytest.mark.live
def test_account_cache_key_includes_address(api_method_call, mc_block):
    wallet = success(api_method_call("getAddressInformation", address=WALLET, seqno=mc_block["seqno"]))
    elector = success(api_method_call("getAddressInformation", address=ELECTOR, seqno=mc_block["seqno"]))
    assert wallet["code"] != elector["code"]
    assert success(api_method_call("getAddressInformation", address=WALLET, seqno=mc_block["seqno"])) == wallet


@pytest.mark.validation
def test_invalid_then_valid_request_do_not_collide(api_method_call):
    error(api_method_call("detectHash", hash="not a hash"))
    expected = success(api_method_call("detectHash", hash="0" * 64))
    error(api_method_call("detectHash", hash="not a hash"))
    assert success(api_method_call("detectHash", hash="0" * 64)) == expected
