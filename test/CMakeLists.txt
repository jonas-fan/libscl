cmake_minimum_required(VERSION 2.8)

project(libscl-test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 -g")

# list
add_executable(list_test
    ./list_test.c
)

target_link_libraries(list_test
    ${TARGET_LIB}
)