cmake_minimum_required(VERSION 2.6)

project(find)

set(BOOST_INCLUDEDIR /usr/local/boost_1_54_0)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

IF(NOT EXISTS ${BIN_DIR})
       FILE(MAKE_DIRECTORY ${BIN_DIR})
ENDIF(NOT EXISTS ${BIN_DIR})


set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})


add_executable(find src/find)

TARGET_LINK_LIBRARIES( find ${Boost_LIBRARIES} )

