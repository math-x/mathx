#include <number_theory.h>

namespace mathx {
    int gcd(int a, int b) {
        while( a * b ){
            if(a > b)
                a = a % b;
            else
                b = b % a;
        }
        return a + b;
    }
    int lcm(int a, int b) {
        return (a * b / gcd(a,b));
    }
}
