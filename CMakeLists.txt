cmake_minimum_required(VERSION 3.1)

project(testy)

set(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage")

##
### Test definitions ###
##

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)

##
### Source definitions ###
##

include_directories("${PROJECT_SOURCE_DIR}/include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/students/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(testy ${sources})

set_target_properties(testy
        PROPERTIES
        COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
        LINK_FLAGS    "-lgcov --coverage"
        )

