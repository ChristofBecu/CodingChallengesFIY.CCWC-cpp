import os
import shutil
import subprocess
import sys
from pathlib import Path

# Configuration
SOURCE_DIR = Path(".")
BUILD_DIR = Path("build")
BUILD_TESTS_OPTION = "-DBUILD_TESTS=OFF"

def show_usage():
    print("Usage: python build.py [OPTION]")
    print()
    print("Options:")
    print("  -b | --build   build the project")
    print("  -t | --test    build & test the project")
    print("  -c | --clean   clean up the build artifacts")
    print("  -h | --help    show this help")

def clean():
    print("Cleaning build artifacts...")
    if BUILD_DIR.exists():
        shutil.rmtree(BUILD_DIR)
    print("Clean complete.")

def build():
    # Configure the project
    print("Configuring the project...")
    subprocess.run(["cmake", "-S", str(SOURCE_DIR), "-B", str(BUILD_DIR), BUILD_TESTS_OPTION], check=True)
    
    # Build the project
    print("Building the project...")
    subprocess.run(["cmake", "--build", str(BUILD_DIR)], check=True)

def run_tests():
    print("Running tests...")
    subprocess.run(["ctest", "-VV"], cwd=BUILD_DIR, check=True)

def main():
    global BUILD_TESTS_OPTION
    
    # Check for arguments
    if len(sys.argv) < 2:
        show_usage()
        return

    option = sys.argv[1]
    
    if option in ("-h", "--help"):
        show_usage()
    elif option in ("-c", "--clean"):
        clean()
    elif option in ("-t", "--test"):
        BUILD_TESTS_OPTION = "-DBUILD_TESTS=ON"
        build()
        run_tests()
    elif option in ("-b", "--build"):
        build()
    else:
        print(f"Unknown option: {option}")
        sys.exit(1)

if __name__ == "__main__":
    main()
