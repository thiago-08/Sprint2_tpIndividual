#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

#include "model.h"
#include <vector>

class ModelImpl : public Model
{
protected:
    std::string name;
    std::vector<System *> systems;
    std::vector<Flow *> flows;

public:
    ModelImpl();
    ModelImpl(const ModelImpl &mod);
    ModelImpl(std::string name);
    virtual ~ModelImpl();

    ModelImpl &operator=(const ModelImpl &mod);

    void add(System *s) override;
    void add(Flow *f) override;
    void run(int t_initial, int t_end) override;
    
    std::string getName() const override;
    void setName(std::string name) override;

    friend class UnitModel;
};

#endif