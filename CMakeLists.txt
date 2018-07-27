cmake_minimum_required(VERSION 2.8)

project(libsimplecntr C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c99 -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)

set(OUTPUT_LIB simplecntr)
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/)

add_subdirectory(lib)
add_subdirectory(tests)

message("Install directory: ${INSTALL_DIR}")