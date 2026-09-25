# API integration tests

Run from the repository root against a separately running service:

```sh
python -m pip install -r tests/requirements.txt
python -m pytest tests --endpoint http://localhost:8877/api/v2/ --method all
```

The suite uses mainnet fixtures. It does not start or reconfigure the service.
Requests are sequential, use a shared HTTP session, and have a 3-second connect
timeout and a 20-second read timeout (`--request-timeout` changes the latter).
There are no automatic retries or blanket expected-failure markers.

## Selection and reproducibility

```sh
# Repository inventory and duplicate-test checks: no running API needed.
python -m pytest tests -m local

# Input validation and service/gateway contracts (running API required).
python -m pytest tests --endpoint http://localhost:8877/api/v2/ -m validation

# Known bug regressions remain ordinary failing assertions until fixed.
python -m pytest tests --endpoint http://localhost:8877/api/v2/ -m regression

# Select one transport or repeat --method. Default is all three.
python -m pytest tests --endpoint http://localhost:8877/api/v2/ --method post

# Pin tests using mc_block to a known historical masterchain block.
python -m pytest tests --endpoint http://localhost:8877/api/v2/ --mc-seqno 94980978 \
  --junitxml=/tmp/ton-api-tests.xml
```

New fixed-block tests share `mc_block`, defaulting to latest minus five. Older
tests retain their module-scoped latest-block fixture. `--mc-seqno` does not pin
endpoints that lack a seqno parameter or the older latest-state tests. Historical
fixtures may require archival backend access. Account-history tests pin cursors
from a shared initial query rather than assume an account cannot transact during
the run. Fixture failures are reported, not silently skipped.

`live` includes chain-dependent tests and conservatively includes older tests
without explicit classification. `validation` tests expect rejection before a
successful chain query; a bug can still cause such a request to reach the backend.
`regression` overlaps these markers. Gateway/service tests make explicit raw HTTP
requests and are not filtered by `--method`; the option controls parametrized
endpoint tests. POST-only parametrized tests are skipped in a GET-only run.

## Coverage and intentional failures

`coverage_matrix.py` maps all 38 named methods (including aliases) to tests.
Local checks compare the inventory with configured routes and the JSON-RPC
allowlist, reject placeholder test files, and catch duplicate test function names.
This is endpoint presence coverage, not line or branch coverage.

The suite includes response structure and binary-encoding checks, block file-hash
verification, block/account transaction pagination, linked transaction lookup,
signature variants, config aliases, stack serialization, fee estimation,
transport comparisons, and request-key isolation. BOC checks validate encoding
and magic; they are not a full cell parser or cryptographic proof verifier.

Known regressions deliberately assert desired behavior without `xfail`:

- Missing `.ton` names and the `telegram.t.me` fixture should resolve without a
  resolver VM failure, including at a pinned block.
- `getConfigParam` must reject simultaneous `param` and `config_id` on every
  transport.
- Malformed JSON-RPC envelopes should return HTTP 422 with the standard error
  body, matching REST validation, rather than an empty HTTP 500.
- An unknown legacy stack type is invalid client input and should return HTTP
  422, rather than the current HTTP 542. This mismatch was found by the new tests.

Compatibility tests retain observed behavior where no change has been agreed:
legacy transaction `lt=0`, JSON-RPC's TON response envelope and ignored non-object
params, and the 404 fallback for GET on POST-only REST routes.

## Safety and remaining work

No valid message is submitted. Sender tests contain only missing/empty BOCs;
the shared client rejects nonempty sender payloads before HTTP. Raw sender calls
are also blocked. Fee estimation does not broadcast. Do not add successful send
tests to this live suite without a separate controlled-chain profile.

Follow-up coverage needs controlled fixtures for successful message submission
and external forwarding, known existing libraries, delegated subdomains, both
historical signature variants, configurable stack-depth limits, cache TTL and
concurrency, and backend timeout/failure injection. CI and C++ test registration
are intentionally outside this tests-only change.
