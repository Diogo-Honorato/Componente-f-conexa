# Definição de variáveis
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
SOURCES = modules/adjlistlib.c modules/EdgeFileReader.c modules/GraphPng.c modules/ReadFile.c modules/Queue.c modules/Stack.c modules/sub_f-conexo.c main.c

	  
HEADERS = modules/libgraph.h modules/f-conexo.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = grafo

# Regras de compilação
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)