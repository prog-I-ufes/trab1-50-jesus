#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaArquivos.h"
#include "../include/Classificador.h"

int leConfig(FILE *f, char p1[], char p2[], char p3[], int **k, char **d, float **r)
{
    int i = 0;

    if (f == NULL)
    {
        printf("Não existe config.txt aberto no programa\n");
        exit(1);
    }

    fscanf(f, "%s\n", p1);
    fscanf(f, "%s\n", p2);
    fscanf(f, "%s\n", p3);

    while (!feof(f))
    {
        fscanf(f, "%d, %c, ", &((*k)[i]), &((*d)[i]));

        if (((*d)[i]) == 'M')
        {
            fscanf(f, "%f, ", &((*r)[i]));
        }
        else
        {
            ((*r)[i]) = 0;
        }

        *k = realloc(*k, (2 + i) * sizeof(int));
        *d = realloc(*d, (2 + i) * sizeof(char));
        *r = realloc(*r, (2 + i) * sizeof(float));

        i++;
    }

    return i;
}
