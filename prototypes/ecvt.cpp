#include <cstdint>
#include <cstring>
#include <iostream>

#include <unistd.h>
#include <ihapsa.h>
#include <cvt.h>
#include <ihaecvt.h>

#include "control_block_field_formatter.hpp"

int main(void) {
  CBExplorer::ControlBlockFieldFormatter formatter;

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  // Get the address of the CVT from the PSA
  struct cvtmap *__ptr32 p_cvt = static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  // Get the address of the EVCT from the CVT
  struct ecvt *__ptr32 p_ecvt = static_cast<struct ecvt *__ptr32>(p_cvt->cvtecvt);

  // Get Fields
  std::string sysplex_name = formatter.getString(p_ecvt->ecvtsplx, 8);
  int32_t ecvtssds = p_ecvt->ecvtssds;

  // Print Fields
  std::cout << "Sysplex Name: " << sysplex_name << std::endl;
  std::cout << "ECVTSSDS: " << ecvtssds << std::endl;

  return 0;
}
