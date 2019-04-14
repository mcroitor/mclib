#include "fraction.h"

//additional
#include <sstream>

namespace mc {

    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    int _abs(int p) {
        return (p > 0) ? p : -p;
    }

    int _sign(int p) {
        return (p < 0) ? -1 : 1;
    }

    // realization

    fraction::fraction()
    : numerator(0), denominator(1) {
    }

    fraction::fraction(const fraction& orig)
    : numerator(orig.numerator), denominator(orig.denominator) {
    }

    fraction::fraction(const int n, const int d)
    : numerator(n), denominator(d) {
        normalize();
    }

    fraction::fraction(const int n)
    : numerator(n), denominator(1) {
    }

    fraction fraction::operator=(const fraction& orig) {
        numerator = orig.numerator;
        denominator = orig.denominator;
        return * this;
    }

    fraction::~fraction() {
    }

    void fraction::normalize() {
        int tmp = gcd(_abs(numerator), _abs(denominator));
        numerator /= _sign(denominator) * tmp;
        denominator /= _sign(denominator) * tmp;
    }

    std::string fraction::to_string() const {
        std::ostringstream strout;
        strout << numerator << " / " << denominator;
        return strout.str();
    }

    double fraction::value() const {
        return double(numerator) / denominator;
    }
    //operators

    void fraction::operator*=(const fraction& p) {
        numerator *= p.numerator;
        denominator *= p.denominator;
        normalize();
    }

    void fraction::operator/=(const fraction& p) {
        numerator *= p.denominator;
        denominator *= p.numerator;
        normalize();
    }

    void fraction::operator+=(const fraction& p) {
        numerator = numerator * p.denominator + p.numerator*denominator;
        denominator *= p.denominator;
        normalize();
    }

    void fraction::operator-=(const fraction& p) {
        numerator = numerator * p.denominator - p.numerator*denominator;
        denominator *= p.denominator;
        normalize();
    }

    fraction operator+(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp += p2;
        return tmp;
    }

    fraction operator-(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp -= p2;
        return tmp;
    }

    fraction operator*(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp *= p2;
        return tmp;
    }

    fraction operator/(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp /= p2;
        return tmp;
    }

    bool operator==(const fraction& p1, const fraction& p2) {
        return p1.to_string() == p2.to_string();
    }

    bool operator<(const fraction& p1, const fraction& p2) {
        return p1.value() < p2.value();
    }

    std::istream& operator>>(std::istream& in, fraction& p) {
        int n, d;
        char fix; // is a slash sign
        in >> n >> fix >> d;
        p = fraction(n, d);
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const fraction& p) {
        out << p.to_string();
        return out;
    }
}