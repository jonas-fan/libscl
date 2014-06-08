cmake_minimum_required(VERSION 2.8)

project(test C)

set(CMAKE_C_FLAGS "-Wall -g -O2")

include_directories(${CMAKE_SOURCE_DIR}/c-simple-stl/include)

add_executable(test src/main.c)

target_link_libraries(test csstl)