import pytest


ROOT = '-1:e56754f83426f69b09267bd876ac97c44821345b7e266bd956a7bfbfb98df35c'


def resolve(api_method_call, **params):
    response = api_method_call('dnsResolve', **params)
    data = response.json()
    assert response.status_code == 200, data
    assert data['ok'] is True
    assert data['result']['@type'] == 'dns.resolved'
    assert isinstance(data['result']['entries'], list)
    return data['result']['entries']


@pytest.mark.parametrize('params', [
    {},
    {'domain': ''},
    {'domain': '.'},
    {'domain': '.ton'},
    {'domain': 'sub..domain.ton'},
    {'domain': 'domain.ton..'},
    {'domain': 'bad name.ton'},
    {'domain': 'bad\x00name.ton'},
    {'domain': 'a' * 127},
    {'domain': 'foundation.ton', 'resolver_address': ''},
    {'domain': 'foundation.ton', 'resolver_address': 'invalid'},
    {'domain': 'foundation.ton', 'seqno': 0},
    {'domain': 'foundation.ton', 'seqno': -1},
    {'domain': 'foundation.ton', 'seqno': 'invalid'},
])
def test_invalid_request(api_method_call, params):
    response = api_method_call('dnsResolve', **params)
    assert response.status_code == 422, response.text
    assert response.json()['ok'] is False


@pytest.mark.parametrize('removed', ['address', 'name', 'category', 'ttl'])
def test_removed_parameters(api_method_call, removed):
    response = api_method_call('dnsResolve', domain='foundation.ton', **{removed: '0'})
    assert response.status_code == 422, response.text


@pytest.mark.parametrize('domain', ['foundation.ton', 'telegram.t.me'])
def test_supported_namespaces(api_method_call, domain):
    entries = resolve(api_method_call, domain=domain)
    # A name can have no published records; delegation correctness is also
    # covered by deterministic C++ fixtures independent of live registrations.
    for entry in entries:
        assert entry['@type'] == 'dns.entry'
        assert entry['name'] == domain
        assert 'category' in entry
        assert entry['entry']['@type'].startswith('dns.entryData')


def test_normalization_and_root_override(api_method_call, last_mc_seqno):
    expected = resolve(api_method_call, domain='foundation.ton', seqno=last_mc_seqno)
    assert expected, 'foundation.ton should have DNS records on mainnet'
    assert resolve(api_method_call, domain='FOUNDATION.TON.', seqno=last_mc_seqno) == expected
    assert resolve(api_method_call, domain='foundation.ton', resolver_address=ROOT,
                   seqno=last_mc_seqno) == expected


def test_missing_domain(api_method_call):
    assert resolve(api_method_call, domain='ton-http-api-no-such-domain-82f134a916.ton') == []


def test_historical_resolution(api_method_call, last_mc_seqno):
    seqno = last_mc_seqno - 20
    expected = resolve(api_method_call, domain='foundation.ton', seqno=seqno)
    assert expected
    assert resolve(api_method_call, domain='foundation.ton', resolver_address=ROOT, seqno=seqno) == expected


def test_resolver_cache_isolation(api_method_call, last_mc_seqno):
    assert resolve(api_method_call, domain='foundation.ton', seqno=last_mc_seqno)
    response = api_method_call('dnsResolve', domain='foundation.ton', seqno=last_mc_seqno,
                               resolver_address='0:' + '0' * 64)
    assert response.status_code != 200, response.text
    assert response.json()['ok'] is False


def test_seqno_cache_isolation(api_method_call, last_mc_seqno):
    assert resolve(api_method_call, domain='foundation.ton', seqno=last_mc_seqno)
    response = api_method_call('dnsResolve', domain='foundation.ton', seqno=last_mc_seqno + 100000)
    assert response.status_code != 200, response.text
    assert response.json()['ok'] is False
