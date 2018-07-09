#ifndef MATHX_CALCULUS_H_
#define MATHX_CALCULUS_H_

namespace mathx {
    long double differentiate(long double (*fn)(long double), long double x);
    long double integrate(long double (*fn)(long double), long double ll, long double ul);
    long double apx_root (long double (*fn)(long double), long double guess);
}

#endif
