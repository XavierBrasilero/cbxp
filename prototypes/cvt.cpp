#include <cstdint>
#include <iostream>
#include <string>
#include <cvt.h>
#include <ihapsa.h>
#include "nlohmann/json.hpp"
#include "control_block_field_formatter.hpp"


int main(void) {
  CBExplorer::ControlBlockFieldFormatter formatter;

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  struct cvtmap *__ptr32 p_cvt = static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);


  // Get fields
  nlohmann::json psa_json = {};
  psa_json["CVTABEND"] = formatter.getString(p_cvt->cvtabend, 4);




  std::string psa_json_string = psa_json.dump();
  std::cout << psa_json_string << std::endl;

  return 0;
}


