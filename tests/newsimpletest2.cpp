/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest2.cpp
 * Author: Krey
 *
 * Created on 8 июня 2016 г., 13:27
 */

#include <stdlib.h>
#include <iostream>
#include "strmanip.h"

/*
 * Simple C++ Test Suite
 */

void testDistLevenshtein() {
    std::string p0 = "mama";
    std::string p1 = "pa";
    size_t result = mc::distLevenshtein(p0, p1);
    if (result != 3) {
        std::cout << "%TEST_FAILED% time=0 testname=testDistLevenshtein (newsimpletest2) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest2" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testDistLevenshtein (newsimpletest2)" << std::endl;
    testDistLevenshtein();
    std::cout << "%TEST_FINISHED% time=0 testDistLevenshtein (newsimpletest2)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

