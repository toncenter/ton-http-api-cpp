import pytest


def test_get_masterchain_info(api_method_call):
    response = api_method_call('getMasterchainInfo')
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'blocks.masterchainInfo'
    assert data['result']['last']['@type'] == 'ton.blockIdExt'
    assert data['result']['init']['@type'] == 'ton.blockIdExt'
    return
