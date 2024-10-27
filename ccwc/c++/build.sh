#!/bin/bash

set -e

SOURCE_DIR="."
BUILD_DIR="build"
BUILD_TESTS_OPTION="-DBUILD_TESTS=OFF"

showUsage() {
    echo "Usage: ./build.sh [OPTION]"
    echo 
    echo "Options:"
    echo "  -b | --build  build the project"
    echo "  -t | --test   build & test the project"
    echo "  -c | --clean  clean up the build artifacts"
    echo "  -h | --help   show this help"
}

clean() {
    echo "Cleaning build artifacts..."
    rm -rf build/
    echo "Clean complete."
}

build() {
    # Run CMake to configure and generate build files
    echo "Configuring the project..."
    cmake -S "$SOURCE_DIR" -B "$BUILD_DIR" $BUILD_TESTS_OPTION

    # Build the project
    echo "Building the project..."
    cmake --build "$BUILD_DIR"
}

test() {
    echo "Running tests..."
    cd "$BUILD_DIR"
    ctest -VV
}

if [ $# -eq 0 ]; then
    showUsage
    exit 0
fi

case "$1" in
    -h|--help)
        showUsage
        exit 0
        ;;
    -c|--clean)
        clean
        ;;
    -t|--test)
        BUILD_TESTS_OPTION="-DBUILD_TESTS=ON"
        build
        test
        ;;
    -b|--build)
        build
        ;;
    *) 
        echo "Unknown option: $1"
        exit 1
        ;;
esac
