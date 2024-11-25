#include "cell.hpp"

void Cell::compute() {
    storage = storage + in_a * in_b;

    out_a = in_a;
    out_b = in_b;
}