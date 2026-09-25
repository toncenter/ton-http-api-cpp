import pytest
from tests.helpers import block_id, success


@pytest.mark.live
def test_out_msg_queue_size(api_method_call):
    result = success(api_method_call("getOutMsgQueueSize"))
    assert result["@type"] == "blocks.outMsgQueueSizes"
    assert isinstance(result["ext_msg_queue_size_limit"], int)
    assert result["ext_msg_queue_size_limit"] >= 0
    assert isinstance(result["shards"], list)
    for shard in result["shards"]:
        assert shard["@type"] == "blocks.outMsgQueueSize"
        block_id(shard["id"])
        assert isinstance(shard["size"], int) and shard["size"] >= 0
