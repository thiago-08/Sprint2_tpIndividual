#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "system.h"
#include "flow.h"

class Model {
private:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

public:
    // --- FORMA CANÔNICA ---
    Model();                          // Construtor padrão
    Model(const Model& mod);          // Construtor de cópia
    virtual ~Model();                 // Destrutor virtual (Limpará a memória dos vetores)
    Model& operator=(const Model& mod); // Operador de atribuição

    // Construtor parametrizado
    Model(std::string name);

    void add(System* s);
    void add(Flow* f);

    void run(int t_initial, int t_end);

    std::string getName() const;
    void setName(std::string name);
};

#endif // MODEL_H