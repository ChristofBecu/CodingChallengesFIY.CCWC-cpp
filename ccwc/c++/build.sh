#!/bin/bash

# Get the directory of the script (where CMakeLists.txt is located)
SOURCE_DIR=$(cd "$(dirname "$0")" && pwd)

# Define the build directory
BUILD_DIR="$SOURCE_DIR/build"

# Define the output directory
OUTPUT_DIR="$SOURCE_DIR/output"

# Create the output directory if it doesn't exist
if [ ! -d "$OUTPUT_DIR" ]; then
    mkdir "$OUTPUT_DIR"
    echo "Created output directory: $OUTPUT_DIR"
fi

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
    echo "Created build directory: $BUILD_DIR"
fi

# Change to the build directory
cd "$BUILD_DIR" || { echo "Failed to change directory to $BUILD_DIR"; exit 1; }

# Run CMake to generate the build files
cmake ..

# Build the project
cmake --build .

# Get the name of the built executable
if [ "$(uname)" == "Darwin" ] || [ "$(uname)" == "Linux" ]; then
    EXECUTABLE_NAME="ccwc"
else
    EXECUTABLE_NAME="ccwc.exe"
fi

# Check if the executable exists in the output directory
if [ -f "$OUTPUT_DIR/$EXECUTABLE_NAME" ]; then
    echo "Executable found: $OUTPUT_DIR/$EXECUTABLE_NAME"
else
    echo "Executable not found!"
    exit 1
fi

# Clean up the build directory
cd "$SOURCE_DIR" || exit
rm -rf "$BUILD_DIR"
echo "Deleted build directory: $BUILD_DIR"

echo "Build and cleanup complete!"
