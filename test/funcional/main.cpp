#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include <iostream>

int main() {
    std::cout << "--- STARTING FUNCIONAL TESTS ---" << std::endl;
    
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    
    std::cout << "--- ALL TESTS WERE SUCCESSFUL ---" << std::endl;
    return 0;
}

#endif