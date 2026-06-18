#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @brief Testes unitários para a classe FlowImpl.
 */ 
class UnitFlow {
public:
    /** @brief Testa o construtor padrão da classe FlowImpl. */
    static void unit_Flow_DefaultConstructor();

    /** @brief Testa o construtor parametrizado da classe FlowImpl. */
    static void unit_Flow_ParameterizedConstructor();

    /** @brief Testa o construtor de cópia da classe FlowImpl. */
    static void unit_Flow_CopyConstructor();

    /** @brief Testa o operador de atribuição da classe FlowImpl. */
    static void unit_Flow_Operator();
    
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

    /** @brief Testa a integração entre os métodos de FlowImpl. */
    static void unit_Flow_handle();
};

/** @brief Executa todos os testes unitários de Flow. */
void run_unit_tests_Flow();

#endif