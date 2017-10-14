IDIR = ./header
CXX = g++
CFLAGS=-I $(IDIR)

ODIR=obj

CXXFLAGS += -g -Wall -Wextra -pthread -Weffc++

MAIN = main

DEPS = Dados.h Pilha.h esqueleto.h funcoes.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = funcoes.o esqueleto.o Pilha.o Index.o busca_binaria.o heapsort.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)


main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN) $^ $(CFLAGS)

teste: funcoes.c esqueleto.c Pilha.c Index.c busca_binaria.c heapsort.c main.c
	$(CXX) $(CXXFLAGS) -o $(MAIN) $^ $(CFLAGS)