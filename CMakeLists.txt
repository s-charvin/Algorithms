cmake_minimum_required(VERSION 3.23)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)
include_directories(.)

add_executable(algorithm
        main.cpp)
