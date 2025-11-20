#include <fstream>
#include "header.h"
#include "td/utils/logging.h"
#include "schemas/test_schemas_1.hpp"
#include "userver/formats/json/value_builder.hpp"

void test_schemas_1() {
  LOG(INFO) << "schemas_1";

  constexpr size_t depth = 20000;
  schema::Leaf leaf;
  leaf.field = "leaf!";
  schema::Node node;
  node.ref = leaf;

  schema::Node& head = node;
  for (size_t i = 0; i < depth; i++) {
    schema::Node new_node;
    new_node.ref = head;
    head = new_node;
  }

  auto value = userver::formats::json::ValueBuilder{head}.ExtractValue();

  try {
    std::ofstream file("sandbox/test_output.json");
    if (!file.is_open()) {
      LOG(ERROR) << "Failed to open file for writing";
      return;
    }
    file << ToString(value);
    file.close();
    LOG(INFO) << "Successfully saved to output.json";
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error saving file: " << e.what();
  }

  LOG(INFO) << "OK!";
  return;
}
