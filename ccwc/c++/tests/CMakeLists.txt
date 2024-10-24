set(SRC_DIR "../src")
set(OUTPUT_DIR "output/tests")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

add_library(file "${SRC_DIR}/file.cpp")

find_package(GTest REQUIRED)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/test_data" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/")


add_executable(file_test "${CMAKE_CURRENT_SOURCE_DIR}/file_test.cpp")
target_link_libraries(file_test PRIVATE file GTest::GTest GTest::Main)


enable_testing()

add_test(
  NAME file_test
  COMMAND $<TARGET_FILE:file_test>
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
