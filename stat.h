#ifndef STAT_H
#define STAT_H
#include "defines.h"

namespace mc {
    namespace stat {

        template<class TYPE>
        TYPE min(std::initializer_list<TYPE> il) {
            std::initializer_list<TYPE>::const_iterator it = il.begin();
            TYPE tmp = *it;
            while (it != il.end()) {
                if (*it < tmp) tmp = *it;
                ++it;
            }
            return tmp;
        }

        template<class TYPE>
        TYPE max(std::initializer_list<TYPE> il) {
            std::initializer_list<TYPE>::const_iterator it = il.begin();
            TYPE tmp = *it;
            while (it != il.end()) {
                if (tmp < it) tmp = *it;
                ++it;
            }
            return tmp;
        }
        
        template<class TYPE>
        TYPE sum(std::initializer_list<TYPE> il){
            std::initializer_list<TYPE>::const_iterator it = il.begin();
            TYPE result = TYPE();
            while (it != il.end()) {
                result += *it;
                ++it;
            }
            return result;
        }

        template<class TYPE>
        TYPE average(std::initializer_list<TYPE> il){
            return sum<TYPE>(il) / il.size();
        }
        
        template<class TYPE>
        TYPE deviation(TYPE value, TYPE median){
            return mc::abs(median - value);
        }
    }
}

#endif /* STAT_H */

