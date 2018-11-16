BIN      := ./bin
OBJ      := ./obj
INCLUDE  := ./include
SRC      := ./src
CFLAGS   := -Wall -g
UNAME    := $(shell uname)
# uname: exibe informações sobre o sistema

# Se não for Linux, roda comandos para Windows
# Dá umas merdas no Windows mas funciona
# Obviamente vamos remover antes de entregar
# https://www.facebook.com/ridiculosserradonn/

all:
ifeq ($(UNAME), Linux)
	make allL
else
	make allW
endif

allL:
	make clean
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c $(CFLAGS) testeKNN.c -o "$(OBJ)/main.o"
	gcc $(OBJ)/*.o -o $(BIN)/main.out -lm
	echo -e "\n-------------------\n F U N C I O N O U \n\n G R A Z A D E U S\n-------------------\n"

allW:
	make clean
	cls
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c $(CFLAGS) testeKNN.c -o "$(OBJ)/main.o"
	gcc $(OBJ)/*.o -o $(BIN)/main.exe -lm

run:
ifeq ($(UNAME), Linux)
	make out
else
	make exe
endif

out:
	$(BIN)/main.out

exe:
	$(BIN)/main.exe

val:
	valgrind $(BIN)/main.out

clean:
ifeq ($(UNAME), Linux)
	make cleanL
else
	make cleanW
endif

cleanL:
	-rm $(OBJ)/*.o
	-rm $(BIN)/main.out

cleanW:
	del /F /Q "$(OBJ)\*.o"
	del /F /Q "$(BIN)\main.exe"
