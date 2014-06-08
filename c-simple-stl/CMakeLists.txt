cmake_minimum_required(VERSION 2.8)

project(c-simple-stl C)

set(CMAKE_C_FLAGS "-Wall -g -O2")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(csstl STATIC src/vector.c)