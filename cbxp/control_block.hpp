#ifndef __CONTROL_BLOCK_H_
#define __CONTROL_BLOCK_H_

#include <nlohmann/json.hpp>

#include "control_block_field_formatter.hpp"

namespace CBXP {

class ControlBlock {
 protected:
  ControlBlockFieldFormatter formatter_;
};

}  // namespace CBXP

#endif
