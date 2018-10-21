#include "../include/ManipulaVetores.h"
#include <stdio.h>

// gcc -c $(SRC)/ManipulaVetores.c -I $(INCLUDE) -o $(OBJ)/main.o

// gcc -c $(SRC)/ManipulaVetores.c -I $(INCLUDE) -o $(OBJ)/ManipulaVetores.o

// Soma todos os elementos de um vetor entre si
void somaElementosVet(int a[], int tam, int *somaElementos)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        *somaElementos += a[i];
    }
}

void leVet(int *a, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        scanf("%i", &a[i]);
    }

    printf("\n");
}

void printaVet(int a[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%i\n", a[i]);
    }

    printf("\n");
}

void somaVet(int a[], int b[], int tam, int *vetSoma)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetSoma[i] = a[i] + b[i];
    }
}

// Subtrai B de A
void subVet(int a[], int b[], int tam, int *vetSub)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetSub[i] = a[i] - b[i];
    }
}

void prodVet(int a[], int b[], int tam, int *vetProd)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetProd[i] = a[i] * b[i];
    }
}

void quadradoVet(int a[], int tam, int *vetQuadrado)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetQuadrado[i] = a[i] * a[i];
    }
}

/*
int main()
{
    int i, tam = 3, a[tam], b[tam], soma[tam], sub[tam], prod[tam], quadrado[tam];

    leVet(a, tam);
    leVet(b, tam);

    somaVet(a, b, tam, soma);
    subVet(a, b, tam, sub);
    prodVet(a, b, tam, prod);
    quadradoVet(a, tam, quadrado);

    printaVet(soma, tam);
    printaVet(sub, tam);
    printaVet(prod, tam);
    printaVet(quadrado, tam);

    return 0;
}
*/
