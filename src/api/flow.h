#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

/**
 * @brief Interface abstrata de especificação para um Fluxo.
 */
class Flow
{
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Flow() {}

    /**
     * @brief Define o sistema de origem (fonte) da transferência.
     * @param s Ponteiro para o sistema de onde sairá o valor.
     */
    virtual void setSource(System *s) = 0;

    /**
     * @brief Define o sistema de destino (alvo) da transferência.
     * @param t Ponteiro para o sistema que receberá o valor.
     */
    virtual void setTarget(System *t) = 0;

    /**
     * @brief Retorna o ponteiro para o sistema de origem atual.
     * @return System* Ponteiro do sistema fonte.
     */
    virtual System *getSource() const = 0;

    /**
     * @brief Retorna o ponteiro para o sistema de destino atual.
     * @return System* Ponteiro do sistema alvo.
     */
    virtual System *getTarget() const = 0;

    /**
     * @brief Retorna o nome identificador do fluxo.
     * @return std::string contendo o nome do fluxo.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define um nome identificador para o fluxo.
     * @param name Novo nome a ser atribuído.
     */
    virtual void setName(std::string name) = 0;

    /**
     * @brief Método virtual puro que executa a equação matemática do fluxo.
     * @return double O valor calculado a ser debitado da origem e creditado no destino.
     */
    virtual double execute() = 0;
};

#endif
