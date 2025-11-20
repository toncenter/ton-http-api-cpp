import pytest

SHARD_ALL = -9223372036854775808


def test_get_shard_block_proof(api_method_call, last_mc_seqno):
    seqno = last_mc_seqno - 100
    from_seqno = last_mc_seqno
    response = api_method_call("getShardBlockProof", workchain=-1, shard=SHARD_ALL, seqno=seqno, from_seqno=from_seqno)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'blocks.shardBlockProof'

    result = data['result']
    assert result['from']['@type'] == 'ton.blockIdExt'
    assert result['from']['workchain'] == -1
    assert result['from']['shard'] == str(SHARD_ALL)
    assert result['from']['seqno'] == from_seqno

    assert result['mc_id']['@type'] == 'ton.blockIdExt'
    assert result['mc_id']['workchain'] == -1
    assert result['mc_id']['shard'] == str(SHARD_ALL)
    assert result['mc_id']['seqno'] == seqno

    mc_proof = result['mc_proof'][0]
    assert mc_proof['@type'] == 'blocks.blockLinkBack'
    assert mc_proof['from']['@type'] == 'ton.blockIdExt'
    assert mc_proof['from']['workchain'] == -1
    assert mc_proof['from']['shard'] == str(SHARD_ALL)
    assert mc_proof['from']['seqno'] == from_seqno

    assert mc_proof['from']['seqno'] == result['from']['seqno']

    assert mc_proof['to']['@type'] == 'ton.blockIdExt'
    assert mc_proof['to']['workchain'] == -1
    assert mc_proof['to']['shard'] == str(SHARD_ALL)
    assert mc_proof['to']['seqno'] == seqno

    assert 'dest_proof' in mc_proof
    assert 'proof' in mc_proof
    assert 'state_proof' in mc_proof
    return

def test_wrong_workchain(api_method_call):
    response = api_method_call('getShardBlockProof', workchain='invalid', shard=SHARD_ALL, seqno=1, from_seqno=1)
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_empty_workchain(api_method_call):
    response = api_method_call('getShardBlockProof', shard=SHARD_ALL, seqno=1, from_seqno=1)
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_wrong_shard(api_method_call):
    response = api_method_call('getShardBlockProof', workchain=-1, shard='invalid', seqno=1)
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_empty_shard(api_method_call):
    response = api_method_call('getShardBlockProof', workchain=-1, seqno=1)
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_wrong_seqno(api_method_call):
    response = api_method_call('getShardBlockProof', workchain=-1, shard=SHARD_ALL, seqno='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getShardBlockProof', workchain=-1, shard=SHARD_ALL, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_negative_seqno(api_method_call):
    response = api_method_call('getShardBlockProof', workchain=-1, shard=SHARD_ALL, seqno=-1)
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


def test_old_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getShardBlockProof', workchain=-1, shard=SHARD_ALL, seqno=1)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    return
