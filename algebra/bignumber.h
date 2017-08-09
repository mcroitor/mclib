#ifndef BIGNUMBER_H
#define	BIGNUMBER_H

#include "../defines.h"
#include <string>

namespace mc{
    typedef std::string string;
    class BigNumber{
        string digits;
        
        static string normalize(const string&);
    public:
        BigNumber();
        BigNumber(uint64_t);
        BigNumber(const BigNumber&);
        BigNumber(const string&);
        
        BigNumber operator = (const BigNumber&);
        BigNumber operator = (const string&);
        BigNumber operator = (const uint64_t&);
        
        void operator += (const BigNumber&);
        void operator -= (const BigNumber&);
        void operator *= (const BigNumber&);
        void operator /= (const BigNumber&);
        
        string toString() const;
    };
    
    BigNumber operator + (const BigNumber&, const BigNumber&);
    BigNumber operator - (const BigNumber&, const BigNumber&);
    BigNumber operator * (const BigNumber&, const BigNumber&);
    BigNumber operator / (const BigNumber&, const BigNumber&);
    
    bool operator ==(const BigNumber&, const BigNumber&);
    bool operator !=(const BigNumber&, const BigNumber&);
    bool operator <(const BigNumber&, const BigNumber&);
    
    std::ostream& operator << (std::ostream&, const BigNumber&);
    std::istream& operator >> (std::istream&, BigNumber&);
}

#endif	/* BIGNUMBER_H */

