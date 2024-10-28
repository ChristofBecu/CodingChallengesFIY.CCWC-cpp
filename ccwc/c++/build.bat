@echo off
setlocal

set SOURCE_DIR=.
set BUILD_DIR=build
set BUILD_TESTS_OPTION=-DBUILD_TESTS=OFF

:showUsage
echo Usage: build.bat [OPTION]
echo.
echo Options:
echo   -b ^| --build   build the project
echo   -t ^| --test    build & test the project
echo   -c ^| --clean   clean up the build artifacts
echo   -h ^| --help    show this help
goto :eof

:clean
echo Cleaning build artifacts...
rmdir /S /Q "%BUILD_DIR%"
echo Clean complete.
goto :eof

:build
echo Configuring the project...
cmake -S "%SOURCE_DIR%" -B "%BUILD_DIR%" %BUILD_TESTS_OPTION%

echo Building the project...
cmake --build "%BUILD_DIR%"
goto :eof

:test
echo Running tests...
cd "%BUILD_DIR%"
ctest -VV
cd ..
goto :eof

:: Main script logic
if "%~1"=="" (
    call :showUsage
    exit /b 0
)

if "%~1"=="-h" if "%~2"=="" (
    call :showUsage
    exit /b 0
)
if "%~1"=="--help" if "%~2"=="" (
    call :showUsage
    exit /b 0
)
if "%~1"=="-c" if "%~2"=="" (
    call :clean
    exit /b 0
)
if "%~1"=="--clean" if "%~2"=="" (
    call :clean
    exit /b 0
)
if "%~1"=="-t" if "%~2"=="" (
    set BUILD_TESTS_OPTION=-DBUILD_TESTS=ON
    call :build
    call :test
    exit /b 0
)
if "%~1"=="--test" if "%~2"=="" (
    set BUILD_TESTS_OPTION=-DBUILD_TESTS=ON
    call :build
    call :test
    exit /b 0
)
if "%~1"=="-b" if "%~2"=="" (
    call :build
    exit /b 0
)
if "%~1"=="--build" if "%~2"=="" (
    call :build
    exit /b 0
)

echo Unknown option: %~1
exit /b 1
