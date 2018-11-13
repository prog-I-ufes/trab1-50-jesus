#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
#include "../include/Classificador.h"
#include <stdio.h>
#include <math.h>

void distEuclid(float p[], float q[], int k, float *distE)
{
    float i, s[k], distancias = 0;

    subVet(p, q, k, s);                  // (pi - qi), ..., (pn - qn)
    quadradoVet(s, k, s);                // (pi - qi)^2, ..., (pn - qn)^2
    somaElementosVet(s, k, &distancias); // (pi - qi)^2 + ... + (pn - qn)^2
    *distE = sqrt(distancias);
    round2(distE);
}

void distMinkowski(float p[], float q[], int k, float r, float *distM)
{
    float i, s[k], distancias = 0;

    subVet(p, q, k, s);
    absVet(s, k, s);
    expVet(s, k, r, s);
    somaElementosVet(s, k, &distancias);
    distancias = pow(distancias, 1 / r);
    *distM = distancias;
}

void distChebyshev(float p[], float q[], int k, float *distC)
{
    float distE, s[k], distancias = 0;

    subVet(p, q, k, s);
    absVet(s, k, s);
    *distC = maiorVet(s, k);
}
