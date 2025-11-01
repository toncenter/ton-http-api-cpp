import pytest

ADDRESS = 'EQDtFpEwcFAEcRe5mLVh2N6C0x-_hJEM7W61_JLnSF74p4q2'
FROZEN_ADDRESS = '-1:1562A2794314E178AC1D32C9F23A611F67C413E87B02C3115C5C3EA7D6112F3F'
ZERO_ADDRESS = '-1:0000000000000000000000000000000000000000000000000000000000000000'
@pytest.mark.parametrize("address", [ADDRESS, FROZEN_ADDRESS, ZERO_ADDRESS])
def test_wallet_information(api_method_call, address):
    response = api_method_call('getWalletInformation', address=address)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'ext.accounts.walletInformation'
    return


def test_invalid_address(api_method_call):
    response = api_method_call('getWalletInformation', address='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


def test_empty_address(api_method_call):
    response = api_method_call('getWalletInformation')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


ELECTOR_ADDRESS = 'Ef8zMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzMzM0vF'
def test_address_information_for_given_block(api_method_call, last_mc_seqno):
    response_new = api_method_call('getWalletInformation', address=ELECTOR_ADDRESS, seqno=last_mc_seqno)
    response_old = api_method_call('getWalletInformation', address=ELECTOR_ADDRESS, seqno=last_mc_seqno - 10)
    assert response_new.status_code == 200 and response_old.status_code == 200
    data_new = response_new.json()
    data_old = response_old.json()
    assert data_new['ok'] == True and data_old['ok'] == True
    assert data_old['result']['last_transaction_id']['lt'] < data_new['result']['last_transaction_id']['lt']
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getWalletInformation', address=ADDRESS, seqno='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getWalletInformation', address=ADDRESS, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return

def test_wallet_v1_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='-1:00CB2040D1B8EE338BD00E5CD577FF775B6EFDB00C9648C6F3AF021AF47AF931')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v1 r1'
    assert 'seqno' in data['result']
    return


def test_wallet_v1_r2(api_method_call):
    response = api_method_call('getWalletInformation', address='-1:4F530A942F3EBDC0B6023876287FC51007B6AE8546F4692B3A8787653DD41504')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v1 r2'
    assert 'seqno' in data['result']
    return


def test_wallet_v1_r3(api_method_call):
    response = api_method_call('getWalletInformation', address='-1:0054CF3FC1973810531F0F84AC877E5FDBECC9D5B5FF00DB9E415D0D4821347D')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v1 r3'
    assert 'seqno' in data['result']
    return


def test_wallet_v2_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='0:07896EA2330540BCD7AA884D0C354790480F9A0D1AC281CB172001DBFC17BF5E')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v2 r1'
    assert 'seqno' in data['result']
    return


def test_wallet_v1_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='0:02A6E2136A7AA0CF5ECBB770F993B92E53F98D6646C729DD8FAAFBBEE1A8704A')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v2 r2'
    assert 'seqno' in data['result']
    return


def test_wallet_v3_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='0:0001F349F7231BC799458008B5C9F57009EAEA221D0CB2883159D7D767014E58')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v3 r1'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    return


def test_wallet_v3_r2(api_method_call):
    response = api_method_call('getWalletInformation', address='0:615ACC1BBD5735649E061B54658BCDE9B6896160217901C253544AA5716615E6')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v3 r2'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    return


def test_wallet_v4_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='0:1193ECB0CC2F7C5D0AB9C957780A87EB226B74D16EFACE241C556B3B9EB9C493')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v4 r1'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    return


def test_wallet_v4_r2(api_method_call):
    response = api_method_call('getWalletInformation', address='0:399DC3CE613B3B4E701167BC8ADEAE2442DCD1C34CC21BE625C0E4C5936338AB')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v4 r2'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    return


def test_wallet_v5_beta(api_method_call):
    response = api_method_call('getWalletInformation', address='0:2599F75F0BDC9094DFDDCA8765439E96E451B1300783CF94611995AE94721C95')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v5 beta'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    assert 'is_signature_allowed' in data['result']
    return


def test_wallet_v5_r1(api_method_call):
    response = api_method_call('getWalletInformation', address='0:000013771810888C156D245DE6CE47B7A91C73E45293475EC8926B979E989670')
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['wallet'] == True
    assert data['result']['wallet_type'] == 'wallet v5 r1'
    assert 'seqno' in data['result']
    assert 'wallet_id' in data['result']
    assert 'is_signature_allowed' in data['result']
    return


HIGHLOAD_WALLETS = [
    '0:00D11D36E64E5181229D7E18256C5731700BBD383BBCE6876A6346F2A6DED643',
    '0:1B85D5623E2720758476662D461A312475159C32395F27D00C0D5C00F6EC6C57',
    '0:8A18BB6991F4AFD0ADB70C7D0C820B837295A2FAA506A3E468F739EBEC64FE0D',
    '0:61BB11512CF50F9B8594C0DE7EC04AFB7196677169FCB27385F18E9D4C8543BA'
]
@pytest.mark.parametrize("address", HIGHLOAD_WALLETS)
def test_highload_wallets(api_method_call, address):
    response = api_method_call('getWalletInformation', address=address)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'ext.accounts.walletInformation'
    assert data['result']['wallet'] == False
    return
