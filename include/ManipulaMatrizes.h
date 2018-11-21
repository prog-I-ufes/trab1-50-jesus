// Módulo com funções para manipulação de matrizes

#ifndef __MANIPULAMATRIZES_H
#define __MANIPULAMATRIZES_H


void leMat(float **M, int l, int c);
void printaMat(int l, int c, int M[l][c]);
void fprintaMat(FILE *f, int l, int c, int M[l][c]);
int **inicializaMat(int l, int c, int M[l][c]);

#endif
