# Crear una biblioteca con el código MCTS
add_library(mcts
    mcts.cpp
    mcts.hpp
)

target_include_directories(mcts PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
