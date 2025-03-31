#include "sysarray.hpp"
#include <iostream>

// Initalize systolic mesh with n x m cell elements
// Cell elements init all values to zero
SysArray::SysArray(int n, int m) {
    for ( int i = 0 ; i < n; i++ ) {
        std::vector<Cell> temp;
        for ( int j = 0; j < m; j++ ) {
            temp.push_back(Cell());
        }
        mesh.push_back(temp);
    }
}

// Pretty print state of entire mesh
// Each cell gets a, b, and storage printed, in that order
void SysArray::logState() {
    for ( auto row : mesh ) {
        std::cout << "| ";
        for ( auto cell : row ) {
            std::cout << "a:" << cell.get_a() << ", " << "b:" << cell.get_b() << ", " << "s:" << cell.get_storage() << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for ( auto row : inputBuffer ) {
        std::cout << "| ";
        for ( auto input : row ) {
            std::cout << input << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Loads weights for weight stationary matrix
void SysArray::loadWeights(const std::vector<std::vector<uint32_t>>& weights) {
    if ( weights.size() != mesh.size() ) {
        throw std::invalid_argument("Weights row dimension doesn't match mesh");
    }

    for ( int i = 0; i < mesh.size(); i++ ) {
        if ( weights[i].size() != mesh[i].size() ) {
            throw std::invalid_argument("Weights column dimension doesn't match mesh");
        }

        for ( int j = 0; j < mesh[i].size(); j++ ) {
            mesh[i][j].inp_storage(weights[i][j]);
        }
    }
}

void SysArray::initInputs(const std::vector<std::vector<uint32_t>> matrix) {
    if ( matrix.size() != mesh.size() ) {
        throw std::invalid_argument("Matrix column dimension doesn't match mesh");
    }

    for ( int i = mesh.size(); i > 0; i-- ) {
        if ( matrix[mesh.size()-i].size() != mesh.size() ) {
            throw std::invalid_argument("Matrix row dimension doesn't match mesh");
        }

        std::vector<uint32_t> temp_row;
        for ( int j = 0; j < mesh.size(); j++ ) {
            // Need to initalize the lower rows with 0s in certain spots to properly time things out
            if ( j < ( mesh.size() - i ) ) {
                temp_row.push_back(0);
            } else {
                temp_row.push_back(matrix[mesh.size()-i][j]);
            }
        }
        inputBuffer.push_back(temp_row);
    }
}