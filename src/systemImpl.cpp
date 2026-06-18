#include "systemImpl.h"

SystemBody::SystemBody() : name(""), value(0.0) {}

SystemBody::~SystemBody() {}

SystemBody::SystemBody(std::string name, double value) : name(name), value(value) {}

std::string SystemBody::getName() const{
    return name;
}

void SystemBody::setName(std::string n){
    name = n;
}

double SystemBody::getValue() const{
    return value;
}

void SystemBody::setValue(double v){
    value = v;
}