BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src


all:  # faz toda a compilação necessária ao executar make
	gcc tc-CC-atiliodadalto-tiagodacruz.c "$(SRC)/ManipulaVetores.c" -o $(BIN)/main.exe"
	gcc -c $(SRC)/ManipulaVetores.c -I $(INCLUDE) -o $(OBJ)/main.o
	gcc dists.c "./src/ManipulaVetores.c" -o $(BIN)/dists.exe

run:
	$(BIN)/main.exe

dists:
	$(BIN)/dists.exe

hello:
	echo 'aasf'

#clean:
#	rm $(OBJ)//*.o
