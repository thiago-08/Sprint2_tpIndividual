#include "flow.h"

Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

Flow::Flow(const Flow &fl)
{
    this->name = fl.name;
    this->source = fl.source;
    this->target = fl.target;
}

Flow::~Flow() {}

Flow &Flow::operator=(const Flow &fl)
{
    if (this == &fl)
    {
        return *this;
    }
    this->name = fl.name;
    this->source = fl.source;
    this->target = fl.target;
    return *this;
}

Flow::Flow(std::string name) : name(name), source(nullptr), target(nullptr) {}

void Flow::setSource(System *s)
{
    source = s;
}

void Flow::setTarget(System *t)
{
    target = t;
}
void Flow::setName(std::string n)
{
    name = n;
}

System *Flow::getSource() const
{
    return source;
}

System *Flow::getTarget() const
{
    return target;
}

std::string Flow::getName() const
{
    return name;
}