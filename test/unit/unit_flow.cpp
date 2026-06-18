#include "unit_flow.h"
#include <assert.h>
#include "../../src/flowImpl.h" 
#include "../../src/systemImpl.h" 

// Mock Body para testar a base Flow
class AbstractFlowBody : public FlowBody {
protected:
    AbstractFlowBody() : FlowBody() {}
    AbstractFlowBody(std::string name) : FlowBody(name) {}
public:
    double execute() override { return 0.0; } 
    friend class Handle<AbstractFlowBody>;
};

void UnitFlow::unit_Flow_DefaultConstructor() {
    FlowHandle<AbstractFlowBody> f1;
    assert(f1.getName() == "");
    assert(f1.getSource() == nullptr);
    assert(f1.getTarget() == nullptr);
}

void UnitFlow::unit_Flow_ParameterizedConstructor() {
    FlowHandle<AbstractFlowBody> f2("Test Flow");
    assert(f2.getName() == "Test Flow");
    assert(f2.getSource() == nullptr);
    assert(f2.getTarget() == nullptr);
}

void UnitFlow::unit_Flow_CopyConstructor(){
    FlowHandle<AbstractFlowBody> f2("Test Flow");
    SystemHandle s1("Source", 10.0);
    SystemHandle s2("Target", 20.0);
    f2.setSource(&s1);
    f2.setTarget(&s2);
    
    FlowHandle<AbstractFlowBody> f3(f2);
    assert(f3.getName() == "Test Flow");
    assert(f3.getSource() == &s1);
    assert(f3.getTarget() == &s2);
}

void UnitFlow::unit_Flow_Operator(){
    FlowHandle<AbstractFlowBody> f2("Test Flow");
    SystemHandle s1("Source", 10.0);
    SystemHandle s2("Target", 20.0);
    f2.setSource(&s1);
    f2.setTarget(&s2);

    FlowHandle<AbstractFlowBody> f4;
    f4 = f2;
    assert(f4.getName() == "Test Flow");
    assert(f4.getSource() == &s1);
    assert(f4.getTarget() == &s2);
}

void UnitFlow::unit_Flow_destructor() {
    FlowHandle<AbstractFlowBody>* f = new FlowHandle<AbstractFlowBody>("flow");
    delete f;
}

void UnitFlow::unit_Flow_getName() {
    FlowHandle<AbstractFlowBody> f;
    f.setName("Name");
    assert(f.getName() == "Name");
}

void UnitFlow::unit_Flow_setName() {
    FlowHandle<AbstractFlowBody> f;
    f.setName("NewName");
    assert(f.getName() == "NewName");
}

void UnitFlow::unit_Flow_getSource() {
    FlowHandle<AbstractFlowBody> f;
    SystemHandle s("Sys1", 10.0);
    f.setSource(&s); 
    assert(f.getSource() == &s);
}

void UnitFlow::unit_Flow_setSource() {
    FlowHandle<AbstractFlowBody> f;
    SystemHandle s("Sys1", 10.0);
    f.setSource(&s);
    assert(f.getSource() == &s);
}

void UnitFlow::unit_Flow_getTarget() {
    FlowHandle<AbstractFlowBody> f;
    SystemHandle s("Sys2", 20.0);
    f.setTarget(&s); 
    assert(f.getTarget() == &s);
}

void UnitFlow::unit_Flow_setTarget() {
    FlowHandle<AbstractFlowBody> f;
    SystemHandle s("Sys2", 20.0);
    f.setTarget(&s);
    assert(f.getTarget() == &s);
}

void run_unit_tests_Flow() {
    UnitFlow::unit_Flow_DefaultConstructor();
    UnitFlow::unit_Flow_ParameterizedConstructor();
    UnitFlow::unit_Flow_CopyConstructor();
    UnitFlow::unit_Flow_Operator();
    UnitFlow::unit_Flow_destructor();
    UnitFlow::unit_Flow_getName();
    UnitFlow::unit_Flow_setName();
    UnitFlow::unit_Flow_getSource();
    UnitFlow::unit_Flow_setSource();
    UnitFlow::unit_Flow_getTarget();
    UnitFlow::unit_Flow_setTarget();
}