#include "flow_types.h"
#include "../../src/system.h"
//Implementação do FlowExponencial

FlowExponencial::FlowExponencial() : FlowBody() {}

FlowExponencial::FlowExponencial(std::string name, System *source, System *target) 
    : FlowBody(name, source, target) {}

FlowExponencial::~FlowExponencial() {}

double FlowExponencial::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}

// Implementação do FlowLogistic

FlowLogistic::FlowLogistic() : FlowBody() {}

FlowLogistic::FlowLogistic(std::string name, System *source, System *target) 
    : FlowBody(name, source, target) {}

FlowLogistic::~FlowLogistic() {}

double FlowLogistic::execute() {
    if (getTarget() != nullptr) {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1.0 - (p2 / 70.0));
    }
    return 0.0;
}

// Implementação do FlowComplex

FlowComplex::FlowComplex() : FlowBody() {}

FlowComplex::FlowComplex(std::string name, System *source, System *target) 
    : FlowBody(name, source, target) {}

FlowComplex::~FlowComplex() {}

double FlowComplex::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}