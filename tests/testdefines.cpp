/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   testdefines.cpp
 * Author: krey
 *
 * Created on 8 августа 2017 г., 20:44
 */

#include <stdlib.h>
#include <iostream>
#include "defines.h"

/*
 * Simple C++ Test Suite
 */

void testAbs_1() {
    const int p = 10;
    int result = mc::abs(p);
    if (result != 10) {
        std::cout << "%TEST_FAILED% time=0 testname=testAbs_1 (testdefines) message=abs(" << p << ") = " << result << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testAbs_1 (testdefines) message=abs(" << p << ") = " << result << std::endl;
    }
}

void testAbs_2() {
    const int p = -10;
    int result = mc::abs(p);
    if (result != 10) {
        std::cout << "%TEST_FAILED% time=0 testname=testAbs_2 (testdefines) message=abs(" << p << ") = " << result << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testAbs_2 (testdefines) message=abs(" << p << ") = " << result << std::endl;
    }
}

void testDbl_compare_1() {
    const double& p0 = 0.99;
    const double& p1 = 1.00;
    bool result = mc::dbl_compare(p0, p1);
    if (result == true) {
        std::cout << "%TEST_FAILED% time=0 testname=testDbl_compare_1 (testdefines) message= " << p0 << " is equal " << p1 << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testDbl_compare_1 (testdefines) message= " << p0 << " is equal " << p1 << std::endl;
    }
}

void testDbl_compare_2() {
    const double& p0 = 0.999999999;
    const double& p1 = 1.000000000;
    bool result = mc::dbl_compare(p0, p1);
    if (result != true) {
        std::cout << "%TEST_FAILED% time=0 testname=testDbl_compare_2 (testdefines) message= " << p0 << " is equal " << p1 << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testDbl_compare_2 (testdefines) message= " << p0 << " is equal " << p1 << std::endl;
    }
}

void testSqrt() {
    const double& p0 = 625;
    double result = mc::sqrt(p0);
    if (mc::dbl_compare(result, 25) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testSqrt (testdefines) message=sqrt fails" << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testSqrt (testdefines) message=no errors" << std::endl;
    }
    std::cout << "sqrt(" << p0 << ") = " << result << std::endl;
}

void testIsPrimary_1() {
    const long long& p0 = 13;
    bool result = mc::isPrimary(p0);
    if (result == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testIsPrimary_1 (testdefines) message=primary number is indicated as composed" << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testIsPrimary_1 (testdefines) message=no errors" << std::endl;
    }
    std::cout << p0 << " is primary number" << std::endl;
}

void testTruncate() {
    const double& p0 = 12.01234;
    const int& p1 = 3;
    double result = mc::truncate(p0, p1);
    if (mc::dbl_compare(result, 12.012) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testTruncate (testdefines) message=error message sample" << std::endl;
    }
    std::cout << p0 << " truncated is " << result << std::endl;
}

void testGrad2rad() {
    const int& p0 = 180;
    double result = mc::grad2rad(p0);
    if (mc::dbl_compare(result, mc::PI) == false) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrad2rad (testdefines) message=error message sample" << std::endl;
    }
    std::cout << p0 << " graduses is " << result << " radians" << std::endl;
}

void testRad2grad() {
    const double& p0 = mc::PI;
    int result = mc::rad2grad(p0);
    if (result != 180) {
        std::cout << "%TEST_FAILED% time=0 testname=testRad2grad (testdefines) message=error message sample" << std::endl;
    }
    std::cout << p0 << " radians is " << result << " graduses" << std::endl;
}

