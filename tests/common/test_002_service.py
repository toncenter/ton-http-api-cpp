import pytest
from tests.helpers import error, success


@pytest.mark.validation
def test_healthcheck(raw_api_request):
    response = raw_api_request("GET", "healthcheck")
    assert response.status_code == 200, response.text
    assert response.content == b""


@pytest.mark.validation
def test_unknown_endpoint(raw_api_request):
    error(raw_api_request("GET", "noSuchEndpoint_test_82f134"), 404)


@pytest.mark.validation
@pytest.mark.parametrize("method", ["runGetMethod", "runGetMethodStd", "estimateFee"])
def test_post_only_route_get_uses_not_found_fallback(raw_api_request, method):
    error(raw_api_request("GET", method), 404)


@pytest.mark.validation
def test_version_and_content_type(api_method_call):
    response = api_method_call("detectHash", hash="0" * 64)
    success(response)
    assert response.headers.get("X-API-Version")
    assert response.headers.get("Content-Type", "").startswith("application/json")
