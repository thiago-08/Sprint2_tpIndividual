# MyVensim - Framework C++ para Simulação de Dinâmica de Sistemas

O **MyVensim** é um framework modular desenvolvido em C++ projetado para construir, modelar e executar simulações baseadas em sistemas. 

---

# 📁 Estrutura do Diretório

O projeto segue uma arquitetura rígida de separação de responsabilidades entre os arquivos que formam o produto (`src`),  os arquivos de testes (`test`) e os arquivos binários (`bin`):

MyVensim/
│
├── bin/                       
│
├── src/                        
│   ├── main.cpp               
│   ├── system.h / system.cpp   
│   ├── flow.h / flow.cpp       
│   ├── flow_types.h / .cpp     
│   └── model.h / model.cpp     
│
├── test/                       
│   ├── funcional/              
│   │   ├── main.cpp            
│   │   ├── funcional_tests.h
│   │   └── funcional_tests.cpp # Validação dos cenários Exponencial, Logístico e Complexo
│   │
│   └── unit/                   
│       ├── main.cpp            
│       ├── unit_tests.h
│       └── unit_tests.cpp      # Validação dos construtores, setter, getter e lógica
│
├── Makefile                    
└── README.md                   

---

# 🛠️ Detalhes da Arquitetura e Padrões de Projeto

### Fluxos implementados

#### `FlowExponencial`

Computa uma taxa de crescimento constante proporcional ao estoque de origem:

```math
0.01 × origem
```

#### `FlowLogistico`

Computa o crescimento baseado em restrições físicas de capacidade máxima do ambiente:

```math
0.01 × destino × (1 — destino/70)
```

#### `FlowComplexo`

Implementa uma malha interconectada com múltiplos loops de feedback simultâneos.

---

# 🔨 Compilação

O gerenciamento de build é automatizado via `Makefile`.

## Compilar todo o projeto

Gera os executáveis dentro da pasta `bin/`.

```bash
make
```

---

# ▶️ Execução dos Testes

Para validar o comportamento matemático do framework e garantir compatibilidade com os resultados de referência do Vensim PLE, execute os binários gerados.

## Executar Testes Funcionais

PAra executar os testes funcionais:

```bash
./bin/funcional_tests
```

---

## Executar Testes Unitários

Para executar os testes unitários:

```bash
./bin/unit_tests
```

---

# 👨‍💻 Autores

Arthur Mendes Torres (24.2.4042)
Thiago Linhares Lage (24.2.4032)

Projeto desenvolvido para a disciplina:

**BCC322 - Engenharia de Software I**
Universidade Federal de Ouro Preto (UFOP)

```
```
