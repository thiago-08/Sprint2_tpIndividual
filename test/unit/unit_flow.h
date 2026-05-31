#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

class UnitFlow {
public:
    static void unit_Flow_constructor();
    static void unit_Flow_destructor();
    static void unit_Flow_getName();
    static void unit_Flow_setName();
    static void unit_Flow_getSource();
    static void unit_Flow_setSource();
    static void unit_Flow_getTarget();
    static void unit_Flow_setTarget();
};

void run_unit_tests_Flow();

#endif