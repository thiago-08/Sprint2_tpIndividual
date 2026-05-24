#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

class Model
{
private:
    std::string name;
    std::vector<System *> systems;
    std::vector<Flow *> flows;

public:
    Model();
    Model(const Model &mod);
    virtual ~Model();
    Model &operator=(const Model &mod);

    Model(std::string name);

    void add(System *s);
    void add(Flow *f);

    void run(int t_initial, int t_end);

    std::string getName() const;
    void setName(std::string name);
};

#endif