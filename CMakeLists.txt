cmake_minimum_required(VERSION 3.17)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sudoku src/main.cpp src/Game.cpp src/set_args.cpp)