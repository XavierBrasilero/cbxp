#ifndef __CONTROL_BLOCK_EXPLORER_H_
#define __CONTROL_BLOCK_EXPLORER_H_

#include <nlohmann/json.hpp>

#include "cbxp.h"

namespace CBXP {
    class ControlBlockExplorer {
        private:
            bool _debug;
            cbxp_result_t* _p_result;
        public:
            ControlBlockExplorer(cbxp_result_t* cbxp_result, bool debug);
            void explore_control_block(std::string control_block_name);
    };
} //namespace CBXP

#endif
