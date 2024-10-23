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

include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

if(WIN32)
    set(MAIN_EXE "${PROJECT_NAME}.exe")
else()
    set(MAIN_EXE "${PROJECT_NAME}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

add_executable(${MAIN_EXE} ${SOURCES})


