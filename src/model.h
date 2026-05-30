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
     * @brief Destrutor virtual padrão.
     */
    virtual ~Model() {};
    /**
     * @brief Adiciona um Sistema ao modelo.
     * @param s Ponteiro para o sistema a ser adicionado.
     */
    virtual void add(System *s) = 0;
    /**
     * @brief Adiciona um Fluxo ao modelo.
     * @param f Ponteiro para o fluxo a ser adicionado.
     */
    virtual void add(Flow *f) = 0;
    /**
     * @brief Executa a simulação do modelo no intervalo de tempo especificado.
     * Ao rodar sera feito o calculo de todos os fluxos e depois atualizar os sistemas.
     * @param t_initial Tempo inicial da simulação.
     * @param t_end Tempo final da simulação.
     */
    virtual void run(int t_initial, int t_end) = 0;
    /**
     * @brief Retorna o nome do modelo.
     * @return std::string contendo o nome.
     */
    virtual std::string getName() const = 0;
    /**
     * @brief Define o nome do modelo.
     * @param name Novo nome do modelo.
     */
    virtual void setName(std::string name) = 0;
};

#endif