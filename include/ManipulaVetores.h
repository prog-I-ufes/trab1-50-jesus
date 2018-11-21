// Módulo com funções para manipulação de vetores

#ifndef __MANIPULAVETORES_H
#define __MANIPULAVETORES_H

void somaElementosVet(float a[], int tam, float *somaElementos);
void printaVet(float a[], int tam);
void somaVet(float a[], float b[], int tam, float *vetSoma);
void subVet(float a[], float b[], int tam, float *vetSub);
void prodVet(float a[], float b[], int tam, float *vetProd);
void absVet(float a[], int tam, float *vetAbs);
void expVet(float a[], int tam, float e, float *vetElevado);
void quadradoVet(float a[], int tam, float *vetQuadrado);
void copiaVet(float *dest, float source[], int tam);
void boaSort(float a[], float *ordenado, int tam);
void douBoaSort(float a[], float b[], int tam);
int ocorrenciasVet(float a[], float n, int tam);
int tudoIgualVet(float a[], int tam);
float maiorVet(float a[], int tam);
float maioriaVet(float a[], int tam);

#endif
