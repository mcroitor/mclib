#ifndef BIGINTEGER_H
#define	BIGINTEGER_H

#include "defines.h"
#include <string>

namespace mc{
    typedef std::string string;
    class BigInteger{
        string digits;
        
        static string normalize(const string&);
    public:
        BigInteger();
        BigInteger(uint64_t);
        BigInteger(const BigInteger&);
        BigInteger(const string&);
        
        BigInteger operator = (const BigInteger&);
        BigInteger operator = (const string&);
        BigInteger operator = (const uint64_t&);
        
        void operator += (const BigInteger&);
        void operator -= (const BigInteger&);
        void operator *= (const BigInteger&);
        void operator /= (const BigInteger&);
        
        string toString() const;
    };
    
    BigInteger operator + (const BigInteger&, const BigInteger&);
    BigInteger operator - (const BigInteger&, const BigInteger&);
    BigInteger operator * (const BigInteger&, const BigInteger&);
    BigInteger operator / (const BigInteger&, const BigInteger&);
    
    bool operator ==(const BigInteger&, const BigInteger&);
    bool operator !=(const BigInteger&, const BigInteger&);
    bool operator <(const BigInteger&, const BigInteger&);
    
    std::ostream& operator << (std::ostream&, const BigInteger&);
    std::istream& operator >> (std::istream&, BigInteger&);
}

#endif	/* BIGINTEGER_H */

