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
  struct cvtvstgx *__ptr32 p_cvtvstgx = static_cast<struct cvtvstgx *__ptr32>(p_psa->flccvt);
  
  // Get fields
  nlohmann::json cvt_json = {};

  cvt_json["cvtabend"] = formatter.getHex<uint32_t>(p_cvtmap->cvtabend);
  cvt_json["cvtamff"] = formatter.getHex<uint32_t>(p_cvtmap->cvtamff);
  cvt_json["cvtasmvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtasmvt);
  cvt_json["cvtasvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtasvt);
  cvt_json["cvtbret"] = formatter.getHex<uint16_t>(p_cvtmap->cvtbret);
  cvt_json["cvtbsm0f"] = formatter.getHex<uint16_t>(p_cvtmap->cvtbsm0f);
  cvt_json["cvtcsd"] = formatter.getHex<uint32_t>(p_cvtmap->cvtcsd);
  cvt_json["cvtctlfg"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtctlfg));
  cvt_json["cvtdcb"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtdcb));
  cvt_json["cvtdcpa"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtdcpa);
  cvt_json["cvtdfa"] = formatter.getHex<uint32_t>(p_cvtmap->cvtdfa);
  cvt_json["cvtecvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtecvt);
  cvt_json["cvtedat2"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtedat2);
  cvt_json["cvteplps"] = formatter.getHex<uint32_t>(p_cvtvstgx->cvteplps);
  cvt_json["cvtexit"] = formatter.getHex<uint16_t>(p_cvtmap->cvtexit);
  cvt_json["cvtexp1"] = formatter.getHex<uint32_t>(p_cvtmap->cvtexp1);
  cvt_json["cvtflag2"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag2);
  cvt_json["cvtflag3"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag3);
  cvt_json["cvtflag4"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag4);
  cvt_json["cvtflag5"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag5);
  cvt_json["cvtflag6"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag6);
  cvt_json["cvtflag7"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtflag7);
  cvt_json["cvtflag9"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_cvtmap->cvtflag9));
  cvt_json["cvtflgbt"] = formatter.getBitmap<uint32_t>(p_cvtxtnt2->cvtflgbt);
  cvt_json["cvtgda"] = formatter.getHex<uint32_t>(p_cvtmap->cvtgda);
  cvt_json["cvtgrsst"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtgrsst);
  cvt_json["cvtgvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtgvt);
  cvt_json["cvthid"] = formatter.getHex<uint32_t>(p_cvtmap->cvthid);
  cvt_json["cvtixavl"] = formatter.getHex<uint32_t>(p_cvtmap->cvtixavl);
  cvt_json["cvtjesct"] = formatter.getHex<uint32_t>(p_cvtmap->cvtjesct);
  cvt_json["cvtlccat"] = formatter.getHex<uint32_t>(p_cvtmap->cvtlccat);
  cvt_json["cvtldto"] = formatter.getHex<uint64_t>(p_cvtxtnt2->cvtldto);
  cvt_json["cvtlink"] = formatter.getHex<uint32_t>(p_cvtmap->cvtlink);
  cvt_json["cvtlso"] = formatter.getHex<uint64_t>(p_cvtxtnt2->cvtlso);
  cvt_json["cvtmaxmp"] = p_cvtmap->cvtmaxmp;
  cvt_json["cvtmdl"] = formatter.getHex<uint16_t>(p_cvtfix->cvtmdl);
  cvt_json["cvtmser"] = formatter.getHex<uint32_t>(p_cvtmap->cvtmser);
  cvt_json["cvtopctp"] = formatter.getHex<uint32_t>(p_cvtmap->cvtopctp);
  cvt_json["cvtoslvl"] = formatter.getHex<uint64_t>(p_cvtmap->cvtoslvl) + formatter.getHex<uint64_t>(p_cvtmap->cvtoslvl+8);
  cvt_json["cvtover"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtover);
  cvt_json["cvtpccat"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpccat);
  cvt_json["cvtpcnvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpcnvt);
  cvt_json["cvtprltv"] = formatter.getHex<uint32_t>(p_cvtmap->cvtprltv);
  cvt_json["cvtprod"] = formatter.getHex<uint64_t>(p_cvtfix->cvtprod) + formatter.getHex<uint64_t>(p_cvtfix->cvtprod+8);
  cvt_json["cvtpsxm"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpsxm);
  cvt_json["cvtpvtp"] = formatter.getHex<uint32_t>(p_cvtmap->cvtpvtp);
  cvt_json["cvtqtd00"] = formatter.getHex<uint32_t>(p_cvtmap->cvtqtd00);
  cvt_json["cvtqte00"] = formatter.getHex<uint32_t>(p_cvtmap->cvtqte00);
  cvt_json["cvtrac"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrac);
  cvt_json["cvtrcep"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrcep);
  cvt_json["cvtrczrt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrczrt);
  cvt_json["cvtrelno"] = formatter.getHex<uint32_t>(p_cvtfix->cvtrelno);
  cvt_json["cvtri"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtri);
  cvt_json["cvtrtmct"] = formatter.getHex<uint32_t>(p_cvtmap->cvtrtmct);
  cvt_json["cvtsaf"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsaf);
  cvt_json["cvtscpin"] = formatter.getHex<uint32_t>(p_cvtmap->cvtscpin);
  //cvt_json["cvtsdbf"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtsdbf);
  cvt_json["cvtsdump"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtsdump);
  cvt_json["cvtsmca"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsmca);
  cvt_json["cvtsname"] = formatter.getString(p_cvtmap->cvtsname, 8);
  cvt_json["cvtsubsp"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvtsubsp);
  cvt_json["cvtsvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsvt);
  cvt_json["cvtsysad"] = formatter.getHex<uint32_t>(p_cvtmap->cvtsysad);
  cvt_json["cvttpc"] = formatter.getHex<uint32_t>(p_cvtmap->cvttpc);
  cvt_json["cvttvt"] = formatter.getHex<uint32_t>(p_cvtmap->cvttvt);
  cvt_json["cvttx"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvttx);
  cvt_json["cvttxc"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvttxc);
  cvt_json["cvttxte"] = formatter.getBitmap<uint32_t>(p_cvtmap->cvttxte);
  cvt_json["cvttz"] = p_cvtmap->cvttz;
  cvt_json["cvtucbsc"] = formatter.getHex<uint32_t>(p_cvtmap->cvtucbsc);
  cvt_json["cvtundvm"] = formatter.getBitmap<uint32_t>(p_cvtxtnt2->cvtundvm);
  cvt_json["cvtuser"] = formatter.getHex<uint32_t>(p_cvtmap->cvtuser);
  cvt_json["cvtverid"] = formatter.getHex<uint64_t>(p_cvtfix->cvtverid);
  cvt_json["cvtvfget"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvfget);
  cvt_json["cvtvfind"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvfind);
  cvt_json["cvtvpsib"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvpsib);
  cvt_json["cvtvwait"] = formatter.getHex<uint32_t>(p_cvtmap->cvtvwait);
  cvt_json["cvt0ef00"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0ef00);
  cvt_json["cvt0pt0e"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt0e);
  cvt_json["cvt0pt02"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt02);
  cvt_json["cvt0pt03"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0pt03);
  cvt_json["cvt0scr1"] = formatter.getHex<uint32_t>(p_cvtmap->cvt0scr1);

  std::string cvt_json_string = cvt_json.dump();
  std::cout << cvt_json_string << std::endl;

  return 0;
}


