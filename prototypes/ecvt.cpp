#include <cstring>
#include <iostream>

#include <stdint.h>
#include <unistd.h>
#include <ihapsa.h>
#include <cvt.h>
#include <ihaecvt.h>

int main(void) {
  char sysplex_name[8];

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  // Get the address of the CVT from the PSA
  struct cvtmap *__ptr32 p_cvt = static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  // Get the address of the EVCT from the CVT
  struct ecvt *__ptr32 p_ecvt = static_cast<struct ecvt *__ptr32>(p_cvt->cvtecvt);

  // Copy Sysplex Name from the ECVT (8 bytes of EBCDIC encoded data)
  std::memcpy(sysplex_name, p_ecvt->ecvtsplx, 8);

  // Get ECVTSSDS field (unsigned 4-byte integer)
  int32_t ecvtssds = p_ecvt->ecvtssds;

  // Convert the Sysplex Name from EBCDIC to ASCII
  __e2a_l(sysplex_name, 8);

  std::cout << "Sysplex Name: " << sysplex_name << std::endl;
  std::cout << "ECVTSSDS: " << ecvtssds << std::endl;

  return 0;
}
