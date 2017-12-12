cmake_minimum_required(VERSION 2.8.9)

set (CMAKE_CXX_STANDARD 11)

project(operation_lotto)

#Include headers files
include_directories(include)

#Source files
file(GLOB SOURCES "src/*.cpp")

add_executable(
    operation_lotto
    ${SOURCES}
)
