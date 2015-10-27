cmake_minimum_required(VERSION 2.8)

project(test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -std=c99")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../bin/test)

add_definitions("-D_GNU_SOURCE")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(vector_test
    ./vector_test.c
)

target_link_libraries(vector_test
    ${TARGET_LIB_STATIC}
)

add_executable(list_test
    ./list_test.c
)

target_link_libraries(list_test
    ${TARGET_LIB_STATIC}
)

add_executable(queue_test
    ./queue_test.c
)

target_link_libraries(queue_test
    ${TARGET_LIB_STATIC}
)

add_executable(stack_test
    ./stack_test.c
)

target_link_libraries(stack_test
    ${TARGET_LIB_STATIC}
)

add_executable(ring_buffer_test
    ./ring_buffer_test.c
)

target_link_libraries(ring_buffer_test
    ${TARGET_LIB_STATIC}
    pthread
)