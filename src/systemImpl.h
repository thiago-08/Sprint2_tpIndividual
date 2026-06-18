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
    
    std::string getName() const;
    double getValue() const;
    void setValue(double value);
    void setName(std::string name);

    friend class Handle<SystemBody>;
    friend class UnitSystem;
    friend class UnitModel;
    friend class ModelBody;
    friend class UnitFlow;    
    friend class UnitFlowTypes;
};

class SystemHandle : public System, public Handle<SystemBody>{
    friend class UnitSystem;
    friend class UnitModel;
public:
    SystemHandle(std::string n = "", double v = 0.0) {
        pImpl_->setName(n);
        pImpl_->setValue(v);
    }
    virtual ~SystemHandle() {}
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string n) override { pImpl_->setName(n); }
    double getValue() const override { return pImpl_->getValue(); }
    void setValue(double v) override { pImpl_->setValue(v); }
};

#endif