cmake_minimum_required(VERSION 2.8)

project(test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(vector_test
    ./vector_test.c
)

target_link_libraries(vector_test
    csstl
)

add_executable(list_test
    ./list_test.c
)

target_link_libraries(list_test
    csstl
)

add_executable(queue_test
    ./queue_test.c
)

target_link_libraries(queue_test
    csstl
)