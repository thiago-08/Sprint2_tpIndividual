#include "funcional_tests.h"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

bool compareRounded(double result, double expected){
    int resEscalonado = round(result * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

void exponentialFuncionalTest(){
    cout << "Starting Exponential Funcional Test..." << endl;

    Model *m = Model::createModel("Exponencial Model");

    System *pop1 = m->createSystem("pop1", 100.0);
    System *pop2 = m->createSystem("pop2", 0.0);
    Flow *exp = m->createFlow<FlowExponencial>("exponencial", pop1, pop2);

    m->run(0, 100);

    assert(compareRounded(pop1->getValue(), 36.6032));
    assert(compareRounded(pop2->getValue(), 63.3968));

    cout << "Exponencial Test OK!" << endl;

    Model::deleteModel("Exponencial Model");
}

void logisticalFuncionalTest(){
    cout << "Starting Logistical Funcional Test..." << endl;

    Model *m = Model::createModel("Logistical Model");

    System *p1 = m->createSystem("p1", 100.0);
    System *p2 = m->createSystem("p2", 10.0);

    Flow *log = m->createFlow<FlowLogistic>("logistical", p1, p2);

    m->run(0, 100);

    assert(compareRounded(p1->getValue(), 88.2167));
    assert(compareRounded(p2->getValue(), 21.7833));

    cout << "Logistical Test OK!" << endl;

    Model::deleteModel("Logistical Model");
}

void complexFuncionalTest(){
    cout << "Starting Complex Funcional Test..." << endl;

    Model *m = Model::createModel("Complex Model Q");

    System *q1 = m->createSystem("Q1", 100.0);
    System *q2 = m->createSystem("Q2", 0.0);
    System *q3 = m->createSystem("Q3", 100.0);
    System *q4 = m->createSystem("Q4", 0.0);
    System *q5 = m->createSystem("Q5", 0.0);

    Flow *f = m->createFlow<FlowComplex>("f", q1, q2);
    Flow *g = m->createFlow<FlowComplex>("g", q1, q3);
    Flow *r = m->createFlow<FlowComplex>("r", q2, q5);
    Flow *t = m->createFlow<FlowComplex>("t", q2, q3);
    Flow *u = m->createFlow<FlowComplex>("u", q3, q4);
    Flow *v = m->createFlow<FlowComplex>("v", q4, q1);

    m->run(0, 100);

    assert(compareRounded(q1->getValue(), 31.8513));
    assert(compareRounded(q2->getValue(), 18.4003));
    assert(compareRounded(q3->getValue(), 77.1143));
    assert(compareRounded(q4->getValue(), 56.1728));
    assert(compareRounded(q5->getValue(), 16.4612));

    cout << "Complex Test OK!" << endl;

    Model::deleteModel("Complex Model Q");
}