#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "control_block_explorer.hpp"
#include "cbxp.h"
#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"

namespace CBXP {
  ControlBlockExplorer::ControlBlockExplorer(cbxp_result_t* p_result, bool debug){
    if (p_result->result_json != nullptr) {
      delete[] p_result->result_json;
    }

    p_result->result_json_length = 0;
    p_result->result_json = nullptr;
    p_result->return_code = -1;

    _debug = debug;
    _p_result = p_result;
  }

  void ControlBlockExplorer::explore_control_block(std::string control_block_name){
    nlohmann::json control_block_json = {};

    if (_debug) {
      std::cout << "Retrieving information on the '" << control_block_name << "' control block." << std::endl;
    }

    if (control_block_name == "psa") {
      control_block_json = CBXP::PSA().get();
    } else if (control_block_name == "cvt") {
      control_block_json = CBXP::CVT().get();
    } else if (control_block_name == "ecvt") {
      control_block_json = CBXP::ECVT().get();
    } else {
      std::cout << "Unknown control block '" << control_block_name << "' was specified."
                << std::endl;
      return;
    }

    std::string control_block_json_string = control_block_json.dump();

    if (_debug) {
      std::cout << control_block_json_string << std::endl;
    }

    _p_result->result_json_length = control_block_json_string.length();
    _p_result->result_json = new char[_p_result->result_json_length];


    std::strncpy(_p_result->result_json, control_block_json_string.c_str(),
                _p_result->result_json_length);

    _p_result->return_code = 0;
    return;
    }
    
  } //namespace CBXP
  