void testArctg() {
    const double& p0 = 0.5; // bad if p > 1!!!!
    try {
        double result = mc::arctg(p0);
        if (mc::dbl_compare(result, 0.463647) != true) {
            std::cout << "%TEST_FAILED% time=0 testname=testArctg (testdefines) message=error message sample" << std::endl;
        } else {
            std::cout << "%TEST_PASSED% time=0 testname=testArctg (testdefines) message=no error" << std::endl;
        }
        std::cout << "arctg( " << p0 << " ) = " << result << " radians" << std::endl;
    } catch (mc::ERROR e) {
        std::cout << "%TEST_FAILED% time=0 testname=testArctg (testdefines) message=exception thrown " << e << std::endl;
    }

}

void testTg() {
    const double& p0 = mc::PI / 4;
    double result = mc::tg(p0);
    if (mc::dbl_compare(result, 1) != true ) {
        std::cout << "%TEST_FAILED% time=0 testname=testTg (testdefines) message=error message sample" << std::endl;
    }
    std::cout << "tg( " << p0 << " ) = " << result << std::endl;
}

void testSin() {
    const double& p0 = mc::PI/6;
    double result = mc::sin(p0);
    if (mc::dbl_compare(result, 0.5) != true) {
        std::cout << "%TEST_FAILED% time=0 testname=testSin (testdefines) message=error message sample" << std::endl;
    }
    std::cout << "sin(" <<p0 << ") = " << result << std::endl;
}

void testCos() {
    const double& p0 = mc::PI/3;
    double result = mc::cos(p0);
    if (mc::dbl_compare(result, 0.5) != true) {
        std::cout << "%TEST_FAILED% time=0 testname=testCos (testdefines) message=error message sample" << std::endl;
    }
    std::cout << "cos(" <<p0 << ") = " << result << std::endl;
}

void testIs_digit() {
    const char& p0 = '5';
    bool result = mc::is_digit(p0);
    if (result != true) {
        std::cout << "%TEST_FAILED% time=0 testname=testIs_digit (testdefines) message=error message sample" << std::endl;
    }
}

void testToString() {
    int64_t p0 = 123;
    size_t p1 = 5;
    std::string result = mc::ToString(p0, p1);
    if (result != "00123") {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (testdefines) message=error message sample" << std::endl;
    }
    std::cout << "toString( " << p0 << " ) = '" << result << "'" << std::endl;
}

void testMin() {
    double p0 = 100;
    double p1 = 1;
    double result = mc::min(p0, p1);
    if (result != p1) {
        std::cout << "%TEST_FAILED% time=0 testname=testMin (testdefines) message=min(" << p0 << ", " << p1 << ") = " << result << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testMin (testdefines) message=min(" << p0 << ", " << p1 << ") = " << result << std::endl;
    }
}

void testMin2() {
    double p0 = -10.2;
    double p1 = 0.2;
    double p2 = 12.32;
    double result = mc::min(p0, p1, p2);
    if (result != p0) {
        std::cout << "%TEST_FAILED% time=0 testname=testMin2 (testdefines) message=min(" << p0 << ", " << p1 << ", " << p2 << ") = " << result << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testMin2 (testdefines) message=min(" << p0 << ", " << p1 << ", " << p2 << ") = " << result << std::endl;
    }
}

void testGcd() {
    long long p0 = 100;
    long long p1 = 120;
    long long result = mc::gcd(p0, p1);
    if (result != 20) {
        std::cout << "%TEST_FAILED% time=0 testname=testGcd (testdefines) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testGcd (testdefines) message=no error" << std::endl;
    }
    std::cout << "gcd(" << p0 << ", " << p1 << ") = " << result << std::endl;
}

void testGcd2() {
    long long p0 = 6;
    long long p1 = 4;
    long long p2 = 8;
    long long result = mc::gcd(p0, p1, p2);
    if (result != 2) {
        std::cout << "%TEST_FAILED% time=0 testname=testGcd2 (testdefines) message=error message sample" << std::endl;
    } else {
        std::cout << "%TEST_PASSED% time=0 testname=testGcd2 (testdefines) message=no error" << std::endl;
    }
    std::cout << "gcd(" << p0 << ", " << p1 << ", " << p2 << ") = " << result << std::endl;
}

