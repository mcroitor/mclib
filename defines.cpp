#include "defines.h"
namespace mc {

    bool dbl_compare(const double& p1, const double& p2) {
        return mc::abs(p1 - p2) < EPS;
    }

    double sqrt(const double& p) {
        if (p < 0) throw NEGATIVE_NUMBER_ERROR;
        double x = p / 2;
        double xn = (x + p / x) / 2;
        while (abs(x - xn) >= EPS) {
            x = xn;
            xn = (x + p / x) / 2;
        }
        return x;
    }

    bool isPrimary(const long long& p) {
        long long divisor = 2;
        long long top = (long long) sqrt(p);

        for (; divisor <= top; ++divisor) {
            if (p % divisor == 0) {
                return false;
            }
        }
        return true;
    }

    double truncate(const double& p, const int& grad) {
        double result = p;
        int i;
        for (i = 0; i != grad; ++i) {
            result *= 10;
        }
        result = (int) result;
        for (i = 0; i != grad; ++i) {
            result /= 10;
        }
        return result;
    }

    double grad2rad(const int& p) {
        return p * PI / 180.0;
    }

    int rad2grad(const double& p) {
        return (int) (p * 180.0 / PI);
    }

    double arctg(const double& p) {
        if ((mc::abs(p) - 1) > EPS) throw INFINITY_ERROR;
        double result = 0.0;
        double mono = p;
        int i = 1;
        while (abs(mono) > EPS) {
            result += mono;
            i += 2;
            mono = -mono * p * p * (i - 2) / i;
        }
        return result;
    }

    double sin(const double& p) {
        double result = 0.0;
        double mono = p;
        double i = 1;
        while (abs(mono) > EPS) {
            result += mono;
            mono = -mono * p * p / ((i + 1)*(i + 2));
            i += 2;
        }
        return result;
    }

    double cos(const double& p) {
        double result = 0.0;
        double mono = 1;
        double i = 0;
        while (abs(mono) > EPS) {
            result += mono;
            mono = -mono * p * p / ((i + 1)*(i + 2));
            i += 2;
        }
        return result;
    }

    double tg(const double& p) {
        return sin(p) / cos(p);
    }

    bool is_digit(const char& c) {
        return c >= '0' && c <= '9';
    }

    std::string ToString(int64_t p, size_t d) {
        std::string result(""), tmp("0");
        int sign = 0;
        if(p < 0){
            sign = 1;
            p = -p;
        }

        do {
            tmp[0] = p % 10 + '0';
            result = tmp + result;
            p /= 10;
            --d;
        } while (p > 0 || d > 0);

        if(sign == 1){
            result.insert(result.begin(), '-');
        }
        return result;
    }

    double min(double p1, double p2) {
        if(p1 < p2) return p1;
        return p2;
    }

    double min(double p1, double p2, double p3) {
        return min(p1, min(p2, p3));
    }
    
    long long gcd(long long a, long long b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcd(long long a, long long b, long long c){
        return gcd(gcd(a, b), c);
    }
    long long lcm(long long a, long long b){
        return a*b/gcd(a, b);
    }
    long long lcm(long long a, long long b, long long c){
        return lcm(lcm(a, b), c);
    }
}
