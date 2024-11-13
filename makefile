SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := .

EXE := $(BIN_DIR)/spendscan
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXX = g++
CXXVERSION = -std=c++2b
CXXFLAGS = -Wall -g

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXVERSION) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXVERSION) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rv $(OBJ_DIR) $(EXE)
