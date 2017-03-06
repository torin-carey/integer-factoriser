CC=gcc
CFLAGS=-g -lm -I$(SRC)

SRC=./src
BIN=./bin
EXAMPLE=./examples

LIBOUT=libintegerfactoriser.a
DEP=factoriser.h
OBJ=factoriser.o sieve.o algorithms.o
EXAMPLES=factorise totient
BINOBJ=$(addprefix $(BIN)/, $(OBJ))

.PHONY: all clean reset

all: $(LIBOUT) $(EXAMPLES)

$(LIBOUT): $(BIN) $(BINOBJ)
	ar rvsc $@ $(BINOBJ)

factorise: $(EXAMPLE)/factorise.c $(LIBOUT)
	gcc -o $@ $^ $(CFLAGS)

totient: $(EXAMPLE)/totient.c $(LIBOUT)
	gcc -o $@ $^ $(CFLAGS)

$(BIN)/%.o: $(SRC)/%.c $(SRC)/$(DEP)
	gcc -c -o $@ $< $(CFLAGS)

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)

reset: clean
	rm -f $(LIBOUT) $(EXAMPLES)
