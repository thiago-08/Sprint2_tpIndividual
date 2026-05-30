#include "unit_system.h"
#include <assert.h>
#include <math.h>
#include "../../src/systemImpl.h"

void unit_System_constructor(void) {
    //teste do construtor padrão
    SystemImpl s1;
    assert(s1.name == "");
    assert(s1.value == 0.0);

    //teste do construtor parametrizado
    SystemImpl s2("Test System", 10.5);
    assert(s2.name == "Test System");
    assert(s2.value == 10.5);
    
    //teste do construtor de cópia
    SystemImpl s3(s2);
    assert(s3.name == "Test System");
    assert(s3.value == 10.5);

    //teste do operador de atribuição
    SystemImpl s4;
    s4 = s2;
    assert(s4.name == "Test System");
    assert(s4.value == 10.5);
}

void unit_System_destructor(void) {
    SystemImpl* s1 = new SystemImpl("Sys", 10.0);
    delete s1;
}

void unit_System_getName(void) {
    SystemImpl s("Name", 100.0);
    assert(s.getName() == "Name");
}

void unit_System_setName(void) {
    SystemImpl s;
    s.setName("NewName");
    assert(s.name == "NewName");
}

void unit_System_getValue(void) {
    SystemImpl s("Name", 150.0);
    assert(s.getValue() == 150.0);
}

void unit_System_setValue(void) {
    SystemImpl s;
    s.setValue(25.5);
    assert(s.value == 25.5);
}

void run_unit_tests_System(void) {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getValue();
    unit_System_setValue();
}