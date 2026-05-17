CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

BIN_DIR = bin
SRC_DIR = src
TEST_FUNC_DIR = test/funcional
TEST_UNIT_DIR = test/unit

CORE_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))

EXEC_APP = $(BIN_DIR)/mySim
EXEC_FUNC = $(BIN_DIR)/funcional_tests
EXEC_UNIT = $(BIN_DIR)/unit_tests

all: build_dir app func unit

build_dir:
	mkdir -p $(BIN_DIR)

app: $(SRC_DIR)/main.cpp $(CORE_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_APP)

func: $(TEST_FUNC_DIR)/main.cpp $(TEST_FUNC_DIR)/funcional_tests.cpp $(CORE_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_FUNC)

unit: $(TEST_UNIT_DIR)/main.cpp $(TEST_UNIT_DIR)/unit_tests.cpp $(CORE_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_UNIT)

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all build_dir app func unit clean