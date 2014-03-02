cmake_minimum_required(VERSION 2.6)

project(Reverse)

IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_DEFINITIONS("-Wall")
ENDIF()

add_executable(Reverse src/reverse.cpp)