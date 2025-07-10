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
  std::string psapsa = formatter.getString(p_psa->psapsa, 4);
  uint8_t flcsvilc = p_psa->flcsvilc;
  std::string flcrnpsw_bitstring = formatter.getBitmap<uint32_t>(p_psa->flcrnpsw);
  std::string flcrnpsw_hex = formatter.getHex<uint32_t>(p_psa->flcrnpsw+4);
  std::string flccvt = formatter.getHex<uint32_t>(p_psa->flccvt);
  std::string flcsopsw = formatter.getPswSmall(p_psa->flcsopsw);

  // Print fields
  std::cout << "PSAPSA: " << psapsa << std::endl;
  std::cout << "FLCSVILC: " << static_cast<int>(flcsvilc) << std::endl;
  std::cout << "FLCRNPSW (bitstring portion 32-bit): " << flcrnpsw_bitstring << std::endl;
  std::cout << "FLCRNPSW (hex portion 4-byte): " << flcrnpsw_hex << std::endl;
  std::cout << "FLCCVT: " << flccvt << std::endl;
  std::cout << "FLCSOPSW: " << flcsopsw << std::endl;

    
  std::cout << "Important PSA Information: "  << std::endl;

  std::string flcarch = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->flcarch));
  std::cout << "FLCARCH: " << flcarch << std::endl;

  std::cout << "FLCCVT: " << flccvt << std::endl;

  std::string flccvt64 = formatter.getHex<uint64_t>(p_psa->flccvt64);
  std::cout << "FLCCVT64: " << flccvt64 << std::endl;

  std::string flcfacl = formatter.getBitmap<uint64_t>(p_psa->flcfacl) + 
                        formatter.getBitmap<uint64_t>(p_psa->flcfacl+8);
  std::cout << "flcfacl: " << flcfacl << std::endl;

  std::string flcfacle = formatter.getBitmap<uint64_t>(p_psa->flcfacle) + 
                        formatter.getBitmap<uint64_t>(p_psa->flcfacle+8);
  std::cout << "flcfacle: " << flcfacle << std::endl;

  std::string psaaold = formatter.getHex<uint32_t>(p_psa->psaaold);
  std::cout << "PSAAOLD: " << psaaold << std::endl;

  std::string psaecvt = formatter.getHex<uint64_t>(p_psa->psaecvt);
  std::cout << "PSAECVT: " << psaecvt << std::endl;

  std::string psaflags = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psaflags));
  std::cout << "PSAFLAGS: " << psaflags << std::endl;

  std::string psafpfl = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psafpfl));
  std::cout << "PSAFPFL: " << psafpfl << std::endl;

  std::string psalaa = formatter.getHex<uint32_t>(p_psa->psalaa);
  std::cout << "PSALAA: " << psalaa << std::endl;

  std::string psalccav = formatter.getHex<uint32_t>(&p_psa->psalccav);
  std::cout << "PSALCCAV: " << psalccav << std::endl;

  // Further Research Needed
  // std::string psasvtx = formatter.getHex<uint32_t>(reinterpret_cast<char *>(0xB50));
  // std::string psasvtx = formatter.getHex<uint32_t>(&p_psa->psasvtx);
  // std::cout << "PSASVTX: " << psasvtx << std::endl;

  std::string psatold = formatter.getHex<uint32_t>(p_psa->psatold);
  std::cout << "PSATOLD: " << psatold << std::endl;

  std::string psatrvt = formatter.getHex<uint32_t>(p_psa->psatrvt);
  std::cout << "PSATRVT: " << psatrvt << std::endl;

  std::string psaval = formatter.getBitmap<uint16_t>(p_psa->psaval);
  std::cout << "PSAVAL: " << psaval << std::endl;

  std::string psaxcvt = formatter.getHex<uint64_t>(p_psa->psaval);
  std::cout << "PSAXCVT: " << psaxcvt << std::endl;


  nlohmann::json psa_json = {};
  psa_json["psapsa"] = formatter.getString(p_psa->psapsa, 4);
  psa_json["flcsvilc"] = static_cast<int16_t>(p_psa->flcsvilc);
  psa_json["flcrnpsw_bitstring"] = flcrnpsw_bitstring;
  psa_json["flcrnpsw_hex"] = flcrnpsw_hex;
  psa_json["flccvt"] = flccvt;
  psa_json["flcsopsw"] = flcsopsw;
  psa_json["flcarch"] = flcarch;
  psa_json["flccvt64"] = flccvt64;
  psa_json["flcfacl"] = flcfacl;
  psa_json["flcfacle"] = flcfacle;
  psa_json["psaaold"] = psaaold;
  psa_json["psaecvt"] = psaecvt;
  psa_json["psaflags"] = psaflags;
  psa_json["psafpfl"] = psafpfl;
  psa_json["psalaa"] = psalaa;
  psa_json["psalccav"] = psalccav;
  psa_json["psatold"] = psatold;
  psa_json["psatrvt"] = psatrvt;
  psa_json["psaval"] = psaval;
  psa_json["psaxcvt"] = psaxcvt;

  //std::string psa_json_string result_json_string = result_json.dump();

  std::cout << psa_json << std::endl;
  std::cout << std::setw(4) << psa_json << '\n';
  return 0;
}


