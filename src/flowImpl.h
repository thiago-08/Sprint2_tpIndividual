#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "handleBody.h"
#include "flow.h"
class System;

/**
 * @brief Classe que Bodyementa Fluxo (herda da interface). 
 * Armazena ponteiros para os sistemas de origem e destino, além do nome do fluxo.
 */
class FlowBody : public Body
{
protected:
    /** @brief Nome do fluxo. */
    std::string name;
    /** @brief Ponteiro para o sistema de origem. */
    System *source;
    /** @brief Ponteiro para o sistema de destino. */
    System *target;
    /**
     * @brief Construtor padrão de FlowBody.
     */
    FlowBody();
    /**
     * @brief Construtor parametrizado de FlowBody.
     * @param name Nome a ser atribuído ao fluxo.
     * @param source Ponteiro do sistema inicial
     * @param target Ponteiro do sistema final
     */
    FlowBody(std::string name, System *source = nullptr, System *target = nullptr);
    
public:
    /**
     * @brief Destrutor virtual de FlowBody.
     */
    virtual ~FlowBody();

    void setSource(System *s);
    void setTarget(System *t);
    void setName(std::string n);

    System *getSource() const;
    System *getTarget() const;
    std::string getName() const;

    virtual double execute() = 0;

    friend void unit_Flow_constructor();
    friend void unit_Flow_getName();
    friend void unit_Flow_setName();
    friend void unit_Flow_getSource();
    friend void unit_Flow_setSource();
    friend void unit_Flow_getTarget();
    friend void unit_Flow_setTarget();

    friend class UnitFlow;
    friend class UnitFlowTypes;
    friend class UnitModel;
    friend class Handle<FlowBody>;
};

class FlowHandle : public Flow, public Handle<FlowBody> {
    friend class UnitFlow;
    friend class UnitModel;
public:
    FlowHandle(std::string name = "", System* source = nullptr, System* target = nullptr) {
        pImpl_->setName(name);
        pImpl_->setSource(source);
        pImpl_->setTarget(target);
    }
    virtual ~FlowHandle() {}
    void setSource(System *s) override { pImpl_->setSource(s); }
    void setTarget(System *t) override { pImpl_->setTarget(t); }
    System *getSource() const override { return pImpl_->getSource(); }
    System *getTarget() const override { return pImpl_->getTarget(); }
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string name) override { pImpl_->setName(name); }
};

#endif