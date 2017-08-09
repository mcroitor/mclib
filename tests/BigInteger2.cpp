/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BigInteger2.cpp
 * Author: krey
 *
 * Created on 25 февраля 2017 г., 19:57
 */

#include <stdlib.h>
#include <iostream>
#include "bignumber.h"

/*
 * Simple C++ Test Suite
 */

void testBigInteger() {
    mc::BigNumber bigInteger();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger (BigInteger2) message=error message sample" << std::endl;
    }
}

void testBigInteger2() {
    uint64_t p0;
    mc::BigNumber bigInteger(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger2 (BigInteger2) message=error message sample" << std::endl;
    }
}

void testBigInteger3() {
    BigInteger& p0;
    mc::BigNumber bigInteger(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger3 (BigInteger2) message=error message sample" << std::endl;
    }
}

void testBigInteger4() {
    string& p0;
    mc::BigNumber bigInteger(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger4 (BigInteger2) message=error message sample" << std::endl;
    }
}

void testToString() {
    mc::BigNumber bigInteger;
    string result = bigInteger.toString();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (BigInteger2) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% BigInteger2" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger (BigInteger2)" << std::endl;
    testBigInteger();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger (BigInteger2)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger2 (BigInteger2)" << std::endl;
    testBigInteger2();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger2 (BigInteger2)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger3 (BigInteger2)" << std::endl;
    testBigInteger3();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger3 (BigInteger2)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger4 (BigInteger2)" << std::endl;
    testBigInteger4();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger4 (BigInteger2)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (BigInteger2)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (BigInteger2)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

