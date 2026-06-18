#ifndef SYSTEM_Body_H
#define SYSTEM_Body_H

#include "system.h"
#include "handleBody.h"

/**
 * @brief Classe que Bodyementa System (herda da interface).
 * Herda da interface System e gerencia o armazenamento do nome e do valor numérico.
 */
class SystemBody : public Body {
protected:
    /** @brief Nome do sistema. */
    std::string name;
    /** @brief Valor numérico atual do sistema. */
    double value;

    /**
     * @brief Construtor padrão de SystemBody.
     * Inicializa os atributos com valores nulos/vazios.
     */
    SystemBody();

    /**
     * @brief Construtor parametrizado de SystemBody.
     * @param name Nome inicial a ser atribuído ao sistema.
     * @param value Valor inicial a ser atribuído ao sistema.
     */
    SystemBody(std::string name, double value);

public:
    /**
     * @brief Destrutor virtual de SystemBody.
    */
    virtual ~SystemBody();
    
    /** @brief Método para obter o nome do sistema. */
    std::string getName() const;
    
    /** @brief Método para obter o valor do sistema. */
    double getValue() const;
    
    /** @brief Método para definir o valor do sistema. */
    void setValue(double value);
    
    /** @brief Método para definir o nome do sistema. */
    void setName(std::string name);

    friend class Handle<SystemBody>;
    friend class UnitSystem;
    friend class UnitModel;
};

class SystemHandle : public System, public Handle<SystemBody>{
    friend class UnitSystem;
    friend class UnitModel;
public:
    
/** @brief Construtor de SystemHandle com parâmetros opcionais. */
    SystemHandle(std::string n = "", double v = 0.0) {
        pImpl_->setName(n);
        pImpl_->setValue(v);
    }

    /** @brief Destrutor virtual de SystemHandle. */
    virtual ~SystemHandle() {}

    /** @brief Método para obter o nome do sistema. */
    std::string getName() const override { return pImpl_->getName(); }
    
    /** @brief Método para definir o nome do sistema. */
    void setName(std::string n) override { pImpl_->setName(n); }
    
    /** @brief Método para obter o valor do sistema. */
    double getValue() const override { return pImpl_->getValue(); }
    
    /** @brief Método para definir o valor do sistema. */
    void setValue(double v) override { pImpl_->setValue(v); }
};

#endif