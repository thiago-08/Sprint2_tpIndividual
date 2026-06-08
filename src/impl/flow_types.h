#ifndef FLOW_TYPES_H
#define FLOW_TYPES_H

#include "flowImpl.h"

/**
 * @addtogroup Impl
 * @{
 */

/**
 * @brief Fluxo com equação de crescimento/decaimento exponencial.
 *
 * Equação: `execute() = 0.01 * source->getValue()`
 *
 * Criado exclusivamente via @ref ModelFactory::createFlowExponencial.
 */
class FlowExponencial : public FlowImpl
{
public:
    /** @brief Construtor padrão. */
    FlowExponencial();

    /**
     * @brief Construtor de cópia.
     * @param f Objeto FlowExponencial de origem.
     */
    FlowExponencial(const FlowExponencial &f);

    /** @brief Destrutor virtual. */
    virtual ~FlowExponencial();

    /**
     * @brief Operador de atribuição por cópia.
     * @param f Objeto FlowExponencial de origem.
     * @return FlowExponencial& Referência para o objeto atualizado.
     */
    FlowExponencial &operator=(const FlowExponencial &f);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo exponencial.
     */
    FlowExponencial(std::string name);

    /**
     * @brief Executa o cálculo exponencial.
     * @return double Resultado de `0.01 * source->getValue()`, ou 0.0 se source for nulo.
     */
    double execute() override;
};

/**
 * @brief Fluxo com equação de crescimento logístico.
 *
 * Equação: `execute() = 0.01 * target->getValue() * (1 - target->getValue() / 70.0)`
 *
 * Modela uma população com capacidade de suporte igual a 70 unidades.
 * Criado exclusivamente via @ref ModelFactory::createFlowLogistic.
 */
class FlowLogistic : public FlowImpl
{
public:
    /** @brief Construtor padrão. */
    FlowLogistic();

    /**
     * @brief Construtor de cópia.
     * @param f Objeto FlowLogistic de origem.
     */
    FlowLogistic(const FlowLogistic &f);

    /** @brief Destrutor virtual. */
    virtual ~FlowLogistic();

    /**
     * @brief Operador de atribuição por cópia.
     * @param f Objeto FlowLogistic de origem.
     * @return FlowLogistic& Referência para o objeto atualizado.
     */
    FlowLogistic &operator=(const FlowLogistic &f);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo logístico.
     */
    FlowLogistic(std::string name);

    /**
     * @brief Executa o cálculo logístico.
     * @return double Resultado da equação logística, ou 0.0 se target for nulo.
     */
    double execute() override;
};

/**
 * @brief Fluxo com equação para cenários complexos de múltiplos sistemas.
 *
 * Equação: `execute() = 0.01 * source->getValue()`
 *
 * Utilizado em modelos com vários reservatórios interligados.
 * Criado exclusivamente via @ref ModelFactory::createFlowComplex.
 */
class FlowComplex : public FlowImpl
{
public:
    /** @brief Construtor padrão. */
    FlowComplex();

    /**
     * @brief Construtor de cópia.
     * @param f Objeto FlowComplex de origem.
     */
    FlowComplex(const FlowComplex &f);

    /** @brief Destrutor virtual. */
    virtual ~FlowComplex();

    /**
     * @brief Operador de atribuição por cópia.
     * @param f Objeto FlowComplex de origem.
     * @return FlowComplex& Referência para o objeto atualizado.
     */
    FlowComplex &operator=(const FlowComplex &f);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo complexo.
     */
    FlowComplex(std::string name);

    /**
     * @brief Executa o cálculo do fluxo complexo.
     * @return double Resultado de `0.01 * source->getValue()`, ou 0.0 se source for nulo.
     */
    double execute() override;
};

/** @} */ // fim do grupo Impl

#endif
