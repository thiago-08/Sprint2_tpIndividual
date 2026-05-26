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
     * @brief Construtor padrão. Inicializa ponteiros nulos e nome vazio.
     */
    Flow();

    /**
     * @brief Construtor de cópia.
     * @param fl Objeto Flow a ser copiado.
     */
    Flow(const Flow &fl);

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Flow();

    /**
     * @brief Operador de atribuição.
     * @param fl Objeto Flow a ser atribuído.
     * @return Referência para o próprio objeto atualizado.
     */
    Flow &operator=(const Flow &fl);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do fluxo.
     */
    Flow(std::string name);

    /**
     * @brief Define o sistema de origem (fonte).
     * @param s Ponteiro para o sistema fonte.
     */
    void setSource(System *s);

    /**
     * @brief Define o sistema de destino (alvo).
     * @param t Ponteiro para o sistema alvo.
     */
    void setTarget(System *t);

    /**
     * @brief Retorna o sistema de origem.
     * @return System* Ponteiro para o sistema fonte.
     */
    System *getSource() const;

    /**
     * @brief Retorna o sistema de destino.
     * @return System* Ponteiro para o sistema alvo.
     */
    System *getTarget() const;

    /**
     * @brief Retorna o nome do fluxo.
     * @return std::string contendo o nome.
     */
    std::string getName() const;

    /**
     * @brief Define o nome do fluxo.
     * @param name Novo nome do fluxo.
     */
    void setName(std::string name);

    /**
     * @brief Método virtual puro para executar a equação do fluxo.
     * @return double O valor calculado a ser transferido.
     */
    virtual double execute() = 0;
};

#endif