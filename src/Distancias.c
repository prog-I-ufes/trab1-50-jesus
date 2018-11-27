#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
#include <math.h>

void distEuclid(float p[], float q[], int k, float *distE)
{
    float s[k], distancias = 0;

    subVet(p, q, k, s);                  // (pi - qi), ..., (pn - qn)
    quadradoVet(s, k, s);                // (pi - qi) ^ 2, ..., (pn - qn) ^ 2
    somaElementosVet(s, k, &distancias); // (pi - qi) ^ 2 + ... + (pn - qn) ^ 2
    *distE = sqrt(distancias);
}

void distMinkowski(float p[], float q[], int k, float r, float *distM)
{
    float s[k], distancias = 0;

    subVet(p, q, k, s);                  // (pi - qi), ..., (pn - qn)
    absVet(s, k, s);                     // (|pi - qi|), ..., (|pn - qn|)
    expVet(s, k, r, s);                  // (|pi - qi|) ^ r, ..., (|pn - qn|) ^ r
    somaElementosVet(s, k, &distancias); // (|pi - qi|) ^ r + ... + (|pn - qn|) ^ r
    distancias = pow(distancias, 1 / r); // ((|pi - qi|) ^ r + ... + (|pn - qn|) ^ r) ^ (1 / r)
    *distM = distancias;
}

void distChebyshev(float p[], float q[], int k, float *distC)
{
    float s[k];

    subVet(p, q, k, s); // (pi - qi), ..., (pn - qn)
    absVet(s, k, s);    // (|pi - qi|), ..., (|pn - qn|)
    *distC = maiorVet(s, k);
}
