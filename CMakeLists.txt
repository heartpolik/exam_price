cmake_minimum_required(VERSION 3.4)
project(pricelist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(pricelist ${SOURCE_FILES})