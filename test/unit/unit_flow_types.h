#ifndef UNIT_FLOW_TYPES_H
#define UNIT_FLOW_TYPES_H

/**
 * @brief Testes unitários para as equações dos fluxos especializados.
 */
class UnitFlowTypes {
public:
    /** @brief Testa a equação do FlowExponencial. */
    static void unit_FlowExponencial_execute();

    /** @brief Testa a equação do FlowLogistic. */
    static void unit_FlowLogistic_execute();

    /** @brief Testa a equação do FlowComplex. */
    static void unit_FlowComplex_execute();
};

/** @brief Executa todos os testes de equações de fluxo. */
void run_unit_tests_FlowTypes();

#endif