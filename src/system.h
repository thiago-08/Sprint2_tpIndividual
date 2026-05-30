#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/**
 * @brief Classe que representa um Sistema (System).
 * * Um Sistema é uma classe que armazena um valor numérico e possui um nome.
 */
class System
{
protected:
    std::string name;
    double value;

public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~System() {}
    /**
     * @brief Retorna o nome do sistema.
     * @return std::string contendo o nome.
     */
    virtual std::string getName() const = 0;
    /**
     * @brief Retorna o valor atual do sistema.
     * @return double representando o valor.
     */
    virtual double getValue() const = 0;
    /**
     * @brief Define um novo valor para o sistema.
     * @param value Novo valor a ser atribuído.
     */
    virtual void setValue(double value) = 0;
    /**
     * @brief Define um novo nome para o sistema.
     * @param name Novo nome a ser atribuído.
     */
    virtual void setName(std::string name) = 0;
};

#endif