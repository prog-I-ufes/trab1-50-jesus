BIN     = ./bin
OBJ     = ./obj
INCLUDE = ./include
SRC     = ./src


all:  # faz toda a compilação necessária ao executar make
	gcc tc-CC-atiliodadalto-tiagodacruz.c "$(SRC)/*.c" -o "$(BIN)/main.exe"
	gcc -c "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"
	gcc -c "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"
	gcc -c tc-CC-atiliodadalto-tiagodacruz.c -o "$(OBJ)/main.o"

run:
	$(BIN)/main.exe

#dists:
#	$(BIN)/dists.exe

hello:
	echo 'sim'

#clean:
#	rm $(OBJ)//*.o
