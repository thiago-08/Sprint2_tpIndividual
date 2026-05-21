#include "model.h"

Model::Model() : name("") {}

Model::Model(const Model &mod)
{
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
}

Model::~Model() {}

Model &Model::operator=(const Model &mod){
    if (this == &mod){
        return *this;
    }
    this->name = mod.name;
    this->systems = mod.systems;
    this->flows = mod.flows;
    return *this;
}

Model::Model(std::string name) : name(name) {}

std::string Model::getName() const{
    return name;
}

void Model::setName(std::string n){
    name = n;
}

void Model::add(System *s){
    systems.push_back(s);
}

void Model::add(Flow *f){
    flows.push_back(f);
}

void Model::run(int t_initial, int t_end){
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