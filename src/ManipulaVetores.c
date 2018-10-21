#include "../include/ManipulaVetores.h"
#include <stdio.h>
#include <math.h>

// gcc -c $(SRC)/ManipulaVetores.c -I $(INCLUDE) -o $(OBJ)/main.o

// gcc -c $(SRC)/ManipulaVetores.c -I $(INCLUDE) -o $(OBJ)/ManipulaVetores.o

// Soma todos os elementos de um vetor entre si
void somaElementosVet(float a[], int tam, float *somaElementos)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        *somaElementos += a[i];
    }
}

void leVet(float *a, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        scanf("%f", &a[i]);
    }

    printf("\n");
}

void printaVet(float a[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("%.2f\n", a[i]);
    }

    printf("\n");
}

void somaVet(float a[], float b[], int tam, float *vetSoma)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetSoma[i] = a[i] + b[i];
    }
}

// Subtrai B de A
void subVet(float a[], float b[], int tam, float *vetSub)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetSub[i] = a[i] - b[i];
    }
}

void prodVet(float a[], float b[], int tam, float *vetProd)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetProd[i] = a[i] * b[i];
    }
}

void absVet(float a[], int tam, float *vetAbs)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetAbs[i] = abs(a[i]);
    }
}

// Caso particular de expVet
void quadradoVet(float a[], int tam, float *vetQuadrado)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetQuadrado[i] = a[i] * a[i];
    }
}

void expVet(float a[], int tam, float e, float *vetElevado)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetElevado[i] = powf(a[i], e);
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
