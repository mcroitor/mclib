/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   datetest.cpp
 * Author: mcroitor
 *
 * Created on 10 December 2017, 19:02
 */

#include <stdlib.h>
#include <iostream>
#include "date.h"

/*
 * Simple C++ Test Suite
 */

void testDate_t() {
    mc::utils::date_t _date_t();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t (datetest) message=error message sample" << std::endl;
    }
}

void testDate_t2() {
    const mc::utils::date_t& p0;
    mc::utils::date_t _date_t(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t2 (datetest) message=error message sample" << std::endl;
    }
}

void testDate_t3() {
    mc::utils::year_t p0;
    mc::utils::month_t p1;
    mc::utils::day_t p2;
    mc::utils::date_t _date_t(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t3 (datetest) message=error message sample" << std::endl;
    }
}

void testCurrent() {
    mc::utils::date_t _date_t;
    mc::utils::date_t& result = _date_t.current();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCurrent (datetest) message=error message sample" << std::endl;
    }
}

void testToString() {
    mc::utils::date_t _date_t;
    std::string result = _date_t.toString();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (datetest) message=error message sample" << std::endl;
    }
}

void testFormat() {
    mc::utils::date_t _date_t;
    std::string result = _date_t.format();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFormat (datetest) message=error message sample" << std::endl;
    }
}

void testFormat2() {
    std::string p0;
    mc::utils::date_t _date_t;
    _date_t.format(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFormat2 (datetest) message=error message sample" << std::endl;
    }
}

void testYear() {
    mc::utils::date_t _date_t;
    mc::utils::year_t result = _date_t.year();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testYear (datetest) message=error message sample" << std::endl;
    }
}

void testMonth() {
    mc::utils::date_t _date_t;
    mc::utils::month_t result = _date_t.month();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testMonth (datetest) message=error message sample" << std::endl;
    }
}

void testDay() {
    mc::utils::date_t _date_t;
    mc::utils::day_t result = _date_t.day();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDay (datetest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% datetest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t (datetest)" << std::endl;
    testDate_t();
    std::cout << "%TEST_FINISHED% time=0 testDate_t (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t2 (datetest)" << std::endl;
    testDate_t2();
    std::cout << "%TEST_FINISHED% time=0 testDate_t2 (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t3 (datetest)" << std::endl;
    testDate_t3();
    std::cout << "%TEST_FINISHED% time=0 testDate_t3 (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testCurrent (datetest)" << std::endl;
    testCurrent();
    std::cout << "%TEST_FINISHED% time=0 testCurrent (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (datetest)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testFormat (datetest)" << std::endl;
    testFormat();
    std::cout << "%TEST_FINISHED% time=0 testFormat (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testFormat2 (datetest)" << std::endl;
    testFormat2();
    std::cout << "%TEST_FINISHED% time=0 testFormat2 (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testYear (datetest)" << std::endl;
    testYear();
    std::cout << "%TEST_FINISHED% time=0 testYear (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testMonth (datetest)" << std::endl;
    testMonth();
    std::cout << "%TEST_FINISHED% time=0 testMonth (datetest)" << std::endl;

    std::cout << "%TEST_STARTED% testDay (datetest)" << std::endl;
    testDay();
    std::cout << "%TEST_FINISHED% time=0 testDay (datetest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

