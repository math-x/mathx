/*
* Long Integers Class `int_l` for integers without any memory bound
*/
#ifndef INT_L_MATHX_
#define INT_L_MATHX_
#include <ostream>
#include <string>

#include <cstdint>

#define INT std::int64_t

/*
 * Class structure of `int_l`
 */
class int_l {
private:
	// String that stores number as string
	std::string num;
	// Function to empty the string `num`
	void null ();
	// boolean to store the sign of number
	bool is_positive;
	// function to remove trailing 0s
	void remove_trailing_zeroes();
public:
	// Constructor which converts `INT` to `int_l`
	int_l (INT x);
	// Constructor that converts `int` to `INT`
	int_l (int x) : int_l(static_cast<INT>(x)) {}
	// Constructor which converts `string` to `int_l`
	int_l (std::string x = "0");
	// Copy Constructor which converts `const char *` to `string`
	// and calls the int_l (std::string x) constructor
	int_l (const char* x) : int_l(static_cast<std::string>(x)) {}
	// + operator to handle addition
	int_l operator+ (const int_l &y);
	int_l operator+ (const INT &y);
	friend int_l operator+ (const INT &x, int_l &y);
	// - operator to handle subtraction
	int_l operator- (const int_l &y);
	int_l operator- (const INT &y);
	friend int_l operator- (const INT &x, int_l &y);
	// * operator to handle multiplication
	int_l operator* (const int_l &y);
	int_l operator* (const INT &y);
	friend int_l operator* (const INT &y, int_l &x);
	// << operator to make it usable for cout
	friend std::ostream& operator<<(std::ostream& os, const int_l &c);
	// Assignment operator
	void operator= (const INT &x);
	void operator= (const std::string &x);
	// Relational operators
	bool operator== (const int_l &x);
	bool operator== (const INT &x);
	bool operator<  (const int_l &x);
	bool operator<  (const INT &x);
	bool operator<= (const int_l &x);
	bool operator<= (const INT &x);
	bool operator>  (const int_l &x);
	bool operator>  (const INT &x);
	bool operator>= (const int_l &x);
	bool operator>= (const INT &x);
	// Unary operators
	int_l  operator- ();
	int_l& operator++();		//Prefix
	int_l  operator++(int);		//Postfix
	int_l& operator--();		//Prefix
	int_l  operator--(int);		//Postfix
};

/*
 * Member functions' defination of `int_l` class
 */
