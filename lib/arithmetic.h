#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_
long long power(long long x,long long n){
	if( n == 0 )
		return 1;
	long long tmp = power( x , n/2 );
	if( n % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * x;
}

long double power(long double x,long long n){
	if( n == 0 )
		return 1;
	long double tmp = power( x , n/2 );
	if( n % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * x;
}
long double power(double x,long long n){
	if( n == 0 )
		return 1;
	long double tmp = power( x , n/2 );
	if( n % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * x;
}
float power(float x,long long n){
	if( n == 0 )
		return 1;
	float tmp = power( x , n/2 );
	if( n % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * x;
}
#endif