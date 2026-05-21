#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/flow_types.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

bool compareRounded(double result, double expected)
{
    int resEscalonado = round(result * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

void exponentialFuncionalTest()
{
    cout << "Starting Exponential Funcional Test..." << endl;

    System *pop1 = new System("pop1", 100.0);
    System *pop2 = new System("pop2", 0.0);
    FlowExponencial *exp = new FlowExponencial("exponencial");

    exp->setSource(pop1);
    exp->setTarget(pop2);

    Model *m = new Model("Exponencial Model");
    m->add(pop1);
    m->add(pop2);
    m->add(exp);

    m->run(0, 100);

    assert(compareRounded(pop1->getValue(), 36.6032));
    assert(compareRounded(pop2->getValue(), 63.3968));

    cout << "Exponencial Test OK!" << endl;

    delete m;
}

void logisticalFuncionalTest()
{
    cout << "Starting Logistical Funcional Test..." << endl;

    System *p1 = new System("p1", 100.0);
    System *p2 = new System("p2", 10.0);
    FlowLogistic *log = new FlowLogistic("logistical");

    log->setSource(p1);
    log->setTarget(p2);

    Model *m = new Model("Logistical Model");
    m->add(p1);
    m->add(p2);
    m->add(log);

    m->run(0, 100);

    assert(compareRounded(p1->getValue(), 88.2167));
    assert(compareRounded(p2->getValue(), 21.7833));

    cout << "Logistical Test OK!" << endl;

    delete m;
    delete p1;
    delete p2;
    delete log;
}

void complexFuncionalTest()
{
    cout << "Starting Complex Funcional Test..." << endl;

    System *q1 = new System("Q1", 100.0);
    System *q2 = new System("Q2", 0.0);
    System *q3 = new System("Q3", 100.0);
    System *q4 = new System("Q4", 0.0);
    System *q5 = new System("Q5", 0.0);

    FlowComplex *f = new FlowComplex("f");
    f->setSource(q1);
    f->setTarget(q2);
    FlowComplex *g = new FlowComplex("g");
    g->setSource(q1);
    g->setTarget(q3);
    FlowComplex *r = new FlowComplex("r");
    r->setSource(q2);
    r->setTarget(q5);
    FlowComplex *t = new FlowComplex("t");
    t->setSource(q2);
    t->setTarget(q3);
    FlowComplex *u = new FlowComplex("u");
    u->setSource(q3);
    u->setTarget(q4);
    FlowComplex *v = new FlowComplex("v");
    v->setSource(q4);
    v->setTarget(q1);

    Model *m = new Model("Complex Model Q");
    m->add(q1);
    m->add(q2);
    m->add(q3);
    m->add(q4);
    m->add(q5);
    m->add(f);
    m->add(g);
    m->add(r);
    m->add(t);
    m->add(u);
    m->add(v);

    m->run(0, 100);

    assert(compareRounded(q1->getValue(), 31.8513));
    assert(compareRounded(q2->getValue(), 18.4003));
    assert(compareRounded(q3->getValue(), 77.1143));
    assert(compareRounded(q4->getValue(), 56.1728));
    assert(compareRounded(q5->getValue(), 16.4612));

    cout << "Complex Test OK!" << endl;

    delete m;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete f;
    delete g;
    delete r;
    delete t;
    delete u;
    delete v;
}