#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaArquivos.h"

int leConfig(FILE *f, char **pathTreino, char **pathTeste, char **pathEscrita, int **k, char **d, float **r)
{
    int i = 0;
    int j = 0;

    /* Os três whiles seguintes se referem à leitura dos
       endereços de treino, teste e escrita, respectivamente */

    while (!feof(f))
    {
        fscanf(f, "%c", &((*pathTreino)[j]));
        if ((*pathTreino)[j] == '\n')
        {
            (*pathTreino)[j] = '\0';
            break;
        }

        j++;
        *pathTreino = realloc(*pathTreino, (j + 1) * sizeof(char));
    }
    j = 0;

    while (!feof(f))
    {
        fscanf(f, "%c", &((*pathTeste)[j]));
        if ((*pathTeste)[j] == '\n')
        {
            (*pathTeste)[j] = '\0';
            break;
        }

        j++;
        *pathTeste = realloc(*pathTeste, (j + 1) * sizeof(char));
    }
    j = 0;

    while (!feof(f))
    {
        fscanf(f, "%c", &((*pathEscrita)[j]));
        if ((*pathEscrita)[j] == '\n')
        {
            (*pathEscrita)[j] = '\0';
            break;
        }

        j++;
        *pathEscrita = realloc(*pathEscrita, (j + 30) * sizeof(char));
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
        *k = realloc(*k, (i + 2) * sizeof(int));
        *d = realloc(*d, (i + 2) * sizeof(char));
        *r = realloc(*r, (i + 2) * sizeof(float));

        i++;
    }

    return i;
}

// Para ler os dados do arquivo .csv
float **leDados(FILE *p, int *l, int *c)
{
    char caractereAtual;
    float **matriz;
    int k = 0, features = 0;
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
            features++;
        }
    }
    features += 1; // Após a última vírgula na leitura do arquivo, ainda há uma feature

    rewind(p); // Volta para o começo do arquivo após contar todas as vírgulas

    // Passa arquivo para matriz
    while (!feof(p))
    {
        matriz[k] = (float *)malloc((features) * sizeof(float));

        for (int j = 0; j < (features); j++)
        {
            fscanf(p, "%f, ", &matriz[k][j]);
        }

        k++;
        matriz = realloc(matriz, (k + 1) * sizeof(float *));
    }

    *l = k;        // Retorna linhas (k vizinhos)
    *c = features; // Retorna colunas (cada vírgula é uma coluna) (cada k uma lágrima)
    return matriz; // Retorna matriz gerada
}
