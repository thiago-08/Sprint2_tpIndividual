#include "unit_flow.h"
#include <assert.h>
#include "../../src/flowImpl.h"
#include "../../src/systemImpl.h" 

// Classe Abstract criada para testar a base abstrata FlowImpl
class AbstractFlow : public FlowImpl {
public:
    AbstractFlow() : FlowImpl() {}
    AbstractFlow(std::string name) : FlowImpl(name) {}
    AbstractFlow(const AbstractFlow &f) : FlowImpl(f) {} 
    AbstractFlow& operator=(const AbstractFlow& f) {    
        if (this == &f) return *this;
        FlowImpl::operator=(f);
        return *this;
    }
    double execute() override { return 0.0; } 
};

void unit_Flow_constructor() {
    //teste construtor padrão
    AbstractFlow f1;
    assert(f1.name == "");
    assert(f1.source == nullptr);
    assert(f1.target == nullptr);

    //teste construtor parametrizado
    AbstractFlow f2("Test Flow");
    assert(f2.name == "Test Flow");
    assert(f2.source == nullptr);
    assert(f2.target == nullptr);

    //teste construtor de cópia
    SystemImpl s1("Source", 10.0);
    SystemImpl s2("Target", 20.0);
    f2.setSource(&s1);
    f2.setTarget(&s2);
    AbstractFlow f3(f2);
    assert(f3.name == "Test Flow");
    assert(f3.source == &s1);
    assert(f3.target == &s2);

    //teste operador de atribuição
    AbstractFlow f4;
    f4 = f2;
    assert(f4.name == "Test Flow");
    assert(f4.source == &s1);
    assert(f4.target == &s2);
}

void unit_Flow_destructor() {
    AbstractFlow* f = new AbstractFlow("flow");
    delete f;
}

void unit_Flow_getName() {
    AbstractFlow f;
    f.name = "Name";
    assert(f.getName() == "Name");
}

void unit_Flow_setName() {
    AbstractFlow f;
    f.setName("NewName");
    assert(f.name == "NewName");
}

void unit_Flow_getSource() {
    AbstractFlow f;
    SystemImpl s("Sys1", 10.0);
    f.source = &s; 
    assert(f.getSource() == &s);
}

void unit_Flow_setSource() {
    AbstractFlow f;
    SystemImpl s("Sys1", 10.0);
    f.setSource(&s);
    assert(f.source == &s);
}

void unit_Flow_getTarget() {
    AbstractFlow f;
    SystemImpl s("Sys2", 20.0);
    f.target = &s; 
    assert(f.getTarget() == &s);
}

void unit_Flow_setTarget() {
    AbstractFlow f;
    SystemImpl s("Sys2", 20.0);
    f.setTarget(&s);
    assert(f.target == &s);
}

void run_unit_tests_Flow() {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
}