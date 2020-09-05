cmake_minimum_required(VERSION 3.5.1)

project(modulo)

set(EXEC modulo)

set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

file(GLOB SOURCES src/*.cpp)

add_executable(${EXEC} ${SOURCES})