void testLcm() {
    long long p0 = 100;
    long long p1 = 120;
    long long result = mc::lcm(p0, p1);
    if (result != 600) {
        std::cout << "%TEST_FAILED% time=0 testname=testLcm (testdefines) message=lcm test failed" << std::endl;
    }
    std::cout << "lcm(" << p0 << ", " << p1 << ") = " << result << std::endl;
}

void testLcm2() {
    long long p0 = 4;
    long long p1 = 6;
    long long p2 = 8;
    long long result = mc::lcm(p0, p1, p2);
    if (result != 24) {
        std::cout << "%TEST_FAILED% time=0 testname=testLcm2 (testdefines) message=error message sample" << std::endl;
    }
    std::cout << "lcm(" << p0 << ", " << p1 << ", " << p2 << ") = " << result << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% testdefines" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testAbs_1 (testdefines)" << std::endl;
    testAbs_1();
    std::cout << "%TEST_FINISHED% time=0 testAbs_1 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testAbs_2 (testdefines)" << std::endl;
    testAbs_2();
    std::cout << "%TEST_FINISHED% time=0 testAbs_2 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testDbl_compare_1 (testdefines)" << std::endl;
    testDbl_compare_1();
    std::cout << "%TEST_FINISHED% time=0 testDbl_compare_1 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testDbl_compare_2 (testdefines)" << std::endl;
    testDbl_compare_2();
    std::cout << "%TEST_FINISHED% time=0 testDbl_compare_2 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testSqrt (testdefines)" << std::endl;
    testSqrt();
    std::cout << "%TEST_FINISHED% time=0 testSqrt (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testIsPrimary (testdefines)" << std::endl;
    testIsPrimary_1();
    std::cout << "%TEST_FINISHED% time=0 testIsPrimary (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testTruncate (testdefines)" << std::endl;
    testTruncate();
    std::cout << "%TEST_FINISHED% time=0 testTruncate (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testGrad2rad (testdefines)" << std::endl;
    testGrad2rad();
    std::cout << "%TEST_FINISHED% time=0 testGrad2rad (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testRad2grad (testdefines)" << std::endl;
    testRad2grad();
    std::cout << "%TEST_FINISHED% time=0 testRad2grad (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testArctg (testdefines)" << std::endl;
    testArctg();
    std::cout << "%TEST_FINISHED% time=0 testArctg (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testTg (testdefines)" << std::endl;
    testTg();
    std::cout << "%TEST_FINISHED% time=0 testTg (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testSin (testdefines)" << std::endl;
    testSin();
    std::cout << "%TEST_FINISHED% time=0 testSin (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testCos (testdefines)" << std::endl;
    testCos();
    std::cout << "%TEST_FINISHED% time=0 testCos (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testIs_digit (testdefines)" << std::endl;
    testIs_digit();
    std::cout << "%TEST_FINISHED% time=0 testIs_digit (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (testdefines)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testMin (testdefines)" << std::endl;
    testMin();
    std::cout << "%TEST_FINISHED% time=0 testMin (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testMin2 (testdefines)" << std::endl;
    testMin2();
    std::cout << "%TEST_FINISHED% time=0 testMin2 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testGcd (testdefines)" << std::endl;
    testGcd();
    std::cout << "%TEST_FINISHED% time=0 testGcd (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testGcd2 (testdefines)" << std::endl;
    testGcd2();
    std::cout << "%TEST_FINISHED% time=0 testGcd2 (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testLcm (testdefines)" << std::endl;
    testLcm();
    std::cout << "%TEST_FINISHED% time=0 testLcm (testdefines)" << std::endl;

    std::cout << "%TEST_STARTED% testLcm2 (testdefines)" << std::endl;
    testLcm2();
    std::cout << "%TEST_FINISHED% time=0 testLcm2 (testdefines)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

