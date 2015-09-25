cmake_minimum_required(VERSION 2.8)

project(simple-container C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O2 -Wall -Wextra -std=gnu99 -pedantic")
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

set(HEADER ./include/vector.h ./include/list.h ./include/queue.h ./include/stack.h)
set(SOURCE ./src/vector.c ./src/list.c ./src/queue.c ./src/stack.c)

set(TARGET_LIB simplecontainer)
set(TARGET_LIB_STATIC ${TARGET_LIB}_static)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${TARGET_LIB} SHARED ${SOURCE})
add_library(${TARGET_LIB_STATIC} STATIC ${SOURCE})

install(FILES ${HEADER} DESTINATION ${INSTALL_DIR}/include)
install(TARGETS ${TARGET_LIB} ${TARGET_LIB_STATIC} DESTINATION ${INSTALL_DIR}/lib)

add_subdirectory(test)