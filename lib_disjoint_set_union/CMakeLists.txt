create_executable_project(LibDSU)
target_link_libraries(LibDSU gtest gtest_main)
add_test(NAME LibDSU COMMAND LibDSU)