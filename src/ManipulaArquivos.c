#include <stdio.h>
#include <stdlib.h>
#include "../include/ManipulaArquivos.h"
#include "../include/Classificador.h"

int leConfig(FILE *f, char **p1, char **p2, char **p3, int **k, char **d, float **r)
{
    int i = 0;
    int j = 0;

    while(!feof(f)){
        fscanf(f, "%c", &((*p1)[j]));
        if((*p1)[j] == '\n'){
            (*p1)[j] = '\0';
            break;
        }
        j++;
        *p1 = realloc(*p1, (j+1)*sizeof(char));
    }
    j = 0;
    while(!feof(f)){
        fscanf(f, "%c", &((*p2)[j]));
        if((*p2)[j] == '\n'){
            (*p2)[j] = '\0';
            break;
        }
        j++;
        *p2 = realloc(*p2, (j+1)*sizeof(char));
    }
    j = 0;
    while(!feof(f)){
        fscanf(f, "%c", &((*p3)[j]));
        if((*p3)[j] == '\n'){
            (*p3)[j] = '\0';
            break;
        }
        j++;
        *p3 = realloc(*p3, (j+1)*sizeof(char));
    }
    j = 0;
    //fscanf(f, "%s\n", p2);
    //fscanf(f, "%s\n", p3);

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
