# Compilador
CC=gcc

# Flags para compilação e vinculação
CFLAGS=-g -Wall -Werror -Wextra -pedantic
LDFLAGS=-lm

# Nome do arquivo executável
EXECUTABLE=trab

# Arquivos fonte
SRC_ORDENACAO=ordenacao.c
SRC_MAIN=main.c

# Arquivos objeto
OBJ_ORDENACAO=ordenacao.o
OBJ_MAIN=main.o

# Alvo default
all: $(EXECUTABLE)

# Alvo para criar arquivo executável
$(EXECUTABLE): $(OBJ_ORDENACAO) $(OBJ_MAIN)
	$(CC) $(LDFLAGS) $^ -o $@

# Alvo para compilar libAgenda.c
$(OBJ_ORDENACAO): $(SRC_ORDENACAO)
	$(CC) $(CFLAGS) -c $^ -o $@

# Alvo para compilar main.c
$(OBJ_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -c $^ -o $@

# Alvo para limpar os arquivos objeto e executável
clean:
	rm -f $(OBJ_ORDENACAO) $(OBJ_MAIN) $(EXECUTABLE)
