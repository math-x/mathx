#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_


// This power function only return rvalue references
// and works with c++14 and above
template<typename T>
auto power(const T& x, const T& n){
	if( n == 0 )
		return 1;

	auto tmp = power( x, n/2 );
	if( n % 2 == 0 )
		return tmp * temp;
	else
		return tmp * tmp * x;
}

#endif