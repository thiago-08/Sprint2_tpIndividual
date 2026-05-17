#include "unit_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/flow_types.h"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

// TESTES DA CLASSE SYSTEM

void testSystemDefaultConstructor()
{
    System s;
    assert(s.getName() == "");
    assert(s.getValue() == 0.0);
    cout << "testSystemDefaultConstructor OK!" << endl;
}

void testSystemParametrizedConstructor()
{
    System s("Test", 10.0);
    assert(s.getName() == "Test");
    assert(s.getValue() == 10.0);
    cout << "testSystemParametrizedConstructor OK!" << endl;
}

void testSystemGetters()
{
    System s("Test", 10.0);
    assert(s.getName() == "Test");
    assert(s.getValue() == 10.0);
    cout << "testSystemGetters OK!" << endl;
}

void testSystemSetters()
{
    System s;
    s.setName("NewName");
    s.setValue(20.5);

    assert(s.getName() == "NewName");
    assert(s.getValue() == 20.5);
    cout << "testSystemSetters OK!" << endl;
}

// TESTES DAS CLASSES FLOW

void testFlowGetters()
{
    System s1("S1", 10.0);
    System s2("S2", 20.0);
    FlowExponencial f("F");

    f.setSource(&s1);
    f.setTarget(&s2);

    assert(f.getSource() == &s1);
    assert(f.getTarget() == &s2);
    assert(f.getName() == "F");
    cout << "testFlowGetters OK!" << endl;
}

void testFlowSetters()
{
    System s1("S1", 10.0);
    System s2("S2", 20.0);
    FlowExponencial f("F");

    f.setSource(&s1);
    f.setTarget(&s2);

    assert(f.getSource() == &s1);
    assert(f.getTarget() == &s2);
    cout << "testFlowSetters OK!" << endl;
}

void testFlowExponentialExecute()
{
    System s("Test", 100.0);
    FlowExponencial f("exp");
    f.setSource(&s);

    assert(f.execute() == 1.0);
    cout << "testFlowExponentialExecute OK!" << endl;
}

void testFlowLogisticExecute()
{
    System s("Test", 10.0);
    FlowLogistic f("Log");
    f.setTarget(&s);

    assert(abs(f.execute() - 0.0857) < 0.0001);
    cout << "testFlowLogisticExecute OK!" << endl;
}

void testFlowComplexExecute()
{
    System s("Test", 100.0);
    FlowComplex f("Comp");
    f.setSource(&s);

    // O FlowComplex no seu código atual tem a mesma lógica do Exponencial
    assert(f.execute() == 1.0);
    cout << "testFlowComplexExecute OK!" << endl;
}

// TESTES DA CLASSE MODEL

void testModelGetters()
{
    Model m("TestModel");
    assert(m.getName() == "TestModel");
    cout << "testModelGetters OK!" << endl;
}

void testModelSetters()
{
    Model m;
    m.setName("NewModelName");
    assert(m.getName() == "NewModelName");
    cout << "testModelSetters OK!" << endl;
}

void testModelAddSystem()
{
    Model m("TestModel");
    System *s = new System("S", 10.0);
    m.add(s);

    cout << "testModelAddSystem OK!" << endl;
    delete s;
}

void testModelAddFlow()
{
    Model m("TestModel");
    FlowExponencial *f = new FlowExponencial("F");
    m.add(f);

    cout << "testModelAddFlow OK!" << endl;
    delete f;
}

void testModelRun()
{
    Model m("Simulation");
    System *q1 = new System("Q1", 100.0);
    System *q2 = new System("Q2", 0.0);
    FlowExponencial *f = new FlowExponencial("f");

    f->setSource(q1);
    f->setTarget(q2);

    m.add(q1);
    m.add(q2);
    m.add(f);

    m.run(0, 1);

    assert(q1->getValue() == 99.0);
    assert(q2->getValue() == 1.0);

    cout << "testModelRun OK!" << endl;

    delete q1;
    delete q2;
    delete f;
}