cmake_minimum_required(VERSION 3.14)
set(bin_name gmp_cpp)
project(${bin_name})

# requirements : Google Test
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# for unit tests
set(TEST_NAME gmp_test)
enable_testing()

add_executable(
        ${TEST_NAME}
        tests/orderedmap_test.cc
        tests/google_test.cc
        src/ordered_map.cpp
        include/scheduler.h
        include/routine.h
        include/thread.h
        include/pool.h
        include/common.h
)

target_link_libraries(
        ${TEST_NAME}
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

# project code
add_executable(
        ${bin_name}
        include/scheduler.h
        include/routine.h
        include/thread.h
        include/pool.h
        include/common.h
        src/ordered_map.cpp
)