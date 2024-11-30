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
}