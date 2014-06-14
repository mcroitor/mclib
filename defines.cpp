#include "defines.h"
namespace mc{

	double sqrt(const double& p){
		if(p < 0) throw NEGATIVE_NUMBER_ERROR;
		double x = p/2;
		double xn = (x + p/x)/2;
		while(abs(x-xn) >= EPS){
			x = xn;
			xn = (x + p/x)/2;
		}
		return x;
	}

	bool isPrimary(const uint64& p){
		uint64 divisor = 2;
		uint64 top = (uint64)sqrt(p);

		for(; divisor <= top; ++divisor){
			if(p % divisor == 0){
				return false;
			}
		}
		return true;
	}
        double truncate(const double& p, const int& grad){
            double result = p;
            int i;
            for(i = 0; i != grad; ++i){
                result *= 10;
            }
            result = (int)result;
            for(i = 0; i != grad; ++i){
                result /= 10;
            }
            return result;
        }

	double grad2rad(const int& p){ return p*PI / 180.0; }

	int rad2grad(const double& p){ return (int)(p*180.0 / PI); }

	double arctg(const double& p){
		if(abs(p) - 1 > EPS) throw INFINITY_ERROR;
		double result = 0.0;
		double mono = p;
		int i = 1;
		while(abs(mono) > EPS){
			result += mono;
			i += 2;
			mono = -mono*p*p*(i-2)/i;
		}
		return result;
	}
	double sin(const double& p){
		double result = 0.0;
		double mono = p;
		double i = 1;
		while(abs(mono) > EPS){
			result += mono;
			mono = -mono*p*p/((i+1)*(i+2));
			i += 2;
		}
		return result;
	}
	double cos(const double& p){
		double result = 0.0;
		double mono = 1;
		double i = 0;
		while(abs(mono) > EPS){
			result += mono;
			mono = -mono*p*p/((i+1)*(i+2));
			i += 2;
		}
		return result;
	}
	double tg(const double& p){ return sin(p) / cos(p); }
        
        bool is_digit(const char& c){
            return c >= '0' && c <= '9';
        }
        
        std::string ToString(int64 p, size_t d){
            std::string result(""), tmp("0");
            uint64 condition = d * p;            
            
            do{
                tmp[0] = p % 10 + '0';
                result = tmp + result;
                p /= 10;
                --d;
                condition = d * p;
            }
            while(condition > 0);
            
            return result;
        }
}
