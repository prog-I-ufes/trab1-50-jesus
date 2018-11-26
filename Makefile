OBJ      := ./obj
INCLUDE  := ./include
SRC      := ./src
CFLAGS   := -Wall -g -O2

all:
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"
	gcc $(OBJ)/*.o -o trab1 -lm

run:
	./trab1

val:
	valgrind --leak-check=full -v ./trab1

clean:
	-rm $(OBJ)/*.o
	-rm trab1
