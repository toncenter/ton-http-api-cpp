import pytest
from tests.helpers import block_id, error, success


@pytest.mark.live
def test_lookup_by_seqno(api_method_call, mc_block):
    block_id(success(api_method_call("lookupBlock", **mc_block)), mc_block)


@pytest.mark.live
@pytest.mark.parametrize("selector", ["lt", "unixtime"])
def test_lookup_by_header(api_method_call, mc_block, selector):
    header = success(api_method_call("getBlockHeader", **mc_block))
    value = int(header["start_lt"]) + 1 if selector == "lt" else header["gen_utime"]
    params = {key: mc_block[key] for key in ("workchain", "shard")}
    result = success(api_method_call("lookupBlock", **params, **{selector: value}))
    block_id(result)
    assert result["workchain"] == mc_block["workchain"]
    assert result["shard"] == mc_block["shard"]
    if selector == "lt":
        assert result == header["id"]
    else:
        # Multiple blocks can share a Unix second. Timestamp lookup need not
        # choose the same seqno as the block used to obtain that timestamp.
        found = success(api_method_call("getBlockHeader", **{
            key: result[key] for key in ("workchain", "shard", "seqno")}))
        assert found["id"] == result
        assert found["gen_utime"] == value


@pytest.mark.validation
@pytest.mark.parametrize("selectors", [{}, {"seqno": 0}, {"seqno": -1},
    {"lt": -1}, {"unixtime": -1}, {"seqno": 1, "lt": 0},
    {"lt": 0, "unixtime": 0}, {"seqno": "bad"}, {"lt": str(2**63)}])
def test_invalid_lookup(api_method_call, selectors):
    error(api_method_call("lookupBlock", workchain=-1, shard="-9223372036854775808", **selectors))
