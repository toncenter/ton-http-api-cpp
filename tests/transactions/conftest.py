import pytest
from tests.data import WALLET
from tests.helpers import success


@pytest.fixture(scope="session")
def wallet_history(api_method_call_get):
    history = success(api_method_call_get("getTransactions", address=WALLET, limit=3))
    assert len(history) == 3, "Mainnet wallet fixture must have at least three transactions"
    return history
