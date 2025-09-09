#ifndef __ASVT_H_
#define __ASVT_H_

#include "control_block.hpp"

#pragma pack(push, 1)  // Don't byte align structure members.
typedef struct {
  char esvtprfx[464];
  uint32_t asvthwmasid;
  uint32_t asvtcurhighasid;
  char __ptr32* asvtreua;
  char __ptr32* asvtravl;
  uint32_t asvtaav;
  uint32_t asvtast;
  uint32_t asvtanr;
  uint32_t asvtstrt;
  uint32_t asvtnonr;
  uint32_t asvtmaxi;
  //ignored bitstring
  char asvtasvt[4];
  uint32_t  asvtmaxu;
  char __ptr32*  asvtfrst;
  // skipped this single bit
  char __ptr32*  asvtavai;
  // skipped ASVTAVAL ---> to bottom
} asvt_t;
#pragma pack(pop)  // Restore default structure packing options.

namespace CBXP {

class ASVT : public ControlBlock {
 public:
  nlohmann::json get();
};

}  // namespace CBXP

#endif
