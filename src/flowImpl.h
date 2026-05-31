#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

#include "flow.h"

class FlowImpl : public Flow
{
protected:
    std::string name;
    System *source;
    System *target;

public:
    FlowImpl();
    FlowImpl(const FlowImpl &fl);
    virtual ~FlowImpl();
    FlowImpl &operator=(const FlowImpl &fl);
    FlowImpl(std::string name);

    void setSource(System *s) override;
    void setTarget(System *t) override;
    void setName(std::string n) override;

    System *getSource() const override;
    System *getTarget() const override;
    std::string getName() const override;

    virtual double execute() = 0;

    friend void unit_Flow_constructor();
    friend void unit_Flow_getName();
    friend void unit_Flow_setName();
    friend void unit_Flow_getSource();
    friend void unit_Flow_setSource();
    friend void unit_Flow_getTarget();
    friend void unit_Flow_setTarget();

    friend class UnitFlow;
    friend class UnitFlowTypes;
};

#endif