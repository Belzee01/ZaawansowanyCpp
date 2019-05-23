cmake_minimum_required(VERSION 3.5.1)
project(test_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_1 tests_run.cpp DAGenerator.h DAGenerator.cpp InputBuilder.cpp InputBuilder.h Process.cpp Process.h Task.h TasksContainer.h Communication.cpp Communication.h OutputParser.h tests/communication_tests.cpp tests/dagenerator_tests.cpp tests/inputbuilder_tests.cpp tests/task_tests.cpp)

add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

target_link_libraries(test_1 gtest gtest_main)