cmake_minimum_required(VERSION 3.17)
project(UTforLab7)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
 add_subdirectory(src)
include_directories(src)

file(GLOB tests "tests/*.cpp")
add_executable(UTforLab7 ${tests})
target_link_libraries(UTforLab7 src gtest gtest_main )

