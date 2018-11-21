
#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaMatrizes.h"

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
void mallocaMat(float ***M, int l, int c)
{
    int i;

    *M = (float**)malloc(l * sizeof(float*));
    for (i = 0; i < l; i++)
    {
        *M[i] = (float*)malloc(c * sizeof(float));
    }

}
