#include "../include/ManipulaVetores.h"
#include <stdio.h>
#include <math.h>

// Soma todos os elementos de um vetor entre si
void somaElementosVet(float a[], int tam, float *somaElementos)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        *somaElementos += a[i];
    }
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

void expVet(float a[], int tam, float e, float *vetElevado)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        vetElevado[i] = powf(a[i], e);
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

void copiaVet(float *dest, float source[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        dest[i] = source[i];
    }
}

void boaSort(float a[], float *ordenado, int tam)
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

// Versão do boaSort para float (finge que é pra (dou)ble) e que ordena B em relação a A
// (Isto é útil na ordenação dos rótulos com as distâncias)
void douBoaSort(float a[], float b[], int tam)
{
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

int inicializaVet(int a[], int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        a[i] = 0;
    }

    return 0;
}

// Quantas vezes um float ocorre no vetor
int ocorrenciasVet(float a[], float n, int tam)
{
    int ocorrencias = 0;

    for (int i = 0; i < tam; i++)
    {
        if (a[i] == n)
        {
            ocorrencias++;
        }
    }

    return ocorrencias;
}

// Se todos os elementos do vetor são iguais
int tudoIgualVet(float a[], int tam)
{
    int i;

    for (i = 0; i < tam - 1; i++)
    {
        if (a[i] != a[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

// Maior elemento do vetor
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

// Elemento que mais ocorre em um vetor (retorna o menor de maior ocorrência)
float maioriaVet(float a[], int tam)
{
    int i;
    int ocorre = 0, maiorOcorrencia = 0;
    int moda = 0;

    if (tudoIgualVet(a, tam))
    {
        return a[0];
    }

    else
    {
        for (i = 0; i < tam; i++)
        {
            ocorre = ocorrenciasVet(a, a[i], tam);

            if (ocorre > maiorOcorrencia)
            {
                moda = a[i];
                maiorOcorrencia = ocorre;
            }
            else if (ocorre == maiorOcorrencia)
            {
                if (moda > a[i])
                {
                    moda = a[i];
                }
            }
        }

        return moda;
    }
}
