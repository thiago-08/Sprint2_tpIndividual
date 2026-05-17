#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System
{
protected:
    std::string name;
    double value;

public:
    System();
    System(const System &sys);
    virtual ~System();
    System &operator=(const System &sys);

    System(std::string name, double value);

    std::string getName() const;
    double getValue() const;
    void setValue(double value);
    void setName(std::string name);
};

#endif