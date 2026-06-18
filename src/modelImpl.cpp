#include "modelImpl.h"
#include "systemImpl.h"
#include "flowImpl.h"

//global variable
std::vector<Model*> ModelBody::models;

ModelBody::ModelBody() : name("") {}

ModelBody::ModelBody(std::string name) : name(name) {}

ModelBody::~ModelBody() {
    for (std::vector<System*>::iterator it = systems.begin(); it != systems.end(); ++it) {
        delete *it; 
    }
    for (std::vector<Flow*>::iterator it = flows.begin(); it != flows.end(); ++it) {
        delete *it;
    }
    systems.clear();
    flows.clear();
}

Model* Model::createModel(std::string name) {
    Model* m = new ModelHandle(name);
    ModelBody::models.push_back(m);
    return m;
}

System* ModelBody::createSystem(std::string name, double value) {
    System* s = new SystemHandle(name, value);
    systems.push_back(s);
    return s;
}

bool Model::deleteModel(std::string name) {
    for (auto it = ModelBody::models.begin(); it != ModelBody::models.end(); ++it) {
        if ((*it)->getName() == name) {
            Model* m = *it;
            ModelBody::models.erase(it);
            delete m; 
            return true;
        }
    }
    return false;
}

bool ModelBody::deleteSystem(System* s) {
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if (*it == s) {
            systems.erase(it);
            delete s;
            return true;
        }
    }
    return false;
}

bool ModelBody::deleteFlow(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if (*it == f) {
            flows.erase(it);
            delete f;
            return true;
        }
    }
    return false;
}

void ModelBody::add(Flow* f) {
    flows.push_back(f);
}

void ModelBody::add(System *s){
    systems.push_back(s);
}

std::string ModelBody::getName() const{
    return name;
}

void ModelBody::setName(std::string n){
    name = n;
}

void ModelBody::run(int t_initial, int t_end){
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

#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif