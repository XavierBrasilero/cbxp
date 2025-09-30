#ifndef __ECVT_H_
#define __ECVT_H_

#include "control_block.hpp"

namespace CBXP {

class ECVT : public ControlBlock {
 public:
  nlohmann::json get();
};
}  // namespace CBXP
#endif
