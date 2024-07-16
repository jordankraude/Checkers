cmake_minimum_required(VERSION 3.10)
project(Checkers)

set(CMAKE_CXX_STANDARD 11)

add_executable(checkers main.cpp Board.cpp Piece.cpp Game.cpp)
