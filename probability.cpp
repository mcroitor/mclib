#include "probability.h"
#include <functional>
#include <numeric>

namespace mc{
    namespace prob{
        double P(int success, int total){
            return (double)success / total;
        }

        double P_SUM(std::initializer_list<double> c){
            return std::accumulate(c.begin(), c.end(), 0);            
        }
        double P_PRODUCT(std::initializer_list<double> c){
            return std::accumulate(c.begin(), c.end(), 0, std::multiplies<double>());            
        }
    }
}