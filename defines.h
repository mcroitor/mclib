#ifndef MC_DEFINES_H
#define	MC_DEFINES_H
#include <string>
#include <stdint.h>
/**
 * some usefull constants
 */

namespace mc {

    typedef uint8_t byte;

    const uint32_t MAX_ITERATIONS = 1000;
    const double EPS = 0.000001;
    const double PI = 3.14159265358979;
    const double E = 2.718281828459;

    enum ERROR {
        NO_ERROR, EMPTY_ERROR, BOUND_ERROR, MULT_MATRIX_ERROR,NEGATIVE_NUMBER_ERROR, INFINITY_ERROR
    };

    template<class TYPE>
    TYPE abs(const TYPE& p) {
        return (p > 0) ? p : -p;
    }
    
    template<class COMPARABLE_TYPE>
    bool operator != (const COMPARABLE_TYPE& p1, const COMPARABLE_TYPE& p2){
        return !(p1 == p2);
    }

    bool dbl_compare(const double&, const double&);

    /**
     * square root with EPS precision
     * @param num - 
     * @return 
     */
    double sqrt(const double&);

    /**
     * detects if number is primary
     * @param num - 
     * @return 
     */
    bool isPrimary(const long long&);

    /**
     * number truncation
     * @param num - 
     * @param digits - number of throwed digits
     * @return truncated value
     */
    double truncate(const double&, const int&);
    double grad2rad(const int&);
    int rad2grad(const double&);
    double arctg(const double&); // radian
    double tg(const double&); // radian
    double sin(const double&); // radian
    double cos(const double&); // radian

    /**
     * проверяется, является ли символ цифрой
     * @param chr - проверяемый символ
     * @return если параметр является цифрой, то true, иначе false
     */
    bool is_digit(const char&);
    /**
     * преобразование длинного числа в строку.
     * @param num - преобразуемое число.
     * @param num_chars - количество символов в строке. 
     * @return в случае, если символов больше цифр в числе, то результат получается с лидирующими нулями.
     */
    std::string ToString(int64_t, size_t = 0);
    
    double min(double, double);
    double min(double, double, double);
}
#endif	/* DEFINES_H */

