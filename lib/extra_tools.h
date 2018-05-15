#ifndef _EXTRA_TOOLS_H_
#define _EXTRA_TOOLS_H_

template <typename T>
void swap(T &x, T &y)
{
	T z = x;
	x = y;
	y = z;
}

#endif