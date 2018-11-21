// Módulo com algoritmos para cálculo das distâncias

#ifndef __DISTANCIAS_H
#define __DISTANCIAS_H

void distEuclid(float p[], float q[], int k, float *distE);
void distMinkowski(float p[], float q[], int k, float r, float *distM);
void distChebyshev(float p[], float q[], int k, float *distC);

#endif
