# Nombre del ejecutable final
PROGRAMA := scanner2

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

$(PROGRAMA): scanner2.l
	# TODO 1: flex ...
	flex scanner2.l
	# TODO 2: $(CC) ...
	$(CC) lex.yy.c -o $(PROGRAMA)

clean:
	# TODO 3: rm -f ...
	rm -f $(PROGRAMA) lex.yy.c