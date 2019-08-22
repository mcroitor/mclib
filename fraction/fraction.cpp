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
    : numerator_(0), denominator_(1) {
    }

    fraction::fraction(const fraction& orig)
    : numerator_(orig.numerator_), denominator_(orig.denominator_) {
    }

    fraction::fraction(const int n, const int d)
    : numerator_(n), denominator_(d) {
        normalize();
    }
    
    fraction::fraction(const double p)
    : numerator_(p / fraction::EPS), denominator_(1. / fraction::EPS) {
        normalize();
    }

    fraction::fraction(const int n)
    : numerator_(n), denominator_(1) {
    }

    fraction fraction::operator=(const fraction& orig) {
        numerator_ = orig.numerator_;
        denominator_ = orig.denominator_;
        return * this;
    }

    fraction::~fraction() {
    }

    void fraction::normalize() {
        int tmp = gcd(_abs(numerator_), _abs(denominator_));
        numerator_ /= _sign(denominator_) * tmp;
        denominator_ /= _sign(denominator_) * tmp;
    }

    std::string fraction::to_string() const {
        std::ostringstream strout;
        strout << numerator_ << " / " << denominator_;
        return strout.str();
    }

    double fraction::value() const {
        return double(numerator_) / denominator_;
    }

    int fraction::numerator() const {
        return numerator_;
    }

    int fraction::denominator() const {
        return denominator_;
    }

    //operators

    void fraction::operator*=(const fraction& p) {
        numerator_ *= p.numerator_;
        denominator_ *= p.denominator_;
        normalize();
    }

    void fraction::operator/=(const fraction& p) {
        numerator_ *= p.denominator_;
        denominator_ *= p.numerator_;
        normalize();
    }

    void fraction::operator+=(const fraction& p) {
        numerator_ = numerator_ * p.denominator_ + p.numerator_*denominator_;
        denominator_ *= p.denominator_;
        normalize();
    }

    void fraction::operator-=(const fraction& p) {
        numerator_ = numerator_ * p.denominator_ - p.numerator_*denominator_;
        denominator_ *= p.denominator_;
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