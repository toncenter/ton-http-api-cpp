import pytest
from tests.data import EMPTY_BODY_BOC, WALLET
from tests.helpers import error, success


@pytest.mark.live
def test_estimate_fee_does_not_require_broadcast(api_method_call_no_get):
    result = success(api_method_call_no_get("estimateFee", address=WALLET,
                                            body=EMPTY_BODY_BOC, ignore_chksig=True))
    assert result["@type"] == "query.fees"
    assert isinstance(result["destination_fees"], list)
    for fees in [result["source_fees"], *result["destination_fees"]]:
        assert fees["@type"] == "fees"
        for key in ("in_fwd_fee", "storage_fee", "gas_fee", "fwd_fee"):
            assert isinstance(fees[key], int) and fees[key] >= 0


@pytest.mark.validation
@pytest.mark.parametrize("params", [{}, {"address": WALLET},
    {"address": "bad", "body": EMPTY_BODY_BOC},
    {"address": WALLET, "body": "not base64!"},
    {"address": WALLET, "body": EMPTY_BODY_BOC, "ignore_chksig": "not-bool"}])
def test_invalid_fee_request(api_method_call_no_get, params):
    error(api_method_call_no_get("estimateFee", **params))
