
#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaMatrizes.h"

void leMat(float **M, int l, int c)
{
    int i, j_ordana;

    printf("Informe os valores da matriz:\n");
    for (i = 0; i < l; i++)
    {
        for (j_ordana = 0; j_ordana < c; j_ordana++)
        {
            scanf("%f", &M[i][j_ordana]);
        }
    }
}

void printaMat(int l, int c, int M[l][c])
{
    int i, j_ordana;

    printf("\n");
    for (i = 0; i < l; i++)
    {
        for (j_ordana = 0; j_ordana < c; j_ordana++)
        {
            printf("%i ", M[i][j_ordana]);
        }
        printf("\n");
    }
    printf("\n");
}

void fprintaMat(FILE *f, int l, int c, int M[l][c])
{
    int i, j_ordana;

    for (i = 0; i < l; i++)
    {
        fprintf(f, "%d", M[i][0]);
        for (j_ordana = 1; j_ordana < c; j_ordana++)
        {
            fprintf(f, " %d", M[i][j_ordana]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}

int **inicializaMat(int l, int c, int M[l][c])
{
    int i, j_ordana;

    for (i = 0; i < l; i++)
    {
        for (j_ordana = 0; j_ordana < c; j_ordana++)
        {
            M[i][j_ordana] = 0;
        }
    }

    return 0;
}

// ???
float **mallocaMat(float **M, int l, int c)
{
    int i;

    M = (float**)malloc(l * sizeof(float*));
    for (i = 0; i < l; i++)
    {
        M[i] = (float*)malloc(c * sizeof(float));
    }

    return M;
}

/*
void main()
{
    int i;
    int l, c;

    printf("Informe o numero de linhas: ");
    scanf(" %i", &l);

    printf("Informe o numero de colunas: ");
    scanf(" %i", &c);

    float A[l][c], **B;
    // printaMatEstatica(l, c, A);
    // inicializaMat(l, c, A);
    // printaMatEstatica(l, c, A);

    // mallocaMat(B, l, c);
    // inicializaMat(l, c, A);
    printaMatDinamica(l, c, B);
    // inicializaMat(B, l, c);
    // printaMat(B, l, c);
}
*/
