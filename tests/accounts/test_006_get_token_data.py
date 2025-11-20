import pytest


MASTER_WITH_ADMIN = '0:4A011E625131E31728ED1398D92C90C18DE463D0580E123BBF6979DC718C4500'
MASTER_NO_ADMIN = '0:582A704468CABF8A12021A510A0335202C55052FEAB74569806B4FC7D4F4282E'
MASTER_MINTLESS = 'EQD6Z9DHc5Mx-8PI8I4BjGX0d2NhapaRAK12CgstweNoMint'
MASTER_USDT = 'EQCxE6mUtQJKFnGfaROTKOt1lZbDiiX1kCixRv7Nw2Id_sDs'
MASTER_LIST = [
    MASTER_WITH_ADMIN,
    MASTER_NO_ADMIN,
    MASTER_MINTLESS,
    MASTER_USDT
]

JETTON_WALLET_USDT = 'EQAmJs8wtwK93thF78iD76RQKf9Z3v2sxM57iwpZZtdQAiVM'
JETTON_WALLET_MINTLESS_CLAIMED = 'EQAaj04atIJcQn6wsRoz6DMUdOuS3pnN03g62gJIcpQF2Fx8'
JETTON_WALLET_MINTLESS_UNCLAIMED = 'EQD4Par0nbU69EU5Lv8KVjlYZkAbhaY7DNNvT7E4Pr1HMm2_'
JETTON_WALLET_LIST = [JETTON_WALLET_USDT, JETTON_WALLET_MINTLESS_CLAIMED, JETTON_WALLET_MINTLESS_UNCLAIMED]

NFT_COLLECTION_WITH_OWNER = '0:948C60752383D70D0F87C98FF7DA7510FF9A4C089247784B0CF284FB3DC3FC3E'
NFT_COLLECTION_WITHOUT_OWNER = '0:B774D95EB20543F186C06B371AB88AD704F7E256130CAF96189368A7D0CB6CCF'

JETTON_CONTENT_ONCHAIN = '0:4A011E625131E31728ED1398D92C90C18DE463D0580E123BBF6979DC718C4500'
NFT_CONTENT_OFFCHAIN = '0:BBE4B240CF509E7FBEEB4AC5925A83C55F4A14EB9A84BA19FD9481BFD4054BA6'

NFT_ITEM = '0:BBE4B240CF509E7FBEEB4AC5925A83C55F4A14EB9A84BA19FD9481BFD4054BA6'
NFT_ITEM_WITHOUT_OWNER = '0:B9C23B7ABAA128732093B2180A3C7DE73E9D382CEDECDF6C6EBFAA0417BB9962'
NFT_ITEM_WITHOUT_COLLECTION = '0:3B65BDAAACBC12F327CE75B82ED21CFE73DB8D78190044C056EA5CFF64899130'

DNS_WITH_RESOLVER = '0:8D87FA315733D2237522F328FDDA503BDB40222492726DAD3BBA277B6CB01E15'
DNS_WITH_SITE = DNS_WITH_RESOLVER
DNS_WITH_ADNL = DNS_WITH_RESOLVER
DNS_WITH_WALLET = '0:D6AF0A38A2852EA934DC8450CAFCAC273439B4C925D1AA3F64F49BB5575943C0'

NOT_TOKEN = '0:399DC3CE613B3B4E701167BC8ADEAE2442DCD1C34CC21BE625C0E4C5936338AB'


@pytest.mark.parametrize("address", [
    MASTER_WITH_ADMIN,
    JETTON_WALLET_USDT,
    NFT_COLLECTION_WITH_OWNER,
    NFT_COLLECTION_WITHOUT_OWNER,
    DNS_WITH_WALLET
])
def test_get_token_data(api_method_call, address):
    response = api_method_call('getTokenData', address=address)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True
    assert data['result']['@type'] in {
        'ext.tokens.jettonMasterData',
        'ext.tokens.jettonWalletData',
        'ext.tokens.nftCollectionData',
        'ext.tokens.nftItemData',
    }
    return


def test_invalid_address(api_method_call):
    response = api_method_call('getTokenData', address='invalid')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


def test_empty_address(api_method_call):
    response = api_method_call('getTokenData')
    assert response.status_code == 422, response.json()['error']
    data = response.json()
    assert data['ok'] == False
    return


def test_master_with_admin(api_method_call):
    response = api_method_call('getTokenData', address=MASTER_WITH_ADMIN)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'jetton_master'
    assert data['result']['@type'] == 'ext.tokens.jettonMasterData'
    assert 'admin_address' in data['result']
    return


