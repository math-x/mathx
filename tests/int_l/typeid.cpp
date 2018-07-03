#include <iostream>
#include <cassert>
#include "../../lib/int_l.h"

int main() {
    int_l x;
    int_l y = 2;
    int_l z = "2";
    int_l a = x;
    assert(y == z);
}
