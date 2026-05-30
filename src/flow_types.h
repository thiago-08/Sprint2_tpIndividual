#ifndef FLOW_TYPES_H
#define FLOW_TYPES_H

#include "flowImpl.h"

/**
 * @brief Classe que implementa um Fluxo Exponencial.
 * * Herda de Flow e implementa a equação exponencial.
 */
class FlowExponencial : public FlowImpl
{
public:
    FlowExponencial();
    FlowExponencial(const FlowExponencial &f);
    virtual ~FlowExponencial();
    FlowExponencial &operator=(const FlowExponencial &f);

    FlowExponencial(std::string name);

    /**
     * @brief Executa o cálculo exponencial do fluxo.
     * @return double O resultado da equação. Retorna 0.0 se a fonte for nula.
     */
    double execute() override;
};

/**
 * @brief Classe que implementa um Fluxo Logístico.
 * * Herda de Flow e implementa uma equação logística baseada no valor do sistema alvo.
 */
class FlowLogistic : public FlowImpl
{
public:
    FlowLogistic();
    FlowLogistic(const FlowLogistic &f);
    virtual ~FlowLogistic();
    FlowLogistic &operator=(const FlowLogistic &f);

    FlowLogistic(std::string name);

    /**
     * @brief Executa o cálculo logístico do fluxo.
     * @return double O resultado da equação. Retorna 0.0 se o alvo for nulo.
     */
    double execute() override;
};

/**
 * @brief Classe que implementa um Fluxo Complexo.
 * Herda de flow, implementado o comportamento de vários sistemas interligados.
 */
class FlowComplex : public FlowImpl
{
public:
    FlowComplex();
    FlowComplex(const FlowComplex &f);
    virtual ~FlowComplex();
    FlowComplex &operator=(const FlowComplex &f);

    FlowComplex(std::string name);

    /**
     * @brief Executa o cálculo complexo do fluxo.
     * @return double O resultado da equação.
     */
    double execute() override;
};

#endif