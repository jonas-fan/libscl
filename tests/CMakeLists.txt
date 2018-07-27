cmake_minimum_required(VERSION 2.8)

project(libsimplecntr-test C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -pedantic -std=c99 -g")

### list

add_executable(list_test list_test.c)
target_link_libraries(list_test ${OUTPUT_LIB})

add_executable(list_test_echo list_test_echo.c)
target_link_libraries(list_test_echo ${OUTPUT_LIB})

### vector

add_executable(vector_test vector_test.c)
target_link_libraries(vector_test ${OUTPUT_LIB})

add_executable(vector_test_echo vector_test_echo.c)
target_link_libraries(vector_test_echo ${OUTPUT_LIB})