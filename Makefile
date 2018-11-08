BIN     := ./bin
OBJ     := ./obj
INCLUDE := ./include
SRC     := ./src
UNAME   := $(shell uname)
# uname: exibe informações sobre o sistema

# Se não for Linux, roda comandos para Windows
ifeq ($(UNAME), Linux)
allL:
	make cleanL
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o" -g
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o" -g
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o" -g
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o" -g
	gcc -c testes.c -o "$(OBJ)/main.o" -g
	gcc $(OBJ)/*.o -o $(BIN)/main.out  -lm -g
	eject
	eject -t
	make runL
else
allW:
	make cleanW
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o" -g
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o" -g
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o" -g
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o" -g
	gcc -c testes.c -o "$(OBJ)/main.o" -g
	gcc $(OBJ)/*.o -o $(BIN)/main.exe  -lm -g
	eject
	eject -t
	make runW
endif

runW:
	$(BIN)/main.exe

runL:
	valgrind $(BIN)/main.out
	make cleanL

cleanL:
	-rm $(OBJ)/*.o

cleanW:
	del /F /Q "$(OBJ)" ".o"
	del /F /Q "$(BIN)" ".exe"
