BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src

all:
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o" -g
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o" -g
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o" -g
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o" -g
	gcc -c testes.c -o "$(OBJ)/main.o" -g
	gcc $(OBJ)/*.o -o $(BIN)/main.exe  -lm -g
	eject
	eject -t

run:
	$(BIN)/main.exe

clean:
	del /F /Q "$(OBJ)" ".o"
	del /F /Q "$(BIN)" ".exe"
