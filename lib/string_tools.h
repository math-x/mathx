#ifndef _STRING_TOOLS_H_
#define _STRING_TOOLS_H_
#include <string>
void trim( std::string &s ) {
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if(s[i] == ' ') {
			s.erase(i,1);
			i--;
			len--;
		}
	}
}
#endif