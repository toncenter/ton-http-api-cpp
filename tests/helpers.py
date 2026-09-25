"""Small semantic assertions shared by the HTTP integration tests."""
import base64


def payload(response):
    try:
        body = response.json()
    except ValueError:
        raise AssertionError(f"HTTP {response.status_code}: non-JSON body {response.text[:1000]!r}") from None
    assert isinstance(body, dict), body
    return body


def success(response):
    assert response.status_code == 200, f"HTTP {response.status_code}: {response.text[:2000]}"
    body = payload(response)
    assert body.get("ok") is True, body
    assert "result" in body, body
    return body["result"]


def error(response, status=422):
    assert response.status_code == status, f"HTTP {response.status_code}: {response.text[:2000]}"
    body = payload(response)
    assert body.get("ok") is False, body
    assert body.get("code") == status, body
    assert isinstance(body.get("error"), str) and body["error"], body
    return body


def binary(value, length=None):
    assert isinstance(value, str), value
    decoded = base64.b64decode(value, validate=True)
    assert decoded
    if length is not None:
        assert len(decoded) == length
    return decoded


def boc(value):
    decoded = binary(value)
    assert decoded[:4] in (bytes.fromhex("b5ee9c72"), bytes.fromhex("68ff65f3"),
                           bytes.fromhex("acc3a728")), "Invalid BOC magic"
    return decoded


def block_id(value, expected=None):
    assert value["@type"] == "ton.blockIdExt"
    assert isinstance(value["workchain"], int)
    assert isinstance(value["shard"], str)
    assert -(2**63) <= int(value["shard"]) < 2**63
    assert isinstance(value["seqno"], int) and value["seqno"] > 0
    for key in ("root_hash", "file_hash"):
        binary(value[key], 32)
    if expected:
        for key in ("workchain", "shard", "seqno"):
            assert value[key] == expected[key]


def transaction_id(transaction):
    identifier = transaction["transaction_id"]
    assert int(identifier["lt"]) > 0
    binary(identifier["hash"], 32)
    return identifier["lt"], identifier["hash"]
