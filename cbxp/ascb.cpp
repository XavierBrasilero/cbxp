#include "ascb.hpp"

#include <cvt.h>
#include <ihapsa.h>

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace ASCB {
nlohmann::json ASCB::get() {
  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  struct cvtmap *__ptr32 p_cvtmap =
      static_cast<struct cvtmap *__ptr32>(p_psa->flccvt);
  struct cvtfix *__ptr32 p_cvtfix =
      static_cast<struct cvtfix *__ptr32>(p_psa->flccvt);
  struct cvtxtnt2 *__ptr32 p_cvtxtnt2 =
      static_cast<struct cvtxtnt2 *__ptr32>(p_psa->flccvt);
  struct cvtvstgx *__ptr32 p_cvtvstgx =
      static_cast<struct cvtvstgx *__ptr32>(p_psa->flccvt);

  // Get fields
  nlohmann::json cvt_json = {};

  cvt_json["cvtabend"]    = formatter_.getHex<uint32_t>(p_cvtmap->cvtabend);
 

  return cvt_json;
}
}  // namespace CBXP

