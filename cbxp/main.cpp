#include <algorithm>
#include <cstring>
#include <iostream>
#include <nlohmann/json.hpp>

#include "cbxp_result.h"
#include "control_block_explorer.hpp"

static void show_usage(const char* argv[]) {
  std::cout << "Usage: " << std::endl;
  std::cout << "  " << argv[0]
            << " [ENABLE_DEBUG_LOGGING: -d/--debug] (default false)"
            << " [CONTROL_BLOCK]" << std::endl;
  std::cout << "  " << argv[0] << " [SHOW_VERSION: -v/--version]" << std::endl;
  std::cout << "  " << argv[0] << " [SHOW_USAGE]: -h/--help" << std::endl;
}

int main(int argc, const char* argv[]) {
  bool debug = false;

  if (argc == 3) {
    if ((std::strcmp(argv[1], "-d") == 0) ||
        (std::strcmp(argv[1], "--debug") == 0)) {
      debug = true;
    } else {
      show_usage(argv);
      return -1;
    }
  } else if (argc != 2) {
    show_usage(argv);
    return -1;
  }

  if (std::strcmp(argv[1], "-v") == 0 ||
      std::strcmp(argv[1], "--version") == 0) {
    std::cout << "CBXP " << VERSION << std::endl;
    return 0;
  }

  if (std::strcmp(argv[1], "-h") == 0 || std::strcmp(argv[1], "--help") == 0) {
    show_usage(argv);
    return 0;
  }

  std::string control_block_name = argv[argc - 1];

  nlohmann::json control_block_json;

  static cbxp_result_t cbxp_result = {nullptr, 0, -1};

  CBXP::ControlBlockExplorer explorer =
      CBXP::ControlBlockExplorer(&cbxp_result, debug);

  explorer.exploreControlBlock(control_block_name);

  if (cbxp_result.return_code == -1) {
    std::cout << "Unknown control block '" << control_block_name
              << "' was specified." << std::endl;
  } else {
    std::cout << cbxp_result.result_json << std::endl;
  }

  return cbxp_result.return_code;
}