void int_l::null() {
	num = "";
}
void int_l::remove_trailing_zeroes() {
	int l = 0;
	while(num[l] == '0')
		l++;
	num = num.substr(l);
}
int_l::int_l (std::string x) {
	if(x[0] == '-') {
		is_positive = false;
		num = x.substr(1);
	}
	else if(x[0] == '+') {
		is_positive = true;
		num = x.substr(1);
	}
	else {
		is_positive = true;
		num = x;
	}
}
int_l::int_l (INT x) {
	if (x >= 0) {
		is_positive = true;
		num = std::to_string(x);
	}
	else {
		is_positive = false;
		num = std::to_string(-x);
	}
}
int_l int_l::operator+ (const int_l &y) {
	int_l res = y;
	if(is_positive && !y.is_positive)
		return *this - (-res);
	if(!is_positive && y.is_positive)
		return res - (-(*this));
	res.null();
	INT len1,len2;
	len1 = this->num.size();
	len2 = y.num.size();
	int carry = 0, sum, dig1, dig2;
	res.is_positive = is_positive;
	while(len1 && len2) {
		len1--;
		len2--;
		dig1 = this->num[len1] - '0';
		dig2 = y.num[len2] - '0';
		if(dig1 + dig2 + carry > 9) {
			res.num = (char)(dig1 + dig2 - 10 + '0' + carry) + res.num;
			carry = 1;
		}
		else {
			res.num = (char)(dig1 + dig2 + '0' + carry) + res.num;
			carry = 0;
		}
	}
	if(!len2) {
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
int_l int_l::operator+ (const INT &y) {
	int_l x = y;
	return (*this) + x;
}
int_l operator+ (const INT &x, int_l &y) {
	return y + x;
}
int_l int_l::operator- (const int_l &z) {
	int_l x = *(this);
	int_l y = z;
	if(this->is_positive != y.is_positive) {
		if(this->is_positive) {
			return x + (-y);
		}
		else {
			return -((-x) + y);
		}
	}
	else {
		if(this->is_positive) {
			if(x >= y) {
				int_l res = y;
				int len = res.num.size();
				for (int i = 0; i < len; ++i) {
					res.num[i] = '0' + '0' + 9 - res.num[i];
				}
				res = res + x + 1;
				int x = res.num.size() - len -1;
				while (res.num[x] == '0') {
					res.num[x] = '9';
					x--;
				}
				res.num[x] = res.num[x] - 1;
				res.remove_trailing_zeroes();
				return res;
			}
			else {
				return -(y - x);
			}
		}
		else {
			return (-y) - (-x);
		}
	}
}
int_l int_l::operator- (const INT &y) {
	int_l res = y;
	res = *(this) - res;
	return res;
}
int_l operator- (const INT &x, int_l &y) {
	int_l res = (y - x);
	res = -res;
	return res;
}
int_l int_l::operator* (const INT &y) {
	int_l res = 0;
	INT mod = (y >= 0 ? y : -y);
    for (int_l i = 0; i < mod; i = i+1)
    {
        res = res + (*this);
    }
    if(y < 0) {
		res = -res;
	}
    return static_cast<int_l>(res);
}
int_l int_l::operator* (const int_l &y) {
	int_l res = 0;
	int_l mod = y;
	mod = (mod >= 0 ? mod : -mod);
    for (int_l i = 0; i < mod; i = i+1)
    {
        res = res + (*this);
    }
    mod = y;
    if(mod < 0) {
		res = -res;
	}
    return static_cast<int_l>(res);
}
int_l operator* (const INT &x, int_l &y) {
	return y * x;
}
std::ostream& operator<<(std::ostream &os, const int_l &c) {
	if (!c.is_positive)
		os << '-';
	os << c.num;
	return os;
}

void int_l::operator= (const INT &x) {
	if (x >= 0) {
		is_positive = true;
		this->num = std::to_string(x);
	}
	else {
		is_positive = false;
		this->num = std::to_string(-x);
	}
}
void int_l::operator= (const std::string &x) {
	if(x[0] == '-') {
		is_positive = false;
		num = (x.substr(1));
	}
	else if(x[0] == '+') {
		is_positive = true;
		num = (x.substr(1));
	}
	else {
		is_positive = true;
		num = x;
	}
}
bool int_l::operator== (const int_l &x) {
	if(is_positive == x.is_positive && num == x.num)
		return true;
	return false;
}
bool int_l::operator== (const INT &x) {
	if(is_positive == (x >= 0)) {
		if(x >= 0)
			if(num == std::to_string(x))
				return true;
		else
			if(num == std::to_string(-x))
				return true;
	}
	return false;
}
bool int_l::operator< (const int_l &x) {
	if(is_positive && !x.is_positive)
		return false;
	if(!is_positive && x.is_positive)
		return true;
	if(num.size() < x.num.size())
		return is_positive;
	if(num.size() > x.num.size())
		return !(is_positive);
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < x.num[i])
			return is_positive;
		if(num[i] > x.num[i])
			return !(is_positive);
	}
	return false;
}
bool int_l::operator< (const INT &x) {
	bool sign = (x >= 0);
	std::string n = std::to_string((sign ? x : -x));
	if(is_positive && !sign)
		return false;
	if(!is_positive && sign)
		return true;
	if(num.size() < n.size())
		return is_positive;
	if(num.size() > n.size())
		return !(is_positive);
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < n[i])
			return is_positive;
		if(num[i] > n[i])
			return !(is_positive);
	}
	return false;
}
bool int_l::operator<= (const int_l &x) {
	if(is_positive && !x.is_positive)
		return false;
	if(!is_positive && x.is_positive)
		return true;
	if(num.size() < x.num.size())
		return is_positive;
	if(num.size() > x.num.size())
		return !(is_positive);
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < x.num[i])
			return is_positive;
		if(num[i] > x.num[i])
			return !(is_positive);
	}
	return true;
}
bool int_l::operator<= (const INT &x) {
	bool sign = (x >= 0);
	std::string n = std::to_string((sign ? x : -x));
	if(is_positive && !sign)
		return false;
	if(!is_positive && sign)
		return true;
	if(num.size() < n.size())
		return is_positive;
	if(num.size() > n.size())
		return !(is_positive);
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < n[i])
			return is_positive;
		if(num[i] > n[i])
			return !(is_positive);
	}
	return true;
}
bool int_l::operator> (const int_l &x) {
	if(is_positive && !x.is_positive)
		return true;
	if(!is_positive && x.is_positive)
		return false;
	if(num.size() < x.num.size())
		return !(is_positive);
	if(num.size() > x.num.size())
		return is_positive;
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < x.num[i])
			return !(is_positive);
		if(num[i] > x.num[i])
			return is_positive;
	}
	return false;
}
bool int_l::operator> (const INT &x) {
	bool sign = (x >= 0);
	std::string n = std::to_string((sign ? x : -x));
	if(is_positive && !sign)
		return true;
	if(!is_positive && sign)
		return false;
	if(num.size() < n.size())
		return !(is_positive);
	if(num.size() > n.size())
		return is_positive;
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < n[i])
			return !(is_positive);
		if(num[i] > n[i])
			return is_positive;
	}
	return false;
}
bool int_l::operator>= (const int_l &x) {
	if(is_positive && !x.is_positive)
		return true;
	if(!is_positive && x.is_positive)
		return false;
	if(num.size() < x.num.size())
		return !(is_positive);
	if(num.size() > x.num.size())
		return is_positive;
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < x.num[i])
			return !(is_positive);
		if(num[i] > x.num[i])
			return is_positive;
	}
	return true;
}
bool int_l::operator>= (const INT &x) {
	bool sign = (x >= 0);
	std::string n = std::to_string((sign ? x : -x));
	if(is_positive && !sign)
		return true;
	if(!is_positive && sign)
		return false;
	if(num.size() < n.size())
		return !(is_positive);
	if(num.size() > n.size())
		return is_positive;
	for (int i = 0; i < num.size(); ++i) {
		if(num[i] < n[i])
			return !(is_positive);
		if(num[i] > n[i])
			return is_positive;
	}
	return true;
}
int_l int_l::operator- () {
	int_l x = *(this);
	if(x.num != "0")
		x.is_positive = !(x.is_positive);
	return x;
}
int_l& int_l::operator++ () {
	*this = *this + 1;
	return *this;
}
int_l int_l::operator++ (int x) {
	int_l y = *this;
	*this = *this + 1;
	return y;
}
int_l& int_l::operator-- () {
	*this = *this - 1;
	return *this;
}
int_l int_l::operator-- (int x) {
	int_l y = *this;
	*this = *this - 1;
	return y;
}
#endif
