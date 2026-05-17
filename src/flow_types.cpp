#include "flow_types.h"

//Implementação do FlowExponencial

FlowExponencial::FlowExponencial() : Flow() {}

FlowExponencial::FlowExponencial(std::string name) : Flow(name) {}

FlowExponencial::FlowExponencial(const FlowExponencial& f) : Flow(f) {}

FlowExponencial::~FlowExponencial() {}

FlowExponencial& FlowExponencial::operator=(const FlowExponencial& f) {
    if (this == &f) return *this;
    Flow::operator=(f); 
    return *this;
}

double FlowExponencial::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}

// Implementação do FlowLogistic

FlowLogistic::FlowLogistic() : Flow() {}

FlowLogistic::FlowLogistic(std::string name) : Flow(name) {}

FlowLogistic::FlowLogistic(const FlowLogistic& f) : Flow(f) {}

FlowLogistic::~FlowLogistic() {}

FlowLogistic& FlowLogistic::operator=(const FlowLogistic& f) {
    if (this == &f) return *this;
    Flow::operator=(f);
    return *this;
}

double FlowLogistic::execute() {
    if (getTarget() != nullptr) {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1.0 - (p2 / 70.0));
    }
    return 0.0;
}

// Implementação do FlowComplex

FlowComplex::FlowComplex() : Flow() {}

FlowComplex::FlowComplex(std::string name) : Flow(name) {}

FlowComplex::FlowComplex(const FlowComplex& f) : Flow(f) {}

FlowComplex::~FlowComplex() {}

FlowComplex& FlowComplex::operator=(const FlowComplex& f) {
    if (this == &f) return *this;
    Flow::operator=(f);
    return *this;
}

double FlowComplex::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}