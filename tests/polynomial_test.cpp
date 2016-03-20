#include <stdlib.h>
#include <iostream>

#include "polynomial.h"

/*
 * Simple C++ Test Suite
 */

void polynomial_test() {
    std::cout << "polynomial test 1" << std::endl;
    std::cout << "monomial creation" << std::endl;
    mc::polynomial<double> p = 10;
    std::cout << p << std::endl;
}

void polynomial_division_test() {
    std::cout << "polynomial test 2" << std::endl;
    mc::polynomial<double> a = {2, -3, 1};
    mc::polynomial<double> b = {-1, 1};
    mc::polynomial<double> result = {-2, 1};
    if(a / b == result){
        std::cout << "%TEST_PASSED% time=0 testname=polynomial_division_test (polynomial) message=polynomial division" << std::endl;
    }
    else{
        std::cout << "%TEST_FAILED% time=0 testname=polynomial_division_test (polynomial) message=polynomial division error" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% polynomial" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (polynomial)" << std::endl;
    polynomial_test();
    std::cout << "%TEST_FINISHED% time=0 test1 (polynomial)" << std::endl;

    std::cout << "%TEST_STARTED% polynomial_division_test (polynomial)\n" << std::endl;
    polynomial_division_test();
    std::cout << "%TEST_FINISHED% time=0 polynomial_division_test (polynomial)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

