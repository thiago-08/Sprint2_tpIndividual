#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

class UnitModel {
public:
    static void unit_Model_constructor();
    static void unit_Model_destructor();
    static void unit_Model_getName();
    static void unit_Model_setName();
    static void unit_Model_addSystem();
    static void unit_Model_addFlow();
    static void unit_Model_run();
};

void run_unit_tests_Model();

#endif