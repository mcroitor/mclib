/* 
 * File:   matrix.cpp
 * Author: Krey
 *
 * Created on Jun 14, 2014, 8:53:24 PM
 */

#include <stdlib.h>
#include <iostream>
#include "./algebra/matrix.h"

/*
 * Simple C++ Test Suite
 */

void creation_matrix_test() {
    std::cout << "matrix test 1" << std::endl;
    mc::matrix<int, 3, 4> m;
}

void test2() {
    std::cout << "matrix test 2" << std::endl;
    mc::matrix<int, 3, 2> m;
    m[0][0] = 1;
    m[0][1] = 5;
    m[1][0] = 2;
    m[2][1] = 2;

    std::cout << m;

    m.swap_cols(0, 1);
    std::cout << "swap columns 0 & 1:" << std::endl;
    std::cout << m;
}

void test3() {
    std::cout << "matrix test 3" << std::endl;
    mc::matrix<int, 5, 2> m1;
    mc::matrix<int, 2, 5> m2;
    try {
        m2 = mc::transponate(m1);
        std::cout << "%TEST_PASSED%" << std::endl;
    } catch (std::exception ex) {
        std::cout << "%TEST_FAILED% time=0 testname=test3 (matrix) message=error transponation" << std::endl;
    }
}

void test4() {
    std::cout << "matrix test 4" << std::endl;
    mc::matrix<int, 3, 2> m1;
    try {
        m1[0][0] = 1;
        m1[2][0] = -1;
        m1[1][0] = 2;
        m1[1][1] = 1;
    } catch (std::exception ex) {
        std::cout << "%TEST_FAILED% time=0 testname=test4 (matrix) message=error initialization" << std::endl;
    }
    
    mc::matrix<int, 2, 4> m2;
    try {        
        m2[0][0] = 1;
        m2[1][1] = 1;
        m2[0][2] = 1;
        m2[1][3] = 1;
    } catch (std::exception ex) {
        std::cout << "%TEST_FAILED% time=0 testname=test4 (matrix) message=error initialization" << std::endl;
    }

    mc::matrix<int, 3, 4> result;

    try {
        result = m1*m2;

        std::cout << m1 << std::endl;
        std::cout << m2 << std::endl;
        std::cout << result << std::endl;
        std::cout << "%TEST_PASSED%" << std::endl;
    } catch (std::exception ex) {
        std::cout << "%TEST_FAILED% time=0 testname=test4 (matrix) message=error multiplication" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% matrix" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (matrix)" << std::endl;
    creation_matrix_test();
    std::cout << "%TEST_FINISHED% time=0 test1 (matrix)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (matrix)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (matrix)" << std::endl;

    std::cout << "%TEST_STARTED% test3 (matrix)\n" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% time=0 test3 (matrix)" << std::endl;

    std::cout << "%TEST_STARTED% test4 (matrix)\n" << std::endl;
    test4();
    std::cout << "%TEST_FINISHED% time=0 test4 (matrix)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

