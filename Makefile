OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3 -march=native -ftree-loop-vectorize -pipe
# -Os (parece ser mais lenta que O2 que por sua vez é mais lenta que O3) -Ofast (It also enables optimizations that are not valid for all standard-compliant programs. It turns on -ffast-math) (aaa)
# The first and most important option is -march. This tells the compiler what code it should produce for the system's processor architecture (or arch); it tells GCC that it should produce code for a certain kind of CPU.
# -flto and various other flags can be used to switch on link-time optimization (LTO). This can result in improved performance and smaller code, but may interfere with debugging. It may also reveal conformance issues in the source code that were previously hidden by separate compilations.
# For some applications -O3 or -O2 -ftree-loop-vectorize will provide a significant speed boost. By default, GCC does not perform loop vectorization. The reason it isn't enabled at -O2 is that it doesn't always improve code, it can make code slower as well, and usually makes the code larger; it really depends on the loop etc.
# A common flag is -pipe. This flag has no effect on the generated code, but it makes the compilation process faster. It tells the compiler to use pipes instead of temporary files during the different stages of compilation, which uses more memory. On systems with low memory, GCC might get killed. In those cases do not use this flag. [[[[[[LABGRAD INTENSIFIES]]]]]]
# Basicamente tirado de https://wiki.gentoo.org/wiki/GCC_optimization/pt-br e https://developers.redhat.com/blog/2018/03/21/compiler-and-linker-flags-gcc/


all: main

main: $(OBJ)/Distancias.o $(OBJ)/ManipulaVetores.o $(OBJ)/ManipulaMatrizes.o $(OBJ)/ManipulaArquivos.o $(OBJ)/Classificador.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o trab1 -lm $(CFLAGS)

$(OBJ)/Distancias.o: $(SRC)/Distancias.c $(INC)/Distancias.h
	gcc -c $(CFLAGS) "$(SRC)/Distancias.c" -o "$(OBJ)/Distancias.o"

$(OBJ)/ManipulaVetores.o: $(SRC)/ManipulaVetores.c $(INC)/ManipulaVetores.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaVetores.c" -o "$(OBJ)/ManipulaVetores.o"

$(OBJ)/ManipulaMatrizes.o: $(SRC)/ManipulaMatrizes.c $(INC)/ManipulaMatrizes.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaMatrizes.c" -o "$(OBJ)/ManipulaMatrizes.o"

$(OBJ)/ManipulaArquivos.o: $(SRC)/ManipulaArquivos.c $(INC)/ManipulaArquivos.h
	gcc -c $(CFLAGS) "$(SRC)/ManipulaArquivos.c" -o "$(OBJ)/ManipulaArquivos.o"

$(OBJ)/Classificador.o: $(SRC)/Classificador.c $(INC)/Classificador.h
	gcc -c $(CFLAGS) "$(SRC)/Classificador.c" -o "$(OBJ)/Classificador.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"


run:
	./trab1

time:
	time ./trab1

val:
	valgrind --leak-check=full -v ./trab1

clean:
	-rm $(OBJ)/*.o
	-rm trab1
