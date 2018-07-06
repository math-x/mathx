#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

#include <iostream>

namespace mathx {
    template<typename T, typename N>
    auto power(const T& x, const N& n){
        if( n == 0 )
            return static_cast<T>(1);

        auto tmp = power( x, n/2 );
        if( n % 2 == 0 )
            return tmp * tmp;
        else
            return tmp * tmp * x;
    }
}
#endif
