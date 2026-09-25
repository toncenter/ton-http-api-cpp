import pytest
from tests.data import WALLET
from tests.helpers import error, success, transaction_id

METHODS = ["tryLocateResultTx", "tryLocateTx", "tryLocateSourceTx"]


@pytest.fixture(scope="session")
def linked_transaction(wallet_history):
    for tx in wallet_history:
        msg = tx.get("in_msg")
        if msg and msg.get("source") and msg.get("destination") and int(msg["created_lt"]) > 0:
            return tx, msg
    pytest.fail("Mainnet fixture no longer includes an internal incoming message")


@pytest.mark.live
@pytest.mark.parametrize("method", METHODS)
def test_locate_linked_transaction(api_method_call, linked_transaction, method):
    receiver, msg = linked_transaction
    result = success(api_method_call(method, source=msg["source"], destination=msg["destination"],
                                     created_lt=msg["created_lt"]))
    transaction_id(result)
    if method == "tryLocateSourceTx":
        assert any(out["hash"] == msg["hash"] for out in result["out_msgs"])
    else:
        assert transaction_id(result) == transaction_id(receiver)
        assert result["in_msg"]["hash"] == msg["hash"]


@pytest.mark.validation
@pytest.mark.parametrize("method", METHODS)
@pytest.mark.parametrize("params", [{}, {"source": WALLET},
    {"source": WALLET, "destination": WALLET},
    {"source": WALLET, "destination": WALLET, "created_lt": -1},
    {"source": "bad", "destination": WALLET, "created_lt": 1},
    {"source": WALLET, "destination": "bad", "created_lt": 1},
    {"source": WALLET, "destination": WALLET, "created_lt": str(2**63)}])
def test_invalid_locate(api_method_call, method, params):
    error(api_method_call(method, **params))
