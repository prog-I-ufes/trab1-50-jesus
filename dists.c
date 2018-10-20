#include <stdio.h>
#include <math.h>
#include "include\ManipulaVetores.h"

void distEuclid(int p[], int q[], int s[], int k, int *distE);

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

void distEuclid(int p[], int q[], int s[], int k, int *distE)
{
    int i, distancias = 0;

    subVet(p, q, k, s);                  // (pi - qi), ..., (pn - qn)
    quadradoVet(s, k, s);                // (pi - qi)^2, ..., (pn - qn)^2
    somaElementosVet(s, k, &distancias); // (pi - qi)^2 + ... + (pn - qn)^2

    *distE = sqrt(distancias);
}
