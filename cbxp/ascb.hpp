#ifndef __ASCB_H_
#define __ASCB_H_

#include "control_block.hpp"

namespace CBXP {

class ASCB : public ControlBlock {
 public:
  nlohmann::json get();
};

}  // namespace CBXP

#endif
