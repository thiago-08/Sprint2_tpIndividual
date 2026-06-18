#include "unit_system.h"
#include <assert.h>
#include "../../src/systemImpl.h"

#ifdef DEBUGING
    extern int numHandleCreated;
	extern int numHandleDeleted;
	extern int numBodyCreated;
	extern int  numBodyDeleted;
#endif

void UnitSystem::unit_System_DefaultConstructor() {
    SystemHandle s1;
    assert(s1.pImpl_->name == "");
    assert(s1.pImpl_->value == 0.0);
}

void UnitSystem::unit_System_ParameterizedConstructor() {
    SystemHandle s2("Test System", 10.5);
    assert(s2.pImpl_->name == "Test System");
    assert(s2.pImpl_->value == 10.5);
}

void UnitSystem::unit_System_CopyConstructor() {
    SystemHandle s2("Test System", 10.5);
    SystemHandle s3(s2); // Testa a cópia do Handle
    assert(s3.pImpl_->name == "Test System");
    assert(s3.pImpl_->value == 10.5);
}

void UnitSystem::unit_System_Operator() {
    SystemHandle s2("Test System", 10.5);
    SystemHandle s4;
    s4 = s2; // Testa a atribuição do Handle
    assert(s4.pImpl_->name == "Test System");
    assert(s4.pImpl_->value == 10.5);
}

void UnitSystem::unit_System_destructor() {
    SystemHandle* s1 = new SystemHandle("Sys", 10.0);
    delete s1;
}

void UnitSystem::unit_System_getName() {
    SystemHandle s("Name", 100.0);
    assert(s.getName() == "Name");
}

void UnitSystem:: unit_System_setName() {
    SystemHandle s;
    s.setName("NewName");
    assert(s.pImpl_->name == "NewName");
}

void UnitSystem::unit_System_getValue() {
    SystemHandle s("Name", 150.0);
    assert(s.getValue() == 150.0);
}

void UnitSystem::unit_System_setValue() {
    SystemHandle s;
    s.setValue(25.5);
    assert(s.pImpl_->value == 25.5);
}

void UnitSystem::unit_System_handle(){

    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif

    {
        SystemHandle s1("Sys 1", 10.0);
        SystemHandle s2("Sys 2", 20.0);
        assert(numBodyCreated == 2);
        assert(numBodyDeleted == 0);
        assert(numHandleCreated == 2);
        assert(numHandleDeleted == 0);
        
        s1 = s2; 
        assert(numBodyDeleted == 1);
        
        SystemHandle s3(s1); 
        assert(numHandleCreated == 3); 
        assert(numBodyCreated == 2);
    }

    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2);
    assert(numHandleCreated == 3);
    assert(numHandleDeleted == 3);

    #ifdef DEBUGING
        numHandleCreated = 0;
        numHandleDeleted = 0;
        numBodyCreated = 0;
        numBodyDeleted = 0;
    #endif

    {
        SystemHandle* s1 = new SystemHandle("Sys 1", 10.0);
        SystemHandle* s2 = new SystemHandle("Sys 2", 20.0);
        assert(numBodyCreated == 2);
        assert(numBodyDeleted == 0);
        assert(numHandleCreated == 2);
        assert(numHandleDeleted == 0);
        
        *s1 = *s2; 
        assert(numBodyDeleted == 1);
        
        delete s1; 
        delete s2; 
    }

    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2); 
    assert(numHandleCreated == 2);
    assert(numHandleDeleted == 2);
}

void run_unit_tests_System() {
    UnitSystem::unit_System_DefaultConstructor();
    UnitSystem::unit_System_ParameterizedConstructor();
    UnitSystem::unit_System_CopyConstructor();
    UnitSystem::unit_System_Operator();
    UnitSystem::unit_System_destructor();
    UnitSystem::unit_System_getName();
    UnitSystem::unit_System_setName();
    UnitSystem::unit_System_getValue();
    UnitSystem::unit_System_setValue();
    UnitSystem::unit_System_handle();
}