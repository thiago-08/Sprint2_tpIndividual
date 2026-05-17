#ifndef FLOW_TYPES_H
#define FLOW_TYPES_H

#include "flow.h"

class FlowExponencial : public Flow {
public:
    FlowExponencial();                                    
    FlowExponencial(const FlowExponencial& f);              
    virtual ~FlowExponencial();                            
    FlowExponencial& operator=(const FlowExponencial& f); 

    FlowExponencial(std::string name);

    double execute() override;
};

class FlowLogistic : public Flow {
public:
    FlowLogistic();
    FlowLogistic(const FlowLogistic& f);
    virtual ~FlowLogistic();
    FlowLogistic& operator=(const FlowLogistic& f);

    FlowLogistic(std::string name);

    double execute() override;
};

class FlowComplex : public Flow {
public:
    FlowComplex();
    FlowComplex(const FlowComplex& f);
    virtual ~FlowComplex();
    FlowComplex& operator=(const FlowComplex& f);

    FlowComplex(std::string name);

    double execute() override;
};

#endif // FLOW_TYPES_H