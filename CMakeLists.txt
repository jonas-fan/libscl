cmake_minimum_required(VERSION 2.8)

project(libscl C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c99")
set(INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install/)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
else ()
    if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
        if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
            set(CMAKE_BUILD_TYPE "Debug")
        endif ()
    endif ()
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif ()

set(HEADER ./src/vector.h ./src/list.h ./src/queue.h ./src/stack.h ./src/ring_buffer.h)
set(SOURCE ./src/vector.c ./src/list.c ./src/queue.c ./src/stack.c ./src/ring_buffer.c)

set(TARGET_LIB scl)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${TARGET_LIB} STATIC ${SOURCE})

install(FILES ${HEADER} DESTINATION ${INSTALL_DIR}/include)
install(TARGETS ${TARGET_LIB} DESTINATION ${INSTALL_DIR}/lib)

message("Build type: ${CMAKE_BUILD_TYPE}")
message("Install dir: ${INSTALL_DIR}")

add_subdirectory(test)