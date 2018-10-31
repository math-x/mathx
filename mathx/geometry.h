#ifndef MATHX_NUMBER_THEORY_H_
#define MATHX_NUMBER_THEORY_H_

namespace mathx {
	template<typename T>
	class point
	{
		T x, y;
	public:
		//Constructor
		point(T x = static_cast<T>(0), T y = static_cast<T>(0)): x(x), y(y) {

		};

		point operator+=(const point &t) {
			this->x += t.x;
			this->y += t.y;
			return *this;
		}
		point operator-=(const point &t) {
			this->x -= t.x;
			this->y -= t.y;
			return *this;
		}
		point operator*=(const point &t) {
			this->x *= t;
			this->y *= t;
			return *this;
		}
		point operator/=(const point &t) {
			this->x /= t;
			this->y /= t;
			return *this;
		}
		point operator+(const point &t) const {
			return point(this->x + t.x, this->y + t.y);
		}
		point operator-(const point &t) const {
			return point(this->x - t.x, this->y - t.y);
		}
		point operator*(const T &t) const {
			return point(this->x * t, this->y * t);
		}
		point operator/(const T &t) const {
			return point(this->x / t, this->y / t);
		}
		friend istream& operator>>(istream& is, point& p) { 
			is >> p.x >> p.y; 
			return is;
		}
		friend ostream& operator<<(ostream& os, const point& p) { 
			os << p.x << ' ' << p.y; 
			return os;
		}
		T operator*(const point &p) const { 
			return (this->x * p.x + this->y * p.y); 
		}
		T operator^(const point &p) const { 
			return (this->x * p.y - this->y * p.x); 
		}
		friend point operator* (T const &t, point const &p) { 
			return p * t;
		}
		
		long double polarAngle() {
			if (this->x == static_cast<T>(0))
				return ((this->y > static_cast<T>(0)) ? PI * (0.5) : PI * static_cast<long double>(1.5));
			if (this->y == static_cast<T>(0) && this->x > static_cast<T>(0))
				return (0.0);
			if (this->y == static_cast<T>(0))
				return (PI);
			long double res = atan(abs(y / x));
			if (y > static_cast<T>(0) && x > static_cast<T>(0))
				return res;
			if (y > static_cast<T>(0) && x < static_cast<T>(0))
				return (PI - res);
			if (y < static_cast<T>(0) && x > static_cast<T>(0))
				return (static_cast<long double>(2) * PI - res);
			return (PI + res);
		}
		point rotate(long double sintheta, long double costheta) const { 
			return (costheta * this->x - sintheta * this->y, sintheta * this->x + costheta * this->y); 
		}
		point rotate(long double theta) const { 
			return this->rotate(sin(theta), cos(theta)); 
		}
		long double dist(const point &a = point()) { 
			return sqrt((a - *this) * (a - *this)); 
		}
		static long double area(const point &a, const point &b, const point &c) { 
			long double a1 = sqrt((a - b) * (a - b)); 
			long double a2 = sqrt((b - c) * (b - c)); 
			long double a3 = sqrt((a - c) * (a - c)); 
			long double s = (a1 + a2 + a3) / ((long double) (2.0)); 
			return sqrt((s) * (s - a1) * (s - a2) * (s - a3)); 
		}
		static T dist(const point &a, const point &b) {
			return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
		}
		T distFromLine(point a, const long double& c) { 
			return sqrt((((*this) * a + c) * ((*this) * a + c)) / (a * a)); 
		}
		T distFromLine(point x, point y) { 
			point p = (x + ((((*this - x) * y) / (y * y)) * y)); 
			return sqrt((p - *this) * (p - *this)); 
		}
		static bool clockwise(point a, point b, point c) { 
			return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; 
		}
		static bool counterClockwise(point a, point b, point c) {
			return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
		}
	};

	template<typename T>
	class ConvexHull //Graham's Scan
	{
		vector<point<T> > Hull;
		int n;
		
		int nextin(int i) { 
			return (i == n - 1 ? 0 : i + 1);
		}

	public:
		ConvexHull(vector<point<T> >& a)
		{
			if (a.size() <= 1) 
				return;

			sort(a.begin(), a.end(), [](point<T> a, point<T> b) { 
				return ((a.x < b.x) || (a.x == b.x && a.y < b.y)); 
			});

			point<T> pa = a[0], pb = a.back(); std::vector<point<T> > upper, lower; 
			upper.pb(pa), lower.pb(pa);

			for (int i = 1; i < (int)a.size(); ++i)
			{
				if (i == a.size() - 1 || clockwise(pa, a[i], pb))
				{
					while (upper.size() >= 2 && !clockwise(upper[upper.size() - 2], upper[upper.size() - 1], a[i]))
						upper.pop_back();
					upper.pb(a[i]);
				}
				if (i == a.size() - 1 || counterClockwise(pa, a[i], pb))
				{
					while (lower.size() >= 2 && !counterClockwise(lower[lower.size() - 2], lower[lower.size() - 1], a[i]))
						lower.pop_back();
					lower.pb(a[i]);
				}
			}
			for (int i = 0; i < (int)upper.size(); ++i)
				Hull.pb(upper[i]);

			for (int i = lower.size() - 2; i > 0 ; i--)
				Hull.pb(lower[i]);

			n = Hull.size();
		}
		std::vector<point<T>> Hullify() { 
			return Hull; 
		}
	};
}

#endif