# DNS resolution

`GET /api/v2/dnsResolve`, its POST equivalent, and JSON-RPC method `dnsResolve`
accept these parameters:

| Parameter | Required | Description |
| --- | --- | --- |
| `domain` | Yes | Domain to resolve, such as `subdomain.domain.ton` or `username.t.me`. |
| `resolver_address` | No | Starting resolver, in raw or user-friendly TON address format. If omitted, use on-chain config parameter 4. |
| `seqno` | No | Positive masterchain block sequence number. Defaults to the current block. |

For example:

```text
/api/v2/dnsResolve?domain=foundation.ton
/api/v2/dnsResolve?domain=username.t.me
/api/v2/dnsResolve?domain=subdomain&resolver_address=<resolver-address>
```

With an explicit resolver, the domain is relative to that resolver's namespace.
Names are converted to lowercase, and one trailing dot is accepted. Empty labels,
spaces, control characters, invalid UTF-8, and encoded names longer than 127 bytes
(including the initial self byte for an explicit resolver) are rejected with HTTP 422.

Resolution follows delegation until the complete domain is resolved and returns all
categories in the existing `dns.resolved.entries` array. Each entry's `name` is the
normalized requested domain. Missing records produce an empty array. Unknown record
types use `dns.entryDataUnknown`, whose `bytes` field is a base64-encoded record BOC.
Malformed resolver replies or exceeding 64 resolver calls return HTTP 502.
Root discovery and resolver account states are pinned to the same masterchain block,
including when `seqno` is specified. There is no static resolver configuration.

This replaces the previous `address`, `name`, `category`, and `ttl` request parameters;
requests containing those fields are rejected.

Deterministic protocol tests and live API tests can be run with:

```bash
cmake --build build --target ton-http-api-dns-tests
ctest --test-dir build/ton-http-api -R ton-http-api-dns --output-on-failure
python3 -m pytest tests/accounts/test_007_dns_resolve.py --endpoint http://localhost:8081/api/v2/ --method all
```
