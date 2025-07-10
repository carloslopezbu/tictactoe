#include <iostream>
#include "mcts/mcts.hpp"
#include "policy/policy.hpp"
#include <torch/torch.h>
#include <iostream>


int main() {
    // Usa CUDA si está disponible, si no, CPU
    torch::Device device(torch::cuda::is_available() ? torch::kCUDA : torch::kCPU);

    std::cout << "Usando dispositivo: " << (device.is_cuda() ? "CUDA" : "CPU") << std::endl;

    // Crear un tensor en ese dispositivo
    torch::Tensor tensor = torch::rand({3, 3}, device);

    std::cout << tensor << std::endl;

    return 0;
}
