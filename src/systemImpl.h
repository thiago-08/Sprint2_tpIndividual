#ifndef SYSTEM_IMPL_H
#define SYSTEM_IMPL_H

#include "system.h"

class SystemImpl : public System {
protected:
    std::string name;
    double value;

public:
    SystemImpl();
    SystemImpl(const SystemImpl &sys);
    SystemImpl(std::string name, double value);
    virtual ~SystemImpl();

    SystemImpl &operator=(const SystemImpl &sys);

    std::string getName() const override;
    double getValue() const override;
    void setValue(double value) override;
    void setName(std::string name) override;

    friend class UnitSystem;
};

#endif