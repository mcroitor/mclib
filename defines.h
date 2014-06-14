#ifndef MC_DEFINES_H
#define	MC_DEFINES_H
#include <string>
/**
 * some usefull constants
 */

namespace mc {

#ifndef UINT_TYPE
#define UINT_TYPE
    typedef unsigned int uint;
    typedef unsigned char uint8;
    typedef uint8 byte;
    typedef unsigned short int uint16;
    /***
     * uint32 is missing
     */
    typedef unsigned long long uint64;

    typedef long long int64;
#endif
    const uint MAX_ITERATIONS = 1000;
    const double EPS = 0.000001;
    const double PI = 3.14159265358979;
    const double E = 2.718281828459;

    enum ERROR {
        NO_ERROR, EMPTY_ERROR, BOUND_ERROR, NEGATIVE_NUMBER_ERROR, INFINITY_ERROR
    };

    template<class TYPE>
    TYPE abs(const TYPE& p) {
        return (p > 0) ? p : -p;
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
    std::string ToString(int64, size_t = 0);
}
#endif	/* DEFINES_H */

