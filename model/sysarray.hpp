#ifndef SYSARRAY_HPP
#define SYSARRAY_HPP

#include <vector>
#include <cstdint>

#include "cell.hpp"

class SysArray {
    std::vector<std::vector<Cell>>  mesh{};
    std::vector<std::vector<uint32_t>> inputBuffer{};

public:
    SysArray(int n, int m);

    // Loggin util
    void logState();

    // Mesh operations
    void loadWeights(const std::vector<std::vector<uint32_t>>& weights);
    void initInputs(const std::vector<std::vector<uint32_t>> matrix);

};

#endif