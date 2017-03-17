/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   defines.cpp
 * Author: krey
 *
 * Created on 21 сентября 2016 г., 20:57
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void test1() {
    int a = 12, b = 24, c = 36;
}

void test2() {
    std::cout << "defines test 2" << std::endl;
//    std::cout << "%TEST_FAILED% time=0 testname=test2 (defines) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% defines" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (defines)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (defines)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (defines)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (defines)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

