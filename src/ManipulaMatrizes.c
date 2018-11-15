/* e tá errado? sim
essa merda foi commitada sem minha permissão

eis que você não saber usar vetor de ponteiro de ponteiro de vetor

 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void inicializaMat(float **M, int t)
{
    int i, j_ordana;

    for (i = 0; i < t; i++)
    {
        for (j_ordana = 0; j_ordana < t; j_ordana++)
        {
            M[i][j_ordana] = 0;
        }
    }
}

void leMat(float **M, int t)
{
    int i, j_ordana;

    printf("Informe os valores da matriz:\n");
    for (i = 0; i < t; i++)
    {
        for (j_ordana = 0; j_ordana < t; j_ordana++)
        {
            scanf("%i", &M[i][j_ordana]);
        }
    }
}

int main()
{
    int l = 3;
    int c = 3;

    float **M = (int **)malloc(l * sizeof(int *));

    for (int i = 0; i < l; i++)
    {
        M[i] = (int *)malloc(c * sizeof(int));
    }

    // M = (float **)malloc(3 * sizeof(float *));

    int t = 3;

    leMat(M, t);

    return 0;
}
*/
