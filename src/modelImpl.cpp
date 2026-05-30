#include "modelImpl.h"

ModelImpl::ModelImpl() : name("") {}

ModelImpl::ModelImpl(std::string name) : name(name) {}

ModelImpl::ModelImpl(const ModelImpl &mod){
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}

ModelImpl::~ModelImpl() {
    for(System* s : systems){
        delete s;
    }
    for(Flow* f : flows){
        delete f;
    }
}

ModelImpl &ModelImpl::operator=(const ModelImpl &mod){
    if (this == &mod){
        return *this;
    }
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
    return *this;
}

std::string ModelImpl::getName() const{
    return name;
}

void ModelImpl::setName(std::string n){
    name = n;
}

void ModelImpl::add(System *s){
    systems.push_back(s);
}

void ModelImpl::add(Flow *f){
    flows.push_back(f);
}

void ModelImpl::run(int t_initial, int t_end){
    for (int time = t_initial; time < t_end; ++time){
        std::vector<double> results;
        for (auto it = flows.begin(); it != flows.end(); ++it){
            results.push_back((*it)->execute());
        }
        for (size_t i = 0; i < flows.size(); ++i){
            System *source = flows[i]->getSource();
            System *target = flows[i]->getTarget();
            if (source != nullptr){
                source->setValue(source->getValue() - results[i]);
            }
            if (target != nullptr){
                target->setValue(target->getValue() + results[i]);
            }
        }
    }
}