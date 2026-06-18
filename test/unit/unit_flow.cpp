#include "unit_flow.h"
#include <assert.h>
#include "../../src/flowImpl.h" 
#include "../../src/systemImpl.h" 

#ifdef DEBUGING
    extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int  numBodyDeleted;
#endif

class FlowMock : public FlowHandle {
public:
    FlowMock() : FlowHandle() {}
    FlowMock(std::string name, System* source, System* target) : FlowHandle(name, source, target) {}
    virtual ~FlowMock() {}
    virtual double execute() override { return 0.0; }
};

class SystemMock : public System{
public:
    virtual ~SystemMock() {}
    virtual std::string getName() const override { return ""; }
    virtual void setName(std::string) override {}
    virtual double getValue() const override { return 0.0; }
    virtual void setValue(double) override {}
};

void UnitFlow::unit_Flow_DefaultConstructor() {
    FlowMock f1;
    assert(f1.pImpl_->name == "");
    assert(f1.pImpl_->source == nullptr);
    assert(f1.pImpl_->target == nullptr);
}

void UnitFlow::unit_Flow_ParameterizedConstructor() {
    SystemMock s1;
    SystemMock s2;
    FlowMock f2 ("Test Flow", &s1, &s2);
    assert(f2.pImpl_->name == "Test Flow");
    assert(f2.pImpl_->source == &s1);
    assert(f2.pImpl_->target == &s2);
}

void UnitFlow::unit_Flow_CopyConstructor(){
    FlowMock f2;
    SystemMock s1;
    SystemMock s2;
    f2.pImpl_->name = "Flow";
    f2.pImpl_->source = &s1;
    f2.pImpl_->target = &s2;
    
    FlowMock f3(f2);
    assert(f3.pImpl_->name == "Flow");
    assert(f3.pImpl_->source == &s1);
    assert(f3.pImpl_->target == &s2);
}

void UnitFlow::unit_Flow_Operator(){
    FlowMock f2;
    SystemMock s1;
    SystemMock s2;
    f2.pImpl_->name = "Flow";
    f2.pImpl_->source = &s1;
    f2.pImpl_->target = &s2;

    FlowMock f4;
    f4 = f2;
    assert(f4.pImpl_->name == "Flow");
    assert(f4.pImpl_->source == &s1);
    assert(f4.pImpl_->target == &s2);
}

void UnitFlow::unit_Flow_destructor() {
    FlowMock* f = new FlowMock;
    delete f;
}

void UnitFlow::unit_Flow_getName() {
    FlowMock f;
    f.pImpl_->name = "Name";
    assert(f.getName() == "Name");
}

void UnitFlow::unit_Flow_setName() {
    FlowMock f;
    f.setName("NewName");
    assert(f.pImpl_->name == "NewName");
}

void UnitFlow::unit_Flow_getSource() {
    FlowMock f;
    SystemMock s;
    f.pImpl_->source = &s; 
    assert(f.getSource() == &s);
}

void UnitFlow::unit_Flow_setSource() {
    FlowMock f;
    SystemMock s;
    f.setSource(&s);
    assert(f.pImpl_->source == &s);
}

void UnitFlow::unit_Flow_getTarget() {
    FlowMock f;
    SystemMock s;
    f.pImpl_->target = &s; 
    assert(f.getTarget() == &s);
}

void UnitFlow::unit_Flow_setTarget() {
    FlowMock f;
    SystemMock s;
    f.setTarget(&s);
    assert(f.pImpl_->target == &s);
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