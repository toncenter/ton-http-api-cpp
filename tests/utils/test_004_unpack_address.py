import pytest


ADDRESSES = [
    'UQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqEBI',
    'EQCD39VS5jcptHL8vMjEXrzGaRcCVYto7HUn4bpAOg8xqB2N',
    '0:83dfd552e63729b472fcbcc8c45ebcc6691702558b68ec7527e1ba403a0f31a8',
    '0:83DFD552E63729B472FCBCC8C45EBCC6691702558B68EC7527E1BA403A0F31A8'
]
EXPECTED_RESPONSE = '0:83DFD552E63729B472FCBCC8C45EBCC6691702558B68EC7527E1BA403A0F31A8'


@pytest.mark.parametrize("address", ADDRESSES)
def test_different_address_forms(api_method_call, address):
    response = api_method_call('unpackAddress', address=address)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result'] == EXPECTED_RESPONSE
    return

def test_pack_address_no_address(api_method_call):
    response = api_method_call('unpackAddress')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False

def test_pack_address_invalid_address(api_method_call):
    response = api_method_call('unpackAddress', address='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
