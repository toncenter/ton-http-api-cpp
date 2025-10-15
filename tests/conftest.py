import time

import pytest
import requests

def pytest_addoption(parser):
    parser.addoption(
        "--endpoint",
        action="store",
        default="http://localhost:8080/api/v2/",
        help="REST API endpoint URL"
    )
    parser.addoption(
        "--apikey",
        action="store",
        default=None,
        help="API key to pass in X-API-Key header"
    )

@pytest.fixture(scope='module')
def last_mc_seqno(request):
    headers = {}
    if request.config.getoption('apikey', default=None):
        headers['X-API-Key'] = request.config.getoption('apikey')
    url = f"{request.config.getoption('endpoint')}/getMasterchainInfo"
    resp = requests.get(url, headers=headers)
    resp.raise_for_status()
    return resp.json()['result']['last']['seqno']

@pytest.fixture(scope='module', params=['get','post', 'jsonrpc'])
def api_method_call(request):
    headers = {}
    if request.config.getoption('apikey', default=None):
        headers['X-API-Key'] = request.config.getoption('apikey')
    if request.param == 'get':
        def func(method, **kwargs):
            with requests.Session() as session:
                return session.get(f"{request.config.getoption('endpoint')}/{method}",
                                   params=kwargs,
                                   headers=headers)
        yield func
    elif request.param == 'post':
        def func(method, **kwargs):
            with requests.Session() as session:
                return session.post(f"{request.config.getoption('endpoint')}/{method}",
                                    json=kwargs,
                                    headers=headers)
        yield func
    elif request.param == 'jsonrpc':
        def func(method, **kwargs):
            with requests.Session() as session:
                return session.post(f"{request.config.getoption('endpoint')}/jsonRPC",
                                    json={'jsonrpc': '2.0', 'method': method, 'params': kwargs, 'id': 1},
                                    headers=headers)
        yield func
