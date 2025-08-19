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
  /*
  struct cvtfix *__ptr32 p_cvtfix =
      static_cast<struct cvtfix *__ptr32>(p_psa->flccvt);
  */
  // Get fields
  nlohmann::json ascb_json = {};

  ascb_json["psaaold"] = formatter_.getHex<uint32_t>(p_psa->psaaold);
 

  return ascb_json;
}
}  // namespace CBXP

