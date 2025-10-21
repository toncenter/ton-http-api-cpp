import pytest

def test_address_information(api_method_call, last_mc_seqno):
    response = api_method_call('getMasterchainBlockSignatures', seqno=last_mc_seqno)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'blocks.blockSignatures'
    assert data['result']['signatures'][0]['@type'] == 'blocks.signature'
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getMasterchainBlockSignatures', seqno='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getMasterchainBlockSignatures', seqno=last_mc_seqno + 10000)
    assert response.status_code == 500
    data = response.json()
    assert data['ok'] == False

