/*
 * Calculus capabilities for MathX
 * Assumes that a mathematical continous function is of form `long double func (long double)`
 */
#ifndef CALCULUS_MATHX_

#define CALCULUS_MATHX_
#define dx 0.0000001
#define NEWTON_RAPHSON_PRECISION 100
#define INF 1e12

#include <iostream>
#include <climits>
#include <cstdlib>

namespace mathx {

    // Function which returns the derivative of mathematical function `fn` at `x`
    long double differentiate(long double (*fn)(long double), long double x) {
        long double rhd = (fn(x + dx) - fn(x)) / dx;
        long double lhd = (fn(x) - fn(x - dx)) / dx;
        if(std::abs(rhd - lhd) < (dx)*100)
            return (rhd + lhd)/2;
        else {
            std::cerr << "Then given function is not differentiable at " << x << '\n';
        }
    }

    // Function which returns the integral of mathematical function `fn` from `ll` to `ul`
    long double integrate(long double (*fn)(long double), long double ll, long double ul) {
        if(ul < ll)
            return -integrate(fn, ul, ll);
        long double result = 0;
        while(ul >= ll) {
            result += (fn(ll) * dx);
            ll += dx;
        }
        return result;
    }

    /* Function which returns the root with the help of an initial `guess` using Newton-Raphson Method
     * Generally returns the nearest root to `guess`
     */
    long double apx_root (long double (*fn)(long double), long double guess) {
        for (int i = 0; i < NEWTON_RAPHSON_PRECISION; ++i)
        {
            guess = guess - (fn(guess) / differentiate(fn, guess));
        }
        return guess;
    }
}
#endif
