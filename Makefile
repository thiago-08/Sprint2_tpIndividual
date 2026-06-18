SRC_FILES = $(filter-out src/main.cpp, $(wildcard src/*.cpp))

all:
	mkdir -p bin
	g++ -fPIC -shared $(SRC_FILES) -o bin/libmyvensim.so
	g++ test/funcional/*.cpp -Lbin -lmyvensim -Wl,-rpath,bin -o bin/funcional_tests
	g++ test/unit/*.cpp test/funcional/flow_types.cpp -Lbin -lmyvensim -Wl,-rpath,bin -o bin/unit_tests

run: all
	./bin/funcional_tests
	./bin/unit_tests

run_funcional: all
	./bin/funcional_tests

run_unit: all
	./bin/unit_tests

clean:
	rm -rf bin/*