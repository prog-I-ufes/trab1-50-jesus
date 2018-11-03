BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src

all:
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c testes.c -o "$(OBJ)/main.o"
	gcc $(OBJ)/*.o -o $(BIN)/main.exe  -lm

run:
	$(BIN)/main.exe

clean:
	del /F /Q "$(OBJ)" ".o"
	del /F /Q "$(BIN)" ".exe"
