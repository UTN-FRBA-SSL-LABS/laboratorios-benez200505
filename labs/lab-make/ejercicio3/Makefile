# Nombre del ejecutable final
PROGRAMA := calc3

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

$(PROGRAMA): parser3.y scanner3.l
	# TODO 1: bison ...
	bison -d parser3.y
	# TODO 2: flex ...
	flex scanner3.l
	# TODO 3: $(CC) ...
	$(CC) lex.yy.c parser3.tab.c -o $(PROGRAMA)

clean:
	# TODO 4: rm -f ...
	rm -f $(PROGRAMA) lex.yy.c parser3.tab.c parser3.tab.h
.PHONY: all clean
