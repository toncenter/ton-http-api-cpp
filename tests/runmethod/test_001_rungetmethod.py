import pytest
import logging
import json

logger = logging.getLogger(__name__)

METHOD = 'runGetMethod'

ELECTOR_ADDRESS = '-1:3333333333333333333333333333333333333333333333333333333333333333'
def test_run_get_method(api_method_call_no_get):
    address = ELECTOR_ADDRESS
    data = {
        'address': address,
        'method': 'active_election_id',
        'stack': []
    }
    response = api_method_call_no_get('runGetMethod', **data)
    assert response.status_code == 200, response.json()['error']
    data = response.json()
    assert data['ok'] == True

    result = data['result']
    assert result['@type'] in {'smc.runResult', 'ext.smc.runResult'}

    response_str = json.dumps(data, indent=4)
    logger.info(f'response:\n{response_str}')
    return
