#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "../api/flow.h"

/**
 * @addtogroup Impl
 * @{
 */

/**
 * @brief Implementação base abstrata da interface Flow.
 *
 * Armazena os ponteiros para os sistemas de origem e destino e o nome do
 * fluxo. A equação de execução (execute()) permanece virtual pura, sendo
 * definida pelas subclasses de tipo concreto em flow_types.h.
 *
 * Instâncias nunca são criadas diretamente; use as subclasses por meio da
 * @ref ModelFactory.
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

public:
    /**
     * @brief Construtor padrão. Inicializa name como vazio, source e target como nullptr.
     */
    FlowImpl();

    /**
     * @brief Construtor de cópia.
     * @param fl Objeto FlowImpl de origem a ser copiado.
     */
    FlowImpl(const FlowImpl &fl);

    /**
     * @brief Destrutor virtual.
     */
    virtual ~FlowImpl();

    /**
     * @brief Operador de atribuição por cópia.
     * @param fl Objeto FlowImpl de origem.
     * @return FlowImpl& Referência para o próprio fluxo atualizado.
     */
    FlowImpl &operator=(const FlowImpl &fl);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome a ser atribuído ao fluxo.
     */
    FlowImpl(std::string name);

    void     setSource(System *s) override;
    void     setTarget(System *t) override;
    void     setName(std::string n) override;
    System  *getSource() const override;
    System  *getTarget() const override;
    std::string getName() const override;

    /**
     * @brief Equação matemática do fluxo — deve ser implementada pelas subclasses.
     * @return double Valor calculado a ser transferido entre os sistemas.
     */
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

/** @} */ // fim do grupo Impl

#endif
