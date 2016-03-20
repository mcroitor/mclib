#include <iostream>

#include "biginteger.h"

namespace mc {
    /* TODO #: add sign support */

    BigInteger::BigInteger(): digits("0"){}
    BigInteger::BigInteger(uint64_t p){
        digits = ToString(p);
    }
    BigInteger::BigInteger(const BigInteger& p)
        : digits(p.digits){}
    BigInteger::BigInteger(const string& p){
        digits = normalize(p);
    }

    BigInteger BigInteger::operator =(const BigInteger& p){
        digits = p.digits;
        return *this;
    }
    BigInteger BigInteger::operator =(const string& p){
        digits = normalize(p);
        return *this;
    }
    BigInteger BigInteger::operator =(const uint64_t& p){
        digits = ToString(p);
        return *this;
    }
    
    string BigInteger::normalize(const string& p){
        string result("");
        string::const_iterator i = p.begin();
        while(is_digit(*i)){
            result.push_back(*i);
            ++i;
        }
        return result;
    }

    void BigInteger::operator +=(const BigInteger& p){
        string tmp = p.digits;
        uint8_t rest = 0, aux = 0;
        if(digits.size() < tmp.size()){
            digits.insert(digits.begin(), tmp.size() - digits.size(), '0');
        }
        else{
            tmp.insert(tmp.begin(), digits.size() - tmp.size(), '0');
        }
        
        //std::cout << "debug >> " << digits << "\n----- >> " << tmp << std::endl;
        string::reverse_iterator ri, rti;
        for(ri = digits.rbegin(), rti = tmp.rbegin(); 
                ri != digits.rend(); 
                ++ri, ++rti){
            aux = *ri + *rti - 2*'0' + rest;
            *ri = aux % 10 + '0';
            rest = aux / 10;
        }
        //std::cout << "debug >> " << digits << std::endl;
    }
    void BigInteger::operator -=(const BigInteger& p){
        string tmp = p.digits;
        int aux = 0, res = 0;
        string::reverse_iterator ri, rti;
        if(digits.size() > tmp.size()){
            tmp.insert(tmp.begin(), digits.size() - tmp.size(), '0');
        }
        for(ri = digits.rbegin(), rti = tmp.rbegin(); 
                ri != digits.rend(); ++ri, ++rti){
            aux = *ri - *rti - res;
            *ri = (aux + 10) % 10 + '0' ;
            res = (aux >= 0) ? 0 : 1;
        }
    }
    void BigInteger::operator *=(const BigInteger& p){}
    void BigInteger::operator /=(const BigInteger& p){}

    string BigInteger::toString() const{ return digits;}
    
    BigInteger operator + (const BigInteger& p1, const BigInteger& p2){
        BigInteger tmp(p1);
        tmp += p2;
        return tmp;
    }
    BigInteger operator - (const BigInteger& p1, const BigInteger& p2){
        BigInteger tmp(p1);
        tmp -= p2;
        return tmp;
    }
    BigInteger operator * (const BigInteger& p1, const BigInteger& p2){
        BigInteger tmp(p1);
        tmp *= p2;
        return tmp;
    }
    BigInteger operator / (const BigInteger& p1, const BigInteger& p2){
        BigInteger tmp(p1);
        tmp /= p2;
        return tmp;
    }
    
    bool operator ==(const BigInteger& p1, const BigInteger& p2){
        return p1.toString() == p2.toString();
    }    
    bool operator !=(const BigInteger& p1, const BigInteger& p2){
        return !(p1 == p2);
    }
    bool operator <(const BigInteger& p1, const BigInteger& p2){
        return p1.toString() < p2.toString();
    }
    
    std::ostream& operator << (std::ostream& out, const BigInteger& p){
        out << p.toString();
        return out;
    }
    std::istream& operator >> (std::istream& in, BigInteger& p){
        string tmp;
        in >> tmp;
        p = tmp;
        return in;
    }

}
