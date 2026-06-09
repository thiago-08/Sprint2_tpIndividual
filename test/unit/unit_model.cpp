#include "unit_model.h"
#include <assert.h>
#include "../../src/impl/modelImpl.h"
#include "../../src/impl/systemImpl.h"
#include "../../src/impl/flow_types.h"

void UnitModel::unit_Model_DefaultConstructor(){
    ModelImpl m1;
    assert(m1.name    == "");
    assert(m1.systems.empty());
    assert(m1.flows.empty());
}

void UnitModel::unit_Model_ParameterizedConstructor(){
    ModelImpl m2("Model Test");
    assert(m2.name == "Model Test");
}

void UnitModel::unit_Model_CopyConstructor(){
    ModelImpl m2("Model Test");
    SystemImpl *s = new SystemImpl("Sys", 10.0);
    FlowExponencial *f = new FlowExponencial("Flow");
    m2.add(s);
    m2.add(f);

    ModelImpl m3(m2);
    assert(m3.name == "Model Test");
    assert(m3.systems.size() == 1);
    assert(m3.flows.size() == 1);
    assert(m3.systems[0] == s);
    assert(m3.flows[0] == f);

    m3.systems.clear();
    m3.flows.clear();
}

void UnitModel::unit_Model_Operator(){
    ModelImpl m2("Model Test");
    SystemImpl *s = new SystemImpl("Sys", 10.0);
    FlowExponencial *f = new FlowExponencial("Flow");
    m2.add(s);
    m2.add(f);

    ModelImpl m4;
    m4 = m2;
    assert(m4.name == "Model Test");
    assert(m4.systems.size() == 1);
    assert(m4.flows.size() == 1);
    assert(m4.systems[0] == s);
    assert(m4.flows[0] == f);

    m4.systems.clear();
    m4.flows.clear();
}

void UnitModel::unit_Model_destructor(){
    ModelImpl *m = new ModelImpl();
    m->systems.push_back(new SystemImpl("Sys", 10.0));
    delete m;
}

void UnitModel::unit_Model_getName(){
    ModelImpl m;
    m.name = "Name";
    assert(m.getName() == "Name");
}

void UnitModel::unit_Model_setName(){
    ModelImpl m;
    m.setName("NewName");
    assert(m.name == "NewName");
}

void UnitModel::unit_Model_addSystem(){
    ModelImpl  m;
    SystemImpl *s = new SystemImpl("Sys", 10.0);
    m.add(s);
    assert(m.systems.size() == 1);
    assert(m.systems[0]    == s);
}

void UnitModel::unit_Model_addFlow(){
    ModelImpl m;
    FlowExponencial *f = new FlowExponencial("Flow");
    m.add(f);
    assert(m.flows.size() == 1);
    assert(m.flows[0]    == f);
}

void UnitModel::unit_Model_run(){
    ModelImpl m("Test Run");
    SystemImpl *s1 = new SystemImpl("Source", 100.0);
    SystemImpl *s2 = new SystemImpl("Target", 0.0);
    FlowExponencial *f  = new FlowExponencial("Flow");

    f->source = s1;
    f->target = s2;

    m.add(s1);
    m.add(s2);
    m.add(f);

    m.run(0, 1);

    assert(s1->value == 99.0);
    assert(s2->value == 1.0);
}

void run_unit_tests_Model(){
    UnitModel::unit_Model_DefaultConstructor();
    UnitModel::unit_Model_ParameterizedConstructor();
    UnitModel::unit_Model_CopyConstructor();
    UnitModel::unit_Model_Operator();
    UnitModel::unit_Model_destructor();
    UnitModel::unit_Model_getName();
    UnitModel::unit_Model_setName();
    UnitModel::unit_Model_addSystem();
    UnitModel::unit_Model_addFlow();
    UnitModel::unit_Model_run();
}
