#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @brief Testes unitários para a classe System.
 */
class UnitSystem {
public:
    /** @brief Testa os construtores e operador de atribuição. */
    static void unit_System_constructor();

    /** @brief Testa o destrutor. */
    static void unit_System_destructor();

    /** @brief Testa o método getName. */
    static void unit_System_getName();

    /** @brief Testa o método setName. */
    static void unit_System_setName();

    /** @brief Testa o método getValue. */
    static void unit_System_getValue();

    /** @brief Testa o método setValue. */
    static void unit_System_setValue();
};

/** @brief Executa todos os testes unitários de System. */
void run_unit_tests_System(void);

#endif