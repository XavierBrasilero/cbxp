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
  psa_json["CVTABEND"] = formatter.getHex<uint32_t>(p_cvt->cvtabend);
  psa_json["CVTAMFF"] = "NOT YET DONE";
  psa_json["CVTASMVT"] = formatter.getHex<uint32_t>(p_cvt->cvtasmvt);
  psa_json["CVTASVT"] = formatter.getHex<uint32_t>(p_cvt->cvtasvt);
  psa_json["CVTBRET"] = "NOT YET DONE";
  psa_json["CVTBSM0F"] = "NOT YET DONE";
  psa_json["CVTCSD"] = formatter.getHex<uint32_t>(p_cvt->cvtcsd);
  psa_json["CVTCTLFG"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvt->cvtctlfg));
  psa_json["CVTDCB"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvt->cvtdcb));
  psa_json["CVTDCPA"] = "NOT YET DONE";
  psa_json["CVTDFA"] = formatter.getHex<uint32_t>(p_cvt->cvtdfa);
  psa_json["CVTECVT"] = formatter.getHex<uint32_t>(p_cvt->cvtecvt);
  psa_json["CVTEDAT2"] = "NOT YET DONE";
  psa_json["CVTEPLPS"] = "NOT YET DONE";
  psa_json["CVTEXIT"] = "NOT YET DONE";
  psa_json["CVTEXP1"] = formatter.getHex<uint32_t>(p_cvt->cvtexp1);
  psa_json["CVTFLAG2"] = "NOT YET DONE";
  psa_json["CVTFLAG3"] = "NOT YET DONE";
  psa_json["CVTFLAG4"] = "NOT YET DONE";
  psa_json["CVTFLAG5"] = "NOT YET DONE";
  psa_json["CVTFLAG6"] = "NOT YET DONE";
  psa_json["CVTFLAG7"] = "NOT YET DONE";
  psa_json["CVTFLAG9"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvt->cvtflag9));
  psa_json["CVTFLGBT"] = "NOT YET DONE";
  psa_json["CVTGDA"] = formatter.getHex<uint32_t>(p_cvt->cvtgda);
  psa_json["CVTGRSST"] = "NOT YET DONE";
  psa_json["CVTGVT"] = formatter.getHex<uint32_t>(p_cvt->cvtgvt);
  psa_json["CVTHID"] = formatter.getHex<uint32_t>(p_cvt->cvthid);
  psa_json["CVTIXAVL"] = formatter.getHex<uint32_t>(p_cvt->cvtixavl);
  psa_json["CVTJESCT"] = formatter.getHex<uint32_t>(p_cvt->cvtjesct);
  psa_json["CVTLCCAT"] = formatter.getHex<uint32_t>(p_cvt->cvtlccat);
  psa_json["CVTLDTO"] = "NOT YET DONE";
  psa_json["CVTLINK"] = formatter.getHex<uint32_t>(p_cvt->cvtlink);
  psa_json["CVTLSO"] = "NOT YET DONE";
  psa_json["CVTMAXMP"] = "NOT YET DONE";
  psa_json["CVTMDL"] = "NOT YET DONE";
  psa_json["CVTMSER"] = formatter.getHex<uint32_t>(p_cvt->cvtmser);
  psa_json["CVTOPCTP"] = formatter.getHex<uint32_t>(p_cvt->cvtopctp);
  psa_json["CVTOSLVL"] = "NOT YET DONE";
  psa_json["CVTOVER"] = "NOT YET DONE";
  psa_json["CVTPCCAT"] = formatter.getHex<uint32_t>(p_cvt->cvtpccat);
  psa_json["CVTPCNVT"] = formatter.getHex<uint32_t>(p_cvt->cvtpcnvt);
  psa_json["CVTPRLTV"] = formatter.getHex<uint32_t>(p_cvt->cvtprltv);
  psa_json["CVTPROD"] = "NOT YET DONE";
  psa_json["CVTPSXM"] = formatter.getHex<uint32_t>(p_cvt->cvtpsxm);
  psa_json["CVTPVTP"] = formatter.getHex<uint32_t>(p_cvt->cvtpvtp);
  psa_json["CVTQTD00"] = formatter.getHex<uint32_t>(p_cvt->cvtqtd00);
  psa_json["CVTQTE00"] = formatter.getHex<uint32_t>(p_cvt->cvtqte00);
  psa_json["CVTRAC"] = formatter.getHex<uint32_t>(p_cvt->cvtrac);
  psa_json["CVTRCEP"] = formatter.getHex<uint32_t>(p_cvt->cvtrcep);
  psa_json["CVTRCZRT"] = "NOT YET DONE";
  psa_json["CVTRELNO"] = "NOT YET DONE";
  psa_json["CVTRI"] = "NOT YET DONE";
  psa_json["CVTRTMCT"] = formatter.getHex<uint32_t>(p_cvt->cvtrtmct);
  psa_json["CVTSAF"] = formatter.getHex<uint32_t>(p_cvt->cvtsaf);
  psa_json["CVTSCPIN"] = formatter.getHex<uint32_t>(p_cvt->cvtscpin);
  psa_json["CVTSDBF"] = "NOT YET DONE";
  psa_json["CVTSDUMP"] = "NOT YET DONE";
  psa_json["CVTSMCA"] = formatter.getHex<uint32_t>(p_cvt->cvtsmca);
  psa_json["CVTSNAME"] = "NOT YET DONE";
  psa_json["CVTSUBSP"] = "NOT YET DONE";
  psa_json["CVTSVT"] = formatter.getHex<uint32_t>(p_cvt->cvtsvt);
  psa_json["CVTSYSAD"] = formatter.getHex<uint32_t>(p_cvt->cvtsysad);
  psa_json["CVTTPC"] = formatter.getHex<uint32_t>(p_cvt->cvttpc);
  psa_json["CVTTVT"] = formatter.getHex<uint32_t>(p_cvt->cvttvt);
  psa_json["CVTTX"] = "NOT YET DONE";
  psa_json["CVTTXC"] = "NOT YET DONE";
  psa_json["CVTTXTE"] = "NOT YET DONE";
  psa_json["CVTTZ"] = "NOT YET DONE";
  psa_json["CVTUCBSC"] = formatter.getHex<uint32_t>(p_cvt->cvtucbsc);
  psa_json["CVTUNDVM"] = "NOT YET DONE";
  psa_json["CVTUSER"] = formatter.getHex<uint32_t>(p_cvt->cvtuser);
  psa_json["CVTVERID"] = "NOT YET DONE";
  psa_json["CVTVFGET"] = formatter.getHex<uint32_t>(p_cvt->cvtvfget);
  psa_json["CVTVFIND"] = formatter.getHex<uint32_t>(p_cvt->cvtvfind);
  psa_json["CVTVPSIB"] = formatter.getHex<uint32_t>(p_cvt->cvtvpsib);
  psa_json["CVTVWAIT"] = formatter.getHex<uint32_t>(p_cvt->cvtvwait);
  psa_json["CVT0EF00"] = formatter.getHex<uint32_t>(p_cvt->cvt0ef00);
  psa_json["CVT0PT0E"] = formatter.getHex<uint32_t>(p_cvt->cvt0pt0e);
  psa_json["CVT0PT02"] = formatter.getHex<uint32_t>(p_cvt->cvt0pt02);
  psa_json["CVT0PT03"] = formatter.getHex<uint32_t>(p_cvt->cvt0pt03);
  psa_json["CVT0SCR1"] = formatter.getHex<uint32_t>(p_cvt->cvt0scr1);





  





  std::string psa_json_string = psa_json.dump();
  std::cout << psa_json_string << std::endl;

  return 0;
}


