#ifndef __CVT_H_
#define __CVT_H_

#include "control_block.hpp"

namespace CBXP {

class CVT : public ControlBlock {
 public:
  nlohmann::json get();
};

}  // namespace CBXP

#endif
