import pytest
from tests.data import MISSING_LIBRARY_HASH
from tests.helpers import error, success


@pytest.mark.live
@pytest.mark.parametrize("params", [{}, {"libraries": []},
    {"libraries": [MISSING_LIBRARY_HASH]}, {"libraries": [MISSING_LIBRARY_HASH, MISSING_LIBRARY_HASH]}])
def test_empty_or_missing_libraries(api_method_call, params):
    result = success(api_method_call("getLibraries", **params))
    assert result["@type"] == "smc.libraryResult"
    assert result["result"] == []


@pytest.mark.validation
@pytest.mark.parametrize("value", ["invalid", "f" * 63, "f" * 65])
def test_invalid_library_hash(api_method_call, value):
    error(api_method_call("getLibraries", libraries=[value]))
