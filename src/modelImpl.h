#ifndef MODEL_Body_H
#define MODEL_Body_H

#include "handleBody.h"
#include "model.h"
#include <vector>

/**
 * @brief Classe que implementa as funções de gerenciamento de múltiplos sistemas e fluxos.
 * Responsável por executar os ciclos da simulação temporal atualizando os dados.
 */
class ModelBody : public Body
{
protected:
    /** @brief Nome do modelo de simulação. */
    std::string name;
    /** @brief Vetor de ponteiros contendo todos os sistemas adicionados ao modelo. */
    std::vector<System *> systems;
    /** @brief Vetor de ponteiros contendo todos os fluxos adicionados ao modelo. */
    std::vector<Flow *> flows;
    /** @brief Vetor de ponteiros contendo todos os modelos. */
    static std::vector<Model*> models; 

    /**
     * @brief Construtor padrão de ModelBody.
     */
    ModelBody();

    /**
     * @brief Construtor parametrizado de ModelBody.
     * @param name Nome do modelo de simulação.
     */
    ModelBody(std::string name);

public:
    /**
     * @brief Destrutor virtual de ModelBody.
     */
    virtual ~ModelBody();

    void run(int t_initial, int t_end);
    std::string getName() const;
    void setName(std::string name);

    /**
     * @brief Cria e adiciona um novo Sistema à implementação do modelo.
     */
    System* createSystem(std::string name, double value);

    /**
     * @brief Remove o sistema do vetor interno e o destrói da memória
     */
    bool deleteSystem(System* s);

    /**
     * @brief Remove o fluxo do vetor interno e o destrói da memória.
     */
    bool deleteFlow(Flow* f);

    friend class Model; //to have acess to models
    friend class UnitModel;
    friend class ModelHandle;
    friend class Handle<ModelBody>;

private:

    /** @brief Adiciona um sistema ao modelo. */
    void add(System *s);
    
    /** @brief Adiciona um fluxo ao modelo. */
    void add(Flow *f);
};

/** @brief Classe que representa um manipulador de modelo. */
class ModelHandle : public Model, public Handle<ModelBody>{
friend class UnitModel;
public:
    /** @brief Construtor de ModelHandle com parâmetro opcional. */ 
    ModelHandle(std::string name = "") {
        pImpl_->setName(name);
    }

    /** @brief Destrutor virtual de ModelHandle. */
    virtual ~ModelHandle() {}

    /** @brief Método para criar um novo sistema. */
    System* createSystem(std::string name, double value) override {
        return pImpl_->createSystem(name, value);
    }

    /** @brief Método para remover um sistema do modelo. */
    bool deleteSystem(System* s) override {
        return pImpl_->deleteSystem(s);
    }

    /** @brief Método para remover um fluxo do modelo. */
    bool deleteFlow(Flow* f) override {
        return pImpl_->deleteFlow(f);
    }

    /** @brief Método para executar o modelo. */
    void run(int t_initial, int t_end) override {
        pImpl_->run(t_initial, t_end);
    }

    /** @brief Método para obter o nome do modelo. */
    std::string getName() const override {
        return pImpl_->getName();
    }

    /** @brief Método para definir o nome do modelo. */
    void setName(std::string name) override {
        pImpl_->setName(name);
    }

protected:
    /** @brief Método para adicionar um sistema ao modelo. */
    void add(System *s) override {
        pImpl_->add(s);
    }

    /** @brief Método para adicionar um fluxo ao modelo. */
    void add(Flow *f) override {
        pImpl_->add(f);
    }
};

#endif