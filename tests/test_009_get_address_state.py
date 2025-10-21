import pytest


ADDRESS = 'UQCv3xY8iuGlF2lE2C2tlSR3oIS9jxtqImO1OWvFh6T95Ep1'
FROZEN_ADDRESS = '-1:1562A2794314E178AC1D32C9F23A611F67C413E87B02C3115C5C3EA7D6112F3F'
ZERO_ADDRESS = '-1:0000000000000000000000000000000000000000000000000000000000000000'
BURN_ADDRESS = '0:0000000000000000000000000000000000000000000000000000000000000000'
@pytest.mark.parametrize("address", [ADDRESS, FROZEN_ADDRESS, ZERO_ADDRESS])
def test_address_state(api_method_call, address):
    response = api_method_call('getAddressState', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert isinstance(data['result'], str)
    assert data['result'] in {'active', 'frozen', 'uninitialized'}
    return


def test_active_address(api_method_call):
    response = api_method_call('getAddressState', address=ADDRESS)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result'] == 'active'
    return


def test_frozen_address(api_method_call):
    response = api_method_call('getAddressState', address=FROZEN_ADDRESS)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result'] == 'frozen'
    return


def test_uninitialized_address(api_method_call):
    response = api_method_call('getAddressState', address=BURN_ADDRESS)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result'] == 'uninitialized'
    return


def test_invalid_address(api_method_call):
    response = api_method_call('getAddressState', address='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


def test_empty_address(api_method_call):
    response = api_method_call('getAddressState')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getAddressState', address=ADDRESS, seqno='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getAddressState', address=ADDRESS, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500
    data = response.json()
    assert data['ok'] == False
    return
