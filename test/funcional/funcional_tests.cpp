/**
 * @file funcional_tests.cpp
 * @brief Implementação dos testes funcionais do framework MyVensim.
 *
 * Todo o acesso ao framework é feito exclusivamente via interfaces da
 * camada de API pública (`src/api/`) e da @ref ModelFactory. Nenhum
 * header de `src/impl/` é incluído aqui — demonstrando o desacoplamento
 * correto da arquitetura em camadas.
 */

#include "funcional_tests.h"
#include "../../src/api/system.h"
#include "../../src/api/flow.h"
#include "../../src/api/model.h"
#include "../../src/api/model_factory.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Compara dois doubles com precisão de 4 casas decimais.
 * @param result   Valor obtido pela simulação.
 * @param expected Valor esperado pela especificação.
 * @return true se os valores são iguais ao arredondar para 4 casas decimais.
 */
static bool compareRounded(double result, double expected)
{
    int resEscalonado = round(result   * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

void exponentialFuncionalTest()
{
    cout << "Starting Exponential Funcional Test..." << endl;

    System *pop1 = ModelFactory::createSystem("pop1", 100.0);
    System *pop2 = ModelFactory::createSystem("pop2", 0.0);
    Flow   *exp  = ModelFactory::createFlowExponencial("exponencial");

    exp->setSource(pop1);
    exp->setTarget(pop2);

    Model *m = ModelFactory::createModel("Exponencial Model");
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

    System *p1  = ModelFactory::createSystem("p1", 100.0);
    System *p2  = ModelFactory::createSystem("p2", 10.0);
    Flow   *log = ModelFactory::createFlowLogistic("logistical");

    log->setSource(p1);
    log->setTarget(p2);

    Model *m = ModelFactory::createModel("Logistical Model");
    m->add(p1);
    m->add(p2);
    m->add(log);

    m->run(0, 100);

    assert(compareRounded(p1->getValue(), 88.2167));
    assert(compareRounded(p2->getValue(), 21.7833));

    cout << "Logistical Test OK!" << endl;

    delete m;
}

void complexFuncionalTest()
{
    cout << "Starting Complex Funcional Test..." << endl;

    System *q1 = ModelFactory::createSystem("Q1", 100.0);
    System *q2 = ModelFactory::createSystem("Q2", 0.0);
    System *q3 = ModelFactory::createSystem("Q3", 100.0);
    System *q4 = ModelFactory::createSystem("Q4", 0.0);
    System *q5 = ModelFactory::createSystem("Q5", 0.0);

    Flow *f = ModelFactory::createFlowComplex("f");
    f->setSource(q1);
    f->setTarget(q2);

    Flow *g = ModelFactory::createFlowComplex("g");
    g->setSource(q1);
    g->setTarget(q3);

    Flow *r = ModelFactory::createFlowComplex("r");
    r->setSource(q2);
    r->setTarget(q5);

    Flow *t = ModelFactory::createFlowComplex("t");
    t->setSource(q2);
    t->setTarget(q3);

    Flow *u = ModelFactory::createFlowComplex("u");
    u->setSource(q3);
    u->setTarget(q4);

    Flow *v = ModelFactory::createFlowComplex("v");
    v->setSource(q4);
    v->setTarget(q1);

    Model *m = ModelFactory::createModel("Complex Model Q");
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
}
