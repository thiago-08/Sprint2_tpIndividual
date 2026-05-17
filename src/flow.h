#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

class Flow {
protected:
    std::string name;
    System *source;
    System *target;

public:
    Flow();
    Flow(const Flow &fl);
    virtual ~Flow();
    Flow &operator=(const Flow &fl);

    Flow(std::string name);

    void setSource(System *s);
    void setTarget(System *t);
    System *getSource() const;
    System *getTarget() const;
    std::string getName() const;
    void setName(std::string name);

    virtual double execute() = 0;
};

#endif