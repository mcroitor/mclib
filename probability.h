#ifndef PROBABILITY_H
#define PROBABILITY_H
#include <initializer_list>

namespace mc{
    namespace prob{
        double P(int success, int total);
        double P_SUM(std::initializer_list<double>);
        double P_PRODUCT(std::initializer_list<double>);
    }
}

#endif /* PROBABILITY_H */

