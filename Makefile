CC=gcc
CFLAGS=-g -lm

SRC=./src
BIN=./bin

DEP=factoriser.h
OBJ=factoriser.o sieve.o main.o

.PHONY: all clean

all: $(BIN) factorise

factorise:  $(addprefix $(BIN)/, $(OBJ))
	gcc -o $@ $^ $(CFLAGS)

$(BIN)/%.o: $(SRC)/%.c $(SRC)/$(DEP)
	gcc -c -o $@ $< $(CFLAGS)

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)
