#include <number_theory.h>

namespace mathx {
    long long gcd(long long a, long long b) {
        while( a * b ){
            if(a > b)
                a = a % b;
            else
                b = b % a;
        }
        return a + b;
    }

    long long lcm(long long a, long long b) {
        return (a * b / gcd(a,b));
    }

    long long pow(long long a, long long e, long long mod) {
        if (e == 0) {
            return 1;
        }

        long long x = mathx::pow(a, e / 2, mod);
        if (e % 2 == 0) {
            return (x * x) % mod;
        }
        else {
            return (((x * x) % mod) * x) % mod;
        }
    }

    bool is_miller_rabin_witness(long long a, long long p) {
        long long g = mathx::gcd(a,p);
        if (g == 1) {
            return true;
        }

        long long k = 0;
        long long q = p - 1;
        while (q % 2 == 0) {
            q = q / 2;
            ++k;
        }
        long long temp = mathx::pow(a, q, p);
        if (temp == 1) {
            return false;
        }

        for (int i = 0; i < k; ++i) {
            if (temp == p - 1) {
                return false;
            }
            else {
                temp = (temp * temp) % p;
            }
        }
        return true;
    }


    bool is_prime_fast(long long p) {
        if (p == 1) {
            return false;
        }
        for (int i = 0; i < 100; ++i) {
            if (mathx::is_miller_rabin_witness(i, p) == true) {
                return false;
            }
        }
        return true;
    }
}
