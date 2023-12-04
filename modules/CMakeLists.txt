cmake_minimum_required(VERSION 3.5)

project(AoC1)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
add_compile_options(-g3)


add_library(string string/string.h string/split.cpp)

# LSP stuff, don't worry about it
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
