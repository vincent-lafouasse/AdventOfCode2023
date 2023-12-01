cmake_minimum_required(VERSION 3.0)

project(AoC1)

set(CMAKE_CXX_STANDARD 17)

add_executable(p1 part1/main.cpp)
add_executable(p2 part2/main.cpp)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
