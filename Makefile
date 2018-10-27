BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src


all:  # faz toda a compilação necessária ao executar make
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c tc-CC-atiliodadalto-tiagodacruz.c -o "$(OBJ)/main.o"
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
