#ifndef MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"
#include <iostream>

int main() {
    std::cout << "--- INICIANDO TESTES UNITARIOS ---" << std::endl;
    
    // Testes de System
    testSystemGettersAndSetters();
    
    // Testes de Flow
    testFlowExponentialExecute();
    testFLowLogisticExecute();
    testFlowGettersAndSetters();
    
    // Testes de Model
    testModelAddSystem();
    testModelAddFlow();
    
    std::cout << "--- TODOS OS TESTES UNITARIOS PASSARAM ---" << std::endl;
    return 0;
}

#endif