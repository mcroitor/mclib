/* 
 * File:   newsimpletest2.cpp
 * Author: Krey
 *
 * Created on Jul 17, 2014, 8:18:21 PM
 */

#include <stdlib.h>
#include <iostream>

#include "array.h"
#include "extalg.h"

/*
 * Simple C++ Test Suite
 */

void insertion_sort_test() {
    std::cout << "insertion sort test" << std::endl;
    int tmp[10] = {1, 2, 0, 4, 9, 6, 7, 8, 3, 5};
    mc::array<int, 10> a(tmp, 10);
//    mc::insertion_sort(a.begin(), a.end());
    std::cout << a;
}

void bubble_sort_test() {
    std::cout << "bubble sort test" << std::endl;
    int tmp[10] = {1, 2, 0, 4, 9, 6, 7, 8, 3, 5};
    mc::array<int, 10> a(tmp, 10);
//    mc::bubble_sort(a.begin(), a.end());
    std::cout << a;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% extalg" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (insertion sort)" << std::endl;
    insertion_sort_test();
    std::cout << "%TEST_FINISHED% time=0 test1 (insertion sort)" << std::endl;
    
    std::cout << "%TEST_STARTED% test2 (bubble sort)" << std::endl;
    bubble_sort_test();
    std::cout << "%TEST_FINISHED% time=0 test1 (bubble sort)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

