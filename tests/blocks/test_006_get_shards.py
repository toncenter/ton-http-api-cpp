import pytest
from tests.helpers import block_id, error, success


@pytest.mark.live
@pytest.mark.parametrize("method", ["getShards", "shards"])
def test_shards(api_method_call, mc_block, method):
    result = success(api_method_call(method, seqno=mc_block["seqno"]))
    assert result["@type"] == "blocks.shards"
    assert result["shards"]
    for shard in result["shards"]:
        block_id(shard)
        assert shard["workchain"] != -1


@pytest.mark.live
def test_shards_alias(api_method_call, mc_block):
    assert success(api_method_call("shards", seqno=mc_block["seqno"])) == success(
        api_method_call("getShards", seqno=mc_block["seqno"]))


@pytest.mark.validation
@pytest.mark.parametrize("method", ["getShards", "shards"])
@pytest.mark.parametrize("seqno", [0, -1, "invalid", 2**31])
def test_invalid_shards(api_method_call, method, seqno):
    error(api_method_call(method, seqno=seqno))
