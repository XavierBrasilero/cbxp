#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "cbxp.h"
#include "control_block_explorer.hpp"
#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"

static void show_json_usage(nlohmann::json request_json) {
  std::cout << "Request json must contain 'control_block' key with valid value." << std::endl;
  std::cout << "Your request contains: " << request_json.dump() << std::endl;
}

int cbxp(char *result_json_string, const char *p_request_json_string, int length, bool debug) {
  nlohmann::json request_json, control_block_json;

  try {
    // Ensure Request JSON is a NULL terminated string.
    auto request_json_unique_ptr = std::make_unique<char[]>(length + 1);
    std::memset(request_json_unique_ptr.get(), 0, length + 1);
    std::strncpy(request_json_unique_ptr.get(), p_request_json_string, length);
    // Parse Request JSON
    try {
      request_json = nlohmann::json::parse(request_json_unique_ptr.get());
    } catch (const nlohmann::json::parse_error &ex) {
      std::cout << "Syntax error in request JSON at byte " << ex.byte << std::endl;
      return -1;
    }
  } catch (const std::exception &ex) {
      std::cout << ex.what() << std::endl;
      return -1;
  }

  if (!request_json.contains("control_block")) {
    show_json_usage(request_json);
    return -1;
  }

  if (debug) {
    std::cout << "Caller passed a json with the 'control_block' key!" << std::endl;
  }

  std::string control_block = request_json["control_block"].get<std::string>();

  control_block_json =  explore_control_block(control_block, debug);

  if (control_block_json.empty()){
    std::cout << "Unknown control block '" << control_block << "' was specified."
              << std::endl;
    return -1;
  }

  std::string control_block_json_string = control_block_json.dump();

  if (debug) {
    std::cout << control_block_json_string << std::endl;
  }

  std::strncpy(result_json_string, control_block_json_string.c_str(),
               control_block_json_string.length());

  return 0;
}