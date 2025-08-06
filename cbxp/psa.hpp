#ifndef __PSA_H_
#define __PSA_H_

#include "control_block.hpp"

namespace CBXP {

class PSA : public ControlBlock {
 public:
  nlohmann::json get();
};
}  // namespace CBXP
#endif
