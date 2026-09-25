import pytest
from tests.helpers import binary, block_id

def test_address_information(api_method_call, last_mc_seqno):
    response = api_method_call('getMasterchainBlockSignatures', seqno=last_mc_seqno)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    result = data['result']
    assert result['@type'] in {'blocks.blockSignatures', 'blocks.blockSignatures.simplex'}
    block_id(result['id'])
    assert result['id']['seqno'] == last_mc_seqno
    assert result['signatures']
    for signature in result['signatures']:
        assert signature['@type'] == 'blocks.signature'
        binary(signature['node_id_short'], 32)
        binary(signature['signature'], 64)
    if result['@type'] == 'blocks.blockSignatures.simplex':
        binary(result['session_id'], 32)
        assert isinstance(result['slot'], int) and result['slot'] >= 0
        binary(result['candidate'])
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getMasterchainBlockSignatures', seqno='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getMasterchainBlockSignatures', seqno=last_mc_seqno + 10000)
    assert response.status_code == 500, response.json()['error']
    data = response.json()
    assert data['ok'] == False
