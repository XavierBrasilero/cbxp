#ifndef __CONTROL_BLOCK_EXPLORER_H_
#define __CONTROL_BLOCK_EXPLORER_H_

#include <nlohmann/json.hpp>

static void show_usage(char *argv[]);

nlohmann::json explore_control_block(std::string control_block, bool debug);

#endif