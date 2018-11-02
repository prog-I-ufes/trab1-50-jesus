BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src


all:  # faz toda a compilação necessária ao executar make
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"
	gcc -c "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"
	gcc -c testes.c -o "$(OBJ)/main.o"
	gcc -o $(BIN)/main.exe $(OBJ)/*.o -lm

run:
	$(BIN)/main.exe

#dists:
#	$(BIN)/dists.exe

hello:
	echo 'sim'

clean:
	del "$(OBJ)" ".o"
	del "$(BIN)" ".o"
