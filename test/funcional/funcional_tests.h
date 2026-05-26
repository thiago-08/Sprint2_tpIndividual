#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

/**
 * @brief Executa o teste funcional para o Fluxo Exponencial.
 * * Cria dois sistemas e um fluxo exponencial ligando-os, e testa com assert.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para o Fluxo Logístico.
 * * Cria dois sistemas e um fluxo logístico ligando-os, e testa com assert.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional para um sistema Complexo.
 * * Monta uma rede mais complexa com cinco sistemas e seis fluxos
 * interconectados. Ao final da execução, valida o valor resultante em cada um dos sistemas.
 */
void complexFuncionalTest();

#endif