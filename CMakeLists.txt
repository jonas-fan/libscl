cmake_minimum_required(VERSION 2.8)

project(libscl C)

### build configuration

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c99 -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)

set(HEADER "")
set(SOURCE "")
set(OUTPUT_LIB scl)
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/)

add_subdirectory(src)
add_library(${OUTPUT_LIB} STATIC ${SOURCE})

### tests

add_subdirectory(test)

### installation

message("Install directory: ${INSTALL_DIR}")

install(FILES ${HEADER} DESTINATION ${INSTALL_DIR}/include)
install(TARGETS ${OUTPUT_LIB} ARCHIVE DESTINATION ${INSTALL_DIR}/lib)