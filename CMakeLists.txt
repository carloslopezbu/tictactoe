cmake_minimum_required(VERSION 3.10)
project(tictactoe)

# Estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ruta a libtorch - cámbiala a tu sistema
set(Torch_DIR "/Users/more/libs/libtorch/share/cmake/Torch")

# Encuentra torch
find_package(Torch REQUIRED)

# Subcarpetas de tu proyecto
add_subdirectory(mcts)

# Ejecutable principal
add_executable(tictactoe main.cpp)
target_link_libraries(tictactoe PRIVATE mcts "${TORCH_LIBRARIES}")
target_compile_definitions(tictactoe PRIVATE -D_GLIBCXX_USE_CXX11_ABI=1)

# Incluye las cabeceras de torch
target_include_directories(tictactoe PRIVATE "${TORCH_INCLUDE_DIRS}")
