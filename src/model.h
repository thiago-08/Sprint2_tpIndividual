#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

/**
 * @brief Classe que representa um Modelo (Model).
 * O model gerencia os sistemas e fluxos, de tal forma que roda a simulação de acordo
 *  com o tempo e atualizando sistema de acordo com fluxo.
 */
class Model
{
private:
    std::string name;
    std::vector<System *> systems;
    std::vector<Flow *> flows;

public:
    /**
     * @brief Construtor padrão.
     */
    Model();

    /**
     * @brief Construtor de cópia.
     * @param mod Objeto Model a ser copiado.
     */
    Model(const Model &mod);

    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Model();

    /**
     * @brief Operador de atribuição.
     * @param mod Objeto Model a ser atribuído.
     * @return Referência para o próprio objeto atualizado.
     */
    Model &operator=(const Model &mod);

    /**
     * @brief Construtor parametrizado.
     * @param name Nome do modelo.
     */
    Model(std::string name);

    /**
     * @brief Adiciona um Sistema ao modelo.
     * @param s Ponteiro para o sistema a ser adicionado.
     */
    void add(System *s);

    /**
     * @brief Adiciona um Fluxo ao modelo.
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    void add(Flow *f);

    /**
     * @brief Executa a simulação do modelo no intervalo de tempo especificado.
     * Ao rodar sera feito o calculo de todos os fluxos e depois atualizar os sistemas.
     * @param t_initial Tempo inicial da simulação.
     * @param t_end Tempo final da simulação.
     */
    void run(int t_initial, int t_end);

    /**
     * @brief Retorna o nome do modelo.
     * @return std::string contendo o nome.
     */
    std::string getName() const;

    /**
     * @brief Define o nome do modelo.
     * @param name Novo nome do modelo.
     */
    void setName(std::string name);
};

#endif