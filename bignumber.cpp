#include <iostream>

#include "bignumber.h"

namespace mc {
    /* TODO #: add sign support */

    BigNumber::BigNumber(): digits("0"){}
    BigNumber::BigNumber(uint64_t p){
        digits = ToString(p);
    }
    BigNumber::BigNumber(const BigNumber& p)
        : digits(p.digits){}
    BigNumber::BigNumber(const string& p){
        digits = normalize(p);
    }

    BigNumber BigNumber::operator =(const BigNumber& p){
        digits = p.digits;
        return *this;
    }
    BigNumber BigNumber::operator =(const string& p){
        digits = normalize(p);
        return *this;
    }
    BigNumber BigNumber::operator =(const uint64_t& p){
        digits = ToString(p);
        return *this;
    }
    
    string BigNumber::normalize(const string& p){
        string result("");
        string::const_iterator i = p.begin();
        while(is_digit(*i)){
            result.push_back(*i);
            ++i;
        }
        return result;
    }

    void BigNumber::operator +=(const BigNumber& p){
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
    void BigNumber::operator -=(const BigNumber& p){
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
    void BigNumber::operator *=(const BigNumber& p){}
    void BigNumber::operator /=(const BigNumber& p){}

    string BigNumber::toString() const{ return digits;}
    
    BigNumber operator + (const BigNumber& p1, const BigNumber& p2){
        BigNumber tmp(p1);
        tmp += p2;
        return tmp;
    }
    BigNumber operator - (const BigNumber& p1, const BigNumber& p2){
        BigNumber tmp(p1);
        tmp -= p2;
        return tmp;
    }
    BigNumber operator * (const BigNumber& p1, const BigNumber& p2){
        BigNumber tmp(p1);
        tmp *= p2;
        return tmp;
    }
    BigNumber operator / (const BigNumber& p1, const BigNumber& p2){
        BigNumber tmp(p1);
        tmp /= p2;
        return tmp;
    }
    
    bool operator ==(const BigNumber& p1, const BigNumber& p2){
        return p1.toString() == p2.toString();
    }    
    bool operator !=(const BigNumber& p1, const BigNumber& p2){
        return !(p1 == p2);
    }
    bool operator <(const BigNumber& p1, const BigNumber& p2){
        return p1.toString() < p2.toString();
    }
    
    std::ostream& operator << (std::ostream& out, const BigNumber& p){
        out << p.toString();
        return out;
    }
    std::istream& operator >> (std::istream& in, BigNumber& p){
        string tmp;
        in >> tmp;
        p = tmp;
        return in;
    }

}
