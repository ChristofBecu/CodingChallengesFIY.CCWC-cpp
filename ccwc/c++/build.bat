@echo off
setlocal

rem Get the source directory (where CMakeLists.txt is located)
set SOURCE_DIR=%~dp0
set BUILD_DIR=%SOURCE_DIR%build
set OUTPUT_DIR=%SOURCE_DIR%output

rem Create the output directory if it doesn't exist
if not exist "%OUTPUT_DIR%" (
    mkdir "%OUTPUT_DIR%"
    echo Created output directory: %OUTPUT_DIR%
)

rem Create the build directory if it doesn't exist
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
    echo Created build directory: %BUILD_DIR%
)

rem Change to the build directory
cd "%BUILD_DIR%"

rem Run CMake to generate the build files
cmake ..

rem Build the project
cmake --build .

rem Get the name of the built executable
set EXECUTABLE_NAME=ccwc.exe

rem Check if the executable exists in the build directory
if exist "%BUILD_DIR%\%EXECUTABLE_NAME%" (
    rem Move the executable to the output directory
    move "%BUILD_DIR%\%EXECUTABLE_NAME%" "%OUTPUT_DIR%"
    echo Moved executable to %OUTPUT_DIR%
) else (
    echo Executable not found!
    exit /b 1
)

rem Clean up the build directory
cd "%SOURCE_DIR%"
rmdir /s /q "%BUILD_DIR%"
echo Deleted build directory: %BUILD_DIR%

echo Build and cleanup complete!
endlocal
