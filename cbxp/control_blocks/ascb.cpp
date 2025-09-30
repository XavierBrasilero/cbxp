#include "ascb.hpp"

#include <cvt.h>
#include <ihaascb.h>
#include <ihapsa.h>

#include <asvt.hpp>
#include <cstdint>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "logger.hpp"

namespace CBXP {
nlohmann::json ASCB::get() {
  const struct psa* __ptr32 p_psa = 0;

  const struct cvtmap* __ptr32 p_cvtmap =
      // 'nullPointer' is a false positive because the PSA starts at address 0
      // cppcheck-suppress nullPointer
      static_cast<const struct cvtmap* __ptr32>(p_psa->flccvt);
  const asvt_t* __ptr32 p_asvt =
      static_cast<asvt_t* __ptr32>(p_cvtmap->cvtasvt);

  nlohmann::json ascb_json = {};

  ascb_json["ascbs"]       = std::vector<nlohmann::json>();
  std::vector<nlohmann::json>& ascbs =
      ascb_json["ascbs"].get_ref<std::vector<nlohmann::json>&>();
  ascbs.reserve(p_asvt->asvtmaxu);

  const uint32_t* __ptr32 p_ascb_addr =
      reinterpret_cast<const uint32_t* __ptr32>(&p_asvt->asvtenty);

  for (int i = 0; i < p_asvt->asvtmaxu; i++) {
    if (0x80000000 & *p_ascb_addr) {
      Logger::getInstance().debug(formatter_.getHex<uint32_t>(p_ascb_addr) +
                                  " is not a valid ASCB address");
      p_ascb_addr++;
      continue;
    }
    nlohmann::json ascb_entry_json = {};

    struct ascb* __ptr32 p_ascb =
        reinterpret_cast<struct ascb* __ptr32>(*p_ascb_addr);

    Logger::getInstance().debug("ASCB hex dump:");
    Logger::getInstance().hexDump(reinterpret_cast<const char*>(p_ascb),
                                  sizeof(struct ascb));

    ascb_entry_json["ascbasid"] = static_cast<uint32_t>(p_ascb->ascbasid);
    ascb_entry_json["ascbassb"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbassb));
    ascb_entry_json["ascbasxb"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbasxb));
    ascb_entry_json["ascbdcti"] = p_ascb->ascbdcti;
    ascb_entry_json["ascbejst"] = formatter_.getBitmap<uint64_t>(
        reinterpret_cast<const char*>(&p_ascb->ascbejst));
    ascb_entry_json["ascbflg3"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbflg3);
    ascb_entry_json["ascbfw3"] = formatter_.getBitmap<uint32_t>(
        reinterpret_cast<const char*>(&p_ascb->ascbfw3));
    ascb_entry_json["ascbjbni"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbjbni));
    ascb_entry_json["ascbjbns"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbjbns));
    ascb_entry_json["ascblsqe"] = p_ascb->ascblsqe;
    ascb_entry_json["ascblsqt"] = p_ascb->ascblsqt;
    ascb_entry_json["ascbnoft"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbnoft);
    ascb_entry_json["ascboucb"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascboucb));
    ascb_entry_json["ascbouxb"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbouxb));
    ascb_entry_json["ascbpo1m"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbpo1m);
    ascb_entry_json["ascbp1m0"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbp1m0);
    ascb_entry_json["ascbrsme"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbrsme));
    ascb_entry_json["ascbsdbf"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbsdbf);
    ascb_entry_json["ascbsrbt"] = formatter_.getBitmap<uint64_t>(
        reinterpret_cast<const char*>(&p_ascb->ascbsrbt));
    ascb_entry_json["ascbtcbe"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbtcbe);
    ascb_entry_json["ascbtcbs"] = p_ascb->ascbtcbs;
    ascb_entry_json["ascbxtcb"] =
        formatter_.getHex<uint32_t>(&(p_ascb->ascbxtcb));
    ascb_entry_json["ascbzcx"] =
        formatter_.getBitmap<uint32_t>(p_ascb->ascbzcx);
    ascbs.push_back(ascb_entry_json);
    p_ascb_addr++;  // This SHOULD increment the pointer by 4 bytes.
  }

  return ascb_json;
}
}  // namespace CBXP
