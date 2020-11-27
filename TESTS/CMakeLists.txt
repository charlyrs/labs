cmake_minimum_required(VERSION 3.16)
project(ufff)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "tests/*.cpp")

add_executable(ufff ${tests})

target_link_libraries(ufff src gtest gtest_main)