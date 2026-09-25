"""Only absent/empty BOCs: these tests cannot submit a message."""
import pytest
from tests.helpers import error


@pytest.mark.validation
@pytest.mark.parametrize("method", ["sendBoc", "sendBocReturnHash", "sendBocReturnHashNoError"])
@pytest.mark.parametrize("params", [{}, {"boc": ""}])
def test_missing_message_is_rejected(api_method_call_no_get, method, params):
    error(api_method_call_no_get(method, **params))
