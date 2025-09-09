#include "asvt.hpp"

#include <cvt.h>
#include <ihapsa.h>
#include <ihaasvt.h>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace CBXP {
nlohmann::json ASVT::get() {


    
  // Get fields
  nlohmann::json asvt_json = {};

  asvt_json[""] = formatter_.getBitmap<uint32_t>(p_asvt->asvtasid); 

  return asvt_json;
}
}  // namespace CBXP

