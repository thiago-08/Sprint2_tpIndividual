#include "unit_model.h"
#include <assert.h>
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/flow_types.h" 

void unit_Model_constructor() {
    //teste construtor padrão
    ModelImpl m1;
    assert(m1.name == "");
    assert(m1.systems.empty());
    assert(m1.flows.empty());

    //teste construtor parametrizado
    ModelImpl m2("Model Test");
    assert(m2.name == "Model Test");

    //teste construtor de cópia
    SystemImpl* s = new SystemImpl("Sys", 10.0);
    FlowExponencial* f = new FlowExponencial("Flow");
    m2.add(s);
    m2.add(f);
    ModelImpl m3(m2);
    assert(m3.name == "Model Test");
    assert(m3.systems.size() == 1);
    assert(m3.flows.size() == 1);
    assert(m3.systems[0] == s);
    assert(m3.flows[0] == f);

    //teste operador de atribuição
    ModelImpl m4;
    m4 = m2;
    assert(m4.name == "Model Test");
    assert(m4.systems.size() == 1);
    assert(m4.flows.size() == 1);
    assert(m4.systems[0] == s);
    assert(m4.flows[0] == f);

    m3.systems.clear();
    m3.flows.clear();
    m4.systems.clear();
    m4.flows.clear();
}

void unit_Model_destructor() {
    ModelImpl* m = new ModelImpl();
    m->systems.push_back(new SystemImpl("Sys", 10.0));
    delete m; 
}

void unit_Model_getName() {
    ModelImpl m;
    m.name = "Name"; 
    assert(m.getName() == "Name");
}

void unit_Model_setName() {
    ModelImpl m;
    m.setName("NewName");
    assert(m.name == "NewName");
}

void unit_Model_addSystem() {
    ModelImpl m;
    SystemImpl* s = new SystemImpl("Sys", 10.0); 
    m.add(s);
    assert(m.systems.size() == 1);
    assert(m.systems[0] == s);
}

void unit_Model_addFlow() {
    ModelImpl m;
    FlowExponencial* f = new FlowExponencial("Flow"); 
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0] == f);
}

void unit_Model_run() {
    ModelImpl m("Test Run");
    SystemImpl* s1 = new SystemImpl("Source", 100.0);
    SystemImpl* s2 = new SystemImpl("Target", 0.0);
    FlowExponencial* f = new FlowExponencial("Flow");

    f->setSource(s1);
    f->setTarget(s2);
    
    m.add(s1);
    m.add(s2);
    m.add(f);

    m.run(0, 1); 

    assert(s1->getValue() == 99.0);
    assert(s2->getValue() == 1.0);
}

void run_unit_tests_Model() {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_getName();
    unit_Model_setName();
    unit_Model_addSystem();
    unit_Model_addFlow();
    unit_Model_run();
}