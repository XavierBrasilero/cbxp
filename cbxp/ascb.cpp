#include "ascb.hpp"
#include "logger.hpp"

#include <cvt.h>
#include <ihapsa.h>
#include <ihaascb.h>
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace CBXP {
nlohmann::json ASCB::get() {

  // PSA starts at address 0
  struct psa *__ptr32 p_psa = 0;
  struct ascb *__ptr32 p_ascb =
      static_cast<struct ascb *__ptr32>(p_psa->psaaold);

  Logger::getInstance().debug("Hex dump of ASCB data:");
  Logger::getInstance().hexDump(reinterpret_cast<const char *>(p_ascb), sizeof(ascb));

  // Get fields
  nlohmann::json ascb_json = {};

  //Next one will talk w Team
  ascb_json["ascbasid"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbasid); 
  ascb_json["ascbassb"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbassb));
  ascb_json["ascbasxb"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbasxb));
  ascb_json["ascbdcti"] = p_ascb->ascbdcti;
  ascb_json["ascbejst"] = formatter_.getBitmap<uint64_t>(
      reinterpret_cast<char *>(&p_ascb->ascbejst));
  ascb_json["ascbflg3"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbflg3);
  ascb_json["ascbfw3"] = formatter_.getBitmap<uint32_t>(
      reinterpret_cast<char *>(&p_ascb->ascbfw3));
  ascb_json["ascbjbni"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbjbni));
  ascb_json["ascbjbns"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbjbns));
  ascb_json["ascblsqe"] = p_ascb->ascblsqe;
  ascb_json["ascblsqt"] = p_ascb->ascblsqt;
  ascb_json["ascbnoft"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbnoft);
  ascb_json["ascboucb"] = formatter_.getHex<uint32_t>(&(p_ascb->ascboucb));
  ascb_json["ascbouxb"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbouxb));
  ascb_json["ascbpo1m"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbpo1m);
  ascb_json["ascbp1m0"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbp1m0);
  ascb_json["ascbrsme"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbrsme));
  ascb_json["ascbsdbf"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbsdbf);
  ascb_json["ascbsrbt"] = formatter_.getBitmap<uint64_t>(
      reinterpret_cast<char *>(&p_ascb->ascbsrbt));
  ascb_json["ascbtcbe"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbtcbe);
  ascb_json["ascbtcbs"] = p_ascb->ascbtcbs;
  ascb_json["ascbxtcb"] = formatter_.getHex<uint32_t>(&(p_ascb->ascbxtcb));
  ascb_json["ascbzcx"] = formatter_.getBitmap<uint32_t>(p_ascb->ascbzcx);




  return ascb_json;
}
}  // namespace CBXP

