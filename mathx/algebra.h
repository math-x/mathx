#ifndef MATHX_ALGEBRA_H_
#define MATHX_ALGEBRA_H_

#include <mathx/string_tools.h>

#include <string>
#include <cmath>

namespace mathx {

    double const PI = acos(-1);

    class Complex
    {
        double imaginary, real;
    public:
        //Constructor
        Complex(double a = 0, double b = 0) : real(a), imaginary(b) { }
        //Operators
        Complex operator +(const Complex &o) const {
            return Complex(this->real + o.real, this->imaginary + o.imaginary);
        }
        Complex operator -(const Complex &o) const {
            return Complex(this->real - o.real, this->imaginary - o.imaginary);
        }
        Complex operator *(const Complex &o) const {
            return Complex(this->real * o.real - this->imaginary * o.imaginary, this->real * o.imaginary + this->imaginary * o.real);
        }
        Complex operator *(const double &o) const {
            return Complex(this->real * o, this->imaginary * o);
        }
        Complex operator /(const double &o) const {
            return Complex(this->real / o, this->imaginary / o);
        }
        Complex operator /=(const double &o) {
            this->real /= o; this->imaginary /= o;
            return *this;
        }
        Complex &operator *=(const Complex &o) {
            double r = this->real;
            this->real = this->real * o.real - this->imaginary * o.imaginary;
            this->imaginary = r * o.imaginary + this->imaginary * o.real ;
            return (*this);
        }
        friend ostream &operator<<(ostream &output, const Complex &o ) {
            output << "(" << o.real << ", " << o.imaginary << ")" ;
            return output;
        }
        //Accessors
        double Real() const {
            return this->real;
        }
        double Imag() const {
            return this->imaginary;
        }

    };

    class Polynomial {
    private:
        std::string var;    //variable For eg. "x","y"
        int max_coefficient;
        std::vector<double> coefficients;

        void fft(std::vector<Complex>& a, bool invert)  //sub part which must be abstracted and must not be public
        {
            unsigned n = a.size();
            for (unsigned i = 0, j = 0; i < n; i++) {

                if (i > j)
                    swap(a[i], a[j]);

                for (unsigned l = n >> 1; (j ^= l) < l; l >>= 1);

            }
            for (unsigned len = 2; len <= n; len <<= 1) {

                double ang = (double)(invert ? -2 : 2) * PI / (double)(len);
                Complex wlen((double)cos(ang), (double)sin(ang));

                for (unsigned i = 0; i < n; i += len) {

                    Complex w(1);

                    for (unsigned j = 0; j < (len >> 1); j++) {

                        Complex u = a[i + j], v = a[i + j + (len >> 1)] * w;

                        a[i + j] = u + v;
                        a[i + j + (len >> 1)] = u - v;
                        w *= wlen;
                    }
                }
            }

            if (invert)
                for (int i = 0; i < n; ++i)
                    a[i] /= (double)(n);
        }
    public:
        Polynomial () {
            var = "x";
            coefficients.resize(1);
            coefficients[0] = 0;
            max_coefficient = 0;
        }

        Polynomial (std::string x) {
            var = "x";
            coefficients.resize(1);
            max_coefficient = 0;
            coefficients[0] = 0;
            parse(x);
        }

        void parse (std::string exp) {       // Kanav: Needs a lot of revision.
            trim(exp);
            bool flag = false;
            int temp_power, start = 0;
            double temp_co;
            for (int i = 0; i < exp.length(); )
            {
                start = i;
                if (exp[i] == '-' || exp[i] == '+')
                    i++;
                while (exp[i] >= 48 && exp[i] <= 57 )
                    i++;
                if ( exp.substr(start, i - start) == "+" || exp.substr(start, i - start) == "-") {
                    temp_co = std::stod(exp.substr(start, i - start) + "1");
                }
                else
                    temp_co = std::stod(exp.substr(start, i - start));
                while (!(exp[i] >= 48 && exp[i] <= 57))
                    i++;
                start = i;
                while (exp[i] >= 48 && exp[i] <= 57 )
                    i++;
                temp_power = std::stod(exp.substr(start, i - start));
                if (temp_power > max_coefficient)
                {
                    max_coefficient = temp_power;
                    coefficients.resize(temp_power + 1);
                }
                coefficients[temp_power] = temp_co;
            }
        }

        double evaluate (double const x) {
            double sum = 0;
            for (int i = 0; i <= max_coefficient; i++) {
                if (coefficients[i] != 0)
                    sum += std::pow(x, i) * coefficients[i];
            }
            return sum;
        }

        double const getCoeff (int i) {
            if (i > max_coefficient)
                return static_cast<double>(0);
            return coefficients[i];
        }

        void plot () {
            //TODO: Function to plot and save as JPEG file
        }

        Polynomial derivative () {
            Polynomial der;
            der.coefficients.resize(max_coefficient);
            for (int i = 0; i < max_coefficient; i++)
                der.coefficients[i] = (i + 1) * coefficients[i + 1];
            return der;
        }

        std::string const display () {
            std::string exp = "";
            bool first = true;
            for (int i = max_coefficient; i >= 0; i--) {
                if (coefficients[i] != 0) {
                    if (!first)
                        exp += "+";
                    else
                        first = false;
                    exp += "(";
                    exp += std::to_string(coefficients[i]);
                    exp += ")x^(";
                    exp += std::to_string(i);
                    exp += ")";
                }
            }
            return exp;
        }

        Polynomial operator *(const Polynomial &b) const
        {
            unsigned n = 1;

            while (n < this->max_coefficient + b.max_coefficient + 1)
                n <<= 1;

            std::vector<Complex> fa(this->coefficients.begin(), this->coefficients.end()), fb(b.coefficients.begin(), b.coefficients.end());
            fa.resize(n);
            fb.resize(n);

            fft(fa, false);
            fft(fb, false);

            for (unsigned i = 0; i < n; ++i)
                fa[i] *= fb[i];

            fft(fa, true);

            Polynomial res;
            res.max_coefficient = this->max_coefficient + b.max_coefficient;

            for (unsigned i = 0; i <= res.max_coefficient; ++i)
                res.coefficients[i] = round(fa[i].Real());

            return res;
        }
    };
}

#endif
