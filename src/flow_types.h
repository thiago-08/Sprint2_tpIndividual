#ifndef FLOW_TYPES_H
#define FLOW_TYPES_H

#include "flowImpl.h"

/**
 * @brief Classe que implementa o tipo de Fluxo Exponencial.
 * Herda de FlowImpl e implementa a equação de comportamento exponencial.
 */
class FlowExponencial : public FlowImpl
{
public:
    /**
     * @brief Construtor padrão do fluxo exponencial.
     */
    FlowExponencial();

    /**
     * @brief Construtor de cópia do fluxo exponencial.
     * @param f Objeto FlowExponencial de origem.
     */
    FlowExponencial(const FlowExponencial &f);

    /**
     * @brief Destrutor virtual do fluxo exponencial.
     */
    virtual ~FlowExponencial();

    /**
     * @brief Operador de atribuição por cópia para o fluxo exponencial.
     * @param f Objeto FlowExponencial de origem.
     * @return FlowExponencial& Referência para o objeto atualizado.
     */
    FlowExponencial &operator=(const FlowExponencial &f);

    /**
     * @brief Construtor parametrizado do fluxo exponencial.
     * @param name Nome do fluxo exponencial.
     */
    FlowExponencial(std::string name);

    /**
     * @brief Executa o cálculo exponencial do fluxo.
     * @return double O resultado da equação. Retorna 0.0 se a fonte for nula.
     */
    double execute() override;
};

/**
 * @brief Classe que implementa o tipo de Fluxo Logístico.
 * Herda de FlowImpl e implementa uma equação logística baseada no valor do sistema alvo.
 */
class FlowLogistic : public FlowImpl
{
public:
    /**
     * @brief Construtor padrão do fluxo logístico.
     */
    FlowLogistic();

    /**
     * @brief Construtor de cópia do fluxo logístico.
     * @param f Objeto FlowLogistic de origem.
     */
    FlowLogistic(const FlowLogistic &f);

    /**
     * @brief Destrutor virtual do fluxo logístico.
     */
    virtual ~FlowLogistic();

    /**
     * @brief Operador de atribuição por cópia para o fluxo logístico.
     * @param f Objeto FlowLogistic de origem.
     * @return FlowLogistic& Referência para o objeto atualizado.
     */
    FlowLogistic &operator=(const FlowLogistic &f);

    /**
     * @brief Construtor parametrizado do fluxo logístico.
     * @param name Nome do fluxo logístico.
     */
    FlowLogistic(std::string name);

    /**
     * @brief Executa o cálculo logístico do fluxo.
     * @return double O resultado da equação. Retorna 0.0 se o alvo for nulo.
     */
    double execute() override;
};

/**
 * @brief Classe que implementa o tipo de Fluxo Complexo.
 * Herda de FlowImpl, implementando o comportamento de vários sistemas interligados.
 */
class FlowComplex : public FlowImpl
{
public:
    /**
     * @brief Construtor padrão do fluxo complexo.
     */
    FlowComplex();

    /**
     * @brief Construtor de cópia do fluxo complexo.
     * @param f Objeto FlowComplex de origem.
     */
    FlowComplex(const FlowComplex &f);

    /**
     * @brief Destrutor virtual do fluxo complexo.
     */
    virtual ~FlowComplex();

    /**
     * @brief Operador de atribuição por cópia para o fluxo complexo.
     * @param f Objeto FlowComplex de origem.
     * @return FlowComplex& Referência para o objeto atualizado.
     */
    FlowComplex &operator=(const FlowComplex &f);

    /**
     * @brief Construtor parametrizado do fluxo complexo.
     * @param name Nome do fluxo complexo.
     */
    FlowComplex(std::string name);

    /**
     * @brief Executa o cálculo complexo do fluxo.
     * @return double O resultado da equação.
     */
    double execute() override;
};

#endif