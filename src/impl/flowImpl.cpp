#include "flowImpl.h"

FlowImpl::FlowImpl() : name(""), source(nullptr), target(nullptr) {}

FlowImpl::FlowImpl(const FlowImpl &fl)
{
    this->name   = fl.name;
    this->source = fl.source;
    this->target = fl.target;
}

FlowImpl::~FlowImpl() {}

FlowImpl &FlowImpl::operator=(const FlowImpl &fl)
{
    if (this == &fl)
        return *this;
    this->name   = fl.name;
    this->source = fl.source;
    this->target = fl.target;
    return *this;
}

FlowImpl::FlowImpl(std::string name) : name(name), source(nullptr), target(nullptr) {}

void FlowImpl::setSource(System *s)
{
    source = s;
}

void FlowImpl::setTarget(System *t)
{
    target = t;
}

void FlowImpl::setName(std::string n)
{
    name = n;
}

System *FlowImpl::getSource() const
{
    return source;
}

System *FlowImpl::getTarget() const
{
    return target;
}

std::string FlowImpl::getName() const
{
    return name;
}
