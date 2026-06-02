#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @brief Testes unitários para a classe FlowImpl.
 */
class UnitFlow {
public:
    /** @brief Testa os construtores e operador de atribuição. */
    static void unit_Flow_constructor();

    /** @brief Testa o destrutor. */
    static void unit_Flow_destructor();

    /** @brief Testa o método getName. */
    static void unit_Flow_getName();

    /** @brief Testa o método setName. */
    static void unit_Flow_setName();

    /** @brief Testa o método getSource. */
    static void unit_Flow_getSource();

    /** @brief Testa o método setSource. */
    static void unit_Flow_setSource();

    /** @brief Testa o método getTarget. */
    static void unit_Flow_getTarget();

    /** @brief Testa o método setTarget. */
    static void unit_Flow_setTarget();
};

/** @brief Executa todos os testes unitários de Flow. */
void run_unit_tests_Flow();

#endif