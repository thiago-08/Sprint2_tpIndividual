#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include <iostream>

int main() {
    std::cout << "--- INICIANDO TESTES FUNCIONAIS ---" << std::endl;
    
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    
    std::cout << "--- TODOS OS TESTES FUNCIONAIS PASSARAM ---" << std::endl;
    return 0;
}

#endif