#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "../api/model.h"
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
    /** @brief Vetor de ponteiros para todos os sistemas do modelo. */
    std::vector<System *> systems;
    /** @brief Vetor de ponteiros para todos os fluxos do modelo. */
    std::vector<Flow *> flows;

public:
    /**
     * @brief Construtor padrão. Inicializa o modelo com nome vazio.
     */
    ModelImpl();

    /**
     * @brief Construtor de cópia. Copia o nome e as referências de sistemas e fluxos.
     * @param mod Objeto ModelImpl de origem a ser copiado.
     */
    ModelImpl(const ModelImpl &mod);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do modelo de simulação.
     */
    ModelImpl(std::string name);

    /**
     * @brief Destrutor. Libera a memória de todos os sistemas e fluxos gerenciados.
     */
    virtual ~ModelImpl();

    /**
     * @brief Operador de atribuição por cópia.
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