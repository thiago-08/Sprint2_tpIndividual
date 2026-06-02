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

    /** @brief Testa o construtor de cópia da classe Model. */
    static void unit_Model_CopyConstructor();

    /** @brief Testa o operador de atribuição da classe Model. */
    static void unit_Model_Operator();

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

    /** @brief Testa a execução da simulação (método run). */
    static void unit_Model_run();
};

/** @brief Executa todos os testes unitários de Model. */
void run_unit_tests_Model();

#endif