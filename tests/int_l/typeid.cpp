#include <iostream>
#include <cassert>
#include <mathx.h>

int main() {
    mathx::int_l x;
    mathx::int_l y = 2;
    mathx::int_l z = "2";
    mathx::int_l a = x;
    assert(y == z);
}
