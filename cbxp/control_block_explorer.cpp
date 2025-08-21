#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"

nlohmann::json explore_control_block(std::string control_block, bool debug){
  std::transform(control_block.begin(), control_block.end(),
                control_block.begin(),
                [](unsigned char c) { return std::tolower(c); });

  if (debug) {
    std::cout << "The 'control_block' has the value: " << control_block << std::endl;
  }

  nlohmann::json control_block_json = {};

  if (control_block == "psa") {
    control_block_json = CBXP::PSA().get();
  } else if (control_block == "cvt") {
    control_block_json = CBXP::CVT().get();
  } else if (control_block == "ecvt") {
    control_block_json = CBXP::ECVT().get();
  }

  return control_block_json;
}