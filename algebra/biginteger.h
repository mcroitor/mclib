#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include "bignumber.h"
namespace mc {
    typedef std::string string;

    class BigInteger {
    public:
        enum class SIGN {
            plus, minus
        };
    private:
        SIGN sign;
        BigNumber value;
    public:
        BigInteger();
        explicit BigInteger(int64_t);
        explicit BigInteger(const BigNumber&);
        BigInteger(const BigInteger&);
        explicit BigInteger(const string&);

        const BigInteger& operator=(const BigNumber&);
        const BigInteger& operator=(const BigInteger&);
        const BigInteger& operator=(const string&);
        const BigInteger& operator=(const int64_t&);
        
        BigInteger operator -(void);
        BigInteger operator +(void);

        void operator+=(const BigInteger&);
        void operator-=(const BigInteger&);
        void operator*=(const BigInteger&);
        void operator/=(const BigInteger&);

        string toString() const;
        size_t NrOfDigits() const;
        BigInteger::SIGN Sign() const;
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

