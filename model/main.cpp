#include <iostream>

#include "sysarray.hpp"

int main(int, char**){
    SysArray array(3,3);

    std::vector<uint32_t> weight_row = {1,2,3};
    std::vector<std::vector<uint32_t>> weights(3, weight_row);

    array.logState();

    try {
        array.loadWeights(weights);
    } catch(std::exception& ex) {
        std::cerr << "Weight load error: " << ex.what() << std::endl;
    }

    try {
        array.initInputs(weights);
    } catch(std::exception& ex) {
        std::cerr << "Input buffer init error: " << ex.what() << std::endl;
    }

    array.logState();

    return 0;
}
