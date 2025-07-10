cmake_minimum_required(VERSION 3.10)
project(tictactoe)

# ✅ Habilita compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CUDA_ARCHITECTURES 75)
set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)

# Ruta al directorio de Torch
set(Torch_DIR "/usr/lib/libtorch/share/cmake/Torch")

# 🔧 Añadir manualmente el target CUDA::nvToolsExt
if(NOT TARGET CUDA::nvToolsExt)
    add_library(CUDA::nvToolsExt SHARED IMPORTED)
    set_target_properties(CUDA::nvToolsExt PROPERTIES
        IMPORTED_LOCATION "/usr/local/cuda/lib64/libnvToolsExt.so"
        INTERFACE_INCLUDE_DIRECTORIES "/usr/local/cuda/include"
    )
endif()

# Encuentra Torch
find_package(Torch REQUIRED)

# Subcarpeta con la librería MCTS
add_subdirectory(mcts)

# Ejecutable principal
add_executable(tictactoe main.cpp)
target_link_libraries(tictactoe PRIVATE mcts "${TORCH_LIBRARIES}" CUDA::nvToolsExt)
target_compile_definitions(tictactoe PRIVATE -D_GLIBCXX_USE_CXX11_ABI=1)
target_include_directories(tictactoe PRIVATE "${TORCH_INCLUDE_DIRS}")
