#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "system.h"

/**
 * @brief Classe que implementa System (herda da interface).
 * Herda da interface System e gerencia o armazenamento do nome e do valor numérico.
 */
class SystemImpl : public System {
protected:
    /** @brief Nome do sistema. */
    std::string name;
    /** @brief Valor numérico atual do sistema. */
    double value;

public:
    /**
     * @brief Construtor padrão de SystemImpl.
     * Inicializa os atributos com valores nulos/vazios.
     */
    SystemImpl();

    /**
     * @brief Construtor de cópia de SystemImpl.
     * @param sys Objeto SystemImpl de origem a ser copiado.
     */
    SystemImpl(const SystemImpl &sys);

    /**
     * @brief Construtor parametrizado de SystemImpl.
     * @param name Nome inicial a ser atribuído ao sistema.
     * @param value Valor inicial a ser atribuído ao sistema.
     */
    SystemImpl(std::string name, double value);

    /**
     * @brief Destrutor virtual de SystemImpl.
     */
    virtual ~SystemImpl();

    /**
     * @brief Operador de atribuição por cópia (Sobrecarga de operador =).
     * @param sys Objeto SystemImpl de origem para clonagem.
     * @return SystemImpl& Referência para o próprio objeto atualizado.
     */
    SystemImpl &operator=(const SystemImpl &sys);

    std::string getName() const override;
    double getValue() const override;
    void setValue(double value) override;
    void setName(std::string name) override;

    friend class UnitSystem;
};

#endif