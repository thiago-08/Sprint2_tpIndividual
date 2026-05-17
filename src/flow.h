#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
protected:
    std::string name;
    System* source;
    System* target;

public:
    // --- FORMA CANÔNICA ---
    Flow();                         // Construtor padrão
    Flow(const Flow& fl);           // Construtor de cópia
    virtual ~Flow();                // Destrutor virtual
    Flow& operator=(const Flow& fl); // Operador de atribuição

    // Construtor parametrizado
    Flow(std::string name);

    void setSource(System* s);
    void setTarget(System* t);
    System* getSource() const;
    System* getTarget() const;
    std::string getName() const;

    virtual double execute() = 0; 
};

#endif // FLOW_H