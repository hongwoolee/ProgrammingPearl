cmake_minimum_required(VERSION 2.6)

project(Rotate)

IF(CMAKE_COMPILER_IS_GNUCXX)
    ADD_DEFINITIONS("-Wall")
ENDIF()

add_executable(Rotate src/rotate.cpp)