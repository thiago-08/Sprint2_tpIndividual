#ifndef MODEL_FACTORY_H
#define MODEL_FACTORY_H

#include "model.h"
#include "system.h"
#include "flow.h"
#include <string>

/**
 * @addtogroup API
 * @{
 */

/**
 * @defgroup Factory Fábrica de Objetos (Factory)
 * @ingroup API
 * @brief Ponto de entrada centralizado para criação de todos os objetos do framework.
 *
 * A ModelFactory implementa o padrão **Factory Method**, desacoplando
 * completamente o código cliente das classes de implementação concretas.
 *
 * ### Motivação
 * Em uma arquitetura em camadas com componentização (`.so`/`.dll`), o cliente
 * não deve depender dos cabeçalhos de `src/impl/`. A factory resolve isso:
 * o cliente inclui apenas `src/api/model_factory.h` e obtém ponteiros para
 * as interfaces públicas, sem nunca invocar `new ConcreteClass()` diretamente.
 *
 * ### Uso típico
 * @code
 * #include "api/model_factory.h"
 *
 * System *pop1 = ModelFactory::createSystem("pop1", 100.0);
 * System *pop2 = ModelFactory::createSystem("pop2", 0.0);
 * Flow   *f    = ModelFactory::createFlowExponencial("exp");
 * Model  *m    = ModelFactory::createModel("Meu Modelo");
 *
 * f->setSource(pop1);
 * f->setTarget(pop2);
 * m->add(pop1);
 * m->add(pop2);
 * m->add(f);
 * m->run(0, 100);
 *
 * delete m; // destrói sistemas e fluxos internamente
 * @endcode
 * @{
 */

/**
 * @brief Fábrica estática para instanciação de objetos do framework MyVensim.
 *
 * Todos os objetos criados pelos métodos desta classe são alocados no heap.
 * A propriedade (responsabilidade de deletar) pode ser transferida para um
 * Model, que gerencia o ciclo de vida de seus sistemas e fluxos no destrutor.
 */
class ModelFactory
{
public:
    /**
     * @brief Cria e retorna um novo Model com o nome especificado.
     * @param name Nome identificador do modelo de simulação.
     * @return Model* Ponteiro para o objeto criado (propriedade do chamador).
     */
    static Model *createModel(std::string name);

    /**
     * @brief Cria e retorna um novo System com nome e valor iniciais.
     * @param name  Nome identificador do sistema.
     * @param value Valor numérico inicial do sistema.
     * @return System* Ponteiro para o objeto criado.
     */
    static System *createSystem(std::string name, double value);

    /**
     * @brief Cria e retorna um Fluxo com equação exponencial.
     *
     * Equação: `execute() = 0.01 * source->getValue()`
     *
     * @param name Nome identificador do fluxo.
     * @return Flow* Ponteiro para o objeto criado.
     */
    static Flow *createFlowExponencial(std::string name);

    /**
     * @brief Cria e retorna um Fluxo com equação logística.
     *
     * Equação: `execute() = 0.01 * target->getValue() * (1 - target->getValue() / 70.0)`
     *
     * @param name Nome identificador do fluxo.
     * @return Flow* Ponteiro para o objeto criado.
     */
    static Flow *createFlowLogistic(std::string name);

    /**
     * @brief Cria e retorna um Fluxo com equação complexa (interligação de sistemas).
     *
     * Equação: `execute() = 0.01 * source->getValue()`
     *
     * @param name Nome identificador do fluxo.
     * @return Flow* Ponteiro para o objeto criado.
     */
    static Flow *createFlowComplex(std::string name);
};

/** @} */ // fim do grupo Factory
/** @} */ // fim do grupo API

#endif
