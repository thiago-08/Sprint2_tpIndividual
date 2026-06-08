/**
 * @file model_factory.cpp
 * @brief Implementação da ModelFactory.
 *
 * Este é o ÚNICO arquivo da camada de implementação que precisa ser compilado
 * junto com o código cliente quando não se utiliza linkagem dinâmica (.so).
 * Ele é o "ponto de costura" entre a API pública e as classes concretas:
 * inclui todos os headers de `src/impl/` e delega a criação de objetos.
 */

#include "../api/model_factory.h"
#include "modelImpl.h"
#include "systemImpl.h"
#include "flow_types.h"

Model *ModelFactory::createModel(std::string name)
{
    return new ModelImpl(name);
}

System *ModelFactory::createSystem(std::string name, double value)
{
    return new SystemImpl(name, value);
}

Flow *ModelFactory::createFlowExponencial(std::string name)
{
    return new FlowExponencial(name);
}

Flow *ModelFactory::createFlowLogistic(std::string name)
{
    return new FlowLogistic(name);
}

Flow *ModelFactory::createFlowComplex(std::string name)
{
    return new FlowComplex(name);
}
