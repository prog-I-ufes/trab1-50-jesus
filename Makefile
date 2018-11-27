OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -Os -march=native -ftree-loop-vectorize -pipe -flto -Wall
# -Os -Ofast

all: main

main: $(OBJ)/Distancias.o $(OBJ)/ManipulaVetores.o $(OBJ)/ManipulaMatrizes.o $(OBJ)/ManipulaArquivos.o $(OBJ)/Classificador.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o trab1 -lm

$(OBJ)/Distancias.o: $(SRC)/Distancias.c $(INC)/Distancias.h
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"

$(OBJ)/ManipulaVetores.o: $(SRC)/ManipulaVetores.c $(INC)/ManipulaVetores.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"

$(OBJ)/ManipulaMatrizes.o: $(SRC)/ManipulaMatrizes.c $(INC)/ManipulaMatrizes.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"

$(OBJ)/ManipulaArquivos.o: $(SRC)/ManipulaArquivos.c $(INC)/ManipulaArquivos.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"

$(OBJ)/Classificador.o: $(SRC)/Classificador.c $(INC)/Classificador.h
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"


run:
	./trab1

val:
	valgrind --leak-check=full -v ./trab1

clean:
	-rm $(OBJ)/*.o
	-rm trab1
