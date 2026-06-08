#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "../api/system.h"

/**
 * @defgroup Impl Camada de Implementação
 * @brief Classes concretas que implementam as interfaces da camada API.
 *
 * Esta camada não deve ser incluída diretamente pelo código cliente.
 * O acesso deve ocorrer exclusivamente através das interfaces de `src/api/`
 * e da @ref ModelFactory.
 * @{
 */

/**
 * @brief Implementação concreta da interface System.
 *
 * Gerencia o armazenamento do nome e do valor numérico de um compartimento
 * da simulação. Instâncias desta classe são criadas exclusivamente pela
 * @ref ModelFactory::createSystem.
 */
class SystemImpl : public System
{
protected:
    /** @brief Nome do sistema. */
    std::string name;
    /** @brief Valor numérico atual do sistema. */
    double value;

public:
    /**
     * @brief Construtor padrão. Inicializa nome como vazio e valor como 0.0.
     */
    SystemImpl();

    /**
     * @brief Construtor de cópia.
     * @param sys Objeto SystemImpl de origem a ser copiado.
     */
    SystemImpl(const SystemImpl &sys);

    /**
     * @brief Construtor parametrizado.
     * @param name  Nome inicial do sistema.
     * @param value Valor inicial do sistema.
     */
    SystemImpl(std::string name, double value);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~SystemImpl();

    /**
     * @brief Operador de atribuição por cópia.
     * @param sys Objeto SystemImpl de origem.
     * @return SystemImpl& Referência para o próprio objeto atualizado.
     */
    SystemImpl &operator=(const SystemImpl &sys);

    std::string getName() const override;
    double      getValue() const override;
    void        setValue(double value) override;
    void        setName(std::string name) override;

    friend class UnitSystem;
    friend class UnitModel;
};

/** @} */ // fim do grupo Impl

#endif
