"""Controlled HTTP/log assertions. Uses only the Python standard library."""

import concurrent.futures
import contextlib
import http.client
import json
from pathlib import Path
import socket
import subprocess
import sys
import tempfile
import time
import unittest
from urllib.parse import urlencode


SERVICE_BINARY = None


class Service:
    def __init__(self, level="info", logger_level="critical", handler_level="error"):
        with socket.socket() as listener:
            listener.bind(("127.0.0.1", 0))
            self.port = listener.getsockname()[1]
        self.directory = tempfile.TemporaryDirectory(prefix="ton-debug-request-")
        self.root = Path(self.directory.name)
        self.config = self.root / "config.yaml"
        self.config.write_text(f"""
components_manager:
  task_processors:
    main-task-processor:
      worker_threads: 4
    fs-task-processor:
      worker_threads: 1
  default_task_processor: main-task-processor
  components:
    server:
      middleware-pipeline-builder: debug-request-server-middleware-pipeline-builder
      listener:
        address: 127.0.0.1
        port: {self.port}
        task_processor: main-task-processor
    logging:
      fs-task-processor: fs-task-processor
      loggers:
        default:
          file_path: '@stderr'
          level: critical
          format: json
        api-v2:
          file_path: {json.dumps(str(self.root / 'api.log'))}
          level: {logger_level}
          format: json
        api-v2-jsonrpc:
          file_path: {json.dumps(str(self.root / 'rpc.log'))}
          level: {logger_level}
          format: json
    debug-request-server-middleware-pipeline-builder: {{}}
    debug-request-middleware:
      log-level: {level}
    handler-debug-request-test:
      path: /test
      method: GET,POST
      log-level: {handler_level}
    handler-debug-request-throttled:
      path: /throttle
      method: GET,POST
      log-level: {handler_level}
      max_requests_in_flight: 0
    handler-DetectHash:
      path: /api/v2/detectHash
      method: GET,POST
      log-level: {handler_level}
    handler-JsonRpc:
      path: /api/v2/jsonRPC
      method: GET,POST
      log-level: {handler_level}
      logger: api-v2-jsonrpc
      port: {self.port}
      middlewares:
        debug-request-middleware:
          logger: api-v2-jsonrpc
    dns-client:
      fs-task-processor: fs-task-processor
    http-client-middleware-pipeline:
      middlewares:
        http-client-middleware-disabled:
          enabled: false
        http-client-middleware-override:
          enabled: false
    jsonrpc-http-client-core:
      thread-name-prefix: debug-test-client
      threads: 1
      fs-task-processor: fs-task-processor
    jsonrpc-http-client:
      core-component: jsonrpc-http-client-core
""")
        self.output = (self.root / "service.log").open("w")
        self.process = subprocess.Popen(
            [str(SERVICE_BINARY), "--config", str(self.config)],
            stdout=self.output, stderr=self.output,
        )

    def start(self):
        deadline = time.monotonic() + 15
        while time.monotonic() < deadline:
            if self.process.poll() is not None:
                raise RuntimeError((self.root / "service.log").read_text()[-8000:])
            try:
                if self.request(mode="flush")[0] == 200:
                    return self
            except OSError:
                time.sleep(0.05)
        raise RuntimeError("Test service did not start: " + (self.root / "service.log").read_text()[-8000:])

    def close(self):
        if self.process.poll() is None:
            self.process.terminate()
            try:
                self.process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                self.process.kill()
                self.process.wait()
        self.output.close()
        self.directory.cleanup()

    def request(self, *, path="/test", mode="", marker=None, data=None, **params):
        query = urlencode({"mode": mode, **params})
        headers = {}
        if marker is not None:
            headers["x-DeBuG-ReQuEsT"] = marker
        if data is not None:
            headers["Content-Type"] = "application/json"
        connection = http.client.HTTPConnection("127.0.0.1", self.port, timeout=5)
        try:
            connection.request("GET" if data is None else "POST", path + "?" + query, data, headers)
            response = connection.getresponse()
            return response.status, response.read().decode()
        finally:
            connection.close()

    def records(self, name="api"):
        self.request(mode="flush")
        return [json.loads(line) for line in (self.root / f"{name}.log").read_text().splitlines()]


@contextlib.contextmanager
def running_service(**settings):
    service = Service(**settings)
    try:
        yield service.start()
    finally:
        service.close()


class DebugRequestTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.service = Service()
        try:
            cls.service.start()
        except BaseException:
            cls.service.close()
            raise

    @classmethod
    def tearDownClass(cls):
        cls.service.close()

    def records_for(self, identifier, name="api"):
        return [record for record in self.service.records(name) if identifier in json.dumps(record.get("request"))]

    def test_header_parsing_and_cutoff_bypass(self):
        for index, marker in enumerate([None, "", "false", "1", "debug", "truth", "true,false", "TrUe", " true "]):
            with self.subTest(marker=marker):
                identifier = f"parsing_{index}"
                self.assertEqual(self.service.request(marker=marker, id=identifier)[0], 200)
                records = self.records_for(identifier)
                if index >= 7:
                    self.assertEqual(len(records), 1)
                    self.assertEqual(records[0]["level"], "INFO")
                    self.assertTrue(records[0]["debug_request"])
                    self.assertEqual(records[0]["api_method"], "/test")
                    self.assertIn("trace_id", records[0])
                    self.assertIn("span_id", records[0])
                    self.assertIn("link", records[0])
                else:
                    self.assertEqual(records, [])

    def test_fallback_and_malformed_payloads(self):
        for mode, data, status in [("fallback", '{"id":"fallback_json"}', 200),
                                   ("plain", None, 200), ("malformed", '{broken', 422)]:
            with self.subTest(mode=mode):
                before = len(self.service.records())
                self.assertEqual(self.service.request(mode=mode, data=data, marker="true")[0], status)
                records = self.service.records()[before:]
                self.assertEqual(len(records), 1)
                self.assertEqual(records[0]["level"], "INFO")
                self.assertEqual(records[0]["http_status"], status)
                if mode == "plain":
                    self.assertEqual(records[0]["response"], "plain text response")
                elif mode == "malformed":
                    self.assertEqual(records[0]["request"], "{broken")
                    self.assertEqual(records[0]["response"], {"ok": False})
        before = len(self.service.records())
        self.assertEqual(self.service.request(mode="malformed", data="{broken")[0], 422)
        self.assertEqual(len(self.service.records()), before)

    def test_exceptions_and_early_rejection(self):
        for mode, path, status in [("throw", "/test", 500), ("custom-error", "/test", 400),
                                   ("", "/throttle", 429)]:
            with self.subTest(mode=mode, path=path):
                before = len(self.service.records())
                self.assertEqual(self.service.request(mode=mode, path=path, marker="true")[0], status)
                records = self.service.records()[before:]
                self.assertEqual(len(records), 1)
                self.assertEqual(records[0]["http_status"], status)
                self.assertEqual(records[0]["level"], "INFO")
        before = len(self.service.records())
        self.assertEqual(self.service.request(mode="nonstd-throw", marker="true")[0], 499)
        record = self.service.records()[before:]
        self.assertEqual(len(record), 1)
        self.assertEqual(record[0]["response"], "request processing threw an exception")
        self.assertNotIn("http_status", record[0])

    def test_cached_response_logged_once(self):
        first = self.service.request(mode="cached", cache_key="cache_test", id="cached_first", marker="true")
        second = self.service.request(mode="cached", cache_key="cache_test", id="cached_second", marker="true")
        self.assertEqual(first, second)
        for identifier, hit in [("cached_first", False), ("cached_second", True)]:
            records = self.records_for(identifier)
            self.assertEqual(len(records), 1)
            self.assertEqual(records[0]["cache_hit"], hit)

    def test_concurrent_requests_are_isolated(self):
        def send(index):
            return self.service.request(id=f"concurrent_{index:03d}", marker="true" if index % 2 else None)

        with concurrent.futures.ThreadPoolExecutor(max_workers=8) as executor:
            self.assertTrue(all(status == 200 for status, _ in executor.map(send, range(40))))
        records = [record for record in self.service.records() if "concurrent_" in json.dumps(record.get("request"))]
        self.assertEqual(len(records), 20)
        identifiers = [record["request"]["id"] for record in records]
        self.assertEqual(set(identifiers), {f"concurrent_{index:03d}" for index in range(1, 40, 2)})

    def test_jsonrpc_forwarding_and_outer_record(self):
        for marker in ["TrUe", "false", None]:
            with self.subTest(marker=marker):
                identifier = f"rpc_{marker}"
                data = json.dumps({"method": "detectHash", "params": {"id": identifier}})
                self.assertEqual(self.service.request(path="/api/v2/jsonRPC", marker=marker, data=data)[0], 200)
                expected = 1 if marker == "TrUe" else 0
                self.assertEqual(len(self.records_for(identifier)), expected)
                outer = self.records_for(identifier, "rpc")
                self.assertEqual(len(outer), expected)
                if expected:
                    self.assertEqual(outer[0]["level"], "INFO")
                    self.assertEqual(outer[0]["request"]["method"], "detectHash")
                    self.assertEqual(outer[0]["response"], {"ok": True})
        before = len(self.service.records("rpc"))
        self.assertEqual(self.service.request(path="/api/v2/jsonRPC", marker="true", data="{}")[0], 500)
        self.assertEqual(len(self.service.records("rpc")), before + 1)

    def test_configurable_severity(self):
        for level in ["trace", "debug", "warning", "error", "critical"]:
            with self.subTest(level=level), running_service(level=level) as service:
                service.request(marker="true", id="configured_level")
                records = service.records()
                self.assertEqual(len(records), 1)
                self.assertEqual(records[0]["level"], level.upper())

    def test_normal_logging_and_single_forced_record(self):
        with running_service(logger_level="info", handler_level="info") as service:
            service.request(id="normal")
            service.request(id="forced", marker="true")
            records = service.records()
            self.assertEqual(len(records), 2)
            self.assertNotIn("debug_request", records[0])
            self.assertTrue(records[1]["debug_request"])

    def test_invalid_severity_rejected(self):
        for level in ["none", "verbose", "INFO"]:
            with self.subTest(level=level):
                service = Service(level=level)
                try:
                    self.assertNotEqual(service.process.wait(timeout=15), 0)
                    diagnostic = (service.root / "service.log").read_text()
                    self.assertIn("debug-request-middleware", diagnostic)
                    self.assertIn(f"'{level}'", diagnostic)
                finally:
                    service.close()


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit("Usage: debug_request_tests.py <test-service-binary> [unittest options]")
    SERVICE_BINARY = Path(sys.argv.pop(1)).resolve()
    unittest.main(verbosity=2)
