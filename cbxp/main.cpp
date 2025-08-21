#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "control_block_explorer.hpp"

static void show_cli_usage(char *argv[]) {
  std::cout << "Usage: " << argv[0] << " [CONTROL_BLOCK]" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    show_cli_usage(argv);
    return -1;
  }

  bool debug = true;

  std::string control_block = argv[1];

  nlohmann::json control_block_json;

  control_block_json = explore_control_block(control_block, debug);

  if (control_block_json.empty()){
    std::cout << "Unknown control block '" << control_block << "' was specified."
              << std::endl;
    return -1;
  }

  std::string control_block_json_string = control_block_json.dump();
  std::cout << control_block_json_string << std::endl;

  return 0;
}