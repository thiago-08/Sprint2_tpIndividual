#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
protected:
    std::string name;
    double value;

public:
    // --- FORMA CANÔNICA ---
    System();                           // Construtor padrão
    System(const System& sys);          // Construtor de cópia
    virtual ~System();                  // Destrutor virtual
    System& operator=(const System& sys); // Operador de atribuição

    System(std::string name, double value);

    std::string getName() const;
    double getValue() const;
    void setValue(double value);
};

#endif // SYSTEM_H