#include "unit_system.h"
#include <assert.h>
#include "../../src/impl/systemImpl.h"

void UnitSystem::unit_System_DefaultConstructor(){
    SystemImpl s1;
    assert(s1.name  == "");
    assert(s1.value == 0.0);
}

void UnitSystem::unit_System_ParameterizedConstructor(){
    SystemImpl s2("Test System", 10.5);
    assert(s2.name  == "Test System");
    assert(s2.value == 10.5);
}

void UnitSystem::unit_System_CopyConstructor(){
    SystemImpl s2("Test System", 10.5);
    SystemImpl s3(s2);
    assert(s3.name  == "Test System");
    assert(s3.value == 10.5);
}

void UnitSystem::unit_System_Operator(){
    SystemImpl s2("Test System", 10.5);
    SystemImpl s4;
    s4 = s2;
    assert(s4.name  == "Test System");
    assert(s4.value == 10.5);
}

void UnitSystem::unit_System_destructor(){
    SystemImpl *s1 = new SystemImpl("Sys", 10.0);
    delete s1;
}

void UnitSystem::unit_System_getName(){
    SystemImpl s("Name", 100.0);
    assert(s.getName() == "Name");
}

void UnitSystem::unit_System_setName(){
    SystemImpl s;
    s.setName("NewName");
    assert(s.name == "NewName");
}

void UnitSystem::unit_System_getValue(){
    SystemImpl s("Name", 150.0);
    assert(s.getValue() == 150.0);
}

void UnitSystem::unit_System_setValue(){
    SystemImpl s;
    s.setValue(25.5);
    assert(s.value == 25.5);
}

void run_unit_tests_System(){
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
