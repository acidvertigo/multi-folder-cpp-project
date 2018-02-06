# Now simply link against gtest or gtest_main as needed. Eg
file(GLOB TEST_SRC_FILES *.cpp)

set(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/inc/ )

include_directories( ${INCLUDE_DIRS} )

add_executable(sharedt ${TEST_SRC_FILES})
target_link_libraries(sharedt shared gmock_main)
add_test(NAME shared_test COMMAND sharedt)

add_executable(statict ${TEST_SRC_FILES})
target_link_libraries(statict static gmock_main)
add_test(NAME static_test COMMAND statict)