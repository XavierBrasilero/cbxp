#include <cstring>
#include <iostream>

#include <stdint.h>
#include <unistd.h>
#include <ihapsa.h>

int main(void) {
  // PSAPSA eye catcher
  char psapsa[4];

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;

  // Copy PSAPSA eye catcher (4 bytes of EBCDIC encoded data)
  std::memcpy(psapsa, p_psa->psapsa, 4);

  // Get FLCSVILC field (unsigned 1-byte integer)
  uint8_t flcsvilc = p_psa->flcsvilc;

  // Covert PSAPSA eye catcher from EBCDIC to ASCII
  __e2a_l(psapsa, 4);

  std::cout << "PSA Eyecatcher: " << psapsa << std::endl;
  std::cout << "FLCSVILC: " << static_cast<int>(flcsvilc) << std::endl;

  return 0;
}
