set(SRC_DIR "../src")
set(OUTPUT_DIR "output/tests")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

add_library(file "${SRC_DIR}/file.cpp")

# Include the test_data directory into the build directory
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/test_data" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/")

# Add the test executables
add_executable(countBytes_test "${CMAKE_CURRENT_SOURCE_DIR}/countBytes_test.cpp")
target_link_libraries(countBytes_test PRIVATE file)

enable_testing()

add_test(
  NAME countBytes_test
  COMMAND $<TARGET_FILE:countBytes_test>
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)