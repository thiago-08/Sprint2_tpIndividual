#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @brief Testes unitários para a classe Model.
 */
class UnitModel {
public:
    /** @brief Testa o construtor padrão da classe Model. */
    static void unit_Model_DefaultConstructor();

    /** @brief Testa o construtor parametrizado da classe Model. */
    static void unit_Model_ParameterizedConstructor();

    /** @brief Testa o destrutor. */
    static void unit_Model_destructor();

    /** @brief Testa o método getName. */
    static void unit_Model_getName();

    /** @brief Testa o método setName. */
    static void unit_Model_setName();

    /** @brief Testa a inserção de sistemas no modelo. */
    static void unit_Model_addSystem();

    /** @brief Testa a inserção de fluxos no modelo. */
    static void unit_Model_addFlow();

    static void unit_Model_createModel();
    static void unit_Model_createSystem();
    static void unit_Model_createFlow();

    static void unit_Model_deleteModel();
    static void unit_Model_deleteSystem();
    static void unit_Model_deleteFlow();

    /** @brief Testa a execução da simulação (método run). */
    static void unit_Model_run();
};

/** @brief Executa todos os testes unitários de Model. */
void run_unit_tests_Model(); 

#endif