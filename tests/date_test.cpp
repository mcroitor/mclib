
#include <stdlib.h>
#include <iostream>
#include "date.h"

/*
 * Simple C++ Test Suite
 */

void testDate_t() {
    mc::utils::date_t _date_t;
    if (_date_t.day() != 1) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t (date_test) message=error message sample" << std::endl;
    }
}

void testDate_t2() {
    mc::utils::date_t p0 = mc::utils::date_t::current();
    mc::utils::date_t _date_t(p0);
    if (_date_t.year() != p0.year() || _date_t.month() != p0.month() || _date_t.day() != p0.day()) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t2 (date_test) message=error message sample" << std::endl;
    }
}

void testDate_t3() {
    mc::utils::year_t p0 = 2017;
    mc::utils::month_t p1 = 11;
    mc::utils::day_t p2 = 12;
    mc::utils::date_t _date_t(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDate_t3 (date_test) message=error message sample" << std::endl;
    }
}

void testCurrent() {
    mc::utils::date_t result = mc::utils::date_t::current();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCurrent (date_test) message=error message sample" << std::endl;
    }
}

void testToString() {
    mc::utils::date_t _date_t;
    std::string result = _date_t.toString();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testToString (date_test) message=error message sample" << std::endl;
    }
}

void testFormat() {
    mc::utils::date_t _date_t;
    std::string result = _date_t.format();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFormat (date_test) message=error message sample" << std::endl;
    }
}

void testFormat2() {
    std::string p0;
    mc::utils::date_t _date_t;
    _date_t.format(p0);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testFormat2 (date_test) message=error message sample" << std::endl;
    }
}

void testYear() {
    mc::utils::date_t _date_t;
    mc::utils::year_t result = _date_t.year();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testYear (date_test) message=error message sample" << std::endl;
    }
}

void testMonth() {
    mc::utils::date_t _date_t;
    mc::utils::month_t result = _date_t.month();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testMonth (date_test) message=error message sample" << std::endl;
    }
}

void testDay() {
    mc::utils::date_t _date_t;
    mc::utils::day_t result = _date_t.day();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDay (date_test) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% date_test" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t (date_test)" << std::endl;
    testDate_t();
    std::cout << "%TEST_FINISHED% time=0 testDate_t (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t2 (date_test)" << std::endl;
    testDate_t2();
    std::cout << "%TEST_FINISHED% time=0 testDate_t2 (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testDate_t3 (date_test)" << std::endl;
    testDate_t3();
    std::cout << "%TEST_FINISHED% time=0 testDate_t3 (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testCurrent (date_test)" << std::endl;
    testCurrent();
    std::cout << "%TEST_FINISHED% time=0 testCurrent (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testToString (date_test)" << std::endl;
    testToString();
    std::cout << "%TEST_FINISHED% time=0 testToString (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testFormat (date_test)" << std::endl;
    testFormat();
    std::cout << "%TEST_FINISHED% time=0 testFormat (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testFormat2 (date_test)" << std::endl;
    testFormat2();
    std::cout << "%TEST_FINISHED% time=0 testFormat2 (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testYear (date_test)" << std::endl;
    testYear();
    std::cout << "%TEST_FINISHED% time=0 testYear (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testMonth (date_test)" << std::endl;
    testMonth();
    std::cout << "%TEST_FINISHED% time=0 testMonth (date_test)" << std::endl;

    std::cout << "%TEST_STARTED% testDay (date_test)" << std::endl;
    testDay();
    std::cout << "%TEST_FINISHED% time=0 testDay (date_test)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

