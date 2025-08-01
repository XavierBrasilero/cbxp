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
  struct cvtmap *__ptr32 p_cvtmap = static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  struct cvtfix *__ptr32 p_cvtfix = static_cast<struct cvtfix *__ptr32>(p_psa->flccvt);
  struct cvtxtnt2 *__ptr32 p_cvtxtnt2 = static_cast<struct cvtxtnt2 *__ptr32>(p_psa->flccvt);
  
  


  // Get fields
  nlohmann::json cvt_json = {};
  cvt_json["CVTABEND"] = formatter.getHex<uint32_t>(p_cvtmap->cvtabend);
  cvt_json["CVTAMFF"] = formatter.getHex<uint32_t>(p_cvtmap->cvtamff);
  cvt_json["CVTASMVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtasmvt);
  cvt_json["CVTASVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtasvt);
  cvt_json["CVTBRET"] = formatter.getHex<uint16_t>(p_cvtmap->cvtbret);
  cvt_json["CVTBSM0F"] = formatter.getHex<uint16_t>(p_cvtmap->cvtbsm0f);
  cvt_json["CVTCSD"] = formatter.getHex<uint32_t>(p_cvtmap->cvtcsd);
  cvt_json["CVTCTLFG"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtctlfg));
  cvt_json["CVTDCB"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtdcb));
  cvt_json["CVTDCPA"] = "NOT YET DONE";
  cvt_json["CVTDFA"] = formatter.getHex<uint32_t>(p_cvtmap->cvtdfa);
  cvt_json["CVTECVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtecvt);
  cvt_json["CVTEDAT2"] = "NOT YET DONE";
  cvt_json["CVTEPLPS"] = "NOT YET DONE";
  cvt_json["CVTEXIT"] = formatter.getHex<uint16_t>(p_cvtmap->cvtexit);
  cvt_json["CVTEXP1"] = formatter.getHex<uint32_t>(p_cvtmap->cvtexp1);
  cvt_json["CVTFLAG2"] = "NOT YET DONE";
  cvt_json["CVTFLAG3"] = "NOT YET DONE";
  cvt_json["CVTFLAG4"] = "NOT YET DONE";
  cvt_json["CVTFLAG5"] = "NOT YET DONE";
  cvt_json["CVTFLAG6"] = "NOT YET DONE";
  //cvt_json["CVTFLAG7"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtflag7));
  cvt_json["CVTFLAG9"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtflag9));
  cvt_json["CVTFLGBT"] = "NOT YET DONE";
  cvt_json["CVTGDA"] = formatter.getHex<uint32_t>(p_cvtmap->cvtgda);
  cvt_json["CVTGRSST"] = "NOT YET DONE";
  cvt_json["CVTGVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtgvt);
  cvt_json["CVTHID"] = formatter.getHex<uint32_t>(p_cvtmap->cvthid);
  cvt_json["CVTIXAVL"] = formatter.getHex<uint32_t>(p_cvtmap->cvtixavl);
  cvt_json["CVTJESCT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtjesct);
  cvt_json["CVTLCCAT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtlccat);
  cvt_json["CVTLDTO"] = formatter.getHex<uint64_t>(p_cvtxtnt2->cvtldto);
  cvt_json["CVTLINK"] = formatter.getHex<uint32_t>(p_cvtmap->cvtlink);
  cvt_json["CVTLSO"] = formatter.getHex<uint64_t>(p_cvtxtnt2->cvtlso);
  cvt_json["CVTMAXMP"] = p_cvtmap->cvtmaxmp;
  cvt_json["CVTMDL"] = formatter.getHex<uint16_t>(p_cvtfix->cvtmdl);
  cvt_json["CVTMSER"] = formatter.getHex<uint32_t>(p_cvtmap->cvtmser);
  cvt_json["CVTOPCTP"] = formatter.getHex<uint32_t>(p_cvtmap->cvtopctp);
  cvt_json["CVTOSLVL"] = formatter.getHex<uint64_t>(p_cvtmap->cvtoslvl) + formatter.getHex<uint64_t>(p_cvtmap->cvtoslvl+8);
  cvt_json["CVTOVER"] = "NOT YET DONE";
  cvt_json["CVTPCCAT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpccat);
  cvt_json["CVTPCNVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpcnvt);
  cvt_json["CVTPRLTV"] = formatter.getHex<uint32_t>(p_cvtmap->cvtprltv);
  cvt_json["CVTPROD"] = formatter.getHex<uint64_t>(p_cvtfix->cvtprod) + formatter.getHex<uint64_t>(p_cvtfix->cvtprod+8);
  cvt_json["CVTPSXM"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpsxm);
  cvt_json["CVTPVTP"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpvtp);
  cvt_json["CVTQTD00"] = formatter.getHex<uint32_t>(p_cvtmap->cvtqtd00);
  cvt_json["CVTQTE00"] = formatter.getHex<uint32_t>(p_cvtmap->cvtqte00);
  cvt_json["CVTRAC"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrac);
  cvt_json["CVTRCEP"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrcep);
  cvt_json["CVTRCZRT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrczrt);
  cvt_json["CVTRELNO"] = formatter.getHex<uint32_t>(p_cvtfix->cvtrelno);
  cvt_json["CVTRI"] = "NOT YET DONE";
  cvt_json["CVTRTMCT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrtmct);
  cvt_json["CVTSAF"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsaf);
  cvt_json["CVTSCPIN"] = formatter.getHex<uint32_t>(p_cvtmap->cvtscpin);
  //cvt_json["CVTSDBF"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsdbf);
  cvt_json["CVTSDUMP"] = "NOT YET DONE";
  cvt_json["CVTSMCA"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsmca);
  cvt_json["CVTSNAME"] = formatter.getString(p_cvtmap->cvtsname, 8);
  cvt_json["CVTSUBSP"] = "NOT YET DONE";
  cvt_json["CVTSVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsvt);
  cvt_json["CVTSYSAD"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsysad);
  cvt_json["CVTTPC"] = formatter.getHex<uint32_t>(p_cvtmap->cvttpc);
  cvt_json["CVTTVT"] = formatter.getHex<uint32_t>(p_cvtmap->cvttvt);
  cvt_json["CVTTX"] = "NOT YET DONE";
  cvt_json["CVTTXC"] = "NOT YET DONE";
  cvt_json["CVTTXTE"] = "NOT YET DONE";
  cvt_json["CVTTZ"] = p_cvtmap->cvttz;
  cvt_json["CVTUCBSC"] = formatter.getHex<uint32_t>(p_cvtmap->cvtucbsc);
  //cvt_json["CVTUNDVM"] = formatter.getHex<uint32_t>(p_cvtxtnt2->cvtundvm);
  cvt_json["CVTUSER"] = formatter.getHex<uint32_t>(p_cvtmap->cvtuser);
  cvt_json["CVTVERID"] = formatter.getHex<uint64_t>(p_cvtfix->cvtverid);
  cvt_json["CVTVFGET"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvfget);
  cvt_json["CVTVFIND"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvfind);
  cvt_json["CVTVPSIB"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvpsib);
  cvt_json["CVTVWAIT"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvwait);
  cvt_json["CVT0EF00"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0ef00);
  cvt_json["CVT0PT0E"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt0e);
  cvt_json["CVT0PT02"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt02);
  cvt_json["CVT0PT03"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt03);
  cvt_json["CVT0SCR1"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0scr1);


  std::string cvt_json_string = cvt_json.dump();
  std::cout << cvt_json_string << std::endl;

  return 0;
}


