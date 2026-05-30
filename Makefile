all:
	mkdir -p bin
	g++ $(filter-out src/main.cpp, $(wildcard src/*.cpp)) test/funcional/*.cpp -o bin/funcional_tests
	g++ $(filter-out src/main.cpp, $(wildcard src/*.cpp)) test/unit/*.cpp -o bin/unit_tests

run: all
	./bin/funcional_tests
	./bin/unit_tests

run_funcional: all
	./bin/funcional_tests

run_unit: all
	./bin/unit_tests

clean:
	rm -rf bin/*