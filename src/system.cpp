#include "system.h"

System::System() : name(""), value(0.0) {}

System::System(const System &sys)
{
    this->name = sys.name;
    this->value = sys.value;
}

System::~System() {}

System &System::operator=(const System &sys)
{
    if (this == &sys)
    {
        return *this;
    }
    this->name = sys.name;
    this->value = sys.value;
    return *this;
}

System::System(std::string name, double value) : name(name), value(value) {}

std::string System::getName() const
{
    return name;
}

void System::setName(std::string n)
{
    name = n;
}

double System::getValue() const
{
    return value;
}

void System::setValue(double v)
{
    value = v;
}