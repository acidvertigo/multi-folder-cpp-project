# Now simply link against gtest or gtest_main as needed. Eg
file(GLOB TEST_SRC_FILES *.cpp)

set(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/inc )

add_executable(sample ${TEST_SRC_FILES})
target_link_libraries(sample gmock_main)
add_test(NAME sample_test COMMAND sample)