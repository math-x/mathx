#ifndef _TRIG_H_
#define _TRIG_H_
#define PI 3.14159265

long double cos( long double x ) {
	long double res = 1;
	long double tmp = 1;

	for (int i = 2; i < 30 ; i = i + 2 ) {
		tmp = -tmp * x * x / ( i * (i-1) );
		res = res + tmp;
	}
	return res;
}
long double sin( long double x ) {
	long double res = x;
	long double tmp = x;

	for ( int i = 3; i < 30; i = i + 2) {
		tmp = -tmp * x * x / ( i * (i-1) );
		res = res + tmp;
	}
	return res;
}
long double tan( long double x ) {
	return sin(x)/cos(x);
}
#endif