#include "modelImpl.h"
#include "systemImpl.h"

//global variable
std::vector<Model*> ModelImpl::models;

ModelImpl::ModelImpl() : name("") {}

ModelImpl::ModelImpl(std::string name) : name(name) {}

ModelImpl::ModelImpl(const ModelImpl &mod){
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}

ModelImpl::~ModelImpl() {
    for (std::vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete *it; 
    }
    for (std::vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    systems.clear();
    flows.clear();
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

Model* Model::createModel(std::string name) {
    Model* m = new ModelImpl(name);
    ModelImpl::models.push_back(m);
    return m;
}

System* ModelImpl::createSystem(std::string name, double value) {
    System* s = new SystemImpl(name, value);
    systems.push_back(s);
    return s;
}

bool Model::deleteModel(std::string name) {
    for (auto it = ModelImpl::models.begin(); it != ModelImpl::models.end(); ++it) {
        if ((*it)->getName() == name) {
            Model* m = *it;
            ModelImpl::models.erase(it);
            delete m; 
            return true;
        }
    }
    return false;
}

bool ModelImpl::deleteSystem(System* s) {
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if (*it == s) {
            systems.erase(it);
            delete s;
            return true;
        }
    }
    return false;
}

bool ModelImpl::deleteFlow(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if (*it == f) {
            flows.erase(it);
            delete f;
            return true;
        }
    }
    return false;
}

void ModelImpl::add(Flow* f) {
    flows.push_back(f);
}

void ModelImpl::add(System *s){
    systems.push_back(s);
}

std::string ModelImpl::getName() const{
    return name;
}

void ModelImpl::setName(std::string n){
    name = n;
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