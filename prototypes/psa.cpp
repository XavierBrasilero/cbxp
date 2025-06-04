#include <iomanip>
#include <iostream>
#include <string>

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

  // FLCRNPSW bitstring and hex portion
  uint32_t flcrnpsw_bitstring;
  uint32_t flcrnpsw_hex;

  // Copy first 4 bytes of FLCRNPSW to flcrnpsw_bitstring
  // Copy the last 4 bytes of FLCRNPSW to flcrnpsw_hex
  std::memcpy(reinterpret_cast<char *>(&flcrnpsw_bitstring), p_psa->flcrnpsw, 4);
  std::memcpy(reinterpret_cast<char *>(&flcrnpsw_hex), p_psa->flcrnpsw+4, 4);

  std::cout << "FLCRNPSW (bitstring portion 32-bit): " << std::bitset<32>{flcrnpsw_bitstring} << std::endl;
  std::cout << "FLCRNPSW (hex portion 4-byte): 0x" << std::hex << std::setfill('0') << std::setw(8) << flcrnpsw_hex << std::endl;

  // FLCCVT address and FLCSOPSW bitstring
  uint32_t flccvt;
  uint64_t flcsopsw;

  // Copy FLCVT address and FLCSOPSW bitstring
  std::memcpy(reinterpret_cast<char *>(&flccvt), p_psa->flccvt, 4);
  std::memcpy(reinterpret_cast<char *>(&flcsopsw), p_psa->flcsopsw, 8);

  std::cout << "FLCCVT (hex address 4-byte): 0x" << std::hex << std::setfill('0') << std::setw(8) << flccvt << std::endl;
  std::cout << "FLCSOPSW (bitstirng 64-bit): " << std::bitset<64>{flcsopsw} << std::endl;

  return 0;
}
