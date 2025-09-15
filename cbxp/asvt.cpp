#include "asvt.hpp"
#include "logger.hpp"

#include <cvt.h>
#include <ihapsa.h>
#include <asvt.hpp>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

namespace CBXP {
nlohmann::json ASVT::get() {

struct psa *__ptr32 p_psa = 0;
struct cvtmap *__ptr32 p_cvtmap =
    static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
asvt_t *__ptr32 p_asvt = 
    static_cast<asvt_t *__ptr32>(p_cvtmap->cvtasvt);

Logger::getInstance().debug("Hex dump of ASVT data:");
Logger::getInstance().hexDump(reinterpret_cast<const char *>(p_asvt), sizeof(asvt_t));


  // Get fields
nlohmann::json asvt_json = {};
asvt_json["asvthwmasid"] = p_asvt->asvthwmasid;
asvt_json["asvtcurhighasid"] = p_asvt->asvtcurhighasid;
asvt_json["asvtreua"] = formatter_.getHex<uint32_t>(p_asvt->asvtreua);
asvt_json["asvtreua"] = formatter_.getHex<uint32_t>(p_asvt->asvtravl);
asvt_json["asvtaav"] = p_asvt->asvtaav;
asvt_json["asvtast"] = p_asvt->asvtast;
asvt_json["asvtanr"] = p_asvt->asvtanr;
asvt_json["asvtstrt"] = p_asvt->asvtstrt;
asvt_json["asvtnonr"] = p_asvt->asvtnonr;
asvt_json["asvtmaxi"] = p_asvt->asvtmaxi;
asvt_json["asvtasvt"] = formatter_.getString(p_asvt->asvtasvt, 4);
asvt_json["asvtmaxu"] = p_asvt->asvtmaxu;
asvt_json["asvtmdsc"] = p_asvt->asvtmdsc;
asvt_json["asvtfrst"] = formatter_.getHex<uint32_t>(p_asvt->asvtfrst);

Logger::getInstance().debug("Hex dump of ASVT ASCB pointers:");
Logger::getInstance().hexDump(p_asvt->asvtenty, p_asvt->asvtmaxu*4);

std::vector<std::string> ascbs;
ascbs.reserve(p_asvt->asvtmaxu);
uint32_t *__ptr32 p_ascb = reinterpret_cast<uint32_t *__ptr32>(&p_asvt->asvtenty);

for (int i = 0; i < p_asvt->asvtmaxu; i++) {
    ascbs.push_back(formatter_.getHex<uint32_t>(p_ascb));
    p_ascb++; // This SHOULD increment the pointer by 4 bytes.
}

asvt_json["asvtenty"] = ascbs;
return asvt_json;
}
}  // namespace CBXP

