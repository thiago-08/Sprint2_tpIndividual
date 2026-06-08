#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

/**
 * @defgroup FuncionalTests Testes Funcionais
 * @brief Validação de cenários de simulação completos usando apenas a API pública.
 *
 * Estes testes verificam o comportamento end-to-end do framework, operando
 * exclusivamente através das interfaces de `src/api/` e da @ref ModelFactory,
 * sem qualquer dependência das classes concretas de `src/impl/`.
 * @{
 */

/**
 * @brief Testa o modelo de crescimento/decaimento exponencial.
 *
 * Cria dois sistemas (pop1=100, pop2=0) conectados por um FlowExponencial
 * e executa 100 ciclos. Verifica os valores finais esperados.
 */
void exponentialFuncionalTest();

/**
 * @brief Testa o modelo de crescimento logístico.
 *
 * Cria dois sistemas (p1=100, p2=10) conectados por um FlowLogistic
 * e executa 100 ciclos. Verifica os valores finais esperados.
 */
void logisticalFuncionalTest();

/**
 * @brief Testa o modelo complexo com múltiplos sistemas e fluxos.
 *
 * Cria cinco sistemas interligados por seis FlowComplex e executa
 * 100 ciclos. Verifica os valores finais esperados em todos os sistemas.
 */
void complexFuncionalTest();

/** @} */ // fim do grupo FuncionalTests

#endif
