create_executable_project(LibQueue)
target_link_libraries(LibQueue gtest gtest_main)
add_test(NAME LibQueue COMMAND LibQueue)