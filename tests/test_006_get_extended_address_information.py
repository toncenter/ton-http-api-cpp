import pytest


ADDRESS = 'EQDtFpEwcFAEcRe5mLVh2N6C0x-_hJEM7W61_JLnSF74p4q2'
FROZEN_ADDRESS = '-1:1562A2794314E178AC1D32C9F23A611F67C413E87B02C3115C5C3EA7D6112F3F'
@pytest.mark.parametrize("address", [ADDRESS, FROZEN_ADDRESS])
def test_extended_address_information(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    return


ZERO_ADDRESS = '-1:0000000000000000000000000000000000000000000000000000000000000000'
@pytest.mark.parametrize("address", [ZERO_ADDRESS])
def test_account_state_raw(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'raw.accountState'
    return


WALLET_V3_ADDRESSES = [
    '0:0001F349F7231BC799458008B5C9F57009EAEA221D0CB2883159D7D767014E58',
    '0:615ACC1BBD5735649E061B54658BCDE9B6896160217901C253544AA5716615E6'
]
@pytest.mark.parametrize("address", WALLET_V3_ADDRESSES)
def test_account_state_wallet_v3(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'wallet.v3.accountState'
    assert 'wallet_id' in data['result']['account_state']
    assert 'seqno' in data['result']['account_state']
    return


WALLET_V4_ADDRESSES = [
    '0:399DC3CE613B3B4E701167BC8ADEAE2442DCD1C34CC21BE625C0E4C5936338AB'
]
@pytest.mark.parametrize("address", WALLET_V4_ADDRESSES)
def test_account_state_wallet_v4(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'wallet.v4.accountState'
    assert 'wallet_id' in data['result']['account_state']
    assert 'seqno' in data['result']['account_state']
    return


HIGHLOAD_V1_ADDRESSES = [
    '0:00D11D36E64E5181229D7E18256C5731700BBD383BBCE6876A6346F2A6DED643'
]
@pytest.mark.parametrize("address", HIGHLOAD_V1_ADDRESSES)
def test_account_state_wallet_highload_v1(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'wallet.highload.v1.accountState'
    assert 'wallet_id' in data['result']['account_state']
    assert 'seqno' in data['result']['account_state']
    return


HIGHLOAD_V2_ADDRESSES = [
    '0:1B85D5623E2720758476662D461A312475159C32395F27D00C0D5C00F6EC6C57',
    '0:8A18BB6991F4AFD0ADB70C7D0C820B837295A2FAA506A3E468F739EBEC64FE0D',
    '0:61BB11512CF50F9B8594C0DE7EC04AFB7196677169FCB27385F18E9D4C8543BA'
]
@pytest.mark.parametrize("address", HIGHLOAD_V2_ADDRESSES)
def test_account_state_wallet_highload_v2(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'wallet.highload.v2.accountState'
    assert 'wallet_id' in data['result']['account_state']
    assert 'seqno' not in data['result']['account_state']
    return


MANUAL_DNS_ADDRESSES = [
    '0:ACB4C149E8892869181EC98E74FE9711E891A69F9FA909F99A9D9BC16462F302',
    '-1:EAC391A15AD065447024AE74D55EB5E61F8B7FCE48F68EEF5981B07ECC4C094A'
]
@pytest.mark.parametrize("address", MANUAL_DNS_ADDRESSES)
def test_account_state_dns(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'dns.accountState'
    assert 'wallet_id' in data['result']['account_state']
    return



RWALLET_ADDRESSES = [
    '-1:170A415D4C5D0E93AEF74CC261C3F83A0693A6179B86CF44E17B070E673ACE7E'
]
@pytest.mark.parametrize("address", RWALLET_ADDRESSES)
def test_account_state_rwallet(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'rwallet.accountState'
    assert 'wallet_id' in data['result']['account_state']
    assert 'seqno' in data['result']['account_state']
    assert 'unlocked_balance' in data['result']['account_state']
    assert data['result']['account_state']['config']['@type'] == 'rwallet.config'
    for item in data['result']['account_state']['config']['limits']:
        assert item['@type'] == 'rwallet.limit'
    return


PCHAN_ADDRESSES = [
    '0:1748083DA0468FE89CF6C9298B35D355E1FD624DF1EECA826B869CDF2C59D718'
]
@pytest.mark.parametrize("address", PCHAN_ADDRESSES)
def test_account_state_pchan(api_method_call, address):
    response = api_method_call('getExtendedAddressInformation', address=address)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['account_state']['@type'] == 'pchan.accountState'
    assert 'config' in data['result']['account_state']
    assert 'state' in data['result']['account_state']
    assert 'description' in data['result']['account_state']
    assert data['result']['account_state']['config']['@type'] == 'pchan.config'
    possible_states = {'pchan.stateInit', 'pchan.stateClose', 'pchan.statePayout'}
    assert data['result']['account_state']['state']['@type'] in possible_states
    return


def test_address_information_for_given_block(api_method_call, last_mc_seqno):
    response = api_method_call('getExtendedAddressInformation', address=ADDRESS, seqno=last_mc_seqno - 10)
    assert response.status_code == 200
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] == 'fullAccountState'
    assert data['result']['block_id']['seqno'] == last_mc_seqno - 10
    return


def test_wrong_seqno(api_method_call):
    response = api_method_call('getExtendedAddressInformation', address=ADDRESS, seqno='invalid')
    assert response.status_code == 422
    data = response.json()
    assert data['ok'] == False


def test_future_seqno(api_method_call, last_mc_seqno):
    response = api_method_call('getExtendedAddressInformation', address=ADDRESS, seqno=last_mc_seqno + 10000)
    assert response.status_code == 500
    data = response.json()
    assert data['ok'] == False
