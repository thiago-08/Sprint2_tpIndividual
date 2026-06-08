#include "flow_types.h"

// ---------------------------------------------------------------------------
// FlowExponencial
// ---------------------------------------------------------------------------

FlowExponencial::FlowExponencial() : FlowImpl() {}

FlowExponencial::FlowExponencial(std::string name) : FlowImpl(name) {}

FlowExponencial::FlowExponencial(const FlowExponencial &f) : FlowImpl(f) {}

FlowExponencial::~FlowExponencial() {}

FlowExponencial &FlowExponencial::operator=(const FlowExponencial &f)
{
    if (this == &f)
        return *this;
    FlowImpl::operator=(f);
    return *this;
}

double FlowExponencial::execute()
{
    if (getSource() != nullptr)
        return 0.01 * getSource()->getValue();
    return 0.0;
}

// ---------------------------------------------------------------------------
// FlowLogistic
// ---------------------------------------------------------------------------

FlowLogistic::FlowLogistic() : FlowImpl() {}

FlowLogistic::FlowLogistic(std::string name) : FlowImpl(name) {}

FlowLogistic::FlowLogistic(const FlowLogistic &f) : FlowImpl(f) {}

FlowLogistic::~FlowLogistic() {}

FlowLogistic &FlowLogistic::operator=(const FlowLogistic &f)
{
    if (this == &f)
        return *this;
    FlowImpl::operator=(f);
    return *this;
}

double FlowLogistic::execute()
{
    if (getTarget() != nullptr) {
        double p2 = getTarget()->getValue();
        return 0.01 * p2 * (1.0 - (p2 / 70.0));
    }
    return 0.0;
}

// ---------------------------------------------------------------------------
// FlowComplex
// ---------------------------------------------------------------------------

FlowComplex::FlowComplex() : FlowImpl() {}

FlowComplex::FlowComplex(std::string name) : FlowImpl(name) {}

FlowComplex::FlowComplex(const FlowComplex &f) : FlowImpl(f) {}

FlowComplex::~FlowComplex() {}

FlowComplex &FlowComplex::operator=(const FlowComplex &f)
{
    if (this == &f)
        return *this;
    FlowImpl::operator=(f);
    return *this;
}

double FlowComplex::execute()
{
    if (getSource() != nullptr)
        return 0.01 * getSource()->getValue();
    return 0.0;
}
