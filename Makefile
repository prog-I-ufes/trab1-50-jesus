BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
UNAME   := $(shell uname)
# uname: exibe informações sobre o sistema

# Se não for Linux, roda comandos para Windows
# Dá umas merdas no Windows mas funciona
# https://www.facebook.com/ridiculosserradonn/

all:
ifeq ($(UNAME), Linux)
	make allL
else
	make allW
endif

allL:
	make clean
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o" -g
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o" -g
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o" -g
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o" -g
	gcc -c testes.c -o "$(OBJ)/main.o" -g
	gcc $(OBJ)/*.o -o $(BIN)/main.out  -lm -g
	# compilar .out mesmo sera sera hmm 🤔
	eject
	eject -t
	echo ora parece que voce foi tapeado o sol eh prato
	make allL
	make val

allW:
	make clean
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o" -g
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o" -g
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o" -g
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o" -g
	gcc -c testes.c -o "$(OBJ)/main.o" -g
	gcc $(OBJ)/*.o -o $(BIN)/main.exe  -lm -g
	echo triste vida
	make run

run:
	$(BIN)/main.exe

out:
	$(BIN)/main.out

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

cleanW:
	del /F /Q "$(OBJ)\*.o"
