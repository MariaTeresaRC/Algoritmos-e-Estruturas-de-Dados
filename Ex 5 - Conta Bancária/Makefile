MAIN=main.c
BINARY=executavel

all:
	gcc -Wall -g arvore.c cliente.c $(MAIN) -o $(BINARY)

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) arvore.c cliente.c -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
