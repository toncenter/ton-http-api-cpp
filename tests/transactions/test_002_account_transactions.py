import pytest
from tests.data import WALLET
from tests.helpers import boc, error, success, transaction_id

METHODS = ["getTransactions", "getTransactionsStd"]


def transactions(result, method):
    if method == "getTransactionsStd":
        assert result["@type"] == "raw.transactions"
        assert "previous_transaction_id" in result
        return result["transactions"]
    assert isinstance(result, list)
    return result


@pytest.mark.live
@pytest.mark.parametrize("method", METHODS)
def test_history_at_cursor(api_method_call, wallet_history, method):
    cursor = wallet_history[0]["transaction_id"]
    result = success(api_method_call(method, address=WALLET, limit=3, lt=cursor["lt"], hash=cursor["hash"]))
    items = transactions(result, method)
    assert [transaction_id(tx) for tx in items] == [transaction_id(tx) for tx in wallet_history]
    assert [int(tx["transaction_id"]["lt"]) for tx in items] == sorted(
        [int(tx["transaction_id"]["lt"]) for tx in items], reverse=True)
    for tx in items:
        boc(tx["data"])
        assert int(tx["fee"]) >= 0
        assert tx["utime"] > 0


@pytest.mark.live
def test_standard_pagination(api_method_call, wallet_history):
    cursor = wallet_history[0]["transaction_id"]
    first = success(api_method_call("getTransactionsStd", address=WALLET, limit=1,
                                   lt=cursor["lt"], hash=cursor["hash"]))
    next_cursor = first["previous_transaction_id"]
    second = success(api_method_call("getTransactionsStd", address=WALLET, limit=2,
                                    lt=next_cursor["lt"], hash=next_cursor["hash"]))
    items = first["transactions"] + second["transactions"]
    assert [transaction_id(tx) for tx in items] == [transaction_id(tx) for tx in wallet_history]


@pytest.mark.live
def test_legacy_zero_lt_means_latest(api_method_call):
    # Compatibility behavior: unlike Std, legacy treats lt=0 as absent.
    result = success(api_method_call("getTransactions", address=WALLET, limit=1, lt=0))
    assert len(result) == 1
    transaction_id(result[0])


@pytest.mark.validation
def test_standard_zero_lt_requires_hash(api_method_call):
    error(api_method_call("getTransactionsStd", address=WALLET, lt=0))


@pytest.mark.validation
@pytest.mark.parametrize("method", METHODS)
@pytest.mark.parametrize("changes", [{"address": "bad"}, {"limit": 0}, {"limit": -1},
    {"limit": 1001}, {"limit": "bad"}, {"lt": 1}, {"hash": "0" * 64},
    {"lt": -1, "hash": "0" * 64}, {"lt": 1, "hash": "bad"}])
def test_invalid_history(api_method_call, method, changes):
    error(api_method_call(method, **{"address": WALLET, **changes}))
