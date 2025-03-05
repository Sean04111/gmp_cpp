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
aux_source_directory(./tests test_source)
enable_testing()

add_executable(
        ${TEST_NAME}
        ${test_source}
)

target_link_libraries(
        ${TEST_NAME}
        GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})

# project code
aux_source_directory(./src src_codes)
aux_source_directory(./include src_codes)
add_executable(
        ${bin_name}
        ${src_codes}
        include/scheduler.h
)