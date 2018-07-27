cmake_minimum_required(VERSION 2.8)

project(libscl C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c99 -g")
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/)
set(HEADER ./src/list.h)
set(SOURCE ./src/list.c)
set(TARGET_LIB scl)

add_library(${TARGET_LIB} STATIC ${SOURCE})

install(FILES ${HEADER} DESTINATION ${INSTALL_DIR}/include)
install(TARGETS ${TARGET_LIB} DESTINATION ${INSTALL_DIR}/lib)

message("Install directory: ${INSTALL_DIR}")

add_subdirectory(test)