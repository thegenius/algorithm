SRC_DIR=./src
BIN_DIR=./bin
LIB_DIR=./lib
HEADER_DIR=./include

DEBUG=-g
OPT=-O2

all:power2 count1
power2: $(SRC_DIR)/power2.cpp
	g++ $(DEBUG) $(OPT) $(SRC_DIR)/power2.cpp -o $(BIN_DIR)/power2 -I$(HEADER_DIR)
count1: $(SRC_DIR)/count1.cpp
	g++ $(DEBUG) $(OPT) $(SRC_DIR)/count1.cpp -o $(BIN_DIR)/count1 -I$(HEADER_DIR)
