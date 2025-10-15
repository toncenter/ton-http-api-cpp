import pytest

from tests.conftest import last_mc_seqno

ADDRESS = 'EQDtFpEwcFAEcRe5mLVh2N6C0x-_hJEM7W61_JLnSF74p4q2'
SUSPENDED_ADDRESS = '0:B81B6A61E804BF983FFE708BF8688626D73E63020096FD34C312BEF6CA05CE3F'

@pytest.mark.parametrize("address", [ADDRESS, SUSPENDED_ADDRESS])
def test_address_information(api_method_call, address):
    response = api_method_call('getAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'raw.fullAccountState'
    return

def test_address_information_no_address(api_method_call):
    response = api_method_call('getAddressInformation')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False

def test_address_information_invalid_address(api_method_call):
    response = api_method_call('getAddressInformation', address='invalid')
    assert response.status_code == 422


def test_suspended_address_information(api_method_call):
    response = api_method_call('getAddressInformation', address=SUSPENDED_ADDRESS)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'raw.fullAccountState'
    assert data['result']['sync_utime'] < 1803189600
    assert data['result']['state'] == 'uninitialized'
    assert data['result']['suspended'] == True
    return

def test_frozen_address_information(api_method_call):
    response = api_method_call('getAddressInformation', address='-1:1562A2794314E178AC1D32C9F23A611F67C413E87B02C3115C5C3EA7D6112F3F')
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'raw.fullAccountState'
    assert data['result']['state'] == 'frozen'
    assert len(data['result']['frozen_hash']) > 0
    return


def test_address_with_extra_currency(api_method_call):
    response = api_method_call('getAddressInformation', address='-1:0000000000000000000000000000000000000000000000000000000000000000')
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'raw.fullAccountState'
    assert len(data['result']['extra_currencies']) > 0
    assert data['result']['extra_currencies'][0]['@type'] == 'extraCurrency'

    has_239 = False
    for row in data['result']['extra_currencies']:
        if row['id'] == 239:
            has_239 = True
            break
    assert has_239 == True
    return

def test_address_information_for_given_block(api_method_call, last_mc_seqno):
    response = api_method_call('getAddressInformation', address=ADDRESS, seqno=last_mc_seqno - 10)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'raw.fullAccountState'
    assert data['result']['block_id']['seqno'] == last_mc_seqno - 10
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getAddressInformation', address=ADDRESS, seqno='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getAddressInformation', address=ADDRESS, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500
    data = response.json()
    assert data['ok'] == False