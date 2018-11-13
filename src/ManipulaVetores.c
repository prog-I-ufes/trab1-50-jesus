#include "../include/ManipulaVetores.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

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
        printf("Posição: %d,  %.2f\n",i , a[i]);
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
        vetAbs[i] = fabs(a[i]);
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

void copiaVet(float *dest, float source[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        dest[i] = source[i];
    }
}

float maiorVet(float a[], int tam)
{
    int i;
    float maior;

    maior = a[0];
    for (i = 0; i < tam; i++)
    {
        if (a[i] > maior)
        {
            maior = a[i];
        }
    }

    return maior;
}

void boaSort(float a[], int tam, float *ordenado)
{
    int i = 0, j = 0;
    float aux;

    for (j = 0; j < tam; j++)
    {
        for (i = 0; i < tam - 1; i++)
        {
            if (ordenado[i] > ordenado[i + 1])
            {
                aux = ordenado[i];
                ordenado[i] = ordenado[i + 1];
                ordenado[i + 1] = aux;
            }
        }
    }
}


void douBoaSort(float a[], float b[], int tam){
    int i = 0, j = 0;
    float aux;

    for (j = 0; j < tam; j++)
    {
        for (i = 0; i < tam - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                
                aux = b[i];
                b[i] = b[i + 1];
                b[i + 1] = aux;
            }
        }
    }
}