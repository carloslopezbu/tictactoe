# Crear una biblioteca con el código Policy
add_library(policy
    policy.cpp
    policy.hpp
)

target_include_directories(policy PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
