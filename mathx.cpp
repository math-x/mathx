#include "mathx.h"
#include <iostream>
#include <map>
typedef int (*FnPtr)(int, int);
using namespace std;
map<string,FnPtr> m;
m["gcd"] = gcd;

int main()
{
	cout<<"MATHX INTERPRETER"<<endl;
	cout<<"-----------------"<<endl;
	string inp;
	while(inp!="exit"){
		cout<<">";
		getline(cin , inp);
		
	}
}
