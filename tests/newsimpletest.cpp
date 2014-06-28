/* 
 * File:   array test.cpp
 * Author: Root
 *
 * Created on Jun 14, 2014, 11:30:02 AM
 */

#include <stdlib.h>
#include <iostream>
#include "array.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "array test test 1" << std::endl;
    mc::array<int, 8> a; 
    
}

void test2(){
    mc::array<int, 10> a;
    std::cout << a;
}

//void test2() {
//    std::cout << "array test test 2" << std::endl;
//    std::cout << "%TEST_FAILED% time=0 testname=test2 (array test) message=error message sample" << std::endl;
//}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% array test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (array test)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (array test)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (array test)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (array test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

