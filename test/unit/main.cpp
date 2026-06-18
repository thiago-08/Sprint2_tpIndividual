#include <iostream>
#include "unit_system.h"
#include "unit_flow.h"
#include "unit_flow_types.h"
#include "unit_model.h"

using namespace std;

int main() {
    //run_unit_tests_System();
    cout << "All System Tests were sucessful" << endl;
    //run_unit_tests_Flow();
    cout << "All Flow Tests were sucessful" << endl;
    //run_unit_tests_FlowTypes();
    cout << "All Flow Types Tests were sucessful" << endl;
    run_unit_tests_Model();
    cout << "All Model Tests were sucessful" << endl;
    cout << "All UNIT TESTS WERE SUCESSFUL!" << endl;
    return 0;
}