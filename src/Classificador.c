#include "../include/Classificador.h"
#include <stdio.h>
#include <math.h>

int acuracia(int acertos, int erros)
{
    int acc;

    acc = acertos / erros;

    return acc;
}

void round2(float *n)
{
    *n = (round(*n * 100)) / 100;
}
