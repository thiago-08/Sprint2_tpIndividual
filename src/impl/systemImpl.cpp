#include "systemImpl.h"

SystemImpl::SystemImpl() : name(""), value(0.0) {}

SystemImpl::SystemImpl(const SystemImpl &sys)
{
    this->name  = sys.name;
    this->value = sys.value;
}

SystemImpl::~SystemImpl() {}

SystemImpl &SystemImpl::operator=(const SystemImpl &sys)
{
    if (this == &sys)
        return *this;
    this->name  = sys.name;
    this->value = sys.value;
    return *this;
}

SystemImpl::SystemImpl(std::string name, double value) : name(name), value(value) {}

std::string SystemImpl::getName() const
{
    return name;
}

void SystemImpl::setName(std::string n)
{
    name = n;
}

double SystemImpl::getValue() const
{
    return value;
}

void SystemImpl::setValue(double v)
{
    value = v;
}
