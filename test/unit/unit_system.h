#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

class UnitSystem {
public:
    static void unit_System_constructor();
    static void unit_System_destructor();
    static void unit_System_getName();
    static void unit_System_setName();
    static void unit_System_getValue();
    static void unit_System_setValue();
};

void run_unit_tests_System(void);

#endif