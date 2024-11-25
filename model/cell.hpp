#include <cstdint>
#ifndef CELL_HPP
#define CELL_HPP



class Cell {
    uint32_t storage;

    uint32_t in_a, in_b;

    uint32_t out_a, out_b;

public:
    uint32_t get_a(){return out_a;}
    uint32_t get_b(){return out_b;}
    void inp_a(uint32_t inp){in_a = inp;}
    void inp_b(uint32_t inp){in_b = inp;}

    uint32_t get_storage(){return storage;}

    void compute();
};

#endif