#include <cstdint>
#include <iostream>
#include <string>

#include <ihapsa.h>
#include "nlohmann/json.hpp"
#include "control_block_field_formatter.hpp"


int main(void) {
  CBExplorer::ControlBlockFieldFormatter formatter;

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;

  // Get fields
  nlohmann::json psa_json = {};
  psa_json["psapsa"] = formatter.getString(p_psa->psapsa, 4);
  psa_json["flcsvilc"] = static_cast<int16_t>(p_psa->flcsvilc);
  psa_json["flcrnpsw_bitstring"] = formatter.getBitmap<uint32_t>(p_psa->flcrnpsw);
  psa_json["flcrnpsw_hex"] = formatter.getHex<uint32_t>(p_psa->flcrnpsw+4);
  psa_json["flccvt"] = formatter.getHex<uint32_t>(p_psa->flccvt);
  psa_json["flcsopsw"] = formatter.getPswSmall(p_psa->flcsopsw);
  psa_json["flcarch"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->flcarch));
  psa_json["flccvt64"] = formatter.getHex<uint64_t>(p_psa->flccvt64);
  psa_json["flcfacl"] =  formatter.getBitmap<uint64_t>(p_psa->flcfacl) + 
                        formatter.getBitmap<uint64_t>(p_psa->flcfacl+8);
  psa_json["flcfacle"] = formatter.getBitmap<uint64_t>(p_psa->flcfacle) + 
                        formatter.getBitmap<uint64_t>(p_psa->flcfacle+8);
  psa_json["psaaold"] = formatter.getHex<uint32_t>(p_psa->psaaold);
  psa_json["psaecvt"] = formatter.getHex<uint64_t>(p_psa->psaecvt);
  psa_json["psaflags"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psaflags));
  psa_json["psafpfl"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psafpfl));
  psa_json["psalaa"] = formatter.getHex<uint32_t>(p_psa->psalaa);
  psa_json["psalccav"] = formatter.getHex<uint32_t>(&p_psa->psalccav);
  psa_json["psatold"] = formatter.getHex<uint32_t>(p_psa->psatold);
  psa_json["psatrvt"] = formatter.getHex<uint32_t>(p_psa->psatrvt);
  psa_json["psaval"] = formatter.getBitmap<uint16_t>(p_psa->psaval);
  psa_json["psaxcvt"] = formatter.getHex<uint64_t>(p_psa->psaxcvt);


  std::string psa_json_string = psa_json.dump();
  std::cout << psa_json_string << std::endl;

  return 0;
}


