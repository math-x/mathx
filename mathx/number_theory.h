#ifndef MATHX_NUMBER_THEORY_H_
#define MATHX_NUMBER_THEORY_H_

namespace mathx {
    long long gcd(long long a, long long b);
    long long lcm(long long a, long long b);
    long long pow(long long a, long long e, long long mod);
    bool is_miller_rabin_witness(long long a, long long p);
    bool is_prime_fast(long long p);
}

#endif
