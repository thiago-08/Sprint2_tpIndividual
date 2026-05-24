all:
	mkdir -p bin
	g++ $(filter-out src/main.cpp, $(wildcard src/*.cpp)) test/funcional/*.cpp -o bin/funcional_tests

run: all
	./bin/funcional_tests

clean:
	rm -rf bin/*