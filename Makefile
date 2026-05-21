CXX = g++
CXXFLAGS = -Wall 

all: func

SRC_DIR = src
TEST_FUNC_DIR = test/funcional

CORE_FILES = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))

FUNC_FILES = $(wildcard $(TEST_FUNC_DIR)/*.cpp)

func: $(FUNC_FILES) $(CORE_FILES) 
	$(CXX) $(CXXFLAGS) $^ -o bin/funcional_tests