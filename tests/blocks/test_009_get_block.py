import hashlib
import pytest
from tests.helpers import binary, block_id, boc, success


@pytest.mark.live
def test_block_data_and_file_hash(api_method_call, mc_block):
    result = success(api_method_call("getBlock", **mc_block))
    assert result["@type"] == "blocks.blockData"
    block_id(result["id"], mc_block)
    assert hashlib.sha256(boc(result["data"])).digest() == binary(result["id"]["file_hash"], 32)
    identified = {**mc_block, **{key: result["id"][key] for key in ("root_hash", "file_hash")}}
    assert success(api_method_call("getBlock", **identified)) == result
    assert success(api_method_call("getBlockHeader", **identified))["id"] == result["id"]
