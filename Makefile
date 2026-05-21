CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

BIN_DIR = bin
SRC_DIR = src
TEST_FUNC_DIR = test/funcional

CORE_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))

FUNC_FILES = $(TEST_FUNC_DIR)/main.cpp $(TEST_FUNC_DIR)/funcional_tests.cpp

EXEC_FUNC = $(BIN_DIR)/funcional_tests

all: build_dir func

build_dir:
	mkdir -p $(BIN_DIR)

func: $(FUNC_FILES) $(CORE_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_FUNC)

run: all
	./$(EXEC_FUNC)

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all build_dir func run clean