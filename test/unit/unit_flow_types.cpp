/**
 * @file unit_flow_types.cpp
 * @brief Testes unitários das equações matemáticas das subclasses de FlowImpl.
 *
 * Testes de caixa-branca que verificam os resultados numéricos dos métodos
 * execute() de cada tipo de fluxo. Incluem diretamente `src/impl/` para
 * acessar os atributos protegidos necessários à configuração das fixtures.
 */

#include "unit_flow_types.h"
#include <assert.h>
#include <math.h>
#include "../../src/impl/flow_types.h"
#include "../../src/impl/systemImpl.h"

/**
 * @brief Compara dois doubles com precisão de 4 casas decimais.
 * @param result   Valor obtido.
 * @param expected Valor esperado.
 * @return true se iguais após arredondamento a 4 casas decimais.
 */
static bool compareRounded(double result, double expected)
{
    int resEscalonado = round(result   * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

void UnitFlowTypes::unit_FlowExponencial_execute()
{
    SystemImpl    s1("s1", 100.0);
    FlowExponencial fExp("Exp");
    fExp.source = &s1;
    assert(compareRounded(fExp.execute(), 1.0));
}

void UnitFlowTypes::unit_FlowLogistic_execute()
{
    SystemImpl  s1("s1", 10.0);
    FlowLogistic fLog("Log");
    fLog.target = &s1;
    assert(compareRounded(fLog.execute(), 0.0857));
}

void UnitFlowTypes::unit_FlowComplex_execute()
{
    SystemImpl  s1("s1", 100.0);
    FlowComplex fComp("Comp");
    fComp.source = &s1;
    assert(compareRounded(fComp.execute(), 1.0));
}

void run_unit_tests_FlowTypes()
{
    UnitFlowTypes::unit_FlowExponencial_execute();
    UnitFlowTypes::unit_FlowLogistic_execute();
    UnitFlowTypes::unit_FlowComplex_execute();
}
