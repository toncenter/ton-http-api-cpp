import pytest
from tests.helpers import block_id, error, success


@pytest.mark.live
def test_block_header(api_method_call, mc_block):
    header = success(api_method_call("getBlockHeader", **mc_block))
    assert header["@type"] == "blocks.header"
    block_id(header["id"], mc_block)
    assert int(header["start_lt"]) < int(header["end_lt"])
    assert header["gen_utime"] > 0
    assert len(header["prev_blocks"]) == 1
    block_id(header["prev_blocks"][0], {**mc_block, "seqno": mc_block["seqno"] - 1})
    for flag in ("after_merge", "after_split", "before_split", "want_merge", "want_split", "is_key_block"):
        assert isinstance(header[flag], bool)


@pytest.mark.validation
@pytest.mark.parametrize("method", ["getBlockHeader", "getBlock"])
@pytest.mark.parametrize("changes", [{"seqno": 0}, {"seqno": -1}, {"workchain": "bad"},
    {"shard": str(2**63)}, {"root_hash": "bad"}, {"file_hash": "bad"}])
def test_invalid_block(api_method_call, method, changes):
    error(api_method_call(method, **{"workchain": -1, "shard": "-9223372036854775808", "seqno": 1, **changes}))
