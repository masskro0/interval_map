cmake_minimum_required(VERSION 3.26)
project(interval_map)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

find_package(GTest REQUIRED)
enable_testing()

add_executable(interval_map main.cpp)

target_link_libraries(
  interval_map
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(interval_map)