#include <stdlib.h>
#include <iostream>
#include "BigInteger.h"

/*
 * Simple C++ Test Suite
 */

void testBigInteger() {
    mc::BigInteger bigInteger;
    std::cout << bigInteger << std::endl;
    if (bigInteger.toString() != "0") {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger (bi_test) message=error message sample" << std::endl;
    }
}

void testBigInteger2() {
    int64_t p0 = -5;
    mc::BigInteger bigInteger(p0);
    std::cout << bigInteger << std::endl;
    if (bigInteger.toString() != "-5") {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger2 (bi_test) message=error message sample" << std::endl;
    }
}

void testBigInteger3() {
    const mc::BigNumber& p0 = mc::BigNumber(5);
    mc::BigInteger bigInteger(p0);
    std::cout << bigInteger << std::endl;
    if (bigInteger.toString() != "5") {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger3 (bi_test) message=error message sample" << std::endl;
    }
}

void testBigInteger4() {
    const mc::BigInteger& p0 = mc::BigInteger(-10);
    mc::BigInteger bigInteger(p0);
    std::cout << bigInteger << std::endl;
    if (bigInteger.toString() != "-10") {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger4 (bi_test) message=error message sample" << std::endl;
    }
}

void testBigInteger5() {
    const std::string& p0 = "-1234567890";
    mc::BigInteger bigInteger(p0);
    std::cout << bigInteger << std::endl;
    if (bigInteger.toString() != p0) {
        std::cout << "%TEST_FAILED% time=0 testname=testBigInteger5 (bi_test) message=error message sample" << std::endl;
    }
}

void testAbs() {
    const mc::BigInteger& p0(std::string("-1234567890"));
    mc::BigInteger result = abs(p0);
    std::cout << p0 << " - " << result << std::endl;
    if (result.toString() != std::string("1234567890")) {
        std::cout << "%TEST_FAILED% time=0 testname=testAbs (bi_test) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% bi_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger (bi_test)" << std::endl;
    testBigInteger();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger (bi_test)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger2 (bi_test)" << std::endl;
    testBigInteger2();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger2 (bi_test)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger3 (bi_test)" << std::endl;
    testBigInteger3();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger3 (bi_test)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger4 (bi_test)" << std::endl;
    testBigInteger4();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger4 (bi_test)" << std::endl;

    std::cout << "%TEST_STARTED% testBigInteger5 (bi_test)" << std::endl;
    testBigInteger5();
    std::cout << "%TEST_FINISHED% time=0 testBigInteger5 (bi_test)" << std::endl;

    std::cout << "%TEST_STARTED% testAbs (bi_test)" << std::endl;
    testAbs();
    std::cout << "%TEST_FINISHED% time=0 testAbs (bi_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

