/*
* Long Integers Class `int_l` for integers without any memory bound
*/
#ifndef INT_L_MATHX_
#define INT_L_MATHX_
#include <ostream>
/*
 * Class structure of `int_l`
 */
class int_l {
private:
	// String that stores number as string
	std::string num;
	// Function to empty the string `num`
	void null ();
public:
	// Constructor which converts `long long` to `int_l`
	int_l (long long x);
	// Constructor which converts `string` to `int_l`
	int_l (std::string x = "0");
	// + operator to handle addition
	int_l operator+ (const int_l &y);
	// << operator to make it usable for cout
	friend std::ostream& operator<<(std::ostream& os, const int_l &c);
};

/*
 * Member functions' defination of `int_l` class 
 */
void int_l::null() {
	num = "";
}
int_l::int_l (std::string x) {
	num = x;
}
int_l::int_l (long long x) {
	num = std::to_string(x);
}
int_l int_l::operator+ (const int_l &y) {
	int_l res;
	res.null();
	long long len1,len2;
	len1 = this -> num.size();
	len2 = y.num.size();
	int carry=0,sum,dig1,dig2;
	while(len1 && len2) {
		len1--;
		len2--;
		dig1 = this->num[len1] - '0';
		dig2 = y.num[len1] - '0';
		if(dig1 + dig2 + carry > 9) {
			res.num = (char)(dig1 + dig2 - 10 + '0' + carry) + res.num;
			carry = 1;
		}
		else {
			res.num = (char)(dig1 + dig2 + '0' + carry) + res.num;
			carry = 0;
		}	
	}
	if(len2) {
		while(len1) {
			len1--;
			dig1 = this->num[len1] - '0';
			if(dig1 + carry > 9) {
				res.num = (char)(dig1 - 10 + '0' + carry) + res.num;
				carry = 1;
			}
			else {
				res.num = (char)(dig1  + '0' + carry) + res.num;
				carry = 0;
			}
		}
	} else {
		while(len2) {
			len2--;
			dig2 = y.num[len2] - '0';
			if(dig2 + carry > 9) {
				res.num = (char)(dig2 - 10 + '0' + carry) + res.num;
				carry = 1;
			}
			else {
				res.num = (char)(dig2  + '0' + carry) + res.num;
				carry = 0;
			}
		}
	}
	if(carry != 0) {
		res.num = '1' + res.num;
	}
	return res;
}

std::ostream& operator<<(std::ostream &os, const int_l &c) {
	os << c.num;
	return os;
}
#endif