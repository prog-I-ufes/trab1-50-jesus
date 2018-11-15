#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaArquivos.h"
// #include "../include/Classificador.h"

int leConfig(FILE *f, char **p1, char **p2, char **p3, int **k, char **d, float **r)
{
    int i = 0;
    int j = 0;

    while (!feof(f))
    {
        fscanf(f, "%c", &((*p1)[j]));
        if ((*p1)[j] == '\n')
        {
            (*p1)[j] = '\0';
            break;
        }
        j++;
        *p1 = realloc(*p1, (j + 1) * sizeof(char));
    }
    j = 0;

    while (!feof(f))
    {
        fscanf(f, "%c", &((*p2)[j]));
        if ((*p2)[j] == '\n')
        {
            (*p2)[j] = '\0';
            break;
        }
        j++;
        *p2 = realloc(*p2, (j + 1) * sizeof(char));
    }
    j = 0;

    while (!feof(f))
    {
        fscanf(f, "%c", &((*p3)[j]));
        if ((*p3)[j] == '\n')
        {
            (*p3)[j] = '\0';
            break;
        }
        j++;
        *p3 = realloc(*p3, (j + 30) * sizeof(char));
    }
    j = 0;

    i = 0;
    while (!feof(f))
    {
        ((*d)[i]) = ' ';

        fscanf(f, "%d, ", &((*k)[i]));
        fscanf(f, "%c, ", &((*d)[i]));

        if (((*d)[i]) == 'M')
        {
            fscanf(f, "%f, ", &((*r)[i]));
        }
        else
        {
            ((*r)[i]) = 0;
        }

        // Alocação extra (2) por segurança
        *k = realloc(*k, (2 + i) * sizeof(int));
        *d = realloc(*d, (2 + i) * sizeof(char));
        *r = realloc(*r, (2 + i) * sizeof(float));

        i++;
    }

    return i;
}

float **leDados(FILE *p, int *ln, int *cl)
{
    char caractereAtual;
    float **matriz;
    int k = 0;
    int virgulas = 0;
    matriz = (float **)malloc(1 * sizeof(float *));

    while (!feof(p)) // Conta vírgulas
    {
        fscanf(p, "%c", &caractereAtual);
        if (caractereAtual == '\n')
        {
            break;
        }
        else if (caractereAtual == ',')
        {
            virgulas++;
        }
    }

    rewind(p); // Volta para o começo do arquivo após contar todas as vírgulas

    // Passa arquivo para matriz
    // Aqui, alocamos 'virgulas + 1' pois, após a última vírgula na leitura do arquivo, ainda há um número
    while (!feof(p))
    {
        matriz[k] = (float *)malloc((virgulas + 1) * sizeof(float));

        for (int j = 0; j < (virgulas + 1); j++)
        {
            fscanf(p, "%f, ", &matriz[k][j]);
        }

        k++;
        matriz = realloc(matriz, (1 + k) * sizeof(float *));
    }

    *ln = k;        // Retorna linhas (k vizinhos)
    *cl = virgulas; // Retorna colunas (cada vírgula é uma coluna)
    return matriz;  // Retorna matriz gerada
}
