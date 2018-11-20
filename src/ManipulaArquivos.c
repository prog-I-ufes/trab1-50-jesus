#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaArquivos.h"
#include "../include/Classificador.h"
// #include "../include/Classificador.h"


// adicionando funções inúteis que vamos remover posteriormente
int arquivoVazio(FILE *f, int *k, char *d, float *r, char *pathTreino, char *pathTeste, char *pathEscrita)
{
    if (f == NULL)
    {
        printf("Nao foi possivel abrir o arquivo."); // merda não dá pra falar qual arquivo é
        freeAll(k, d, r, pathTreino, pathTeste, pathEscrita);
        fclose(f);
        exit(1);
    }

    return 0;
}


int leConfig(FILE *f, char **pathTreino, char **pathTeste, char **pathEscrita, int **k, char **d, float **r)
{
    int i = 0;
    int j = 0;

    /* Os três whiles se referem à leitura dos endereços
       de treino, teste e escrita, respectivamente */

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
    *cl = virgulas; // Retorna colunas (cada vírgula é uma coluna) (cada k uma lágrima)
    return matriz;  // Retorna matriz gerada
}
