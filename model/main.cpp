#include <iostream>

#include "cell.hpp"

void step_log(Cell &cell) {
    std::cout << "Out a: " << cell.get_a() << " Out b: " << cell.get_b() << " Storage: " << cell.get_storage() << std::endl;
}

int main(int, char**){
    Cell cell_one;

    cell_one.inp_a(1);
    cell_one.inp_b(2);
    cell_one.compute();
    step_log(cell_one);
}
