# Crear una biblioteca con el código Node
add_library(node
    node.cpp
    node.hpp
)

target_include_directories(node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
