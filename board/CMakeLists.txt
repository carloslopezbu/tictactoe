# Crear una biblioteca con el código Board
add_library(board
    board.cpp
    board.hpp
)

target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
