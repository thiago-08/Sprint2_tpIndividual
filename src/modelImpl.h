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

public:
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
     * @brief Destrutor virtual de ModelImpl.
     */
    virtual ~ModelImpl();

    /**
     * @brief Operador de atribuição por cópia (Sobrecarga de operador =).
     * @param mod Objeto ModelImpl de origem.
     * @return ModelImpl& Referência para o próprio modelo atualizado.
     */
    ModelImpl &operator=(const ModelImpl &mod);

    void add(System *s) override;
    void add(Flow *f) override;
    void run(int t_initial, int t_end) override;
    
    std::string getName() const override;
    void setName(std::string name) override;

    friend class UnitModel;
};

#endif