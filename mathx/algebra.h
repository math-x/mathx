#ifndef _ALGEBRA_H_
#define _ALGEBRA_H_

#include <string_tools.h>
#include <arithmetic.h>

#include <string>

namespace mathx {

    class Polynomial {
    private:
        std::string var;    //variable For eg. "x","y"
        float coefficients[100];

    public:
        Polynomial () {
            var = "x";
            for(int i = 0 ; i < 100; i++)
                coefficients[i] = 0;
        }

        Polynomial (std::string x) {
            var = "x";
            for(int i = 0 ; i < 100; i++)
                coefficients[i] = 0;
            parse(x);
        }

        void parse (std::string exp) {       // Kanav: Needs a lot of revision.
            trim(exp);
            bool flag = false;
            int temp_power, start = 0;
            float temp_co;
            for(int i = 0; i < exp.length(); )
            {
                start = i;
                if(exp[i] == '-' || exp[i] == '+')
                    i++;
                while(exp[i] >= 48 && exp[i] <= 57 )
                    i++;
                if ( exp.substr(start,i-start) == "+" || exp.substr(start,i-start) == "-") {
                    temp_co = std::stof(exp.substr(start,i-start) + "1");
                }
                else
                    temp_co = std::stof(exp.substr(start,i-start));
                while(!(exp[i] >= 48 && exp[i] <= 57))
                    i++;
                start = i;
                while(exp[i] >= 48 && exp[i] <= 57 )
                    i++;
                temp_power = std::stof(exp.substr(start,i-start));
                coefficients[temp_power] = temp_co;
            }
        }

        float evaluate (float const x) {
            float sum = 0;
            for(int i = 0; i<100; i++) {
                if (coefficients[i] != 0)
                    sum += power(x,i)*coefficients[i];
            }
            return sum;
        }

        float const getCoeff (int i) {
            return coefficients[i];
        }

        void plot () {
            //TODO: Function to plot and save as JPEG file
        }

        Polynomial derivative () {
            Polynomial der;
            for(int i = 0; i < 99; i++) {
                der.coefficients[i] = (i+1)*coefficients[i+1];
            }
            return der;
        }

        std::string const display () {
            std::string exp = "";
            for (int i = 99; i >= 0; i--) {
                if(coefficients[i] != 0) {
                    exp += "+(";
                    exp += std::to_string(coefficients[i]);
                    exp += ")x^(";
                    exp += std::to_string(i);
                    exp += ")";
                }
            }
            return exp;
        }
    };
}

#endif
