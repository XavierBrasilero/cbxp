#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "control_block_explorer.hpp"
#include "cbxp.h"
#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"
#include "logger.hpp"
#include "ascb.hpp"
#include "asvt.hpp"

namespace CBXP {
  ControlBlockExplorer::ControlBlockExplorer(cbxp_result_t* p_result, bool debug){
    Logger::getInstance().setDebug(debug);

    if (p_result->result_json != nullptr) {
      Logger::getInstance().debugFree(p_result->result_json);
      delete[] p_result->result_json;
    }

    p_result->result_json_length = 0;
    p_result->result_json = nullptr;
    p_result->return_code = -1;

    _p_result = p_result;
  }

  void ControlBlockExplorer::exploreControlBlock(std::string control_block_name){
    nlohmann::json control_block_json = {};

    Logger::getInstance().debug("Extracting '" + control_block_name + "' control block data...");

    if (control_block_name == "psa") {
      control_block_json = CBXP::PSA().get();
    } else if (control_block_name == "cvt") {
      control_block_json = CBXP::CVT().get();
    } else if (control_block_name == "ecvt") {
      control_block_json = CBXP::ECVT().get();
    }else if (control_block_name == "ascb") {
      control_block_json = CBXP::ASCB().get();
    }else if (control_block_name == "asvt") {
      control_block_json = CBXP::ASVT().get();
    } else {
      return;
    }

    std::string control_block_json_string = control_block_json.dump();

    Logger::getInstance().debug("Done.");

    Logger::getInstance().debug("Control Block JSON: " + control_block_json_string);

    _p_result->result_json_length = control_block_json_string.length();
    _p_result->result_json = new char[_p_result->result_json_length];
    _p_result->result_json[_p_result->result_json_length] = 0;

    Logger::getInstance().debugAllocate(_p_result->result_json, 64, _p_result->result_json_length);

    std::strncpy(_p_result->result_json, control_block_json_string.c_str(),
                _p_result->result_json_length);

    _p_result->return_code = 0;
    return;
    }
    
  } //namespace CBXP
