#include "../api/model_factory.h"
#include "modelImpl.h"
#include "systemImpl.h"
#include "flow_types.h"

Model *ModelFactory::createModel(std::string name){
    return new ModelImpl(name);
}

System *ModelFactory::createSystem(std::string name, double value){
    return new SystemImpl(name, value);
}

Flow *ModelFactory::createFlowExponencial(std::string name){
    return new FlowExponencial(name);
}

Flow *ModelFactory::createFlowLogistic(std::string name){
    return new FlowLogistic(name);
}

Flow *ModelFactory::createFlowComplex(std::string name){
    return new FlowComplex(name);
}
