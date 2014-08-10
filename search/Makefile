SRC_DIR=./src
BIN_DIR=./bin
LIB_DIR=./lib
HEADER_DIR=./include

DEBUG=-g
OPT=-O2

all:deep-first bread-first level-order
deep-first: $(SRC_DIR)/deep-first.cpp
	g++ $(DEBUG) $(OPT) $(SRC_DIR)/deep-first.cpp -o $(BIN_DIR)/deep-fisrt -I$(HEADER_DIR)
bread-first: $(SRC_DIR)/bread-first.cpp
	g++ $(DEBUG) $(OPT) $(SRC_DIR)/bread-first.cpp -o $(BIN_DIR)/bread-fisrt -I$(HEADER_DIR)

level-order: $(SRC_DIR)/level-order.cpp
	g++ $(DEBUG) $(OPT) $(SRC_DIR)/level-order.cpp -o $(BIN_DIR)/level-order -I$(HEADER_DIR)

