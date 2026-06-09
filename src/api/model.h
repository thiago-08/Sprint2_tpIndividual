#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "system.h"
#include "flow.h"

/**
 * @brief Interface abstrata de especificação para um Modelo de Simulação.
 */
class Model
{
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Model() {}

    /**
     * @brief Registra e adiciona um Sistema ao escopo do modelo.
     * @param s Ponteiro para o objeto do sistema a ser inserido.
     */
    virtual void add(System *s) = 0;

    /**
     * @brief Registra e adiciona um Fluxo ao escopo do modelo.
     * @param f Ponteiro para o objeto do fluxo a ser inserido.
     */
    virtual void add(Flow *f) = 0;

    /**
     * @brief Executa a simulação, processando os fluxos e atualizando os sistemas
     *        para cada ciclo temporal no intervalo [t_initial, t_end).
     * @param t_initial Tempo/Ciclo de início da simulação.
     * @param t_end     Tempo/Ciclo final (exclusive) da simulação.
     */
    virtual void run(int t_initial, int t_end) = 0;

    /**
     * @brief Retorna o nome identificador do modelo.
     * @return std::string contendo o nome.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define um nome identificador para o modelo.
     * @param name Novo nome do modelo.
     */
    virtual void setName(std::string name) = 0;
};

#endif
