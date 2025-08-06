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

  ecvt_json["ecvtsplx"]    = formatter_.getString(p_ecvt->ecvtsplx, 8);
  ecvt_json["ecvtssds"]    = p_ecvt->ecvtssds;

  return ecvt_json;
}
}  // namespace CBXP
