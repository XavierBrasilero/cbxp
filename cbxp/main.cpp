#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>


#include "cbxp_result.h"
#include "control_block_explorer.hpp"


static void show_usage(char *argv[]) {
  std::cout << "Usage: " << argv[0] << " [CONTROL_BLOCK]" << argv[1] << " [DEBUG_LOGGING_ENABLED: -d/--debug] (default false)" << std::endl;
}

int main(int argc, char *argv[]) {
  bool debug_logging = false;

  if (argc == 3) {
    std::string argv2 = argv[2];
    if ((argv2.compare("-d") == 0) || (argv2.compare("--debug") == 0)){
      debug_logging = true;
    }
    else{
      show_usage(argv);
      return -1;
    }
  }
  else if (argc != 2) {
    show_usage(argv);
    return -1;
  }

  std::string control_block_name = argv[1];


  nlohmann::json control_block_json;


  static cbxp_result_t cbxp_result = {nullptr, 0, -1};

  CBXP::ControlBlockExplorer explorer = CBXP::ControlBlockExplorer(&cbxp_result, debug_logging);
  
  explorer.exploreControlBlock(control_block_name);


  if (cbxp_result.return_code == -1) {
    std::cout << "Unknown control block '" << control_block_name << "' was specified."
            << std::endl;
  }
  else {
    std::cout << cbxp_result.result_json << std::endl;
  }

  return cbxp_result.return_code;
}
