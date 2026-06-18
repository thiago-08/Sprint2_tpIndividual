#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

/**
 * @brief Testes unitários para a classe System.
 */
class UnitSystem {
public:
    /** @brief Testa o construtor padrão da classe System. */
    static void unit_System_DefaultConstructor();

    /** @brief Testa o construtor parametrizado da classe System. */
    static void unit_System_ParameterizedConstructor();

    /** @brief Testa o construtor de cópia da classe System. */
    static void unit_System_CopyConstructor();

    /** @brief Testa o operador de atribuição da classe System. */
    static void unit_System_Operator();

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

    /** @brief Testa a integração entre os métodos de System. */
    static void unit_System_handle();
};

/** @brief Executa todos os testes unitários de System. */
void run_unit_tests_System(void);

#endif