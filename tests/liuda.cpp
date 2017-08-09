#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "liuda test 1" << std::endl;
}

void test2() {
    std::cout << "liuda test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (liuda) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% liuda" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (liuda)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (liuda)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (liuda)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (liuda)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

