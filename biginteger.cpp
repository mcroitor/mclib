#include "./algebra/biginteger.h"

namespace mc {

    BigInteger::BigInteger() : sign(SIGN::plus), value(0) {
    }

    BigInteger::BigInteger(int64_t p) : sign(SIGN::plus) {
        if (p < 0) {
            sign = SIGN::minus;
            p = -p;
        }
        value = p;
    }

    BigInteger::BigInteger(const BigInteger& p) : sign(p.sign), value(p.value) {
    }

    BigInteger::BigInteger(const BigNumber& p) : sign(SIGN::plus), value(p) {
    }

    BigInteger::BigInteger(const string& p) {
        string tmp = p;
        sign = SIGN::plus;
        if (tmp[0] == '-') {
            sign = SIGN::minus;
            tmp.erase(tmp.begin());
        }
        value = tmp;
    }

    const BigInteger& BigInteger::operator=(const BigInteger& p) {
        sign = p.sign;
        value = p.value;
        return *this;
    }

    const BigInteger& BigInteger::operator=(const BigNumber& p) {
        sign = SIGN::plus;
        value = p;
        return *this;
    }

    const BigInteger& BigInteger::operator=(const string& p) {
        string tmp = p;
        sign = SIGN::plus;
        if (tmp[0] == '-') {
            sign = SIGN::minus;
            tmp.erase(tmp.begin());
        }
        value = tmp;
        return *this;
    }

    const BigInteger& BigInteger::operator=(const int64_t& p) {
        int64_t tmp = p;
        sign = SIGN::plus;
        if (tmp < 0) {
            sign = SIGN::minus;
            tmp = -tmp;
            ;
        }
        value = tmp;
        return *this;
    }

    BigInteger BigInteger::operator-(void) {
        if (sign == SIGN::plus) {
            sign = SIGN::minus;
        } else {
            sign = SIGN::plus;
        }
        return *this;
    }

    BigInteger BigInteger::operator+(void) const {
        return *this;
    }

    void BigInteger::operator+=(const BigInteger& p) {
        BigInteger tmp = p;
        if (sign == tmp.sign) {
            value += tmp.value;
        } else {
            if (value < tmp.value) {
                sign = tmp.sign;
                tmp.value -= value;
                value = tmp.value;
            } else {
                value -= tmp.value;
            }
        }
    }

    void BigInteger::operator-=(const BigInteger& p) {
        BigInteger tmp = p;
        if (sign == tmp.sign) {
            if (tmp.value < value) {
                value -= tmp.value;
            } else {
                tmp.value -= value;
                value = tmp.value;
                if (sign == SIGN::plus) {
                    sign = SIGN::minus;
                } else {
                    sign = SIGN::plus;
                }
            }
        } else {
            tmp = -tmp;
            value += tmp.value;
        }
    }

    void BigInteger::operator*=(const BigInteger& p) {
        if (sign == p.sign) {
            sign = SIGN::plus;
        } else {
            sign = SIGN::minus;
        }
        value *= p.value;
    }

    void BigInteger::operator/=(const BigInteger& p) {
        if (sign == p.sign) {
            sign = SIGN::plus;
        } else {
            sign = SIGN::minus;
        }
        value /= p.value;
    }

    string BigInteger::toString() const {
        string result = value.toString();
        if (sign == SIGN::minus) {
            result.insert(result.begin(), '-');
        }
        return result;
    }

    size_t BigInteger::NrOfDigits() const {
        return value.NrOfDigits();
    }

    BigInteger::SIGN BigInteger::Sign() const {
        return sign;
    }

    BigInteger operator+(const BigInteger& p1, const BigInteger& p2) {
        BigInteger tmp = p1;
        tmp += p2;
        return tmp;
    }

    BigInteger operator-(const BigInteger& p1, const BigInteger& p2) {
        BigInteger tmp = p1;
        tmp -= p2;
        return tmp;
    }

    BigInteger operator*(const BigInteger& p1, const BigInteger& p2) {
        BigInteger tmp = p1;
        tmp *= p2;
        return tmp;
    }

    BigInteger operator/(const BigInteger& p1, const BigInteger& p2) {
        BigInteger tmp = p1;
        tmp /= p2;
        return tmp;
    }

    BigInteger abs(const BigInteger& p) {
        BigInteger tmp = p;
        if (tmp < BigInteger(0)) {
            return -tmp;
        }
        return tmp;
    }

    bool operator==(const BigInteger& p1, const BigInteger& p2) {
        return p1.toString() == p2.toString();
    }

    bool operator!=(const BigInteger& p1, const BigInteger& p2) {
        return !(p1.toString() == p2.toString());
    }

    bool operator<(const BigInteger& p1, const BigInteger& p2) {
        return p1.toString() < p2.toString();
    }

    std::ostream& operator<<(std::ostream& out, const BigInteger& p) {
        out << p.toString();
        return out;
    }

    std::istream& operator>>(std::istream& in, BigInteger& p) {
        string tmp;
        in >> tmp;
        p = tmp;
        return in;
    }
}