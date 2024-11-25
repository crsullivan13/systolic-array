cmake_minimum_required(VERSION 3.5.0)
project(SysArrayModel VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SysArrayModel main.cpp cell.hpp cell.cpp)

include(CTest)
enable_testing()

