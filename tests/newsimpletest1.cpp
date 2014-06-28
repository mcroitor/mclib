/* 
 * File:   matrix.cpp
 * Author: Krey
 *
 * Created on Jun 14, 2014, 8:53:24 PM
 */

#include <stdlib.h>
#include <iostream>
#include "matrix.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "matrix test 1" << std::endl;
    mc::matrix<int, 3, 4> m;
}

void test2() {
    std::cout << "matrix test 2" << std::endl;
    mc::matrix<int,5,2> m;
    std::cout << m;
}

void test3(){
    std::cout << "matrix test 3" << std::endl;
    mc::matrix<int,5,2> m1;
    mc::matrix<int,2,5> m2;
    try{
        m2 = mc::transponate(m1);
        std::cout <<  "%TEST_PASSED%" << std::endl;
    }
    catch(std::exception ex){
        std::cout << "%TEST_FAILED% time=0 testname=test2 (matrix) message=error transponation" << std::endl;
    }    
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% matrix" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (matrix)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (matrix)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (matrix)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (matrix)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (matrix)\n" << std::endl;
    test3();
    std::cout << "%TEST_FINISHED% time=0 test2 (matrix)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

