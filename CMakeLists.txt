cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_COMPILER "ibm-clang++64")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./dist")

project(CBXP VERSION 0.0.1
             DESCRIPTION "A unified and standardized interface for extracting z/OS control block data."
             LANGUAGES C CXX)

file(GLOB CBXP_SRC "cbxp/*.cpp")

add_executable(cbxp ${CBXP_SRC})

target_include_directories(
    cbxp PUBLIC
    cbxp
    /usr/include/zos
)

target_compile_options(
    cbxp PUBLIC 
    -fzos-le-char-mode=ascii
    -Wno-trigraphs
)
