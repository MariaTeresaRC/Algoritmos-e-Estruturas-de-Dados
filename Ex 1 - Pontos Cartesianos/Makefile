PONTO=ponto.c
CAMINHO=caminho.c
MAIN=main.c
BINARY=executavel

all:
	gcc -Wall -g $(PONTO) $(CAMINHO) $(MAIN) -o $(BINARY) -lm

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(PONTO) $(CAMINHO) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
