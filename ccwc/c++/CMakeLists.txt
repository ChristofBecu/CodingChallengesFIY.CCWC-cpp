option(BUILD_TESTS "build tests" OFF)

cmake_minimum_required(VERSION 3.18)

project(ccwc
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "My c++ solution of Coding Challenge Build Your Own wc tool"
    HOMEPAGE_URL "https://codingchallenges.fyi/challenges/challenge-wc"
)

set(SRC_DIR "src")
set(INCLUDE_DIR "include")
set(OUTPUT_DIR "output")
set(TEST_DIR "tests")



include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})


set(MAIN_EXE "${PROJECT_NAME}")


add_executable(${MAIN_EXE} ${SOURCES})

# TESTS

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()



