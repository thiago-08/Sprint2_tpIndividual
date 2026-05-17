#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"
#include <iostream>

int main() {
    std::cout << "--- STARTING UNIT TESTS ---" << std::endl;

    testSystemGettersAndSetters();

    testFlowExponentialExecute();
    testFLowLogisticExecute();
    testFlowGettersAndSetters();

    testModelAddSystem();
    testModelAddFlow();
    
    std::cout << "--- ALL TESTS WERE SUCCESSFUL ---" << std::endl;
    return 0;
}

#endif