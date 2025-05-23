#include <cstdint>
#ifndef CELL_HPP
#define CELL_HPP

// Basic unit of systolic array, also known as processing element
class Cell {
    // Is initalizing stuff like this good style?
    uint32_t storage{};

    uint32_t in_a{}, in_b{};

    uint32_t out_a{}, out_b{};
public:
    uint32_t get_a(){return out_a;}
    uint32_t get_b(){return out_b;}
    void inp_a(uint32_t inp){in_a = inp;}
    void inp_b(uint32_t inp){in_b = inp;}

    uint32_t get_storage(){return storage;}
    // For weight stationary
    void inp_storage(uint32_t inp){storage = inp;}

    void compute();
};

#endif