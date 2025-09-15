#include "psa.hpp"
#include "logger.hpp"

#include <ihapsa.h>

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace CBXP {
nlohmann::json PSA::get() {
  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;

  Logger::getInstance().debug("Hex dump of PSA data:");
  Logger::getInstance().hexDump(reinterpret_cast<const char *>(p_psa), sizeof(psa)/2); //Only the first "page" of the PSA is not fetch-protected

  // Get fieldsß
  nlohmann::json psa_json = {};
  psa_json["psapsa"]      = formatter_.getString(p_psa->psapsa, 4);
  psa_json["flcsvilc"]    = static_cast<int16_t>(p_psa->flcsvilc);
  psa_json["flcrnpsw_bitstring"] =
      formatter_.getBitmap<uint32_t>(p_psa->flcrnpsw);
  psa_json["flcrnpsw_hex"] = formatter_.getHex<uint32_t>(p_psa->flcrnpsw + 4);
  psa_json["flccvt"]       = formatter_.getHex<uint32_t>(p_psa->flccvt);
  psa_json["flcsopsw"]     = formatter_.getPswSmall(p_psa->flcsopsw);
  psa_json["flcarch"] =
      formatter_.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->flcarch));
  psa_json["flccvt64"] = formatter_.getHex<uint64_t>(p_psa->flccvt64);
  psa_json["flcfacl"]  = formatter_.getBitmap<uint64_t>(p_psa->flcfacl) +
                        formatter_.getBitmap<uint64_t>(p_psa->flcfacl + 8);
  psa_json["flcfacle"] = formatter_.getBitmap<uint64_t>(p_psa->flcfacle) +
                         formatter_.getBitmap<uint64_t>(p_psa->flcfacle + 8);
  psa_json["psaaold"] = formatter_.getHex<uint32_t>(p_psa->psaaold);
  psa_json["psaecvt"] = formatter_.getHex<uint64_t>(p_psa->psaecvt);
  psa_json["psaflags"] =
      formatter_.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psaflags));
  psa_json["psafpfl"] =
      formatter_.getBitmap<uint8_t>(reinterpret_cast<char *>(&p_psa->psafpfl));
  psa_json["psalaa"]   = formatter_.getHex<uint32_t>(p_psa->psalaa);
  psa_json["psalccav"] = formatter_.getHex<uint32_t>(&p_psa->psalccav);
  psa_json["psatold"]  = formatter_.getHex<uint32_t>(p_psa->psatold);
  psa_json["psatrvt"]  = formatter_.getHex<uint32_t>(p_psa->psatrvt);
  psa_json["psaval"]   = formatter_.getBitmap<uint16_t>(p_psa->psaval);
  psa_json["psaxcvt"]  = formatter_.getHex<uint64_t>(p_psa->psaxcvt);

  return psa_json;
}
}  // namespace CBXP
