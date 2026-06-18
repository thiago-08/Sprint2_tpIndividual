#include "unit_flow_types.h"
#include <assert.h>
#include <math.h>
#include "../../test/funcional/flow_types.h"
#include "../../src/systemImpl.h"

bool compareRounded(double result, double expected){
    int resEscalonado = round(result * 10000.0);
    int espEscalonado = round(expected * 10000.0);
    return resEscalonado == espEscalonado;
}

void UnitFlowTypes::unit_FlowExponencial_execute() {
    SystemHandle s1("s1", 100.0);
    FlowHandle<FlowExponencial> fExp("Exp");
    fExp.setSource(&s1); 
    assert(compareRounded(fExp.execute(), 1.0));
}

void UnitFlowTypes::unit_FlowLogistic_execute() {
    SystemHandle s1("s1", 10.0);
    FlowHandle<FlowLogistic> fLog("Log");
    fLog.setTarget(&s1); 
    assert(compareRounded(fLog.execute(), 0.0857)); 
}

void UnitFlowTypes::unit_FlowComplex_execute() {
    SystemHandle s1("s1", 100.0);
    FlowHandle<FlowComplex> fComp("Comp");
    fComp.setSource(&s1); 
    assert(compareRounded(fComp.execute(), 1.0));
}

void run_unit_tests_FlowTypes() {
    UnitFlowTypes::unit_FlowExponencial_execute();
    UnitFlowTypes::unit_FlowLogistic_execute();
    UnitFlowTypes::unit_FlowComplex_execute();
}