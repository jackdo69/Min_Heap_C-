cmake_minimum_required(VERSION 3.7)
project(Assignment2Files)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Assignment2Tests.cpp
        Assignment2Test.h
        PriorityQueue.h)

add_executable(Assignment2Files ${SOURCE_FILES})