#include "unit_model.h"
#include <assert.h>
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../test/funcional/flow_types.h" 
#include "../../src/flowImpl.h"

#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

/*!
 * @brief Class used exclusively to instantiate and test System (Body).
 */
class SystemTestBody : public Body {
public:
    std::string name;
    double value;
    void setName(std::string n) { this->name = n; }
    std::string getName() const { return this->name; }
    void setValue(double v) { this->value = v; }
    double getValue() const { return this->value; }
};

/*!
 * @brief Class used exclusively to instantiate and test System (Handle).
 */
class SystemTestHandle : public System, public Handle<SystemTestBody> {
public:
    SystemTestHandle(std::string n = "", double v = 0.0) {
        pImpl_->setName(n);
        pImpl_->setValue(v);
    }
    virtual ~SystemTestHandle() {}
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string n) override { pImpl_->setName(n); }
    double getValue() const override { return pImpl_->getValue(); }
    void setValue(double v) override { pImpl_->setValue(v); }
    friend class UnitModel;
};

/*!
 * @brief Class used exclusively to instantiate and test Flow (Body).
 */
class FlowTestBody : public Body {
public:
    std::string name;
    System *source, *target;
    std::string getName() const { return this->name; }
    void setName(std::string n) { this->name = n; }
    System* getSource() const { return this->source; }
    void setSource(System* s) { this->source = s; }
    System* getTarget() const { return this->target; }
    void setTarget(System* t) { this->target = t; }
    double execute() { return source ? 0.01 * source->getValue() : 0.0; }
};

/*!
 * @brief Class used exclusively to instantiate and test Flow (Handle).
 */
class FlowTestHandle : public Flow, public Handle<FlowTestBody> {
public:
    FlowTestHandle(std::string n="", System* s=nullptr, System* t=nullptr) {
        this->setName(n);
        this->setSource(s);
        this->setTarget(t);
    }
    virtual ~FlowTestHandle() {}
    std::string getName() const override { return pImpl_->getName(); }
    void setName(std::string n) override { pImpl_->setName(n); }
    System* getSource() const override { return pImpl_->getSource(); }
    void setSource(System* s) override { pImpl_->setSource(s); }
    System* getTarget() const override { return pImpl_->getTarget(); }
    void setTarget(System* t) override { pImpl_->setTarget(t); }
    double execute() override { return pImpl_->execute(); }
    friend class UnitModel;
};


void UnitModel::unit_Model_DefaultConstructor() {
    ModelHandle m1;
    assert(m1.pImpl_->name == "");
    assert(m1.pImpl_->systems.size() == 0);
    assert(m1.pImpl_->flows.size() == 0);
}
 
void UnitModel::unit_Model_ParameterizedConstructor() {
    ModelHandle m2("Model Test");
    assert(m2.pImpl_->name == "Model Test");
}

void UnitModel::unit_Model_destructor() {
    ModelHandle* m = new ModelHandle();
    m->pImpl_->systems.push_back(new SystemHandle("Sys", 10.0));
    delete m; 
}

void UnitModel::unit_Model_getName() {
    ModelHandle m;
    m.pImpl_->name = "Name"; 
    assert(m.getName() == "Name");
}

void UnitModel::unit_Model_setName() {
    ModelHandle m;
    m.setName("NewName");
    assert(m.pImpl_->name == "NewName");
}

void UnitModel::unit_Model_addSystem() {
    ModelHandle m;
    System* s = new SystemHandle("Sys", 10.0); 
    m.add(s);
    assert(m.pImpl_->systems.size() == 1);
    assert(m.pImpl_->systems[0] == s);
}

void UnitModel::unit_Model_addFlow() {
    ModelHandle m;
    Flow* f = new FlowTestHandle("Flow");
    m.add(f);
    assert(m.pImpl_->flows.size() == 1);
    assert(m.pImpl_->flows[0] == f);
}

void UnitModel::unit_Model_createModel() {
    size_t pastSize = ModelBody::models.size();
    Model* m = Model::createModel("Factory Model");

    ModelHandle* mh = dynamic_cast<ModelHandle*>(m);
    assert(mh->pImpl_->name == "Factory Model");
    assert(ModelBody::models.size() == pastSize + 1); 
    
    Model::deleteModel("Factory Model");
}

void UnitModel::unit_Model_createSystem() {
    ModelHandle m("Test Create System");
    System* s = m.createSystem("Sys", 10.0);
    
    SystemHandle* sh = dynamic_cast<SystemHandle*>(s);
    assert(sh->pImpl_->name == "Sys");
    assert(sh->pImpl_->value == 10.0);
    assert(m.pImpl_->systems.size() == 1);
    assert(m.pImpl_->systems[0] == s);
}

void UnitModel::unit_Model_createFlow() {
    ModelHandle m("Test Create Flow");
    
    Flow* f = m.createFlow<FlowTestHandle>("FlowExp", nullptr, nullptr);

    FlowTestHandle* fe = dynamic_cast<FlowTestHandle*>(f);
    assert(fe->pImpl_->name == "FlowExp");
    assert(fe->pImpl_->source == nullptr);
    assert(fe->pImpl_->target == nullptr);
    assert(m.pImpl_->flows.size() == 1);
    assert(m.pImpl_->flows[0] == f);

}

void UnitModel::unit_Model_deleteModel() {
    // Usamos a fábrica para que o modelo seja nomeado e registrado corretamente no vetor interno
    Model::createModel("Model To Delete");
    
    // Agora o deleteModel vai encontrar e deletar com sucesso
    bool deleted = Model::deleteModel("Model To Delete");
    
    assert(deleted == true);
}

void UnitModel::unit_Model_deleteSystem() {
    ModelHandle* m = new ModelHandle("Test Delete System");
    System* s = new SystemTestHandle("Sys", 10.0);
    
    m->pImpl_->systems.push_back(s); 
    m->deleteSystem(s);
    assert(m->pImpl_->systems.empty()); 
    delete m;
}

void UnitModel::unit_Model_deleteFlow() {
    ModelHandle* m = new ModelHandle("Test Delete Flow");
    Flow* f = new FlowTestHandle("FlowExp");
    
    m->pImpl_->flows.push_back(f);
    m->deleteFlow(f);
    assert(m->pImpl_->flows.empty()); 
    delete m;
}

void UnitModel::unit_Model_run() {
    ModelHandle m("Test Run");
    SystemHandle* s1 = new SystemHandle("Source", 100.0);
    SystemHandle* s2 = new SystemHandle("Target", 0.0);
   
    Flow* f = new FlowTestHandle("Flow", s1, s2);
    
    m.pImpl_->systems.push_back(s1);
    m.pImpl_->systems.push_back(s2);
    m.pImpl_->flows.push_back(f);

    m.run(0, 1); 

    assert(s1->pImpl_->value == 99.0);
    assert(s2->pImpl_->value == 1.0);
}

void run_unit_tests_Model() {
    UnitModel::unit_Model_DefaultConstructor();
    UnitModel::unit_Model_ParameterizedConstructor();
    UnitModel::unit_Model_destructor();
    UnitModel::unit_Model_getName();
    UnitModel::unit_Model_setName();
    UnitModel::unit_Model_addSystem();
    UnitModel::unit_Model_addFlow();
    UnitModel::unit_Model_createModel();
    UnitModel::unit_Model_createSystem();
    UnitModel::unit_Model_createFlow();
    UnitModel::unit_Model_deleteModel();
    UnitModel::unit_Model_deleteSystem();
    UnitModel::unit_Model_deleteFlow();
    UnitModel::unit_Model_run();
}