def test_master_without_admin(api_method_call):
    response = api_method_call('getTokenData', address=MASTER_NO_ADMIN)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'jetton_master'
    assert data['result']['@type'] == 'ext.tokens.jettonMasterData'
    assert 'admin_address' not in data['result']
    return


def test_jetton_wallet_usdt(api_method_call):
    response = api_method_call('getTokenData', address=JETTON_WALLET_USDT)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'jetton_wallet'
    assert data['result']['@type'] == 'ext.tokens.jettonWalletData'


def test_jetton_wallet_mintless_claimed(api_method_call):
    response = api_method_call('getTokenData', address=JETTON_WALLET_MINTLESS_CLAIMED)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'jetton_wallet'
    assert data['result']['@type'] == 'ext.tokens.jettonWalletData'
    assert 'mintless_is_claimed' in data['result']
    assert data['result']['mintless_is_claimed'] == True
    return


def test_jetton_wallet_mintless_unclaimed(api_method_call):
    response = api_method_call('getTokenData', address=JETTON_WALLET_MINTLESS_UNCLAIMED)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'jetton_wallet'
    assert data['result']['@type'] == 'ext.tokens.jettonWalletData'
    assert 'mintless_is_claimed' in data['result']
    assert data['result']['mintless_is_claimed'] == False
    return


def test_collection_with_owner(api_method_call):
    response = api_method_call('getTokenData', address=NFT_COLLECTION_WITH_OWNER)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_collection'
    assert data['result']['@type'] == 'ext.tokens.nftCollectionData'
    assert 'owner_address' in data['result']
    return


def test_collection_without_owner(api_method_call):
    response = api_method_call('getTokenData', address=NFT_COLLECTION_WITHOUT_OWNER)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_collection'
    assert data['result']['@type'] == 'ext.tokens.nftCollectionData'
    assert 'owner_address' not in data['result']
    return


def test_item_with_owner(api_method_call):
    response = api_method_call('getTokenData', address=NFT_ITEM)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'owner_address' in data['result']
    return


def test_item_without_owner(api_method_call):
    response = api_method_call('getTokenData', address=NFT_ITEM_WITHOUT_OWNER)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'owner_address' not in data['result']
    return


def test_item_without_collection(api_method_call):
    response = api_method_call('getTokenData', address=NFT_ITEM_WITHOUT_COLLECTION)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'collection_address' not in data['result']
    return


def test_content_onchain(api_method_call):
    response = api_method_call('getTokenData', address=JETTON_CONTENT_ONCHAIN)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['jetton_content']['type'] == 'onchain'
    assert isinstance(data['result']['jetton_content']['data'], dict)
    return


def test_content_offchain(api_method_call):
    response = api_method_call('getTokenData', address=NFT_CONTENT_OFFCHAIN)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['content']['type'] == 'offchain'
    assert isinstance(data['result']['content']['data'], str)
    return


def test_not_token(api_method_call):
    response = api_method_call('getTokenData', address=NOT_TOKEN)
    assert response.status_code == 409


def test_dns_with_resolver(api_method_call):
    response = api_method_call('getTokenData', address=DNS_WITH_RESOLVER)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'domain' in data['result']['content']
    assert 'dns_next_resolver' in data['result']['content']['data']
    record = data['result']['content']['data']['dns_next_resolver']
    assert record['@type'] == 'dns_next_resolver'
    assert record['resolver']['@type'] == 'addr_std'
    return


def test_dns_with_site(api_method_call):
    response = api_method_call('getTokenData', address=DNS_WITH_SITE)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'domain' in data['result']['content']
    assert 'site' in data['result']['content']['data']
    record = data['result']['content']['data']['site']
    assert record['@type'] == 'dns_adnl_address'
    assert len(record['adnl_addr']) == 64
    return


def test_dns_with_storage(api_method_call):
    response = api_method_call('getTokenData', address=DNS_WITH_ADNL)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'domain' in data['result']['content']
    assert 'storage' in data['result']['content']['data']
    record = data['result']['content']['data']['storage']
    assert record['@type'] == 'dns_storage_address'
    assert len(record['bag_id']) == 64
    return


def test_dns_with_wallet(api_method_call):
    response = api_method_call('getTokenData', address=DNS_WITH_WALLET)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['result']['contract_type'] == 'nft_item'
    assert data['result']['@type'] == 'ext.tokens.nftItemData'
    assert 'domain' in data['result']['content']
    assert 'wallet' in data['result']['content']['data']
    record = data['result']['content']['data']['wallet']
    assert record['@type'] == 'dns_smc_address'
    assert record['smc_addr']['@type'] == 'addr_std'
    return
