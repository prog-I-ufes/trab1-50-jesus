	#? BIN      := ./bin    vai ter pasta de executável ou não nessa mizera
OBJ      := ./obj
INCLUDE  := ./include
SRC      := ./src
CFLAGS   := -Wall -g

all:
	make clean
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/main.o"
	gcc $(OBJ)/*.o -o main.out -lm
	echo -e "\n-------------------\n F U N C I O N O U \n\n G R A Z A D E U S\n-------------------\n"

run:
	./main.out

val:
	valgrind --leak-check=full -v ./main.out

clean:
	-rm $(OBJ)/*.o
	-rm main.out
