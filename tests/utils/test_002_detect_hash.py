import pytest


TEST_HASHES = [
    ("CPUE4WXeEJT+Dwz1fY/rkreWvYnsOt3I44i1G5ojJPM=", 200),
    ("CPUE4WXeEJT+Dwz1fY/rkreWvYnsOt3I44i1G5ojJPM", 422),
    ("CPUE4WXeEJT-Dwz1fY_rkreWvYnsOt3I44i1G5ojJPM=", 200),
    ("CPUE4WXeEJT-Dwz1fY_rkreWvYnsOt3I44i1G5ojJPM", 200),
    ("08f504e165de1094fe0f0cf57d8feb92b796bd89ec3addc8e388b51b9a2324f3", 200),
    ("08f504e165de1094fe0f0cf57d8feb92b796bd89ec3addc8e388b51b9a2324f3".upper(), 200),
    ("not a hash", 422),
    ("", 422)
]

@pytest.mark.parametrize("hash,code", TEST_HASHES)
def test_detect_hash(api_method_call,
                     hash,
                     code):
    response = api_method_call('detectHash', hash=hash)
    assert response.status_code == code
    if code != 200:
        return
    data = response.json()
    assert data['ok'] == True
    return
