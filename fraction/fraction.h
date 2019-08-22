#ifndef FRACTION_H
#define FRACTION_H

#include <utility>
#include <iostream>
#include <string>

namespace mc {

    using namespace std::rel_ops;

    class fraction {
        int numerator_, denominator_;

        const double EPS = 0.0000001;
        void normalize();
    public:
        fraction();
        fraction(const fraction&);
        fraction(const int, const int);
        fraction(const double);
        fraction(const int);
        fraction operator=(const fraction&);
        virtual ~fraction();

        std::string to_string() const;
        int numerator() const;
        int denominator() const;
        double value() const;

        void operator+=(const fraction&);
        void operator-=(const fraction&);
        void operator*=(const fraction&);
        void operator/=(const fraction&);
    };

    bool operator==(const fraction&, const fraction&);
    bool operator<(const fraction&, const fraction&);

    fraction operator+(const fraction&, const fraction&);
    fraction operator-(const fraction&, const fraction&);
    fraction operator*(const fraction&, const fraction&);
    fraction operator/(const fraction&, const fraction&);

    std::istream& operator>>(std::istream&, fraction&);
    std::ostream& operator<<(std::ostream&, const fraction&);
}

#endif /* FRACTION_H */

