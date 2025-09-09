#include "asvt.hpp"

#include <cvt.h>
#include <ihapsa.h>
#include <asvt.hpp>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace CBXP {
nlohmann::json ASVT::get() {

  struct psa *__ptr32 p_psa = 0;
  struct cvtmap *__ptr32 p_cvtmap =
      static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  asvt_t *__ptr32 p_asvt = 
        static_cast<asvt_t *__ptr32>(p_cvtmap->cvtasvt);




  // Get fields
  nlohmann::json asvt_json = {};
  asvt_json["asvthwmasid"] = p_asvt->asvthwmasid;
  return asvt_json;
}
}  // namespace CBXP

