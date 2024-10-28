cmake_minimum_required(VERSION 3.18)

project(ccwc
    VERSION 1.0
    LANGUAGES CXX
    DESCRIPTION "My C++ solution of Coding Challenge Build Your Own wc tool"
    HOMEPAGE_URL "https://codingchallenges.fyi/challenges/challenge-wc"
)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source directories
set(SRC_DIR "src")
set(INCLUDE_DIR "include")
set(OUTPUT_DIR "output")
set(TEST_DIR "tests")

# Include directories
include_directories(${INCLUDE_DIR})

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

# Add platform-specific flags
if(WIN32)
    target_compile_definitions(${MAIN_EXE} PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Gather source files
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Main executable
set(MAIN_EXE "${PROJECT_NAME}")
add_executable(${MAIN_EXE} ${SOURCES})

# Tests
option(BUILD_TESTS "Build tests" OFF)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_TESTS ON CACHE BOOL "Enable tests by default for Debug builds" FORCE)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()
