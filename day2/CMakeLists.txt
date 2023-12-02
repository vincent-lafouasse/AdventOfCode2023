cmake_minimum_required(VERSION 3.5)

project(AoC2)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)


add_executable(p1 p1/main.cpp p1/Hand.cpp p1/Hand.h)
add_executable(p2 p2/main.cpp)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
