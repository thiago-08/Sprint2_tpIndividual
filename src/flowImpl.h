#ifndef FLOW_Body_H
#define FLOW_Body_H

#include "handleBody.h"
#include "flow.h"
#include "system.h"

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

    /** @brief Método para definir o sistema de origem. */
    void setSource(System *s);
    
    /** @brief Método para definir o sistema de destino. */
    void setTarget(System *t);
    
    /** @brief Método para definir o nome do fluxo. */
    void setName(std::string n);

    /** @brief Método para obter o sistema de origem. */            
    System *getSource() const;
    
    /** @brief Método para obter o sistema de destino. */
    System *getTarget() const;
    
    /** @brief Método para obter o nome do fluxo. */
    std::string getName() const;

    friend class UnitFlow;
    friend class UnitModel;
    friend class Handle<FlowBody>;
};
/** @brief Classe que representa um manipulador de fluxo. */
class FlowHandle : public Flow, public Handle<FlowBody> {
    friend class UnitFlow;
    friend class UnitModel;
public:
    /** @brief Construtor de FlowHandle com parâmetros opcionais. */
    FlowHandle(std::string name = "", System* source = nullptr, System* target = nullptr) {
        this->pImpl_->setName(name);
        this->pImpl_->setSource(source);
        this->pImpl_->setTarget(target);
    }
    
    /** @brief Destrutor virtual de FlowHandle. */
    virtual ~FlowHandle() {}
    
    /** @brief Método virtual puro para executar o fluxo. */
    virtual double execute()=0;
    
    /** @brief Método para definir o sistema de origem. */
    void setSource(System *s) override { this->pImpl_->setSource(s); }
    
    /** @brief Método para definir o sistema de destino. */
    void setTarget(System *t) override { this->pImpl_->setTarget(t); }
    
    /** @brief Método para obter o sistema de origem. */
    System *getSource() const override { return this->pImpl_->getSource(); }
    
    /** @brief Método para obter o sistema de destino. */
    System *getTarget() const override { return this->pImpl_->getTarget(); }
    
    /** @brief Método para obter o nome do fluxo. */
    std::string getName() const override { return this->pImpl_->getName(); }
    
    /** @brief Método para definir o nome do fluxo. */
    void setName(std::string name) override { this->pImpl_->setName(name); }
};

#endif