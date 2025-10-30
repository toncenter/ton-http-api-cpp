import pytest

def test_get_consensus_block(api_method_call):
    response = api_method_call('getConsensusBlock')
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'ext.blocks.consensusBlock'
    return
