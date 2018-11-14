#include "../include/Classificador.h"
#include "../include/ManipulaVetores.h"
#include <stdio.h>
#include <math.h>

float acuracia(float acertos, float total)
{
    float acc;

    acc = acertos / total;

    return acc;
}

void round2(float *n)
{
    *n = (round(*n * 100)) / 100;
}
