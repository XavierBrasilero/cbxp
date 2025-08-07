#include "ecvt.hpp"

#include <cvt.h>
#include <ihaecvt.h>
#include <ihapsa.h>
#include <unistd.h>

#include <cstdint>
#include <string>
#include <nlohmann/json.hpp>

namespace CBXP {
nlohmann::json ECVT::get() {
  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  // Get the address of the CVT from the PSA
  struct cvtmap *__ptr32 p_cvt =
      static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  // Get the address of the EVCT from the CVT
  struct ecvt *__ptr32 p_ecvt =
      static_cast<struct ecvt *__ptr32>(p_cvt->cvtecvt);

  // Get Fields
  nlohmann::json ecvt_json = {};

  ecvt_json["Sysplex Name: "] = formatter.getString(p_ecvt->ecvtsplx, 8);
  ecvt_json["ecvtssds"] = p_ecvt->ecvtssds;
  ecvt_json["ECVT_BoostInfo"] = formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo))+
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo+ 8)) +
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo+ 16));

  ecvt_json["ECVT_BoostInfo_V1"] = 
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v1))+
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v1+ 8)) +
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v1+ 16)) +
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v1+ 24));

  ecvt_json["ecvt_boostinfo_v2"] = 
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v2))+
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v2+ 8)) +
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v2+ 16)) +
                                formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_boostinfo_v2+ 24));

  ecvt_json["ecvt_cms_lockinst_addr"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_cms_lockinst_addr);
  ecvt_json["ecvt_customer_area_addr"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_customer_area_addr);
  ecvt_json["ecvt_enqdeq_cms_lockinst_addr"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_enqdeq_cms_lockinst_addr);
  ecvt_json["ecvt_getsrbidtoken"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_getsrbidtoken);
  ecvt_json["ecvt_installed_core_at_ipl"] = p_ecvt->ecvt_installed_core_at_ipl;
  ecvt_json["ecvt_installed_core_hwm"] = p_ecvt->ecvt_installed_core_hwm;
  ecvt_json["ecvt_installed_cpu_at_ipl"] = p_ecvt->ecvt_installed_cpu_at_ipl;
  ecvt_json["ecvt_installed_cpu_hwm"] = p_ecvt->ecvt_installed_cpu_hwm;
  ecvt_json["ecvt_latch_cms_lockinst_addr"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_latch_cms_lockinst_addr);
  //ecvt_json["ECVT_MAX_CPUMASKSIZEINBITS"] = ECVT_MAX_CPUMASKSIZEINBITS;
  //ecvt_json["ECVT_MAX_CPUMASKSIZEINBYTES"] = ECVT_MAX_CPUMASKSIZEINBYTES;
  //ecvt_json["ECVT_MAX_HIGHESTCPUID"] = ECVT_MAX_HIGHESTCPUID;
  ecvt_json["ecvt_osprotect"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_osprotect));
  ecvt_json["ecvt_osprotect_whensystem"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvt_osprotect_whensystem));
  ecvt_json["ecvt_smf_cms_lockinst_addr"] = formatter.getHex<uint32_t>(p_ecvt->ecvt_smf_cms_lockinst_addr);
  //ecvt_json["ECVT_ZOSR11_CPUMASKSIZEINBITS"] = ECVT_ZOSR11_CPUMASKSIZEINBITS;
  //ecvt_json["ECVT_ZOSR11_CPUMASKSIZEINBYTES"] = ECVT_ZOSR11_CPUMASKSIZEINBYTES;
  //ecvt_json["ECVT_ZOSR11_HIGHESTCPUID"] = ECVT_ZOSR11_HIGHESTCPUID;
  //ecvt_json["ECVT_ZOSV2R1_CPUMASKSIZEINBITS"] = ECVT_ZOSV2R1_CPUMASKSIZEINBITS;
  //ecvt_json["ECVT_ZOSV2R1_CPUMASKSIZEINBYTES"] = ECVT_ZOSV2R1_CPUMASKSIZEINBYTES;
  //ecvt_json["ECVT_ZOSV2R1_HIGHESTCPUID"] = ECVT_ZOSV2R1_HIGHESTCPUID;
  ecvt_json["ecvtalck"] = formatter.getHex<uint32_t>(p_ecvt->ecvtalck);
  ecvt_json["ecvtappc"] = formatter.getHex<uint32_t>(p_ecvt->ecvtappc);
  ecvt_json["ecvtappflags"] = formatter.getBitmap<uint32_t>(p_ecvt->ecvtappflags);
  ecvt_json["ecvtcachelinesize"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtcachelinesize));
  ecvt_json["ecvtcachelinestartbdy"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvtcachelinestartbdy));
  ecvt_json["ecvtclnu"] = formatter.getBitmap<uint32_t>(p_ecvt->ecvtclnu);
  ecvt_json["ecvtclon"] = formatter.getString(p_ecvt->ecvtclon, 2);
  ecvt_json["ecvtcrdt"] = formatter.getHex<uint32_t>(p_ecvt->ecvtcrdt);
  ecvt_json["ecvtcsm"] = formatter.getHex<uint32_t>(p_ecvt->ecvtcsm);
  ecvt_json["ecvtcsvn"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtcsvn));
  ecvt_json["ecvtctbl"] = formatter.getHex<uint32_t>(p_ecvt->ecvtctbl);
  ecvt_json["ecvtctb2"] = formatter.getHex<uint32_t>(p_ecvt->ecvtctb2);
  ecvt_json["ecvtdgnb"] = formatter.getHex<uint32_t>(p_ecvt->ecvtdgnb);
  ecvt_json["ecvtdlpf"] = formatter.getHex<uint32_t>(p_ecvt->ecvtdlpf);
  ecvt_json["ecvtdlpl"] = formatter.getHex<uint32_t>(p_ecvt->ecvtdlpl);
  //ecvt_json["ecvtdpqh"] = formatter.getHex<uint32_t>(p_ecvt->ecvtdpqh); ---> Protection Exception
  ecvt_json["ecvtducu"] = formatter.getHex<uint32_t>(p_ecvt->ecvtducu);
  ecvt_json["ecvtfacl"] = formatter.getHex<uint32_t>(p_ecvt->ecvtfacl);
  ecvt_json["ecvtflg1"] = formatter.getBitmap<uint32_t>(p_ecvt->ecvtflg1);
  ecvt_json["ecvtgmod"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvtgmod));
  ecvt_json["ecvthdnm"] = formatter.getString(p_ecvt->ecvthdnm, 8);
  ecvt_json["ecvtipa"] = formatter.getHex<uint32_t>(p_ecvt->ecvtipa);
  ecvt_json["ecvtjaof"] = formatter.getHex<uint32_t>(p_ecvt->ecvtjaof);
  ecvt_json["ecvtldto"] = formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvtldto)) + 
                          formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvtldto+8));
  ecvt_json["ecvtlogicaltophysicalmask"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtlogicaltophysicalmask));
  ecvt_json["ecvtlpdelen"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvtlpdelen));
  ecvt_json["ecvtlpnm"] = formatter.getString(p_ecvt->ecvtlpnm, 8);
  ecvt_json["ecvtlsab"] = formatter.getHex<uint32_t>(p_ecvt->ecvtlsab);
  ecvt_json["ecvtlsen"] = formatter.getHex<uint32_t>(p_ecvt->ecvtlsen);
  ecvt_json["ecvtlso"] = formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvtlso)) + 
                         formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvtlso+8));
  ecvt_json["ecvtmaxcoreid"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtmaxcoreid));
  ecvt_json["ecvtmaxmpnumbytesinmask"] = p_ecvt->ecvtmaxmpnumbytesinmask;
  ecvt_json["ecvtnumcpuidsincore"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtnumcpuidsincore));
  ecvt_json["ecvtocvt"] = formatter.getHex<uint32_t>(p_ecvt->ecvtocvt);
  ecvt_json["ecvtoext"] = formatter.getHex<uint32_t>(p_ecvt->ecvtoext);
  ecvt_json["ecvtomvs"] = formatter.getBitmap<uint32_t>(p_ecvt->ecvtomvs);
  ecvt_json["ecvtpdvl"] = formatter.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_ecvt->ecvtpdvl));
  ecvt_json["ecvtphysicaltologicalmask"] = formatter.getBitmap<uint16_t>(reinterpret_cast<char *>(&p_ecvt->ecvtphysicaltologicalmask));
  ecvt_json["ecvtpidn"] = formatter.getString(p_ecvt->ecvtpidn, 8);
  ecvt_json["ecvtpmod"] = formatter.getString(p_ecvt->ecvtpmod, 2);
  ecvt_json["ecvtpnam"] = formatter.getString(p_ecvt->ecvtpnam, 16);
  ecvt_json["ecvtpown"] = formatter.getString(p_ecvt->ecvtpown, 16);
  ecvt_json["ecvtprel"] = formatter.getString(p_ecvt->ecvtprel, 2);
  ecvt_json["ecvtpseq"] = p_ecvt->ecvtpseq;
  ecvt_json["ecvtpver"] = formatter.getString(p_ecvt->ecvtpver, 2);
  ecvt_json["ecvtslid"] = formatter.getBitmap<uint32_t>(reinterpret_cast<char *>(&p_ecvt->ecvtslid));
  ecvt_json["ecvtsplx"] = formatter.getString(p_ecvt->ecvtsplx, 8);
  ecvt_json["ecvtsrbj"] = formatter.getHex<uint32_t>(p_ecvt->ecvtsrbj);
  ecvt_json["ecvtsrbl"] = formatter.getHex<uint32_t>(p_ecvt->ecvtsrbl);
  ecvt_json["ecvtsxmp"] = formatter.getHex<uint32_t>(p_ecvt->ecvtsxmp);
  ecvt_json["ecvtsymt"] = formatter.getHex<uint32_t>(p_ecvt->ecvtsymt);
  ecvt_json["ecvttcp"] = formatter.getHex<uint32_t>(p_ecvt->ecvttcp);
  ecvt_json["ecvtvmnm"] = formatter.getBitmap<uint64_t>(reinterpret_cast<char *>(&p_ecvt->ecvtvmnm));
  ecvt_json["ecvtvser"] = formatter.getBitmap<uint32_t>(reinterpret_cast<char *>(&p_ecvt->ecvtvser));
  ecvt_json["ecvtxtsw"] = formatter.getHex<uint32_t>(p_ecvt->ecvtxtsw);

  return ecvt_json;
}
}  // namespace CBXP
