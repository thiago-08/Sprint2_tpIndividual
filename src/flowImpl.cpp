#include "flowImpl.h"
#include "system.h"

FlowBody::FlowBody() : name(""), source(nullptr), target(nullptr) {}

FlowBody::~FlowBody() {}

FlowBody::FlowBody(std::string name, System *source, System *target) 
    : name(name), source(source), target(target) {}

void FlowBody::setSource(System *s){
    source = s;
}

void FlowBody::setTarget(System *t){
    target = t;
}
void FlowBody::setName(std::string n){
    name = n;
}

System *FlowBody::getSource() const{
    return source;
}

System *FlowBody::getTarget() const{
    return target;
}

std::string FlowBody::getName() const{
    return name;
}