#include <algorithm>
#include <iostream>
#include <nlohmann/json.hpp>

#include "cvt.hpp"
#include "ecvt.hpp"
#include "psa.hpp"

static void show_usage(char *argv[]) {
  std::cout << "Usage: " << argv[0] << " [CONTROL_BLOCK]" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    show_usage(argv);
    return -1;
  }

  std::string control_block = argv[1];
  std::transform(control_block.begin(), control_block.end(),
                 control_block.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  nlohmann::json control_block_json;

  if (control_block == "psa") {
    control_block_json = CBXP::PSA().get();
  } else if (control_block == "cvt") {
    control_block_json = CBXP::CVT().get();
  } else if (control_block == "ecvt") {
    control_block_json = CBXP::ECVT().get();
  } else {
    std::cout << "Unknown control block '" << argv[1] << "' was specified."
              << std::endl;
    return -1;
  }

  std::string control_block_json_string = control_block_json.dump();
  std::cout << control_block_json_string << std::endl;

  return 0;
}
