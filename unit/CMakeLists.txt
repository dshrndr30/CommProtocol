cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
 
project(Unit_Test)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -std=c++11")

# get_filename_component(TEST_DIR ${CMAKE_SOURCE_DIR}/../. DIRECTORY)

include_directories(SYSTEM .)

set(VISIONARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/visionary/)

set(NGCP_UNIT_HEADERS 
  ${VISIONARY_DIR}/test.h)

set (NGCP_UNIT_SOURCES
  ${VISIONARY_DIR}/test.cc)

add_library(Visionary STATIC
  ${NGCP_UNIT_HEADERS} 
  ${NGCP_UNIT_SOURCES})
