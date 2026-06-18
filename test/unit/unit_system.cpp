#include "unit_system.h"
#include <assert.h>
#include "../../src/systemImpl.h"

void UnitSystem::unit_System_DefaultConstructor() {
    SystemHandle s1;
    assert(s1.getName() == "");
    assert(s1.getValue() == 0.0);
}

void UnitSystem::unit_System_ParameterizedConstructor() {
    SystemHandle s2("Test System", 10.5);
    assert(s2.getName() == "Test System");
    assert(s2.getValue() == 10.5);
}

void UnitSystem::unit_System_CopyConstructor() {
    SystemHandle s2("Test System", 10.5);
    SystemHandle s3(s2); // Testa a cópia do Handle
    assert(s3.getName() == "Test System");
    assert(s3.getValue() == 10.5);
}

void UnitSystem::unit_System_Operator() {
    SystemHandle s2("Test System", 10.5);
    SystemHandle s4;
    s4 = s2; // Testa a atribuição do Handle
    assert(s4.getName() == "Test System");
    assert(s4.getValue() == 10.5);
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
    assert(s.getName() == "NewName");
}

void UnitSystem::unit_System_getValue() {
    SystemHandle s("Name", 150.0);
    assert(s.getValue() == 150.0);
}

void UnitSystem::unit_System_setValue() {
    SystemHandle s;
    s.setValue(25.5);
    assert(s.getValue() == 25.5);
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
}