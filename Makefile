# Makefile — MyVensim Framework (Arquitetura em Camadas)
# Compila a biblioteca libmyvensim.so e os testes funcionais/unitários

IMPL_SRCS = src/impl/systemImpl.cpp src/impl/flowImpl.cpp src/impl/flow_types.cpp \
            src/impl/modelImpl.cpp src/impl/model_factory.cpp

all:
	mkdir -p bin
	g++ -fPIC -shared $(IMPL_SRCS) -o bin/libmyvensim.so
	g++ test/funcional/main.cpp test/funcional/funcional_tests.cpp -Lbin -lmyvensim -Wl,-rpath,bin -o bin/funcional_tests
	g++ test/unit/main.cpp test/unit/unit_system.cpp test/unit/unit_flow.cpp \
	    test/unit/unit_flow_types.cpp test/unit/unit_model.cpp $(IMPL_SRCS) -o bin/unit_tests

run: all
	./bin/funcional_tests
	./bin/unit_tests

run_funcional: all
	./bin/funcional_tests

run_unit: all
	./bin/unit_tests

doc:
	doxygen Doxyfile

clean:
	rm -rf bin/*
