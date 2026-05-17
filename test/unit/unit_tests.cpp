#include "unit_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include <cassert>
#include <iostream>
#include "../../src/flow_types.h"

using namespace std;

void testSystemGettersAndSetters() {
    System s("Test", 10.0);
    assert(s.getName() == "Test");
    assert(s.getValue() == 10.0);

    s.setValue(20.5);
    assert(s.getValue() == 20.5);
    cout << "testSystemGettersAndSetters OK!" << endl;
}

void testFlowExponentialExecute() {
    System s("Test", 100.0);
    FlowExponencial f("exp");
    f.setSource(&s);

    assert(f.execute() == 1.0); 
    cout << "testFlowExponentialExecute OK!" << endl;
}

void testFLowLogisticExecute(){
    System s("Test", 10.0);
    FlowLogistic f("Log");
    f.setTarget(&s);

    assert(abs(f.execute() - 0.0857) < 0.0001); 
    cout << "testFlowLogisticoExecute OK!" << endl;
}

void testFlowGettersAndSetters() {
    System s1("S1", 10.0);
    System s2("S2", 20.0);
    FlowExponencial f("F");
    
    f.setSource(&s1);
    f.setTarget(&s2);
    
    assert(f.getSource() == &s1);
    assert(f.getTarget() == &s2);
    assert(f.getName() == "F");
    cout << "testFlowGettersAndSetters OK!" << endl;
}

void testModelAddSystem() {
    Model m("TestModel");
    System* s = new System("S", 10.0);
    m.add(s);
    
    assert(m.getName() == "TestModel");
    cout << "testModelAddSystem OK!" << endl;
    delete s;
}

void testModelAddFlow() {
    Model m("TestModel");
    FlowExponencial* f = new FlowExponencial("F");
    m.add(f);
    cout << "testModelAddFlow OK!" << endl;
    delete f;
}