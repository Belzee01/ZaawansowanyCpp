cmake_minimum_required(VERSION 3.5.1)
project(test_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_1 main.cpp DAGenerator.h DAGenerator.cpp InputBuilder.cpp InputBuilder.h Process.cpp Process.h Task.h TasksContainer.h Communication.cpp Communication.h OutputParser.h)