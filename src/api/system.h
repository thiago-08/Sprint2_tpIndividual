#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

/**
 * @defgroup API Camada de Interface Pública (API)
 * @brief Interfaces abstratas que definem o contrato público do framework MyVensim.
 *
 * Esta camada expõe apenas as interfaces puras (sem detalhes de implementação).
 * Todo código cliente — testes funcionais, aplicações externas e a função main —
 * deve incluir apenas os cabeçalhos desta camada e usar a @ref ModelFactory para
 * instanciar objetos, nunca incluir headers de `src/impl/` diretamente.
 * @{
 */

/**
 * @brief Interface abstrata de especificação para um Sistema.
 *
 * Representa um compartimento ou reservatório no modelo de simulação.
 * Armazena um valor numérico que pode ser modificado pelos fluxos durante
 * a execução da simulação.
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

/** @} */ // fim do grupo API

#endif
