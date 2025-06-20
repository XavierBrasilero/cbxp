#include <cstdint>
#include <iostream>
#include <string>

#include <ihapsa.h>

#include "control_block_field_formatter.hpp"

int main(void) {
  CBExplorer::ControlBlockFieldFormatter formatter;

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;

  // Get fields
  std::string psapsa = formatter.getString(p_psa->psapsa, 4);
  uint8_t flcsvilc = p_psa->flcsvilc;
  std::string flcrnpsw_bitstring = formatter.getBitmap<uint32_t>(p_psa->flcrnpsw);
  std::string flcrnpsw_hex = formatter.getHex<uint32_t>(p_psa->flcrnpsw+4);
  std::string flccvt = formatter.getHex<uint32_t>(p_psa->flccvt);
  std::string flcsopsw = formatter.getBitmap<uint64_t>(p_psa->flcsopsw);

  // Print fields
  std::cout << "PSAPSA: " << psapsa << std::endl;
  std::cout << "FLCSVILC: " << static_cast<int>(flcsvilc) << std::endl;
  std::cout << "FLCRNPSW (bitstring portion 32-bit): " << flcrnpsw_bitstring << std::endl;
  std::cout << "FLCRNPSW (hex portion 4-byte): " << flcrnpsw_hex << std::endl;
  std::cout << "FLCCVT: " << flccvt << std::endl;
  std::cout << "FLCSOPSW: " << flcsopsw << std::endl;

  return 0;
}
