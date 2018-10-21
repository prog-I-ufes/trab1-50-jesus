#include "../include/Distancias.h"
#include "../include/ManipulaVetores.h"
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

// Colocar em outro módulo posteriormente
void round2(float *n)
{
    *n = (round(*n * 100)) / 100;
}


/*
int main()
{
    int i, k, stotal, distE;

    printf("k: ");
    scanf("%i", &k);

    int p[k], q[k], s[k];

    leVet(p, k);
    leVet(q, k);

    distEuclid(p, q, s, k, &distE);
    printf("Distancia euclidiana: %i", distE);

    return 0;
}
*/
