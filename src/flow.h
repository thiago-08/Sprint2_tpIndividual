#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

/**
 * @brief Classe base abstrata que representa um Fluxo.
 * Um fluxo é responsavel por calcular valor de transferencia de um sistema para outro.
 */
class Flow
{
protected:
    std::string name;
    System *source;
    System *target;

public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Flow() {}
    /**
     * @brief Define o sistema de origem (fonte).
     * @param s Ponteiro para o sistema fonte.
     */
    virtual void setSource(System *s) = 0;
    /**
     * @brief Define o sistema de destino (alvo).
     * @param t Ponteiro para o sistema alvo.
     */
    virtual void setTarget(System *t) = 0;
    /**
     * @brief Retorna o sistema de origem.
     * @return System* Ponteiro para o sistema fonte.
     */
    virtual System *getSource() const = 0;
    /**
     * @brief Retorna o sistema de destino.
     * @return System* Ponteiro para o sistema alvo.
     */
    virtual System *getTarget() const = 0;
    /**
     * @brief Retorna o nome do fluxo.
     * @return std::string contendo o nome.
     */
    virtual std::string getName() const = 0;
    /**
     * @brief Define o nome do fluxo.
     * @param name Novo nome do fluxo.
     */
    virtual void setName(std::string name) = 0;
    /**
     * @brief Método virtual puro para executar a equação do fluxo.
     * @return double O valor calculado a ser transferido.
     */
    virtual double execute() = 0;
};

#endif