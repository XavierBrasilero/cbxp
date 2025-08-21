#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "cbxp.h"
#include "cbxp_result.h"
#include "control_block_explorer.hpp"
#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"

cbxp_result_t *cbxp(const char *control_block_name, bool debug) {
  nlohmann::json control_block_json;
  std::string control_block = control_block_name;

  static cbxp_result_t cbxp_result = {nullptr, nullptr, 0, -1};

  cbxp_result.result_json_length = 0;
  cbxp_result.result_json = nullptr;
  cbxp_result.control_block = control_block.c_str();
  cbxp_result.return_code = -1;

  control_block_json =  explore_control_block(control_block, debug);

  if (control_block_json.empty()){
    std::cout << "Unknown control block '" << control_block << "' was specified."
              << std::endl;
    return &cbxp_result;
  }

  std::string control_block_json_string = control_block_json.dump();

  if (debug) {
    std::cout << control_block_json_string << std::endl;
  }

  cbxp_result.result_json_length = control_block_json_string.length();
  cbxp_result.result_json = (char *)calloc(cbxp_result.result_json_length, sizeof(char));


  std::strncpy(cbxp_result.result_json, control_block_json_string.c_str(),
               cbxp_result.result_json_length);

  cbxp_result.return_code = 0;
  return &cbxp_result;
}