IMPL_SRCS = $(wildcard src/impl/*.cpp)
FUNC_SRCS = $(wildcard test/funcional/*.cpp)
UNIT_SRCS = $(wildcard test/unit/*.cpp)

all:
	mkdir -p bin
	g++ -fPIC -shared $(IMPL_SRCS) -o bin/libmyvensim.so
	g++ $(FUNC_SRCS) -Lbin -lmyvensim -Wl,-rpath,bin -o bin/funcional_tests
	g++ $(UNIT_SRCS) $(IMPL_SRCS) -o bin/unit_tests

run: all
	./bin/funcional_tests
	./bin/unit_tests

run_funcional: all
	./bin/funcional_tests

run_unit: all
	./bin/unit_tests

clean:
	rm -rf bin/*