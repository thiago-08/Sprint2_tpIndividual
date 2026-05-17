#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"
#include <iostream>

int main()
{
    std::cout << "--- Starting unit tests ---" << std::endl;

    std::cout << "\n[ System Tests ]" << std::endl;
    testSystemDefaultConstructor();
    testSystemParametrizedConstructor();
    testSystemGetters();
    testSystemSetters();

    std::cout << "\n[ Flow Tests ]" << std::endl;
    testFlowGetters();
    testFlowSetters();
    testFlowExponentialExecute();
    testFlowLogisticExecute();
    testFlowComplexExecute();

    std::cout << "\n[ Model Tests ]" << std::endl;
    testModelGetters();
    testModelSetters();
    testModelAddSystem();
    testModelAddFlow();
    testModelRun();

    std::cout << "\n--- ALL TESTS WERE SUCCESSFUL! ---" << std::endl;
    return 0;
}

#endif