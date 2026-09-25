import pytest
from tests.helpers import binary, block_id, boc, error, success, transaction_id

METHODS = ["getBlockTransactions", "getBlockTransactionsExt"]


@pytest.mark.live
@pytest.mark.parametrize("method", METHODS)
def test_block_transactions(api_method_call, mc_block, method):
    result = success(api_method_call(method, **mc_block, count=2))
    assert result["@type"] == ("blocks.transactions" if method == METHODS[0] else "blocks.transactionsExt")
    block_id(result["id"], mc_block)
    assert result["req_count"] == 2
    assert isinstance(result["incomplete"], bool)
    assert len(result["transactions"]) <= 2
    for tx in result["transactions"]:
        if method == METHODS[0]:
            assert int(tx["lt"]) > 0
            binary(tx["hash"], 32)
        else:
            transaction_id(tx)
            boc(tx["data"])


@pytest.mark.live
def test_block_pagination_and_extended_identity(api_method_call, mc_block):
    whole = success(api_method_call("getBlockTransactions", **mc_block, count=100))
    # A masterchain block is small; fail explicitly if this fixture assumption changes.
    assert not whole["incomplete"], "Choose a smaller fixed block with --mc-seqno"
    expected = whole["transactions"]
    cursor = {}
    collected = []
    for _ in range(len(expected) + 1):
        page = success(api_method_call("getBlockTransactions", **mc_block, count=1, **cursor))
        collected.extend(page["transactions"])
        if not page["incomplete"]:
            break
        assert page["transactions"], "Incomplete page did not advance"
        last = page["transactions"][-1]
        cursor = {"after_lt": last["lt"], "after_hash": last["account"]}
    else:
        pytest.fail("Pagination did not terminate")
    assert collected == expected
    assert len({(tx["account"], tx["lt"], tx["hash"]) for tx in collected}) == len(collected)
    extended = success(api_method_call("getBlockTransactionsExt", **mc_block, count=100))
    assert not extended["incomplete"]
    assert [transaction_id(tx) for tx in extended["transactions"]] == [(tx["lt"], tx["hash"]) for tx in expected]


@pytest.mark.validation
@pytest.mark.parametrize("method", METHODS)
@pytest.mark.parametrize("changes", [{"count": 0}, {"count": -1}, {"count": 10001},
    {"seqno": 0}, {"count": "bad"}, {"after_lt": 1}, {"after_hash": "0" * 64},
    {"after_lt": -1, "after_hash": "0" * 64}])
def test_invalid_block_transactions(api_method_call, method, changes):
    error(api_method_call(method, **{"workchain": -1, "shard": "-9223372036854775808", "seqno": 1, **changes}))
