#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/**
 * @brief Interface abstrata de especificação para um Sistema.
 */
class System
{
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~System() {}

    /**
     * @brief Retorna o nome do sistema.
     * @return std::string contendo o nome identificador.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Retorna o valor atual armazenado pelo sistema.
     * @return double representando a quantidade/valor do sistema.
     */
    virtual double getValue() const = 0;

    /**
     * @brief Define um novo valor numérico para o sistema.
     * @param value Novo valor a ser atribuído.
     */
    virtual void setValue(double value) = 0;

    /**
     * @brief Define um novo nome identificador para o sistema.
     * @param name Novo nome a ser atribuído.
     */
    virtual void setName(std::string name) = 0;
};

#endif
