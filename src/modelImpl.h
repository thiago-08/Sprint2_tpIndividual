#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include <vector>

/**
 * @brief Classe que implementa as funções de gerenciamento de múltiplos sistemas e fluxos.
 * Responsável por executar os ciclos da simulação temporal atualizando os dados.
 */
class ModelImpl : public Model
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
     * @brief Construtor padrão de ModelImpl.
     */
    ModelImpl();

    /**
     * @brief Construtor de cópia de ModelImpl.
     * @param mod Objeto ModelImpl de origem a ser copiado.
     */
    ModelImpl(const ModelImpl &mod);

    /**
     * @brief Construtor parametrizado de ModelImpl.
     * @param name Nome do modelo de simulação.
     */
    ModelImpl(std::string name);

    /**
     * @brief Operador de atribuição por cópia (Sobrecarga de operador =).
     * @param mod Objeto ModelImpl de origem.
     * @return ModelImpl& Referência para o próprio modelo atualizado.
     */
    ModelImpl &operator=(const ModelImpl &mod);


public:
    /**
     * @brief Destrutor virtual de ModelImpl.
     */
    virtual ~ModelImpl();

    void run(int t_initial, int t_end) override;
    std::string getName() const override;
    void setName(std::string name) override;

    /**
     * @brief Cria e adiciona um novo Sistema à implementação do modelo.
     */
    System* createSystem(std::string name, double value) override;

    /**
     * @brief Remove o sistema do vetor interno e o destrói da memória
     */
    bool deleteSystem(System* s) override;

    /**
     * @brief Remove o fluxo do vetor interno e o destrói da memória.
     */
    bool deleteFlow(Flow* f) override;

    friend class Model; //to have acess to models
    friend class UnitModel;

private:
    void add(System *s) override;
    void add(Flow *f) override;
};

#endif