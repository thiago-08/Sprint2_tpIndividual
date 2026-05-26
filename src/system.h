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
     * @brief Construtor padrão.
     */
    System();

    /**
     * @brief Construtor de cópia.
     * @param sys Objeto System a ser copiado.
     */
    System(const System &sys);

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~System();

    /**
     * @brief Operador de atribuição.
     * @param sys Objeto System a ser atribuído.
     * @return Referência para o próprio objeto atualizado.
     */
    System &operator=(const System &sys);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do sistema.
     * @param value Valor inicial do sistema.
     */
    System(std::string name, double value);

    /**
     * @brief Retorna o nome do sistema.
     * @return std::string contendo o nome.
     */
    std::string getName() const;

    /**
     * @brief Retorna o valor atual do sistema.
     * @return double representando o valor.
     */
    double getValue() const;

    /**
     * @brief Define um novo valor para o sistema.
     * @param value Novo valor a ser atribuído.
     */
    void setValue(double value);

    /**
     * @brief Define um novo nome para o sistema.
     * @param name Novo nome a ser atribuído.
     */
    void setName(std::string name);
};

#endif