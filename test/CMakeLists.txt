cmake_minimum_required(VERSION 2.8)

project(test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -std=c99")

add_definitions("-D_GNU_SOURCE")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(vector_test
    ./vector_test.c
)

target_link_libraries(vector_test
    simplecontainer
)

add_executable(list_test
    ./list_test.c
)

target_link_libraries(list_test
    simplecontainer
)

add_executable(queue_test
    ./queue_test.c
)

target_link_libraries(queue_test
    simplecontainer
)

add_executable(stack_test
    ./stack_test.c
)

target_link_libraries(stack_test
    simplecontainer
)