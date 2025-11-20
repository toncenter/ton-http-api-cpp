import pytest


TEST_ADDRESSES = [
    ("EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N",
     200),
    ("0:83dfd552e63729b472fcbcc8c45ebcc6691702558b68ec7527e1ba403a0f31a8",
     200),
    ("0:83DFD552E63729B472FCBCC8C45EBCC6691702558B68EC7527E1BA403A0F31A8",
     200),
    ("not_an_address",
     422),
    ("",
     422)
]

@pytest.mark.parametrize("address,code", TEST_ADDRESSES)
def test_detect_address(api_method_call,
                        address,
                        code):
    response = api_method_call('detectAddress', address=address)
    assert response.status_code == code
    if code != 200:
        return
    data = response.json()
    assert data['ok'] == True
    return
