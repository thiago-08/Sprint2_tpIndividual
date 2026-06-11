#ifndef MODEL_H
#define MODEL_H

#include <string>
class System;
class Flow;


/**
 * @brief Interface abstrata de especificação para um Modelo de Simulação.
 */
class Model
{
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Model() {}

    /**
     * @brief Método estático da fábrica de model
    */
    static Model* createModel(std::string name);
    /**
     * @brief Método estático da fábrica de model
     */
    static bool deleteModel(std::string name);

    /**
     * @brief Cria, instancia e adiciona um novo sistema ao modelo
     * @return System* Ponteiro para o sistema recém-criado
     */
    virtual System* createSystem(std::string name, double value) = 0;
    
    /**
     * @brief Cria, instancia e adiciona um novo Fluxo ao modelo através de template.
     * @tparam T_FLOW Tipo do fluxo específico a ser instanciado 
     * @return Flow* Ponteiro para o fluxo recém-criado
     */
    template <typename T_FLOW>
    Flow* createFlow(std::string name, System* source = nullptr, System* target = nullptr) {
        Flow* f = new T_FLOW(name, source, target);
        add(f); 
        return f;
    }

    /**
     * @brief Destrutor virtual de system
     */
    virtual bool deleteSystem(System* s) = 0;
    /**
     * @brief Destrutor virtual de flow
     */
    virtual bool deleteFlow(Flow* f) = 0;

    /**
     * @brief Executa todo o sistema de simulação, processando os fluxos e atualizando os sistemas para cada ciclo temporal.
     * @param t_initial Tempo/Ciclo de início da simulação.
     * @param t_end Tempo/Ciclo final do encerramento da simulação.
     */
    virtual void run(int t_initial, int t_end) = 0;

    /**
     * @brief Retorna o nome identificador do modelo.
     * @return std::string contendo o nome.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Define um nome identificador para o modelo.
     * @param name Novo nome do modelo.
     */
    virtual void setName(std::string name) = 0;

protected:
    /**
     * @brief Registra e adiciona um Sistema ao escopo do modelo.
     * @param s Ponteiro para o objeto do sistema a ser inserido.
     */
    virtual void add(System *s) = 0;
    /**
     * @brief Registra e adiciona um Fluxo ao escopo do modelo.
     * @param f Ponteiro para o objeto do fluxo a ser inserido.
     */
    virtual void add(Flow *f) = 0;
};

#endif