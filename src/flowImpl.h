#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"

/**
 * @brief Classe que implementa Fluxo (herda da interface). 
 * Armazena ponteiros para os sistemas de origem e destino, além do nome do fluxo.
 */
class FlowImpl : public Flow
{
protected:
    /** @brief Nome do fluxo. */
    std::string name;
    /** @brief Ponteiro para o sistema de origem. */
    System *source;
    /** @brief Ponteiro para o sistema de destino. */
    System *target;
    /**
     * @brief Construtor padrão de FlowImpl.
     */
    FlowImpl();
    /**
     * @brief Construtor de cópia de FlowImpl.
     * @param fl Objeto FlowImpl de origem a ser copiado.
     */
    FlowImpl(const FlowImpl &fl);
    /**
     * @brief Operador de atribuição por cópia (Sobrecarga de operador =).
     * @param fl Objeto FlowImpl de origem.
     * @return FlowImpl& Referência para o próprio fluxo atualizado.
     */
    FlowImpl &operator=(const FlowImpl &fl);
    /**
     * @brief Construtor parametrizado de FlowImpl.
     * @param name Nome a ser atribuído ao fluxo.
     * @param source Ponteiro do sistema inicial
     * @param target Ponteiro do sistema final
     */
    FlowImpl(std::string name, System *source = nullptr, System *target = nullptr);
    
public:
    /**
     * @brief Destrutor virtual de FlowImpl.
     */
    virtual ~FlowImpl();

    void setSource(System *s) override;
    void setTarget(System *t) override;
    void setName(std::string n) override;

    System *getSource() const override;
    System *getTarget() const override;
    std::string getName() const override;

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
};

#endif