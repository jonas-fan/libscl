cmake_minimum_required(VERSION 2.8)

project(simple-container C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -std=c99")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(simplecontainer STATIC
    ./src/vector.c
    ./src/list.c
    ./src/list_element.c
    ./src/queue.c
    ./src/stack.c
)

add_subdirectory(test)