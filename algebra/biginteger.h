#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include "bignumber.h"
namespace mc {
    typedef std::string string;

    class BigInteger {
        enum class SIGN {
            plus, minus
        };
        BigNumber value;
        SIGN sign;
    public:
        BigInteger();
        BigInteger(int64_t);
        BigInteger(const BigNumber&);
        BigInteger(const BigInteger&);
        BigInteger(const string&);

        BigInteger operator=(const BigNumber&);
        BigInteger operator=(const BigInteger&);
        BigInteger operator=(const string&);
        BigInteger operator=(const int64_t&);
        
        BigInteger operator -(void);
        BigInteger operator +(void);

        void operator+=(const BigInteger&);
        void operator-=(const BigInteger&);
        void operator*=(const BigInteger&);
        void operator/=(const BigInteger&);

        string toString() const;
    };

    BigInteger operator+(const BigInteger&, const BigInteger&);
    BigInteger operator-(const BigInteger&, const BigInteger&);
    BigInteger operator*(const BigInteger&, const BigInteger&);
    BigInteger operator/(const BigInteger&, const BigInteger&);
    
    BigInteger abs(const BigInteger&);

    bool operator==(const BigInteger&, const BigInteger&);
    bool operator!=(const BigInteger&, const BigInteger&);
    bool operator<(const BigInteger&, const BigInteger&);

    std::ostream& operator<<(std::ostream&, const BigInteger&);
    std::istream& operator>>(std::istream&, BigInteger&);
}

#endif /* BIGINTEGER_H */

