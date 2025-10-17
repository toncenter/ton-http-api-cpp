import pytest


ADDRESS = 'EQDtFpEwcFAEcRe5mLVh2N6C0x-_hJEM7W61_JLnSF74p4q2'
FROZEN_ADDRESS = '-1:1562A2794314E178AC1D32C9F23A611F67C413E87B02C3115C5C3EA7D6112F3F'
ZERO_ADDRESS = '-1:0000000000000000000000000000000000000000000000000000000000000000'
@pytest.mark.parametrize("address", [ADDRESS, FROZEN_ADDRESS, ZERO_ADDRESS])
def test_address_balance(api_method_call, address):
    response = api_method_call('getAddressBalance', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert isinstance(data['result'], str)
    return


def test_invalid_address(api_method_call):
    response = api_method_call('getAddressBalance', address='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


def test_empty_address(api_method_call):
    response = api_method_call('getAddressBalance')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


ELECTOR_ADDRESS = 'Ef8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzM0vF'
def test_address_information_for_given_block(api_method_call, last_mc_seqno):
    response_new = api_method_call('getAddressBalance', address=ELECTOR_ADDRESS, seqno=last_mc_seqno)
    response_old = api_method_call('getAddressBalance', address=ELECTOR_ADDRESS, seqno=last_mc_seqno - 10)
    assert response_new.status_code == 200 and response_old.status_code == 200
    data_new = response_new.json()
    data_old = response_old.json()
    assert data_new['ok'] == True and data_old['ok'] == True
    assert data_old['result'] != data_new['result']
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getAddressBalance', address=ADDRESS, seqno='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False
    return


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getAddressBalance', address=ADDRESS, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500
    data = response.json()
    assert data['ok'] == False
    return
