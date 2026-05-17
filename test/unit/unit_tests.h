#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

// --- Testes da Classe System ---
void testSystemDefaultConstructor();
void testSystemParametrizedConstructor();
void testSystemGetters();
void testSystemSetters();

// --- Testes das Classes Flow ---
void testFlowGetters();
void testFlowSetters();
void testFlowExponentialExecute();
void testFlowLogisticExecute();
void testFlowComplexExecute();

// --- Testes da Classe Model ---
void testModelGetters();
void testModelSetters();
void testModelAddSystem();
void testModelAddFlow();
void testModelRun();

#endif